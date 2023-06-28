all: compile run

compile:
	g++ create_image.cpp -o create_image -lsfml-graphics
	make -C ../build
	../build/donutopia

run:
	./create_image

clean:
	rm create_image
