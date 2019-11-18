#include "monster.hpp"

/* Constructors */
Monster::Monster(Game* g, int i, int j): Elem("s", g, i, j), Move(), Damage(100){

}

/* Path */
#define INF INT_MAX

pair<int, int> dijkstra(Board* b, pair<int, int> s, pair<int, int> dest){
  int rows = b->getLines();
  int cols = b->getCols();

  int row[] = {-1, -1, -1, 0, 0,  1, 1, 1};
  int col[] = {-1,  0,  1, -1,1, -1, 0, 1};

  /* Init */
  int distance[rows][cols];
  bool visited[rows][cols];
  pair<int, int> pred[rows][cols];

  for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
      distance[i][j] = INF;

      visited[i][j] = false;

      pred[i][j] = make_pair(-1, -1);
    }
  }
  distance[s.first][s.second] = 0;
  pred[s.first][s.second] = make_pair(s.first, s.second);

  class Prioritize{
  public:
    bool operator()(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2){
      return p1.second > p2.second;
    }
  };

  priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, Prioritize> pq;
  pq.push(make_pair(make_pair(s.first, s.second), distance[s.first][s.second]=0));

  while(!pq.empty()){
    pair<pair<int, int>, int> u = pq.top();
    pq.pop();

    pair<int, int> u_pos = u.first;
    int i = u_pos.first;
    int j = u_pos.second;
    if(visited[i][j])
      continue;

    visited[i][j] = true;
    for(int k=0; k<8; k++){
      int x = i + row[k];
      int y = j + col[k];
      if(x>=0 && x<rows && y>=0 && y<cols){
        Cell* c = b->getCell(x, y);
        Elem* e = c->getElem();
        if(e!=nullptr && e->getSymb()!="J"){
          // nothing
        }
        else if(!visited[x][y] && 1+u.second < distance[x][y]){
          pred[x][y] = make_pair(i, j);
          pq.push(make_pair(make_pair(x, y), (distance[x][y]=1+u.second)));
        }
      }
    }
  }
  if(distance[dest.first][dest.second] == INF){
    return make_pair(s.first, s.second);
  }

  pair<int, int> test = pred[dest.first][dest.second];
  int pred_i = test.first;
  int pred_j = test.second;
  while(pred[pred_i][pred_j].first!=s.first || pred[pred_i][pred_j].second!=s.second){
    test = pred[pred_i][pred_j];
    pred_i=test.first;
    pred_j=test.second;
  }
  // cout << "pred_i: " << pred_i << ", pred_j: " << pred_j << endl;
  return make_pair(pred_i, pred_j);
}

void Monster::moveToPlayer(){
  pair<int, int> dest = dijkstra(Elem::game->getCurrentBoard(), make_pair(Elem::pos_i, Elem::pos_j), make_pair(Elem::game->getPlayer()->getPosI(), Elem::game->getPlayer()->getPosJ()));
  int dest_i = dest.first;
  int dest_j = dest.second;

  if(dest_i==-1 && dest_j==-1){ /* no path */
    return;
  }
  /* Now that we have the next (position_i, position_j), we need to call Move::(),
  with the good direction */
  Direction d;

  if(dest_i == Elem::pos_i){ /* left or right */
    if(dest_j == Elem::pos_j-1){ /* left */
      d = LEFT;
    }
    else if(dest_j == Elem::pos_j+1){ /* right */
      d = RIGHT;
    }
    else{
      /* same position */
      return;
    }
  }
  else if(dest_i == Elem::pos_i-1){ /* top */
    if(dest_j == Elem::pos_j-1){ /* top left */
      d = TOPLEFT;
    }
    else if (dest_j == Elem::pos_j+1){ /* top right */
      d = TOPRIGHT;
    }
    else if (dest_j == Elem::pos_j){ /* top */
      d = TOP;
    }
  }

  else if(dest_i == Elem::pos_i+1){ /* bot */
    if(dest_j == Elem::pos_j-1){ /* bot left */
      d = BOTLEFT;
    }
    else if (dest_j == Elem::pos_j+1){ /* bot right */
      d = BOTRIGHT;
    }
    else if (dest_j == Elem::pos_j){ /* bot */
      d = BOT;
    }

  }
  Move::move(Elem::game, this, d, 1);
}

/* Methods */

void Monster::takeAction(){
  moveToPlayer();
}

void Monster::onCollision(Elem *e){
  if(e->getSymb()=="J"){
    cout << "Nom nom monster" << endl;
    applyDamage(e);
  }
}

bool Monster::blockable(){
    return true;
}
