# The following is the commands for mingw
# type in mingw32-make then bin/game.exe to run the game

CXX=g++
CXXFLAGS=-std=c++20
INCLUDES= -Iincludes/ -Iincludes/include/
LIB=-Lincludes/include/lib
LIBINC=-lsfml-graphics -lsfml-window -lsfml-system

exec: obj/game.o obj/create.o obj/map.o obj/pacman.o obj/ghost.o obj/collision.o link
tests: bin/tests

obj/game.o:
	$(CXX) $(CXXFLAGS) -c $(INCLUDES) ./src/main.cpp $^ -o $@
obj/create.o:
	$(CXX) $(CXXFLAGS) -c $(INCLUDES) ./src/createmap.cpp $^ -o $@
obj/map.o:
	$(CXX) $(CXXFLAGS) -c $(INCLUDES) ./src/mapcreation.cpp $^ -o $@
obj/pacman.o:
	$(CXX) $(CXXFLAGS) -c $(INCLUDES) ./src/pacman.cpp $^ -o $@
obj/ghost.o:
	$(CXX) $(CXXFLAGS) -c $(INCLUDES) ./src/ghost.cpp $^ -o $@
obj/collision.o:
	$(CXX) $(CXXFLAGS) -c $(INCLUDES) ./src/wallbehavior.cpp $^ -o $@
link:
	$(CXX) $(CXXFLAGS) obj/game.o obj/create.o obj/map.o obj/pacman.o obj/ghost.o obj/collision.o -o bin/game $(LIB) $(LIBINC)

obj/catch.o: tests/catch.cc
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $^ -o $@
bin/tests: ./tests/tests.cc obj/catch.o
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

clean:
	rm -rf bin/game.exe obj/*

.DEFAULT_GOAL := exec
.PHONY: clean exec tests
