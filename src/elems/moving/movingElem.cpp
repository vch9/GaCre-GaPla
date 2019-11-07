#include "movingElem.hpp"

MovingElem::MovingElem(string symb, Game* g, int i, int j, int off): Elem(symb, g, i, j){
    this->pos_i = i;
    this->pos_j = j;
    this->offset_movement = off;
}

void MovingElem::move(Directions d){
    int offset = MovingElem::offset_movement;
    int pos_i = MovingElem::pos_i;
    int pos_j = MovingElem::pos_j;
    switch(d){
        case TOPLEFT:
            Elem::game->elem_move(this, pos_i-offset, pos_j-offset);
            break;
        case TOP:
            Elem::game->elem_move(this, pos_i-offset, pos_j);
            break;
        case TOPRIGHT:
            Elem::game->elem_move(this, pos_i-offset, pos_j+offset);
            break;
        case BOTLEFT:
            Elem::game->elem_move(this, pos_i+offset, pos_j-offset);
            break;
        case BOT:
            Elem::game->elem_move(this, pos_i+offset, pos_j);
            break;
        case BOTRIGHT:
            Elem::game->elem_move(this, pos_i+offset, pos_j+offset);
            break;
        case MIDLEFT:
            Elem::game->elem_move(this, pos_i, pos_j-offset);
            break;
        case MID:
            break;
        case MIDRIGHT:
            Elem::game->elem_move(this, pos_i, pos_j+offset);
            break;

        default:
            break;
    }
}