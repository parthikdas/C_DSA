// #include <iostream>
// using namespace std;
// class base{
//     public:
//         base(){
//             cout<<"Base\n";
//         }
// };
// class derived1: public base{
//     public:
//         derived1(){
//             cout<<"Derived1\n";
//         }
// };
// class derived2: public base{
//     public:
//         derived2(){
//             cout<<"Derived2\n";
//         }
// };
// class derived: public derived1, public derived2{
//     public:
//         derived(){
//             cout<<"Derived\n";
//         }
// };
// int main(){
//     derived obj;
//     /*
//      Ouput:
//      Base
//      Derived1
//      Base
//      Derived2
//      Derived
     
//      So everytime a copy is made. memory is wasted.
//      When is class is derived multi times then make it virtual
//      So make the derived class as virtual
//     */
//     return 0;
// }
// #include <iostream>
// using namespace std;
// class base{
//     public:
//         base(){
//             cout<<"Base\n";
//         }
// };
// class derived1:virtual public base{
//     public:
//         derived1(){
//             cout<<"Derived1\n";
//         }
// };
// class derived2:virtual public base{
//     public:
//         derived2(){
//             cout<<"Derived2\n";
//         }
// };
// class derived: public derived1, public derived2{
//     public:
//         derived(){
//             cout<<"Derived\n";
//         }
// };
// int main(){
//     derived obj;
//     /*
//      Ouput:
//      Base
//      Derived1
//      Derived2
//      Derived
//     */
//     return 0;
// }


