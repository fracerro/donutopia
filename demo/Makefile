all: compile 

compile:
	mkdir -p builds/shapes
	g++ sources/shapes.cpp -L../build -ldonutopia -lsfml-graphics -o builds/shapes/shapes

	mkdir -p builds/custom_shape
	g++ sources/custom_shape.cpp -L../build -ldonutopia -lsfml-graphics -o builds/custom_shape/custom_shape

	mkdir -p builds/video
	g++ sources/video.cpp -L../build -ldonutopia -lsfml-graphics -o builds/video/video

clean:
	rm -rf builds 
