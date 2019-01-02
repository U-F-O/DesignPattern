#include "Header.h"

#include "Strategy.h"
#include "Observer.h"
#include "Decorator.h"
#include "Factory.h"
#include "AbstractFactory.h"
#include "Singleton.h"
#include "Command.h"
#include "Adapter.h"
#include "Facade.h"
#include "Template.h"
#include "Iterator.h"
#include "Composite.h"
#include "StateTest.h"
#include "Proxy.h"
#include "Bridge.h"
#include "Builder.h"
#include "Chain.h"
#include "Flyweight.h"
#include "Interpreter.h"
#include "Mediator.h"
#include "Memento.h"
#include "Prototype.h"
#include "Visitor.h"

Singleton* Singleton::uniqueInstance = NULL;

int main()
{
    
     StrategyTest::test();
     ObserverTest::test();
     DecoratorTest::test();
     FactoryTest::test();
     AbstractFactoryTest::test();
     SingletonTest::test();
     CommandTest::test();
     AdapterTest::test();
     FacadeTest::test();
     TemplateTest::test();
     IteratorTest::test();
     CompositeTest::test();
     StateTest::test();
     ProxyTest::test();
     BridgeTest::test();
     BuilderTest::test();
     ChainTest::test();
     Flyweight::test();
     InterpretTest::test();
     MediatorTest::test();
     MementoTest::test();
     PrototypeTest::test();
     VisitorTest::test();
    
    return 0;
}


