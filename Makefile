#OBJS specifies which files to compile as part of the project
OBJS = renderer.cpp vector.cpp photon.cpp plane.cpp sphere.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = renderer

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ_NAME)
