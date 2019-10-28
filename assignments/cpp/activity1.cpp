#include<iostream>

using namespace std;

class MyClass {
  private:  
    int num;
  public:
    MyClass(int x=0) {
      num = x;
    }
    int doubleNum();    // Returns num times 2
    void print();       // Prints num
};

// Define the methods here
// Define doubleNum:

// Define print:

int main() {
  MyClass obj1(1);
  MyClass obj5(5);

  // Uncomment the following lines to test your code
  /*
  cout << "Object 1:" << endl;
  cout << "   obj1.doubleNum(): " << obj1.doubleNum() << endl;
  cout << "   obj1.print(): ";
  obj1.print();
  cout << endl;
  cout << "Object 5:" << endl;
  cout << "   obj5.doubleNum(): " << obj5.doubleNum() << endl;
  cout << "   obj5.print(): ";
  obj5.print();
  cout << endl;
  */
  return 0;
}
