all: multiballmadness

multiballmadness: raylib.h types.h multiballmadness.c
	gcc -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL -O3 -o multiballmadness multiballmadness.c libraylib.a

raylib:
	git clone https://github.com/raysan5/raylib.git
	make -C raylib/src
	cp raylib/src/libraylib.a libraylib.a
	rm -rf raylib

clean:
	rm -f *.o
	rm -f multiballmadness