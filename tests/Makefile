CXX = g++
CXXFLAGS = -Wall
INCLUDE = 	-I/usr/include \
			-I../src
LDFLAGS = -L/usr/lib
LIBS = -lcppunit

OBJS = \
	TestDog.o \

TESTOBJS = \
	TestDog.o \


all: tester

tester: $(OBJS) $(TESTOBJS)
	$(CXX) $(LDFLAGS) $^ $(LIBS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS) $(TESTOBJS) tester

.PHONY: clean
