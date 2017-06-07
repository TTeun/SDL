#ifndef __COLLISION__H
#define __COLLISION__H

#include "../../window/environment/level/level.h"

class Collision {
public:
  Collision() = default;
  Collision(Level *level);

  bool level_collide(int x, int y);

private:
  Level *m_level;


};


#endif
