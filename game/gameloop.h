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
#include <SDL2/SDL.h>

class  GameLoop {
public:
  GameLoop( Window *w );
  ~GameLoop();

  void start();

private:
  Window *w;

};


#endif
