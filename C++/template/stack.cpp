#include<iostream>
using namespace std;

template <class STACK>
class stack {
    public:
    int top;
    STACK s[5];
    stack() {
        top=-1;
    }
    void push(STACK n){
        s[++top]=n;
    }
    STACK pop() { 
        return s[top--];
    }
};
int main()
{
    stack<int>s1;
    stack<float>s2;
    stack<char>s3;

    s1.push(10);
    s2.push(12.2);
    s3.push('A');
     
    cout<<s1.pop()<<" "<<s2.pop()<<" "<<s3.pop()<<endl;
    return 0;
}