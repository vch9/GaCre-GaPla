#ifndef ELEM
#define ELEM

#include <iostream>
using namespace std;

class Game;

class Elem{
  protected:
    string symb;
    Game* game;
    int pos_i;
    int pos_j;

    /* Constructors */
    Elem(const string symb, Game*, int pos_i, int pos_j);

  public:
    /* Destructors */
    virtual ~Elem();

    /* Getters */
    int getPosI();
    int getPosJ();
    string getSymb();

    /* Setters */
    void setPosI(int pos_i);
    void setPosJ(int pos_j);

    friend ostream& operator<<(ostream& , const Elem&);

    /* Methods */

    /* Each elem pick it's action */
    virtual void takeAction();

    /* When other elem collides on _this, it can apply modifications or actions */
    virtual void onCollision(Elem*);

    /* Indicate if we can move over _this */
    virtual bool blockable();

    /* Return true if the elem is active */
    virtual bool isActive();

    /* Return a description of the elem */
    virtual string to_string();
};

#endif
