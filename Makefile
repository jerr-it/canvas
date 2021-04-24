CPP_COMPILER = g++
CPP_STD = c++17

C_COMPILER = gcc
C_STD = c17

FLAGS = -g -pedantic -Wall -Werror -Wextra -Wfloat-equal -Wshadow

render: main.o artwork.o
	${CPP_COMPILER} -o $@ $^

artwork.o: Artwork/Artwork.c Artwork/Artwork.h Artwork/Color.h
	${C_COMPILER} -std=${C_STD} ${FLAGS} -c -o $@ $<

main.o: main.cpp Artwork/Artwork.h
	${CPP_COMPILER} -std=${CPP_STD} ${FLAGS} -c -o $@ $<

clean: 
	rm -f render artwork.o main.o
