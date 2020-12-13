out: main.o functions.o
	clang++ main.o functions.o -o out

main.o: main.cpp
	clang++ -c main.cpp

functions.o: functions.cpp functions.hpp
	clang++ -c functions.cpp

clear:
	rm *.o out
