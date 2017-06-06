#ifndef __WINDOW__H
#define __WINDOW__H

#include <SDL2/SDL.h>
#include <iostream>

class Window {
public:
 Window(size_t width, size_t height);
 ~Window();

 bool is_success();
 void clear();
 void render();

 SDL_Surface *screenSurface();


private:
  void init_window();

  bool m_success = true;
  size_t m_width;
  size_t m_height;

  SDL_Window* m_window = nullptr;
  SDL_Surface* m_screenSurface = nullptr;
};

bool inline Window::is_success(){
  return m_success;
}
#endif
