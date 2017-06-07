#ifndef __DROP_INFO__H
#define __DROP_INFO__H


// Holds position and velocity of rain drop
struct drop_info {
  drop_info(){
    x = rand() % (Essential::width() + Essential::height());
    y = rand() % Essential::height() + 5;
    vy = rand() % 40 + 400;
    vx = rand() % 4 - 400;
  }
  void reset(){
    x = rand() % (Essential::width() + Essential::height());
    y = 0;
    vy = rand() % 4 + 400;
    vx = rand() % 4 - 400;
  }
  float x;
  float y;
  float vy;
  float vx;
};

#endif
