all:	main.o 
	g++ main.o -o p3

main.o: main.cpp BST.h employee.h BST.cpp
	g++ -c main.cpp

clean: 
	rm -f *~ *# *.o
