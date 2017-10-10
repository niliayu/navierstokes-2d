CPP_FILES := $(wildcard finite_volume/solver/*.cpp)
OBJ_FILES := $(addprefix obj/, $(notdir $(CPP_FILES:.cpp=.o)))
FLAGS := -c -Wall -std=gnu++14 -I/finite_elements/include
#BOOST_FLAGS := -I/cygdrive/c/Program\ Files/boost_1_65_1/ -L/cygdrive/c/Program\ Files/boost_1_65_1/bin.v2/libs  
#BOOST_LIBS = -lboost_system

sim:	$(OBJ_FILES)
	g++ -Wall -o $@ $^  
	./sim

obj/%.o:	finite_volume/solver/%.cpp
	g++ $(FLAGS) -c -o $@ $< 

