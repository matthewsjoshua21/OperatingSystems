###################################
# Lauren Robbins & Joshua Matthews 
# CS433 -Operating Systems
# Programming Assignment 2:
# Linux Shell and History 
# October 8, 2019
# 
###################################
CC = g++			# use g++ for compiling c++ code or gcc for c code
CFLAGS = -O2 -Wall -std=c++11		# compilation flags: -g for debugging. Change to -O2 or -O3 for optimized code.
LIB = -lm			# linked libraries	
LDFLAGS = -L.			# link flags
PROG = prog2 			# target executable (output)
SRCS = main.cpp                 # .c or .cpp source files.
OBJ = $(SRCS:.cpp=.o) 	# object files for the target. Add more to this and next lines if there are more than one source files.

all : $(PROG) depend

$(PROG): $(OBJ) 
	$(CC) -o $(PROG) $(OBJ) $(LDFLAGS) $(LIB)

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
