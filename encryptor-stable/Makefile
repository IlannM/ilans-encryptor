out: main.o functions.o random.o
	clang++ main.o functions.o random.o -o out

main.o: main.cpp
	clang++ -c main.cpp

functions.o: functions.cpp functions.hpp
	clang++ -c functions.cpp

random.o: random.cpp random.hpp
	clang++ -c random.cpp

clear:
	rm *.o out
