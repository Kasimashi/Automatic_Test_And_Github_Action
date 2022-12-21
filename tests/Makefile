CXX = g++
CXXFLAGS = -Wall
INCLUDE = 	-I./cppunit/include \
			-I../src \
			-I./
LDFLAGS = -L/cppunit/lib
LIBS = -lcppunit

OBJS = \
	TestDog.o \
	TestUtilities.o \

TESTOBJS = \
	TestDog.o \
	TestUtilities.o \


all: tester

tester: $(OBJS) $(TESTOBJS)
	$(CXX) $(LDFLAGS) $^ $(LIBS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS) $(TESTOBJS) tester

.PHONY: clean
