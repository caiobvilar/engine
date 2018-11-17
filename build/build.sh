pushd ../src/
g++ -c Game.cpp -std=c++11 -ggdb `pkg-config --cflags --libs sdl2` -lpthread
g++ -c main.cpp -std=c++11 -ggdb `pkg-config --cflags --libs sdl2` -lpthread
g++ main.o Game.o -o ../build/mainexec -std=c++11 -ggdb `pkg-config --cflags --libs sdl2` -lpthread
rm *.o
popd
