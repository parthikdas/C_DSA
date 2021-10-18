/*
Berth Number    Compartment
 1 -  8               1  
 9 - 16               2  
17 - 24               3  
... and so on

 1LB,  2MB,  3UB,  4LB,  5MB,  6UB,  7SL,  8SU  
 9LB, 10MB, ...
 ...   
 ...


 3UB   |  6UB  
2MB   |  5MB  
1LB   |  4LB  
7SL   |  8SU  


    Test Case 1
INPUT (STDIN)
6
341
293
70
41
156
54
EXPECTED OUTPUT
338MB
290MB
67UB
44LB
153LB
51UB

Test Case 2
INPUT (STDIN)
4
23
11
142
95
EXPECTED OUTPUT
24SU
14UB
139UB
96SU
*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int rem = n%8;
    int seatNo;
    if(rem >=1 && rem<=3) seatNo = n+3;
    else if(rem>=4 && rem<=6) seatNo = n-3;
    else if(rem==7) seatNo = n+1;
    else if(rem==0) seatNo = n-1;
    
    if(rem==1 || rem==4) cout<<seatNo<<"LB";
    else if(rem==2 || rem==5) cout<<seatNo<<"MB";
    else if(rem==3 || rem==6)  cout<<seatNo<<"UB";
    else if(rem==7) cout<<seatNo<<"SL";
    else if(rem==0) cout<<seatNo<<"SU";
    return 0;
}