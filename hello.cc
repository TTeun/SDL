#include <iostream>
#include "essential/essential.h"
#include "window/window.h"
#include "window/sprite/sprite.h"
#include "window/environment/rain/rain.h"
#include "physics/collision/collision.h"
#include "window/environment/level/level.h"
#include "window/player/player.h"
#include "window/animation/animation.h"
#include <SDL2/SDL.h>

int Essential::m_screen_width = 1000;
int Essential::m_screen_height = 800;
int Essential::m_level_width = 1000;
int Essential::m_level_height = 800;
int Essential::m_camera_x = 0;
int Essential::m_camera_y = 0;
int Essential::m_fps = 60;
Collision *Essential::m_collision;

using namespace std;

int main( int argc, char* args[] )
{
  Window *w = new Window( Essential::screen_width(), Essential::screen_height() );
  Level *level = new Level( w->screen_renderer() );
  Rain *rain = new Rain( w->screen_renderer() );
  Player *player = new Player( w->screen_renderer() );

  Collision *col = new Collision(level, player);
  Essential::set_collision(col);

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
                player->vx -= 30.0f;
                break;
              case SDLK_RIGHT:
                player->set_dir(Player::DIRECTION::RIGHT);
                player->vx += 30.0f;
                break;
              case SDLK_UP:
                if (player->m_state == Player::STATE::FALLING)
                  break;

                player->set_dir(Player::DIRECTION::STAT);
                player->vy = 40.0f;
                player->m_state = Player::STATE::FALLING;
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


      w->clear();
      player->update();
      rain->render_rain();
      level->render_level();
      player->render_player();
      w->render();


      SDL_GetWindowSize(w->window(), &width, &height);
      Essential::set_screen_width(width);
      Essential::set_screen_height(height);
      Essential::set_level_height(height);
      Essential::update_camera(player->x, player->y);
    }

  delete w;
  delete rain;
	return 0;
}
