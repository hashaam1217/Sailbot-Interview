CC = g++
CFLAGS = -Wall -I/../third-party/googletest/googletest/include
LDFLAGS = -L/../third-party/googletest/lib -lgtest 

all:
	$(CC) gtest_standard_calc.cpp $(CFLAGS) $(LDFLAGS) -o gtest_standard_calc.o

clean:
	rm -f *.o
