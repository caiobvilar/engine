#OBJ_NAME
OBJ_NAME = 25_capping_frame_rate

#OBJS
OBJS = $(OBJ_NAME).cpp

#CC
CC = g++

#COMPILER_FLAGS
COMPILER_FLAGS = -w

#LINKER_FLAGS
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer


#Target
all	:	$(OBJS)
			$(CC)	$(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
