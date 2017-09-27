INIT = ./finite_volume/include/init.h
MOMENTUM_H = ./finite_volume/include/momentum.h 

MOMENTUM = ./finite_volume/solver/momentum.cpp 

SIM = ./finite_volume/solver/sim.cpp


sim: 
	g++ -Wall -c -std=gnu++14 $(INIT) -o init.o 
	g++ -Wall -std=gnu++14 $(SIM) -o sim.o 
	g++ -Wall -c -std=gnu++14 $(MOMENTUM_H) -o momentum_h.o 
	g++ -Wall -c -std=gnu++14 $(MOMENTUM) -o momentum.o 
	./sim.o

all: sim clean

clean:
	rm *.o
