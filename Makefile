# CC specifies which compiler we're using
CC = g++

# HEADERS_FOLDER specifies the folder the .hpp are located
HEADERS_FOLDER = ./includes

# SOURCE specifies all the .cpp files located in the src folder
SOURCE = $(wildcard ./src/*.cpp) $(wildcard ./*.cpp)

# LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image

build:
	$(CC) -std=c++14 -I$(HEADERS_FOLDER) $(SOURCE) $(LINKER_FLAGS) -o game.exe

run:
	./game.exe