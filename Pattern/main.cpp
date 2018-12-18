#include "Header.h"

#include "Strategy.cpp"
#include "Observer.cpp"
#include "Decorator.cpp"
#include "Factory.cpp"
#include "AbstractFactory.cpp"
#include "Singleton.cpp"
#include "Command.cpp"
#include "Adapter.cpp"
#include "Facade.cpp"
#include "Template.cpp"
#include "Iterator.cpp"
#include "Composite.cpp"
#include "StateTest.cpp"
#include "Proxy.cpp"
#include "Bridge.cpp"
#include "Builder.cpp"
#include "Chain.cpp"
#include "Flyweight.cpp"
#include "Interpreter.cpp"
#include "Mediator.cpp"
#include "Memento.cpp"
#include "Prototype.cpp"
#include "Visitor.cpp"

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


