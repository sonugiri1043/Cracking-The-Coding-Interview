/*
  An animal shelter, which holds only dogs and cats, operates on a strictly
  first in, first out basis. People must adopt either the "oldest" ( based on
  arrival time ) of all animals at the shelter, or they can select whether they
  would prefer a dog or a cat ( and will receive the oldest animal of that type).
  They cannot select which specific animal they would like. Create the data structures
  to maintain this system and implement operations such as enqueue, dequeueAny,
  dequeueDog, and dequeueCat. You may use the built-in Linked List data structure.
 */

#include <iostream>
#include <queue>

using namespace std;

class Animal {
private:
  int id;
  int order;
public:
  int getOrder() { return order; }
  void setOrder( int _order ) { order = _order; }
  void setId( int _id ) { id = _id; }
  int getId() {
    return id;
  }
};

class Dog : public Animal {
public:
  Dog() { setId( 1 ); }
};

class Cat : public Animal {  
public:
  Cat() { setId( 2 ); }
};

class AnimalQueue {
public:
  AnimalQueue() { timestamp = 0; }
  void enqueue( Animal *animal ) {
    timestamp++;
    animal->setOrder( timestamp );

    if( animal->getId() == 1 )
      dogQueue.push( ( Dog * ) animal );
    else
      catQueue.push( ( Cat * ) animal );
  }
  
  Animal * dequeueAny() {
    if( catQueue.empty() and dogQueue.empty() )
      return NULL;

    Animal *animal = NULL;      
    if( not catQueue.empty() and not dogQueue.empty() ) {
      if( catQueue.front()->getOrder() > dogQueue.front()->getOrder() ) {
	animal = catQueue.front();
	catQueue.pop();
      } else {
	animal = dogQueue.front();
	dogQueue.pop();
      }
    }
    if( catQueue.empty() ) {
      animal = dogQueue.front();
      dogQueue.pop();
    } else {
      animal = catQueue.front();
      catQueue.pop();
    }
    return animal;
  }

  Dog * dequeueDog() {
    Dog *dog = NULL;
    if( not dogQueue.empty() ) {
      dog = dogQueue.front();
      dogQueue.pop();
    }
    return dog;
  }

  Cat * dequeueCat() {
    Cat *cat = NULL;
    if( not catQueue.empty() ) {
      cat = catQueue.front();
      catQueue.pop();
    }
    return cat;
  }

private:
  int timestamp;
  queue<Dog *> dogQueue;
  queue<Cat *> catQueue;
};

int main() {
  AnimalQueue aq;
  aq.enqueue( new Dog() );
  aq.enqueue( new Cat() );
  aq.dequeueCat();
  aq.dequeueDog();

  aq.enqueue( new Dog() );
  aq.enqueue( new Cat() );
  aq.dequeueAny();
  aq.dequeueAny();
  return 0;
}
