#ifndef __RIGIDBODY__H
#define __RIGIDBODY__H

#include "box.h"

class RigidBody : public Box{
public:
  RigidBody(int x, int y, int w, int h, int weight, int vx = 0, int vy = 0);

  void update();
  void force_up(float f);
  void force_right(float f);


private:
  float m_weight;
  float m_vx;
  float m_vy;

  static constexpr float g = 90;
  enum class STATE {
    GROUNDED,
    FALLING
  };
  STATE m_state = STATE::FALLING;
};

#endif
