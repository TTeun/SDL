#ifndef __COLLISION__H
#define __COLLISION__H

#include "../../window/player/player.h"
#include "../../window/environment/level/level.h"

class Collision {
public:
  Collision() = default;
  Collision(Level *level, Player *player);

  bool level_collide(int x, int y);
  bool player_collide(int x, int y);
  bool no_ground_underneath(int x, int y);

private:
  Level *m_level;
  Player *m_player;


};

bool inline Collision::level_collide(int x, int y){
  return m_level->does_hit(x, y);
}

bool inline Collision::no_ground_underneath(int x, int y){
  return not m_level->does_hit(x, y - 31);
}

bool inline Collision::player_collide(int x, int y){
  return m_player->does_hit(x, y);;
}


#endif
