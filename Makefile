bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp ListArray.h

bin/testNode: testNode.cpp node.h
	mkdir -p bin
	g++ -o bin/TestNode testNode.cpp node.h

bin/testListLinked: testListLinked.cpp ListLinked.h List.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp ListLinked.h 

Point2D.o: Point2D.h Point2D.cpp
	g++ -c Point2D.cpp

bin/testPoint2D: testPoint2D.cpp Point2D.o
	g++ -c testPoint2D.cpp
	mkdir -p bin
	g++ -o bin/testPoint2D testPoint2D.o Point2D.o

bin/testCircle: testCircle.cpp Circle.o Shape.o Point2D.o
	g++ -c testCircle.cpp 
	mkdir -p bin
	g++ -o bin/testCircle testCircle.o Circle.o Shape.o Point2D.o

testRectangle.o: testRectangle.cpp Rectangle.h Shape.h Point2D.h
	g++ -c testRectangle.cpp

bin/testRectangle: testRectangle.o Rectangle.o Shape.o Point2D.o
	mkdir -p bin
	g++ -o bin/testRectangle testRectangle.o Rectangle.o Shape.o Point2D.o

Rectangle.o: Rectangle.cpp Rectangle.h Shape.h Point2D.h
	g++ -c Rectangle.cpp

Square.o: Square.cpp Square.h Rectangle.h Shape.h Point2D.h
	g++ -c Square.cpp

testSquare.o: testSquare.cpp Square.h Rectangle.h Shape.H Point2D.h
	g++ -c testSquare.cpp

bin/testSquare: testSquare.o Square.o Rectangle.o Shape.o Point2D.o
	mkdir -p bin
	g++ -o bin/testSquare testSquare.o Square.o Rectangle.o Shape.o Point2D.o

bin/testDrawing: testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o
	mkdir -p bin
	g++ -o bin/testDrawing testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o
clean:
	rm -rf *.o *.gch bin

