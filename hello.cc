#include <iostream>
#include "window/window.h"
#include "window/sprite/sprite.h"

using namespace std;

int main( int argc, char* args[] )
{
  Sprite *s = new Sprite("window/hello_world.bmp");
  if (not s->is_success())
    cout << "Erorr\n";

  Window *w = new Window(1000, 800);
  if (w->is_success())
    while (1){
      w->clear();
      s->blit(w->screenSurface(), NULL);
      w->render();
    }


	return 0;
}
