#include "collision.h"

Collision::Collision(Level *level)
  : m_level(level)
{}

bool Collision::level_collide(int x, int y){
  return m_level->does_hit(x, y);
}
