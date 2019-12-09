#include "dijkstra.hpp"

#define INF INT_MAX

pair<int, int> Dijkstra::dijkstra(Board* b, pair<int, int> s, pair<int, int> dest){
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
        if(e!=nullptr && (e->blockable() && e->getSymb()!="J")){
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

  if(pred_i==s.first && pred_j == s.second){ /* next hop is the destination */
    return make_pair(dest.first, dest.second);
  }

  while(pred[pred_i][pred_j].first!=s.first || pred[pred_i][pred_j].second!=s.second){
    test = pred[pred_i][pred_j];
    pred_i=test.first;
    pred_j=test.second;
  }
  cout << endl;
  return make_pair(pred_i, pred_j);
}
