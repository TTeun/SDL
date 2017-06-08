#include "player.h"
#include <iostream>
#include "../../essential/essential.h"

using namespace std;

Player::Player(SDL_Renderer* screen_renderer)
  : m_sprite(new Sprite("assets/player/player.png",screen_renderer)),
    src_rect(new SDL_Rect),
    des_rect(new SDL_Rect),
    m_rigidbody(new RigidBody(50, 50, 64, 64, 100))
{
  des_rect->x = 0;
  des_rect->y = 0;
  des_rect->w = 64;
  des_rect->h = 64;
}

void Player::render_player(){
  if (m_dir == DIRECTION::STAT){
    src_rect->x = 0;
    src_rect->y = 0;
    src_rect->w = 32;
    src_rect->h = 32;
  }
  else if (m_dir == DIRECTION::RIGHT){
    src_rect->x = 32;
    src_rect->y = 0;
    src_rect->w = 32;
    src_rect->h = 32;
  }
  else if (m_dir == DIRECTION::LEFT){
    src_rect->x = 64;
    src_rect->y = 0;
    src_rect->w = 32;
    src_rect->h = 32;
  }
  des_rect->x = Essential::to_screen_x(m_rigidbody->m_x);
  des_rect->y = Essential::to_screen_y(m_rigidbody->m_y + m_rigidbody->m_h);
  m_sprite->blit(des_rect, src_rect);
}

void Player::update(){
  if (m_state == STATE::FALLING)
  {
    if (Essential::collision()->level_collide(m_rigidbody->m_x, m_rigidbody->m_y + vy / Essential::fps(), 64, 64)){
      m_state = STATE::GROUNDED;
      vy = 0;
      m_rigidbody->m_y /= 16;
      m_rigidbody->m_y *= 16;
    } else {
      m_rigidbody->m_y += vy / Essential::fps();
      vy -= 7.0f / Essential::fps();
    }
  }
  if (m_state == STATE::GROUNDED && (Essential::collision()->no_ground_underneath(m_rigidbody->m_x, m_rigidbody->m_y, 64, 64))){
    m_state = STATE::FALLING;
  }

  if (not Essential::collision()->level_collide(m_rigidbody->m_x + vx / Essential::fps(), m_rigidbody->m_y, 64, 64) )
    m_rigidbody->m_x += vx / Essential::fps();
  else
    vx = 0;

  set_dir();
}

bool Player::does_hit(int _x, int _y){
  return m_rigidbody->does_collide_with_piont(_x, _y);
}
