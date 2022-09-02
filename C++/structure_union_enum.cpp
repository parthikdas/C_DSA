#include<iostream>
using namespace std;

typedef struct employee
{
    /* data */
    int eId; //4
    char favChar; //1
    float salary; //4
} ep; // so total 9bytes will be used

union money
{
    /* data */
    int rice; //4
    char car; //1
    float pounds; //4
};//We can only use 1 variable at a time otherwise the compiler will give us a garbage value
//The compiler chooses the data type which has maximum memory for the allocation.


int main(){
    enum Meal{ breakfast, lunch, dinner};
    Meal m1 = lunch;
    cout<<(m1==2);
    // cout<<breakfast; // 0
    // cout<<lunch; // 1
    // cout<<dinner; // 2

// The main thing to note here is that:
// We can only use 1 variable at a time otherwise the compiler will give us a garbage value
// The compiler chooses the data type which has maximum memory for the allocation.
    // union money m1;
    // m1.rice = 34;
    // m1.car = 'c';
    // cout<<m1.car; // this will print 'c'
    // cout<<m1.rice; // now this will throw garbage value, as only 1 can be used


    // ep harry;
    // struct employee shubham;
    // struct employee rohanDas;
    // harry.eId = 1;
    // harry.favChar = 'c';
    // harry.salary = 120000000;
    // cout<<"The value is "<<harry.eId<<endl; 
    // cout<<"The value is "<<harry.favChar<<endl; 
    // cout<<"The value is "<<harry.salary<<endl; 
    return 0;
}
