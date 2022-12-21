#include "Utility.hpp"

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/TextOutputter.h>


// Register test fixture
CPPUNIT_TEST_SUITE_REGISTRATION(UtilityTestCase);


// method to test the assigning and retrieval of grades
void UtilityTestCase::basicTest()
{

    int x = 5;
    int y = 6;

    CPPUNIT_ASSERT_EQUAL(25, square(x));

    CPPUNIT_ASSERT_EQUAL(30, multiply(x, y));

    CPPUNIT_ASSERT_EQUAL(1337, MAGIC_NUMBER);

    CPPUNIT_ASSERT_EQUAL(1337*5, magic(x));

    CPPUNIT_ASSERT_EQUAL(120, battleOfTheFiveGods());
}

// the main method
int main(int argc, char *argv[])
{
    CppUnit::TestResultCollector result;

    CppUnit::TestResult controller;
    controller.addListener(&result);

    CppUnit::BriefTestProgressListener progress;
    controller.addListener(&progress);

    CppUnit::TestRunner runner;
    runner.addTest(CppUnit::TestFactoryRegistry::getRegistry().makeTest());
    runner.run(controller);

    CppUnit::TextOutputter outputter(&result, std::cerr);
    outputter.write();

    return result.wasSuccessful() ? 0 : 1;
}
