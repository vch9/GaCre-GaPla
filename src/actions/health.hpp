#ifndef HEALTH
#define HEALTH

class Health{
  private:
    int hp_max;
    int current_hp;

  public:
    /* Constructors */
    Health(int hp_max);

    /* Methods */

    /* Health reduces with dmg */
    void reduceHealth(int dmg);

    /* Add health with heal */
    void heal(int h);
};

#endif
