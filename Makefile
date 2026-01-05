bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp ListArray.h

bin/testNode: testNode.cpp node.h
	mkdir -p bin
	g++ -o bin/TestNode testNode.cpp node.h

Point2D.o: Point2D.h Point2D.cpp
	g++ -c Point2D.cpp

bin/testCircle: testCircle.cpp Circle.o Shape.o Point2D.o
	g++ -c testCircle.cpp 
	mkdir -p bin
	g++ -o bin/testCircle testCircle.o Circle.o Shape.o Point2D.o

clean:
	rm -rf *.o *.gch bin

