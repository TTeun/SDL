#include "player.h"
#include <iostream>
#include "../../essential/essential.h"

using namespace std;

Player::Player(SDL_Renderer* screen_renderer)
  : m_sprite(new Sprite("game/assets/player/player.png",screen_renderer)),
    src_rect(new SDL_Rect),
    des_rect(new SDL_Rect),
    m_rigidbody(new RigidBody(250, 550, 64, 64, 50))
{
  des_rect->x = 0;
  des_rect->y = 0;
  des_rect->w = 64;
  des_rect->h = 64;
}

Player::~Player(){
  cout << "Player desctructor\n";
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
  m_rigidbody->update();
  set_dir();
}

bool Player::does_hit(int _x, int _y){
  return m_rigidbody->does_collide_with_piont(_x, _y);
}
