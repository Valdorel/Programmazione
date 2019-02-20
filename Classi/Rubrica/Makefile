
#MODE = -DNDEBUG #per compilare in modalita' release

MODE =  # per compilare in modalita' debug

main.exe: main.o rubrica.o voce.o
	g++ $(MODE) main.o rubrica.o voce.o -o main.exe

main.o: main.cpp voce.h rubrica.h
	g++ $(MODE) -c main.cpp -o main.o

voce.o: voce.cpp voce.h
	g++ $(MODE) -c voce.cpp -o voce.o

rubrica.o: rubrica.cpp rubrica.h voce.h
	g++ $(MODE) -c rubrica.cpp -o rubrica.o

.PHONY: clean

clean:
	rm *.exe *.o
