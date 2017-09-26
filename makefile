INIT = ./finite_volume/include/init.h
SIM = ./finite_volume/solver/sim.cpp

initialization:	$(INIT)	
	g++ -Wall -c -std=gnu++14 $(INIT) -o init.o 

sim: $(SIM)
	g++ -Wall -std=gnu++14 $(SIM) -o sim.o 
	./sim.o

all: initialization sim clean

clean:
	rm *.o
