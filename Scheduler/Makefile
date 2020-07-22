###################################
# OS COURSE - CS 433 example
# 
###################################
CC = g++			# use g++ for compiling c++ code or gcc for c code
CFLAGS = -g -Wall -std=c++11		# compilation flags: -g for debugging. Change to -O or -O2 for optimized code.
LIB = -lm			# linked libraries	
LDFLAGS = -L.			# link flags
PROG = prog3			# target executable (output)
SRCS = main.cpp PCB.cpp random.cpp scheduler.cpp    # .c or .cpp source files.
OBJ = $(SRCS:.cpp=.o) 	# object files for the target. 

all : $(PROG) random_test depend

$(PROG): $(OBJ) 
	$(CC) -o $(PROG) $(OBJ) $(LDFLAGS) $(LIB)

random_test: random.o random_main.o
	$(CC) -o random_test random.o random_main.o $(LDFLAGS) $(LIB)

.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^ > ./.depend;

include .depend

# cleanup
clean:
	/bin/rm -f *.o $(PROG) .depend

# DO NOT DELETE
