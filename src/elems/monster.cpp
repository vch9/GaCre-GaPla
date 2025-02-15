#include "monster.hpp"

/* Constructors */
Monster::Monster(Game* g, int i, int j): Elem("s", g, i, j), Move(), Health(50){

}

void Monster::moveToPlayer(){
  pair<int, int> dest = Dijkstra::dijkstra(Elem::game->getCurrentBoard(), make_pair(Elem::pos_i, Elem::pos_j), make_pair(Elem::game->getPlayer()->getPosI(), Elem::game->getPlayer()->getPosJ()));
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
  int prob = rand()%100;
  if(prob<66){ /* 2/3 to move */
    moveToPlayer();
  }
}

void Monster::onCollision(Elem *e){
  if(e->getSymb()=="J"){
    View::print("Nom nom monster\n");
    ((Player*)e)->reduceHealth(100);
  }
}

bool Monster::blockable(){
    return true;
}

bool Monster::reduceHealth(int dmg){
  bool dead = Health::reduceHealth(dmg);
  if(dead){
    Elem::switchActive();
    Elem::game->getCurrentBoard()->getCell(Elem::pos_i, Elem::pos_j)->setElem(nullptr);
  }
  return dead;
}
