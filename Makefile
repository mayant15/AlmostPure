TGT=almostpure

all: $(TGT)

almostpure: main.o Dolphin.o Event.o
	g++ -o $(TGT) main.o Dolphin.o Event.o

main.o: main.cpp
	g++ -c main.cpp

Dolphin.o: Dolphin.cpp Dolphin.h
	g++ -c Dolphin.cpp

Event.o: Event.cpp Event.h
	g++ -c Event.cpp

clean:
	$(RM) *.o
