main.exe: main.o dbuff.o
	g++ main.o dbuff.o -o main.exe

main.o: main.cpp
	g++ -c main.cpp -o main.o

dbuff.o: dbuff.cpp
	g++ -c dbuff.cpp -o dbuff.o


.PHONY: clean

clean:
	rm *.exe *.o
