// Que - min no of swap to balance parenthesis, assuming only () brackets
// )()( -> 1
#include <iostream>
using namespace std;
int main() {
    string s;
    cin>>s;
    int start=0, end=0; // start is the total no of opening brackets, end is total no of closing brackets that dont have a opening bracket to support it
    for(int i=0;i<s.length();i++) {
        if(s[i]=='(') start++; // count all the opening brackets
    }
    // if we get a opening bracket make flag 1, then if we get a closing bracket check if there was a opening bracket to support it if yes then reduce the start counter else inc the end counter
    // instead of flag++ we did flag*10+1 cause if there is (()) then after 1st ( flag is 1, 2nd ( flag is 1, 1st ) flag is 0, then flag should have 1 left as ) is there and its a balanced string, so instead of 1,0 do 1, 11, 111.. and reduce by /=10 make 11 to 1
    int flag = 0;
    for(int i=0;i<s.length();i++) {
        if(s[i]=='(') {
            flag = flag*10 + 1;
        } else if(s[i]==')') {
            if(flag) {
                start--;
            } else end++;
            flag /= 10;
        }
    }
    if(start == end) cout<<start;
    else cout<<"Can't be balanced";
    return 0;
}