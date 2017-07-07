#ifndef __LEVEL__H
#define __LEVEL__H

#include "../../sprite/sprite.h"
#include <vector>
#include <tuple>
#include "../../../physics/rigidbody/box.h"

class Level {
public:
  Level();
  Level(SDL_Renderer *screen_renderer);
  ~Level();

  void render_level();
  bool does_hit(int x, int y);
  bool does_hit(Box *box);
  size_t level_height();
  size_t level_width();

  int start_x();
  int start_y();

private:
  SDL_Rect m_src_rects[2];
  SDL_Rect m_des_rect;

  int m_start_x = 100;
  int m_start_y = 100;

  void read_level();
  size_t m_level_width;
  size_t m_level_height;
  Sprite *m_level_sprite = nullptr;
  std::vector<short unsigned int> m_level_desc;
};

size_t inline Level::level_height(){
  return m_level_height;
}

size_t inline Level::level_width(){
  return m_level_width;
}

int inline Level::start_x(){
  return m_start_x;
}

int inline Level::start_y(){
  return m_start_y;
}


#endif
