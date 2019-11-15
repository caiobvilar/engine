pushd ../src/
g++ -c TextureManager.cpp -std=c++11 -ggdb `pkg-config --cflags --libs sdl2 SDL2_image` -lpthread
g++ -c Player.cpp -std=c++11 -ggdb `pkg-config --cflags --libs sdl2 SDL2_image` -lpthread
g++ -c Game.cpp -std=c++11 -ggdb `pkg-config --cflags --libs sdl2 SDL2_image` -lpthread
g++ -c main.cpp -std=c++11 -ggdb `pkg-config --cflags --libs sdl2 SDL2_image` -lpthread
g++ main.o Game.o Player.o TextureManager.o -o ../build/mainexec -std=c++11 -ggdb `pkg-config --cflags --libs sdl2 SDL2_image` -lpthread

rm *.o
popd
