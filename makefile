# Compiler
CC = g++
# Compiler flags
CFLAGS = -Wall -std=c++14
# OpenGL libraries
LIBS = -lglut -lGLU -lGL -lglfw -lGLEW

# Source files
SRCS = p1.cpp

# Output executable name
OUT = p1

all: $(OUT)

$(OUT): $(SRCS) ./*.cpp ./vendor/stb_image/stb_image.cpp ./vendor/imgui/*.cpp ./test/*.cpp
	$(CC) $(CFLAGS) -o $(OUT) ./*.cpp ./vendor/stb_image/stb_image.cpp ./vendor/imgui/*.cpp ./test/*.cpp $(LIBS)

clean:
	rm -f $(OUT)
