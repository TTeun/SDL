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

private:
  void read_level();
  size_t m_level_width;
  size_t m_level_height;
  Sprite *m_level_sprite = nullptr;
  std::vector<short unsigned int> m_level_desc;
};




#endif
