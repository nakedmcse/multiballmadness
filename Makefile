all: multiballmadness

multiballmadness: raylib.h types.h multiballmadness.c
	gcc -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL -O3 -o multiballmadness multiballmadness.c libraylib.a

clean:
	rm -f *.o
	rm -f multiballmadness