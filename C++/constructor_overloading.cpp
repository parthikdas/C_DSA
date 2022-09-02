/*
-> constructor are special functions. Difference between constructor and functions is name of constructor is same as
class name but in functions u can give any name.
Eg:
	if class name is lol then constructor name will be lol not anything else.
-> if u dont give return type of constructor then default is void but in function it will give error.
-> There are three types of constructors:
    1. Default - No arguments
    2. Parametized - before all data types like int float double 
    3. Copy - Class objects as arguments
-> Overloading constructor is same as function overloading, which function to choose is decided by the number of arguments.
*/
#include <iostream>
using namespace std;
class trying {
	public:
		int a;
		/*
		trying(int b=0) {
			a = b; // i could use another variable to assign but if u want the same variable name then use this keyword else a=a; will be error
		}
		*/
		trying(int a=0) { // return type is not specified so void by default
			this->a = a;
		}
		void display() {
			cout<<a<<endl;
		}
		/*
		// Default constructor:
		trying() {
			a = 0;
		}
		// Parametized constructor:
		trying(int a=0) {
			this->a = a;
		}
		// Copy constructor:
		trying(trying obj) {
			a = obj.a;
		}
		*/
};
int main() {
	trying a(5), b;
	a.display(); // 5
	b.display(); // 0
	// So u can make objects by: trying b; b.a = 5; or trying b(5)
}

/*
    // Code with all types of constructor
	#include <iostream>
	using namespace std;
	class cons {
	  public:
	    int num;
	    cons() { // default 
	        num = 0;
	    }
	    cons(int n) { // Parametized
	        num = n;
	    }
	    cons(cons &c) { // Copy
	        num = c.num;
	    }
	    void display() {
	        cout<<num<<endl;
	    }
	};
	int main() {
	    cons a;
	    cons b(10);
	    cons c(b);
	    a.display();
	    b.display();
	    c.display();
	    return 0;
	}
*/