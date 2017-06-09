#include <iostream>
#include "game/gameloop.h"

int Essential::m_screen_width = 1000;
int Essential::m_screen_height = 800;
int Essential::m_level_width = 1000;
int Essential::m_level_height = 800;
int Essential::m_camera_x = 0;
int Essential::m_camera_y = 0;
int Essential::m_fps = 60;

Collision *Essential::m_collision;

using namespace std;

int main(){
  unique_ptr<Window> w = make_unique<Window>( Essential::screen_width(), Essential::screen_height() );

  unique_ptr<GameLoop> game_loop = make_unique<GameLoop>(w.get());
  game_loop->start();

}
