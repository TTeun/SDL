#include "window.h"

using namespace std;

Window::Window(size_t width, size_t height)
  : m_width(width), m_height(height)
{
  init_window();
  m_screenSurface = SDL_GetWindowSurface(m_window );
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
  SDL_FillRect( m_screenSurface, NULL, SDL_MapRGB( m_screenSurface->format, 0xFF, 0xFF, 0xFF ) );
}

void Window::render(){
  SDL_UpdateWindowSurface( m_window );
}

SDL_Surface * Window::screenSurface(){
  return m_screenSurface;
}
