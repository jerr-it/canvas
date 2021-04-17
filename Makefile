COMPILER = g++
FLAGS = -g

render: main.o artwork.o
	${COMPILER} -o $@ $^

artwork.o: Artwork/Artwork.c Artwork/Artwork.h Artwork/Color.h
	${COMPILER} ${FLAGS} -c -o $@ $<

main.o: main.cpp Artwork/Artwork.h
	${COMPILER} ${FLAGS} -c -o $@ $<

clean: 
	rm -f render artwork.o main.o