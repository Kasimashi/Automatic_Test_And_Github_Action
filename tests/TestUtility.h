#ifndef TestStudent_h
#define TestStudent_h

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include <iostream>
#include <string>

#include "dog.hpp"


class UtilityTestCase : public CppUnit::TestFixture
{
CPPUNIT_TEST_SUITE(UtilityTestCase);
CPPUNIT_TEST(basicTests);
CPPUNIT_TEST_SUITE_END();

public:
    void setUp() {}
    void tearDown() {}

protected:

    // method to test the basics things
    void basicTests();

};


#endif
