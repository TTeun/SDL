#ifndef __PLAYER__H
#define __PLAYER__H

#include "../sprite/sprite.h"
#include "../../physics/rigidbody/rigidbody.h"

class Player {
public:
  Player(SDL_Renderer* screen_renderer);
  ~Player();
  void render_player();
  void update();


  enum class DIRECTION {
    STAT,
    LEFT,
    RIGHT
  };

  bool does_hit(int x, int y);
  int x();
  int y();
  void force_up(float f);
  void force_right(float f);

private:
  void set_dir();
  DIRECTION m_dir = DIRECTION::STAT;

  Sprite *m_sprite;
  SDL_Rect *src_rect;
  SDL_Rect *des_rect;
  RigidBody *m_rigidbody = nullptr;
};

inline void Player::set_dir(){
  m_dir = m_rigidbody->vx() > 0  ? DIRECTION::RIGHT :
          m_rigidbody->vx() == 0 ? DIRECTION::STAT  :
                    DIRECTION::LEFT  ;
}

inline int Player::x(){
  return m_rigidbody->m_x;
}

inline int Player::y(){
  return m_rigidbody->m_y;
}

inline void Player::force_up(float f) {
  m_rigidbody->force_up(f);
}

inline void Player::force_right(float f) {
  m_rigidbody->force_right(f);
}

#endif
