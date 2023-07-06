all: shapes custom_shape video 

shapes:
	mkdir -p builds/shapes
	g++ sources/shapes.cpp -std=c++17 -L../build -ldonutopia -lsfml-graphics -o builds/shapes/shapes

custom_shape:
	mkdir -p builds/custom_shape
	g++ sources/custom_shape.cpp -std=c++17 -L../build -ldonutopia -lsfml-graphics -o builds/custom_shape/custom_shape

video:
	mkdir -p builds/video
	g++ sources/video.cpp -std=c++17 -L../build -ldonutopia -lsfml-graphics -o builds/video/video

clean:
	rm -rf builds 
