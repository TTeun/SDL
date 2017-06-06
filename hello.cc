#include <iostream>
#include "essential/essential.h"
#include "window/window.h"
#include "window/sprite/sprite.h"
#include "window/environment/rain/rain.h"
#include "window/player/player.h"
#include <SDL2/SDL.h>

int Essential::m_width = 1000;
int Essential::m_height = 800;
int Essential::m_fps = 60;

using namespace std;

int main( int argc, char* args[] )
{

  Window *w = new Window(Essential::width(), Essential::height());
  Rain *rain = new Rain( w->screen_renderer() );
  Player *player = new Player( w->screen_renderer() );

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
      Essential::set_width(width);
      Essential::set_height(height);

      w->clear();
      player->render_player();
      rain->render_rain();
      w->render();
    }

  delete w;
  delete rain;
	return 0;
}
