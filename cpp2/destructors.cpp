#include<iostream>

using namespace std;

class MyClass {
  public:
    int * a;
  private:
    int b;
    string name;

  public:
    // Constructor
    MyClass(int x, string n="") {
      static int counter = 1;
      a = new int;
      *a = x;
      b = counter;
      counter ++;
      name = n;
      cout << "  Constructor " << name << " " << b << " : " 
             << a << " (" << *a << ")" << endl;
    }

    // Copy constructor
    MyClass(const MyClass& original) {
      a = new int;
      *a = *(original.a);
      b = original.b * 10;
      name = original.name + "COPY";
      cout << "    Copy ctor " << name << " " << b << " : " 
             << a << " (" << *a << ")" << endl;
    }

    void print() {
      cout << "       object " << name << " " << b << " : "
             << a << " (" << *a << ")" << endl;
    }

    ~MyClass() {
      cout << "   Destructor " << name << " " << b << " : "
             << a << " (" << *a << ")" << endl;
      delete a;
      a = nullptr;
    }
};

void func(MyClass cparam) {
 cout << " FUNC: ++++++++++++ start func ++++++++++++" << endl;

 cout << " FUNC: begin declare c3" << endl;
 MyClass c3(3, "c3");
 cout << " FUNC: end declare c3" << endl;

 cout << " FUNC: begin print cparam" << endl;
 cparam.print();
 cout << " FUNC: end print cparam" << endl;

 cout << " FUNC: begin print c3" << endl;
 c3.print();
 cout << " FUNC: end print c3" << endl;

 cout << " FUNC: +++++++++++++ end func _++++++++++++" << endl;
}

int main() {
  cout << "MAIN: start" << endl;

  cout << "MAIN: begin declare c1" << endl;
  MyClass c1(1, "c1");         // MyClass object allocated on stack
  cout << "MAIN: end declare c1" << endl;

  cout << "MAIN: begin declare c2" << endl;
  MyClass * c2;
  cout << "MAIN: end declare c2" << endl;
  cout << "MAIN: begin instantiate c2 with new" << endl;
  c2 = new MyClass(2, "c2");  // MyClass object allocated on heap
  cout << "MAIN: end instantiate c2 with new" << endl;

  cout << "MAIN: begin call to func(c1)" << endl;
  func(c1);
  cout << "MAIN: end call to func(c1)" << endl;

  cout << "MAIN: begin delete c2" << endl;
  delete c2;
  cout << "MAIN: end delete c2" << endl;
    
  cout << "MAIN: exiting" << endl;
  return 0;
}
