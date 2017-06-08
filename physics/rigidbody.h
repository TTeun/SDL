#ifndef __RIGIDBODY__H
#define __RIGIDBODY__H

#include "box.h"

class RigidBody : public Box{
public:
  RigidBody(int x, int y, int w, int h, int weight, int vx = 0, int vy = 0)
    : Box(Box(x, y, w, h))
  {
    m_weight = weight;
    m_vx = vx;
    m_vy = vy;
  }

  float m_weight;
  float m_vx;
  float m_vy;



};

#endif
