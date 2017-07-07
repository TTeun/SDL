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
    cout << "Falling, \t";
  else
    cout << "Grounded, \t";

  cout << has_jumped_twice << '\n';

  if (m_state == STATE::FALLING){
    if (Essential::collision()->level_collide_vert(static_cast<Box *>(this), m_vy)){
      m_vy = 0;
      m_state = STATE::GROUNDED;
      has_jumped_twice = false;
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

  if ((not has_jumped_twice) && m_jump_released && (m_state == STATE::FALLING) && (jump_timer + double_jump_delay < SDL_GetTicks())){
    m_vy = 2 * f * m_weight;
    has_jumped_twice = true;
  }

  if (m_state == STATE::GROUNDED){
    m_jump_released = false;
    m_vy = 2 * f * m_weight;
    has_jumped_twice = false;
    m_state = STATE::FALLING;
    jump_timer = SDL_GetTicks();
  }

}

void RigidBody::force_right(int f){
  m_vx += 122 * f * m_weight / Essential::fps();
  m_vx = m_vx > 1000  ?  1000 :
         m_vx < -1000 ? -1000 :
         m_vx;
}
