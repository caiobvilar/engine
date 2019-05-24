#OBJS
OBJS = 18_key_states.cpp
#CC
CC = g++

#COMPILER_FLAGS
COMPILER_FLAGS = -w

#LINKER_FLAGS
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

#OBJ_NAME
OBJ_NAME = 18_key_states -Wl,-rpath=/usr/local/lib


#Target
all	:	$(OBJS)
			$(CC)	$(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
