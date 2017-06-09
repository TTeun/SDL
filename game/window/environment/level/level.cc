#include "level.h"
#include "../../../essential/essential.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

Level::Level(){}

Level::Level(SDL_Renderer *screen_renderer)
  : m_level_sprite(new Sprite("game/assets/environment/grass.png", screen_renderer))
{
  cout << "Level constructor\n";
  m_level_desc.clear();
  m_src_rects[0].x = 0;
  m_src_rects[0].y = 0;
  m_src_rects[0].w = 32;
  m_src_rects[0].h = 32;

  m_src_rects[1].x = 32;
  m_src_rects[1].y = 0;
  m_src_rects[1].w = 32;
  m_src_rects[1].h = 32;

  m_des_rect.w = 32;
  m_des_rect.h = 32;

  read_level();
}

void Level::read_level(){
  cout << "Reading level\n";
  ifstream level_file;
  level_file.open("game/window/environment/level/levels/level2");

  string line;
  if (level_file.is_open())
  {
    level_file >> m_level_height;
    level_file >> m_level_width;

    m_level_desc.resize(m_level_width * m_level_height);
    size_t index = m_level_width * m_level_height - 1;
    getline(level_file, line);
    int height = m_level_height - 2;
    while (getline(level_file, line))
    {
      --height;
      assert(line.length() == m_level_width);
      for (size_t i = 0; i != m_level_width; ++i){
        m_level_desc[index] = line[i] == '.' ? 0 :
                              line[i] == 'S' ? 0 :
                              line[i] == 'g' ? 1 : 2 ;

        if (line[i] == 'S'){
          m_start_x = 32 * (m_level_width - i - 1);
          m_start_y = 32 * height;
        }
        --index;
      }
    }
  } else {
    cout << "Cannot read level file!\n";
  }
}

Level::~Level(){
  cout << "Level destructor\n";

}

void Level::render_level(){
  size_t h, w;
  for (size_t i = 0; i != m_level_desc.size(); ++i)
    if (m_level_desc[i]){
      w = i % m_level_width;
      h = i / m_level_width + 1;
      m_des_rect.x = Essential::to_screen_x( 32 * w);
      m_des_rect.y = Essential::to_screen_y(32 * h);
      if (m_level_desc[i] == 1)
        m_level_sprite->blit(&m_des_rect, &(m_src_rects[0]));
      else
        m_level_sprite->blit(&m_des_rect, &(m_src_rects[1]));
    }
}

bool Level::does_hit(int x, int y){
  y /= 32;
  x /= 32;
  if (y < 0 || x < 0)
    return true;

  if (y >= static_cast<int>(m_level_height) || x >= static_cast<int>(m_level_width))
    return false;

  return m_level_desc[x + m_level_width * y] != 0;

}
