#include<iostream>
#include<string>

using namespace std;

class Animal {
  protected:
    string name;

  public:
    Animal(string s="Noname") { name = s;}   // Default value = "NoName"

    // Pure virtual method - much be overridden by any non-abstrac 
    //  derrived class
    virtual void speak() = 0;

    // Virtual method - can be overriden by the child class.  The type of
    //  the *OBJECT* being pointed to determines the method that gets called.
    virtual void move() { cout << "  ANIMAL " << name << ": I'm moving!" << endl;}

    // Non-virtual method - can be overriden by the child class.  The type
    //  of the *POINTER* being used determines the method that gets called.
    void eat() { cout << "  ANIMAL " << name << ": I'm hungry!" << endl;}
};

class Dog : public Animal {
  public:
    Dog(string s="Dog") : Animal(s) {}
    void speak() { cout << "  DOG "<< name << ": Woof!  Woof!" << endl;}
    void move() { cout << "  DOG " << name << ": Run around!" << endl;}
    void fetch() { cout << "  DOG " << name << ": Ball! Ball!" << endl;}
};

class Cat : public Animal {
  public:
    Cat(string s="Cat") : Animal(s) {}
    void speak() { cout << "  Cat "<< name << ": Meow." << endl;}
};

int main() {
  //  Animal a;  // Can't instantiate an Animal
  // Animal * aptr;
  Dog d("Pugsley");
  Dog * dptr;
  Dog & dogRef = d;
  Cat c("Mittens");
  Cat *cptr;
  Cat &catRef = c;


  Animal *danimal, *canimal;

  /* // Can't instantiate an Animal
  cout << endl << "Animal object: " << endl;
  a.speak();
  a.move();
  a.eat();

  cout << endl << "Animal pointer to an Animal object: " << endl;
  aptr = new Animal("Anotherone");
  aptr->speak();
  aptr->move();
  aptr->eat();
  */

  cout << endl << "Dog object: " << endl;
  d.speak();
  d.move();
  d.eat();
  d.fetch();

  cout << endl << "Dog pointer to an Dog object: " << endl;
  dptr = new Dog("Clifford");
  dptr->speak();
  dptr->move();
  dptr->eat();
  dptr->fetch();

  cout << endl << "Dog reference to an Dog object: " << endl;
  dogRef.speak();
  dogRef.move();
  dogRef.eat();
  dogRef.fetch();

  danimal = &d;
  cout << endl << "Animal pointer to an Dog object: " << endl;
  danimal->speak();
  danimal->move();
  danimal->eat();
  // danimal->fetch();

  cout << endl << "Cat object: " << endl;
  c.speak();
  c.move();
  c.eat();

  cout << endl << "Cat pointer to a Cat object: " << endl;
  cptr = new Cat("Garfield");
  cptr->speak();
  cptr->move();
  cptr->eat();

  cout << endl << "Cat reference to a Cat object: " << endl;
  catRef.speak();
  catRef.move();
  catRef.eat();

  cout << endl << "Animal pointer to a Cat object: " << endl;
  canimal = &c;
  canimal->speak();
  canimal->move();
  canimal->eat();

  cout << endl << "Animal reference to a cat object: " << endl; 
  Animal & animalRef = c;
  animalRef.speak();
  animalRef.move();
  animalRef.eat();

  return 0;
}
