#include "level.h"
#include "../../../essential/essential.h"
#include <iostream>

using namespace std;

Level::Level(){}

Level::Level(SDL_Renderer *screen_renderer)
  : m_level_sprite(new Sprite("assets/environment/tile.png", screen_renderer))
{
  m_level_desc.clear();
  m_level_desc.push_back(vector<pair<size_t, size_t> >(1,pair<size_t, size_t>(0UL,100UL)));
  for (size_t i = 0; i < 5; ++i)
    m_level_desc.push_back(vector<pair<size_t, size_t> >());


  m_level_desc.push_back(vector<pair<size_t, size_t> >(1,pair<size_t, size_t>(0UL,1UL)));

  for (size_t i = 0; i < 20; ++i)
    m_level_desc.push_back(vector<pair<size_t, size_t> >());


}

void Level::render_level(){
  size_t h;
  size_t y_offset = Essential::screen_height() + Essential::camera_y();
  for (auto it = m_level_desc.begin(); it != m_level_desc.end(); ++it)
  {
    h = y_offset - 32 * (it - m_level_desc.begin() + 1);
    for (auto & col : *it )
    {
      // if col.first > RHS continue
      for (size_t cc = col.first; cc != col.first + col.second; ++cc)
        m_level_sprite->blit(32 * cc, h);

    }

  }
}
