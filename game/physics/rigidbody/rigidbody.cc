#include "rigidbody.h"
#include "../../essential/essential.h"
#include <iostream>

using namespace std;

RigidBody::RigidBody(int x, int y, int w, int h, int weight, int vx, int vy)
  : Box(Box(x, y, w, h))
{
  m_state = STATE::FALLING;
  m_weight = weight;
  m_vx = vx;
  m_vy = vy;
}

void RigidBody::update()
{
  if (m_state == STATE::FALLING)
    cout << "Falling\n";
  else
    cout << "Grounded\n";

  if (m_state == STATE::FALLING){
    if (Essential::collision()->level_collide_vert(static_cast<Box *>(this), m_vy)){
      m_vy = 0;
      m_state = STATE::GROUNDED;
    }
    else {
      m_y += m_vy / Essential::fps();
      m_vy -= g * m_weight / Essential::fps();

      if (m_vy < (-31 * Essential::fps()))
        m_vy = -31 * Essential::fps();
    }
  }

  m_x += m_vx / Essential::fps();
  m_vx *= 0.7; // Something log

  if (m_state == STATE::GROUNDED && Essential::collision()->no_ground_underneath(m_x, m_y, m_w, m_h) )
    m_state = STATE::FALLING;
}

void RigidBody::force_up(int f){
  // Moet nog een button release ding op

  if (m_state == STATE::FALLING && ((not can_double_jump) || has_jumped_twice))
    return;

  if (has_jumped)
    has_jumped_twice = true;
  else
    has_jumped = true;

  m_state = STATE::FALLING;
  // m_y += 5;
  m_vy = 2 * f * m_weight;
}

void RigidBody::force_right(int f){
  m_vx += 122 * f * m_weight / Essential::fps();
  m_vx = m_vx > 1000  ?  1000 :
         m_vx < -1000 ? -1000 :
         m_vx;
}
