OBJS = main.cc \
			game/gameloop.cc \
			game/window/window.cc \
			game/window/sprite/sprite.cc \
			game/window/environment/rain/rain.cc \
			game/window/player/player.cc \
			game/window/animation/animation.cc \
			game/window/environment/level/level.cc \
			game/physics/collision/collision.cc \
			game/physics/rigidbody/rigidbody.cc \
			game/physics/math.cc

CC = g++

COMPILER_FLAGS = -std=c++14 -Wall

LINKER_FLAGS = -lSDL2 -lSDL2_image

OBJ_NAME = hell

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean:
	rm $(OBJ_NAME)
