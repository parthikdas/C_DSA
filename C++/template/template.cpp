#include <iostream>
using namespace std;
// So every function have its own template
// struct nn{
//     int n;
// }
template<class T> // or u can use template<typename T>
T abs(T n) {
    return n<0?-n:n;
}
template<class V>
V maximum(V n, V m)
{
    return n>m?n:m;
}
int main(){
    int a;
    float b;
    cin>>a>>b;
    a = abs<int>(a); // can send float, char, any data type
    b = abs<int>(b);
    cout<<a<<" "<<b<<endl;
    // nn n1;
    // n1.n = -9;
    //cout<<(abs<struct nn>(n1)); // not working for user defined data types
    cout<<"Max : "<<(maximum<int>(a, b))<<endl;
    return 0;
}
