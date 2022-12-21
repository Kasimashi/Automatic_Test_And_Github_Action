#include "Dog.hpp"

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/TextOutputter.h>


// Register test fixture
CPPUNIT_TEST_SUITE_REGISTRATION(DogTestCase);

// method to test the constructor
void DogTestCase::testConstructor()
{
    // create a student object
    Dog MyDog("Wuzu");

    // check that the object is constructed correctly
    std::string dog_name = MyDog.getDogName();
    CPPUNIT_ASSERT(dog_name == "Wuzu");
}


// method to test the assigning and retrieval of grades
void DogTestCase::testEnergy()
{
    // create a dog
    Dog MyDog("Wuzu");

    // Check the dog energy at startup
    CPPUNIT_ASSERT_EQUAL(MAX_ENERGY / 2, MyDog.getEnergy();

    // Set it sleep 5 min
    MyDog.sleep(5);

    // Check the dog energy after sleep
    CPPUNIT_ASSERT_EQUAL(MAX_ENERGY, MyDog.getEnergy();

    // Let my Dog bark two time
    MyDog.bark();
    MyDog.bark();

    // Check the dog energy after 2 barks
    CPPUNIT_ASSERT_EQUAL(MAX_ENERGY - 2, MyDog.getEnergy();
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
