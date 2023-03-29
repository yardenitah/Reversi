cmake_minimum_required(VERSION 3.23)
project(Reversi_game)

set(CMAKE_CXX_STANDARD 14)

add_executable(Reversi_game main.cpp Board.cpp Board.h Test.cpp Test.h Player.cpp Player.h Mammal.cpp Mammal.h PlayerList.cpp PlayerList.h Dog.cpp Dog.h Cat.cpp Cat.h Dolphin.cpp Dolphin.h Fish.cpp Fish.h League.cpp League.h Shark.cpp Shark.h Barracuda.cpp Barracuda.h Bug.cpp Bug.h Ant.cpp Ant.h Grasshopper.cpp Grasshopper.h Wasp.cpp Wasp.h)
