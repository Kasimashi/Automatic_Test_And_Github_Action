#ifndef TestStudent_h
#define TestStudent_h

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include <iostream>
#include <string>

#include "dog.hpp"


class DogTestCase : public CppUnit::TestFixture
{
CPPUNIT_TEST_SUITE(DogTestCase);
CPPUNIT_TEST(testConstructor);
CPPUNIT_TEST(testAssignAndRetrieveGrades);
CPPUNIT_TEST_SUITE_END();

public:
    void setUp() {}
    void tearDown() {}

protected:

    // method to test the constructor
    void testConstructor();

    // method to test the Energy of the dog
    void testEnergy();

};


#endif
