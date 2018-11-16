pushd ../src/
g++ -c InputHandler.cpp -std=c++11 -ggdb `pkg-config --cflags --libs sdl2` -lpthread
g++ -c WindowModule.cpp -std=c++11 -ggdb `pkg-config --cflags --libs sdl2` -lpthread
g++ -c main.cpp -std=c++11 -ggdb `pkg-config --cflags --libs sdl2` -lpthread
g++ main.o WindowModule.o InputHandler.o -o ../build/mainexec -std=c++11 -ggdb `pkg-config --cflags --libs sdl2` -lpthread
rm *.o
popd
