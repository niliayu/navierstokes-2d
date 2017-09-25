INIT = ./finite_volume/include/init.h
# CODE = /finite_volume/sim/

initialization:	$(INIT)	
	g++ -Wall -c -std=gnu++14 $(INIT) -o init.o 

all: initialization clean

clean:
	rm *.o
