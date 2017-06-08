#include "level.h"
#include "../../../essential/essential.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

Level::Level(){}

Level::Level(SDL_Renderer *screen_renderer)
  : m_level_sprite(new Sprite("assets/environment/tile.png", screen_renderer))
{
  cout << "Level constructor\n";
  m_level_desc.clear();
  read_level();
}

void Level::read_level(){
  cout << "Reading level\n";
  ifstream level_file;
  level_file.open("window/environment/level/levels/level1");

  string line;
  if (level_file.is_open())
  {
    level_file >> m_level_height;
    level_file >> m_level_width;

    m_level_desc.resize(m_level_width * m_level_height);
    size_t index = m_level_width * m_level_height - 1;
    getline(level_file, line);
    while (getline(level_file, line))
    {
      assert(line.length() == m_level_width);
      for (size_t i = 0; i != m_level_width; ++i){
        m_level_desc[index] = line[i] == '.' ? 0 : 1 ;
        --index;
      }

    }

  } else {
    cout << "Cannot read level file!\n";
  }
}

void Level::render_level(){
  size_t h, w;
  for (size_t i = 0; i != m_level_desc.size(); ++i)
    if (m_level_desc[i] & 1){
      w = i % m_level_width;
      h = i / m_level_width + 1;
      m_level_sprite->blit(Essential::to_screen_x( 32 * w), Essential::to_screen_y(32 * h));
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
