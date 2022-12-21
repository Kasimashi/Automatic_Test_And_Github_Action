#include <cppunit/config/SourcePrefix.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <map>
#include <cppunit/TestSuite.h>
#include <assert.h>


CPPUNIT_NS_BEGIN

/*! \brief (INTERNAL) List of all TestFactoryRegistry.
 */
class TestFactoryRegistryList
{
private:
  typedef std::map<std::string, TestFactoryRegistry *, std::less<std::string> > Registries;
  Registries m_registries;

  enum State {
    doNotChange =0,
    notCreated,
    exist,
    destroyed
  };

  static State stateFlag( State newState = doNotChange )
  {
    static State state = notCreated;
    if ( newState != doNotChange )
      state = newState;
    return state;
  }

  static TestFactoryRegistryList *getInstance()
  {
    static TestFactoryRegistryList list;
    return &list;
  }

  TestFactoryRegistry *getInternalRegistry( const std::string &name )
  {
    Registries::const_iterator foundIt = m_registries.find( name );
    if ( foundIt == m_registries.end() )
    {
      TestFactoryRegistry *factory = new TestFactoryRegistry( name );
      m_registries.insert( std::pair<const std::string, TestFactoryRegistry*>( name, factory ) );
      return factory;
    }
    return (*foundIt).second;
  }

public:
  TestFactoryRegistryList()
    : m_registries()
  {
    stateFlag( exist );
  }

  ~TestFactoryRegistryList()
  {
    for ( Registries::iterator it = m_registries.begin(); it != m_registries.end(); ++it )
      delete (*it).second;

    stateFlag( destroyed );
  }

  static TestFactoryRegistry *getRegistry( const std::string &name )
  {
    // If the following assertion failed, then TestFactoryRegistry::getRegistry() 
    // was called during static variable destruction without checking the registry 
    // validity beforehand using TestFactoryRegistry::isValid() beforehand.
    assert( isValid() );
    if ( !isValid() )         // release mode
      return nullptr;            // => force CRASH

    return getInstance()->getInternalRegistry( name );
  }

  static bool isValid()
  {
    return stateFlag() != destroyed;
  }
};



TestFactoryRegistry::TestFactoryRegistry( std::string name ) :
    m_factories(),
    m_name( name )
{
}


TestFactoryRegistry::~TestFactoryRegistry()
{
}


TestFactoryRegistry &
TestFactoryRegistry::getRegistry( const std::string &name )
{
  return *TestFactoryRegistryList::getRegistry( name );
}


void 
TestFactoryRegistry::registerFactory( const std::string &,
                                      TestFactory *factory )
{
  registerFactory( factory );
}


void 
TestFactoryRegistry::registerFactory( TestFactory *factory )
{
  m_factories.insert( factory );
}


void 
TestFactoryRegistry::unregisterFactory( TestFactory *factory )
{
  m_factories.erase( factory );
}


void 
TestFactoryRegistry::addRegistry( const std::string &name )
{
  registerFactory( &getRegistry( name ) );
}


Test *
TestFactoryRegistry::makeTest()
{
  TestSuite *suite = new TestSuite( m_name );
  addTestToSuite( suite );
  return suite;
}


void 
TestFactoryRegistry::addTestToSuite( TestSuite *suite )
{
  std::multimap<std::string, Test *> sorted;
  for ( Factories::iterator it = m_factories.begin(); 
        it != m_factories.end(); 
        ++it )
  {
    TestFactory *factory = *it;
    Test *test = factory->makeTest();
    sorted.insert({test->getName(), test});
  }
  // In the unlikely case of multiple Tests with identical names, those will
  // still be added in random order:
  for (auto const &i: sorted)
  {
    suite->addTest( i.second );
  }
}


bool 
TestFactoryRegistry::isValid()
{
  return TestFactoryRegistryList::isValid();
}


CPPUNIT_NS_END
