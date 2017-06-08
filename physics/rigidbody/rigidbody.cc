#include "rigidbody.h"
#include "../../essential/essential.h"
#include <iostream>

RigidBody::RigidBody(int x, int y, int w, int h, int weight, int vx, int vy)
  : Box(Box(x, y, w, h))
{
  m_weight = weight;
  m_vx = vx;
  m_vy = vy;
}

void RigidBody::update(){

  if (m_state == STATE::FALLING)
  {
    if (Essential::collision()->level_collide(m_x, m_y + m_vy / Essential::fps(), m_w, m_h)){
      m_state = STATE::GROUNDED;

      m_vy = 0;
      m_y /= 16;
      m_y *= 16;
    } else {
      m_y += m_vy / Essential::fps();
      m_vy -= g * m_weight / Essential::fps();
    }
  }
  if ( Essential::collision()->no_ground_underneath(m_x, m_y, m_w, m_h) ){
    m_state = STATE::FALLING;
  }

  if (not Essential::collision()->level_collide(m_x + m_vx / Essential::fps(), m_y, m_w, m_h) )
    m_x += m_vx / Essential::fps();
  else
    m_vx = 0;

  m_vx *= (1.0f - 5.0f / (Essential::fps()));
}

void RigidBody::force_up(float f){
  if (m_state == STATE::FALLING)
    return;

  m_state = STATE::FALLING;
  // m_y += 5;
  m_vy = 2 * f * m_weight;
}

void RigidBody::force_right(float f){
  m_vx += 0.2 * f * m_weight;
  m_vx = m_vx > 950  ?  950 :
         m_vx < -950 ? -950 :
         m_vx;
}
