#ifndef __DROP_INFO__H
#define __DROP_INFO__H

#include <iostream>
// Holds position and velocity of rain drop
struct drop_info {
  drop_info(){
    x = Essential::camera_x() + (rand() % (Essential::screen_width() + Essential::screen_height()));
    y = Essential::camera_y() + (rand() % Essential::screen_height());
    vy = -( rand() % 40 + 700 );
    vx = rand() % 4 - 400;
  }
  void reset(){
    x = Essential::camera_x() - 100 + (rand() % (Essential::screen_width() + Essential::screen_height()) + 100);
    y = Essential::camera_y() + Essential::screen_height() + 50;
    vy = -( rand() % 40 + 700 );
    vx = rand() % 4 - 400;
  }
  int x;
  int y;
  int vy;
  int vx;
};

#endif
