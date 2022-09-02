// There's no syntax for using the increment or decrement operators to pass these values other than explicit invocation, as shown in the preceding code. A more straightforward way to implement this functionality is to overload the addition/assignment operator (+=).
//Source (See this) : https://docs.microsoft.com/en-us/cpp/cpp/increment-and-decrement-operator-overloading-cpp?view=msvc-160
#include <iostream>
using namespace std;
class trys{
  public:
  int n;
  int sumoffact();
  friend void operator >> (istream &in,  trys &c); // if u dont use friend u have to call this as void trys::operator>>(...){...}
  //A friend class can access private and protected members of other class in which it is declared as friend. It is sometimes useful to allow a particular class to access private members of other class. For example, a LinkedList class may be allowed to access private members of Node. 
};
int trys::sumoffact(){
    int ans=1,x=1;
      for(int i=2;i<=n;i++){
        x *= i;
        ans += x;
      }
      return ans;
}
void operator >> (istream &in,  trys &c){
    cout<<"Enter the number : ";
    in>>c.n;
}
void operator << (ostream &out,  trys &c){
    out<<"The sum of series of factorials till " <<c.n<<" is "<<c.sumoffact();
}
int main()
{
trys t;
cin>>t;
cout<<t;
  return 0;
}
/*
Another eg:
#include <iostream>
using namespace std;
 
class Complex
{
private:
    int real, imag;
public:
    Complex(int r = 0, int i =0)
    {  real = r;   imag = i; }
    friend ostream & operator << (ostream &out, const Complex &c);
    friend istream & operator >> (istream &in,  Complex &c);
};
 
ostream & operator << (ostream &out, const Complex &c)
{
    out << c.real;
    out << "+i" << c.imag << endl;
    return out;
}
 
istream & operator >> (istream &in,  Complex &c)
{
    cout << "Enter Real Part ";
    in >> c.real;
    cout << "Enter Imaginary Part ";
    in >> c.imag;
    return in;
}
 
int main()
{
   Complex c1;
   cin >> c1;
   cout << "The complex object is ";
   cout << c1;
   return 0;
}

Output: 

Enter Real Part 10
Enter Imaginary Part 20
The complex object is 10+i20
*/

// if u dont want to use friend then 
/*
#include <iostream>
using namespace std;
class complex{
  public:
  int real, imag;
  complex(int a=0,int b=0) {real=a;imag=b;}
  void print(){
      cout<<real<<(imag>=0?"+":"")<<imag<<"i\n";
  }
  complex operator-(complex ob){
      complex aa;
      aa.real = ob.real - real;
      aa.imag = ob.imag - imag;
      return aa;
  }
};
int main()
{
  int a,b;
  cin>>a>>b;
  class complex a1(a,b);
  cin>>a>>b;
  class complex a2(a,b);
  a1.print();
  a2.print();
  a2 = a2 - a1;
  a2.print();
  return 0;
}

Test Case 2
INPUT (STDIN)
2 0
1 2
EXPECTED OUTPUT
2+0i
1+2i
1-2i
*/
// above program but simpler
/*
#include <iostream>
using namespace std;
class complex{
  public:
  int real, imag;
  void print(){
      cout<<real<<(imag>=0?"+":"")<<imag<<"i\n";
  }
  complex operator-(complex ob){
      complex aa;
      aa.real = ob.real - real;
      aa.imag = ob.imag - imag;
      return aa;
  }
};
int main()
{
complex t,s;
cin>>t.real>>t.imag>>s.real>>s.imag;
t.print();
s.print();
t = s - t;
t.print();
  return 0;
}
*/
// ----------------------------------------------
/* // Here with help of constructor few line of code is saved in overloading + operator
#include <iostream>
using namespace std;
class complex {
    public:
        int real, imaginary;
        // complex() {
        //     real = imaginary = 0;
        // }
        complex(int real, int imaginary) {
            this->real = real;
            this->imaginary = imaginary;
        }
        void display() {
            cout<<real<<(imaginary<0 ? "-" : "+")<<imaginary<<"i"<<endl;
        }
        complex operator + (const complex &c2) {
            return complex(real + c2.real, imaginary + c2.imaginary); // so i can do this with help of constructor
        }
};
int main() {
    complex c1(2,3), c2(3,4);
    c1.display();
    c2.display();
    cout<<"After Adding : ";
    c1 = c1 + c2;
    c1.display();
    return 0;
}

*/