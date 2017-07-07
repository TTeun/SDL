#ifndef __RIGIDBODY__H
#define __RIGIDBODY__H

#include "box.h"

class RigidBody : public Box{
public:
  RigidBody(int x, int y, int w, int h, int weight, int vx = 0, int vy = 0);

  void update();
  void force_up(int f);
  void force_right(int f);

  int vx();
  int vy();
  void jump_released();

private:
  int m_weight;
  int m_vx;
  int m_vy;

  bool has_jumped_twice;
  bool m_jump_released = false;
  bool can_double_jump = true;

  unsigned int double_jump_delay = 320;
  unsigned int jump_timer;

  static constexpr int g = 50;
  enum class STATE {
    GROUNDED,
    FALLING
  };
  STATE m_state = STATE::GROUNDED;
};

inline int RigidBody::vx(){
  return m_vx;
}

inline int RigidBody::vy(){
  return m_vy;
}

inline void RigidBody::jump_released(){
  m_jump_released = true;
}

#endif
