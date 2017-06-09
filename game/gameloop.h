#ifndef __GAMELOOP__H
#define __GAMELOOP__H

#include "essential/essential.h"
#include "window/window.h"
#include "window/sprite/sprite.h"
#include "window/environment/rain/rain.h"
#include "physics/collision/collision.h"
#include "window/environment/level/level.h"
#include "window/player/player.h"
#include "window/animation/animation.h"

#include <memory>
#include <SDL2/SDL.h>

class  GameLoop {
public:
  GameLoop( Window *w );
  ~GameLoop();

  void start();

private:
  Window *w;
  std::unique_ptr<Level> level;
  std::unique_ptr<Player> player;
  std::unique_ptr<Collision> col;
  std::unique_ptr<Rain> rain;



};


#endif
