CXX = g++
CXXFLAGS =  -std=c++0x
CXXFLAGS +=   -Wall
CXXFLAGS +=   -pedantic-errors
CXXFLAGS +=   -g
#CXXFLAGS +=   -O3
LDFLAGS =  -lboost_date_time
OBJS = Animal.o Menu.o NewAnimal.o Penguin.o Tiger.o Turtle.o validateInput.o Zoo.o main.o
SRCS = Animal.cpp Menu.cpp NewAnimal.cpp Penguin.cpp Tiger.cpp Turtle.cpp validateInput.cpp Zoo.cpp main.cpp
HEADERS = Animal.hpp Menu.hpp NewAnimal.hpp Penguin.hpp Tiger.hpp Turtle.hpp validateInput.hpp Zoo.hpp 

#target: dependencies
#rule to build
#

Lab3: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o Project2

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c   $(@:.o=.cpp)

.PHONY: clean
clean:
	rm ${OBJS} Project2

zip:
	zip -D Project2_Cooke_Emmet.zip ${HEADERS} ${SRCS} makefile
