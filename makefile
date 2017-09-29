INIT = ./finite_volume/include/init.h
MOMENTUM_H = ./finite_volume/include/momentum.h 

MOMENTUM = ./finite_volume/solver/momentum.cpp 

SIM = ./finite_volume/solver/sim.cpp

FLAGS = -c -Wall -std=gnu++14 -lwinmm -I/finite_elements/include 

sim:	$(MOMENTUM) $(INIT) $(SIM) 
	g++ $(FLAGS) $(MOMENTUM) -o momentum.o 	
	g++ $(FLAGS) $(SIM) -o sim.o
	g++ momentum.o sim.o -o run
	./run

clean:
	rm *.o 

all: sim clean 

	
