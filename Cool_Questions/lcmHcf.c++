#include <iostream>
using namespace std;
// Assuming numbers are whole numbers
int lcm(int a, int b) {
    if(!a) return b;
    else if(!b) return a;
    int max = a>b?a:b;
    while(1) {
        if(!(max%a) && !(max%b)) return max;
        max++;
    }
}
int hcf(int a, int b) {
    if(!a || !b) return 0;
    int min = a>b?b:a;
    for(int i=1;i<=min;i++) {
        if(!(a%i) && !(b%i)) return i;
    }
    return 1;
}
int main() {
    int a, b;
    cin>>a>>b;
    cout<<"LCM of "<<a<<"and "<<b<<"is "<<lcm(a,b)<<endl;
    cout<<"HCF of "<<a<<"and "<<b<<"is "<<hcf(a,b)<<endl;
}