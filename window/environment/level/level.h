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

private:
  Sprite *m_level_sprite = nullptr;
  std::vector<std::vector<std::pair<size_t, size_t>>> m_level_desc;
};




#endif
