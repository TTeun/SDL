#include "window.h"

using namespace std;

Window::Window(size_t width, size_t height)
  : m_width(width), m_height(height)
{
  init_window();
  m_screen_surface = SDL_GetWindowSurface( m_window );
  m_screen_renderer = SDL_CreateRenderer( m_window, -1, SDL_RENDERER_ACCELERATED );
  SDL_SetRenderDrawColor( m_screen_renderer, 0xFF, 0xFF, 0xFF, 0xFF );
}

Window::~Window(){
  SDL_DestroyWindow(m_window );
  SDL_Quit();
}

void Window::init_window(){
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
    cout << "SDL could not initialize! SDL_Error: " <<  SDL_GetError() << '\n';
    m_success = false;
  }
  else
  {
    m_window = SDL_CreateWindow( "Window!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_width, m_height, SDL_WINDOW_SHOWN );
    if( m_window == NULL ) {
      cout << "Window could not be created! SDL_Error: " <<  SDL_GetError() << '\n';
      m_success = false;
    }
  }
}

void Window::clear(){
  SDL_RenderClear( m_screen_renderer );
}

void Window::render(){
  SDL_RenderPresent( m_screen_renderer );
}

SDL_Surface * Window::screen_surface(){
  return m_screen_surface;
}

SDL_Renderer * Window::screen_renderer(){
  return m_screen_renderer;
}
