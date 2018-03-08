pushd ../src/
g++ -c InputManager.cpp -std=c++11 -ggdb `pkg-config --cflags --libs sdl2` -lpthread
#g++ -c Game.cpp -std=c++11 -ggdb `pkg-config --cflags --libs sdl2` -lpthread
#g++ -c WindowModule.cpp -std=c++11 -ggdb `pkg-config --cflags --libs sdl2` -lpthread
#g++ -c main.cpp -std=c++11 -ggdb `pkg-config --cflags --libs sdl2` -lpthread
#g++ Game.o main.o WindowModule.o InputManager.o -o ../build/mainexec -std=c++11 -ggdb `pkg-config --cflags --libs sdl2` -lpthread
rm *.o
popd
