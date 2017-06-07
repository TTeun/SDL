#include <iostream>
#include "essential/essential.h"
#include "window/window.h"
#include "window/sprite/sprite.h"
#include "window/environment/rain/rain.h"
#include "window/environment/level/level.h"
#include "window/player/player.h"
#include "window/animation/animation.h"
#include <SDL2/SDL.h>

int Essential::m_screen_width = 1000;
int Essential::m_screen_height = 800;
int Essential::m_camera_x = 0;
int Essential::m_camera_y = 0;
int Essential::m_fps = 60;

using namespace std;

int main( int argc, char* args[] )
{

  Window *w = new Window( Essential::screen_width(), Essential::screen_height() );
  Rain *rain = new Rain( w->screen_renderer() );
  Player *player = new Player( w->screen_renderer() );
  Level *level = new Level( w->screen_renderer() );

  int width, height;
  bool running = true;
  SDL_Event e;

  if (w->is_success())
    while (running)
    {

      while( SDL_PollEvent( &e ) != 0 )
      {
        switch( e.type ){
          /* Look for a keypress */
          case SDL_KEYDOWN:
            /* Check the SDLKey values and move change the coords */
            switch( e.key.keysym.sym ){
              case SDLK_LEFT:
                player->set_dir(Player::DIRECTION::LEFT);
                break;
              case SDLK_RIGHT:
                player->set_dir(Player::DIRECTION::RIGHT);
                break;
              default:
                break;
            }
            break;
          case SDL_QUIT:
            running = false;
            break;
          }
      }

      SDL_GetWindowSize(w->window(), &width, &height);
      Essential::set_screen_width(width);
      Essential::set_screen_height(height);

      w->clear();
      rain->render_rain();
      level->render_level();
      player->render_player();
      w->render();
    }

  delete w;
  delete rain;
	return 0;
}
