#OBJS
OBJS = 09_the_viewport.cpp
#CC
CC = g++

#COMPILER_FLAGS
COMPILER_FLAGS = -w

#LINKER_FLAGS
LINKER_FLAGS = -lSDL2 -lSDL2_image

#OBJ_NAME
OBJ_NAME = 09_the_viewport -Wl,-rpath=/usr/local/lib

#Target
all	:	$(OBJS)
			$(CC)	$(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
