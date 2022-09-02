#include<iostream>
using namespace std;
// by this u can use mutli line define
#define ss cout<<"bkhskbsk" \
        cout<<"ssjbsjkb"

inline int product(int a, int b){
    return a*b;
}
int sum(int a, int b){
    static int c=0;
    c++;//c+=1;
    return a+b+c;
}
float moneyReceived(int currentMoney, float factor=1.04){// default arg should be at last not like (float factor=1.04,int currentMoney)
    return currentMoney * factor;
}
// int strlen(const char *p){

// }
int main(){
    int a, b;
    // cout<<"Enter the value of a and b"<<endl;
    // cin>>a>>b;
    // cout<<"The product of a and b is "<<product(a,b)<<endl; // now compiler will replace the inline func code to product(a,b) everytime 
    // cout<<"The product of a and b is "<<product(a,b)<<endl;
    // cout<<"The product of a and b is "<<product(a,b)<<endl;
    // cout<<"The product of a and b is "<<product(a,b)<<endl;
    // cout<<"The product of a and b is "<<product(a,b)<<endl;
// So if too many times function is called, func is big or static var, recursion is there dont use inline 

    // cout<<"Enter the value of a and b"<<endl;
    // cin>>a>>b; // assume a=1,b=1
    // cout<<"The sum of a and b is "<<sum(a,b)<<endl;//3
    // cout<<"The sum of a and b is "<<sum(a,b)<<endl;//4
    // cout<<"The sum of a and b is "<<sum(a,b)<<endl;//5
    // cout<<"The sum of a and b is "<<sum(a,b)<<endl;//6
    // cout<<"The sum of a and b is "<<sum(a,b)<<endl;//7
// cuz c is static and value of c is kept everytime

    int money = 100000;
    cout<<"If you have "<<money<<" Rs in your bank account, you will recive "<<moneyReceived(money)<< "Rs after 1 year"<<endl;
    cout<<"For VIP: If you have "<<money<<" Rs in your bank account, you will recive "<<moneyReceived(money, 1.1)<< " Rs after 1 year";
    return 0;
}