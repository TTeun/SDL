#ifndef __ESSENTIAL__H
#define __ESSENTIAL__H

#include "../physics/collision/collision.h"
#include "../physics/math.h"

class Essential{
public:

private:
  static int m_screen_width;
  static int m_screen_height;
  static int m_level_width;
  static int m_level_height;
  static int m_camera_x;
  static int m_camera_y;

  static int m_fps;
  static Collision* m_collision;


public:
  static inline int level_width(){
    return m_level_width;
  }
  static inline void set_level_width(int var){
    m_level_width = var;
  }
  static inline int level_height(){
    return m_level_height;
  }
  static inline void set_level_height(int var){
    m_level_height = var;
  }
  static inline int screen_width(){
    return m_screen_width;
  }
  static inline void set_screen_width(int var){
    m_screen_width = var;
  }
  static inline int screen_height(){
    return m_screen_height;
  }
  static inline void set_screen_height(int var){
    m_screen_height = var;
  }
  static inline int camera_x(){
    return m_camera_x;
  }
  static inline void set_camera_x(int var){
    m_camera_x = var;
  }
  static inline int camera_y(){
    return m_camera_y;
  }
  static inline void set_camera_y(int var){
    m_camera_y = var;
  }
  static inline int fps(){
    return m_fps;
  }
  static inline void set_fps(int var){
    m_fps = var;
  }
  static inline Collision *collision(){
    return m_collision;
  }
  static inline void set_collision(Collision *var){
    m_collision = var;
  }
  static inline int to_screen_y(int y){
    return screen_height() - y + camera_y();
  }
  static inline int to_screen_x(int x){
    return x - camera_x();
  }
  static inline void update_camera(int x, int y){
    m_camera_x = Math::max<int>(x - m_screen_width / 2, 0);
    m_camera_y = Math::max(y - m_screen_height / 2, 0);
  }

};

#endif
