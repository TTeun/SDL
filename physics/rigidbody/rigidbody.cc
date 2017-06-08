#include "rigidbody.h"
#include "../../essential/essential.h"
#include <iostream>

using namespace std;

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
    int yy = m_y;
    if (Essential::collision()->level_collide_from_top(m_x, yy, m_w, m_h, m_vy / Essential::fps()))
    {
      m_state = STATE::GROUNDED;
      m_vy = 0;
      m_y = yy;
    }
    else
    {
      m_y += m_vy / Essential::fps();
      m_vy -= g * m_weight / Essential::fps();
      if (m_vy < (-31 * Essential::fps()))
        m_vy = -31 / Essential::fps();
    }
  }
  if ( Essential::collision()->no_ground_underneath(m_x, m_y, m_w, m_h) ){
    m_state = STATE::FALLING;
  }

  if (not Essential::collision()->level_collide(m_x + m_vx / Essential::fps(), m_y, m_w, m_h) )
    m_x += m_vx / Essential::fps();
  else
    m_vx = 0;

  // m_vx *= 0.7; // Something log
}

void RigidBody::force_up(int f){
  if (m_state == STATE::FALLING)
    return;

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
