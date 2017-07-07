#include "collision.h"
#include <iostream>

using namespace std;

Collision::Collision(Level *level, Player *player)
  : m_level(level),
    m_player(player)
{}

bool Collision::level_collide_vert(Box *box, int vy){

  while (vy <= 0){
    if (m_level->does_hit(box)){
      box->m_y = static_cast<int>(box->m_y) / 32;
      box->m_y++;
      box->m_y *= 32;
      return true;
    }
    // box->m_y += min(32, -vy);
    vy += 32;
  }


  return false;

}

bool Collision::level_collide_from_side(int x, int y, int w, int h, int vx){
  return false;
}
