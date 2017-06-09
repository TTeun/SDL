#ifndef __COLLISION__H
#define __COLLISION__H

#include "../../window/player/player.h"
#include "../../window/environment/level/level.h"

class Collision {
public:
  Collision() = default;
  Collision(Level *level, Player *player);

  bool level_collide(int x, int y);
  bool level_collide(int x, int y, int w, int h);
  bool player_collide(int x, int y);
  bool no_ground_underneath(int x, int y);
  bool no_ground_underneath(int x, int y, int w, int h);

  bool level_collide_from_top(int x, int &y, int w, int h, int vy);

private:
  Level *m_level;
  Player *m_player;
};

bool inline Collision::level_collide(int x, int y){
  return m_level->does_hit(x, y);
}

bool inline Collision::level_collide(int x, int y, int w, int h){
  return (m_level->does_hit(x, y) || m_level->does_hit(x, y + h) || m_level->does_hit(x + w, y) || m_level->does_hit(x + w, y + h));
}

bool inline Collision::no_ground_underneath(int x, int y){
  return not m_level->does_hit(x, y - 5);
}

bool inline Collision::no_ground_underneath(int x, int y, int w, int h){
  return not level_collide(x, y - 5, w, h);
}

bool inline Collision::player_collide(int x, int y){
  return m_player->does_hit(x, y);;
}

#endif
