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


int main(){
  Window *w = new Window( Essential::screen_width(), Essential::screen_height() );
  GameLoop *game_loop = new GameLoop(w);
  // game_loop->start();


}
