#ifndef __LEVEL__H
#define __LEVEL__H

#include "../../sprite/sprite.h"
#include <vector>
#include <tuple>

class Level {
public:
  Level();
  Level(SDL_Renderer *screen_renderer);

  void render_level();
  bool does_hit(int x, int y);
  size_t level_height();
  size_t level_width();
private:
  SDL_Rect m_src_rects[2];
  SDL_Rect m_des_rect;

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


#endif
