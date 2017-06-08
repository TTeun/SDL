#include "collision.h"
#include <iostream>

using namespace std;

Collision::Collision(Level *level, Player *player)
  : m_level(level),
    m_player(player)
{}


bool Collision::level_collide_from_top(int x, int &y, int w, int h, int vy){
  if (vy >= 0)
    return false;

  if (m_level->does_hit(x, y) || m_level->does_hit(x + w, y) || m_level->does_hit(x + w / 2, y)){
    y /= 32;
    ++y;
    y *= 32;
    return true;
  }

  if ((y / 32) == ((y + vy) / 32))
    return false;

  y -= h;

  int y_start = y;
  while (y >= y_start + vy)
  {
    if (m_level->does_hit(x, y) || m_level->does_hit(x + w, y) || m_level->does_hit(x + w / 2, y)){
      y /= 32;
      ++y;
      y *= 32;
      return true;
    }
    y -= 32;
  }
  return false;
}
