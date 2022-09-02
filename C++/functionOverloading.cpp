#include <iostream>
using namespace std;
// cannot overload functions distinguished by return type alone, these 2 functions will throw error as compiler 
//will be confused which one to choose it chooses on basis of number of arguments
int area(int a){
    return a*a;
}
float area(int a){
    return a*a;
}
/*  correct ones are :
int area(int a){
    return a*a;
}
float area(int a, int b){
    return a*b;
}
int area(int a, float b){
    return a*b;
}
int area(float a, int b){
    return a*b;
}
int area(int a, int b, int c){
    return a*b*c;
}
*/
int main()
{
    cout<<area(2);
    cout<<area(2,4);
    cout<<area(2,2.5);
    cout<<area(2.5,4);
    return 0;
}
