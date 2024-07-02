#include <stdio.h>
#include <math.h>
//first method
int powerOf2(int n){
    if(n==0) return 0;
   return (ceil(log2(n)) == floor(log2(n)));
}
int firstMethod(int n,int k){
    int temp=n,biggestPower=0;
    while(temp){
    if(powerOf2(temp)) {biggestPower = temp;break;}
    temp--;
    }
    int l=n-biggestPower;
    printf("%d ",l);
    return 2*l+1;
}
//ends
//second method
int decimalTObinary(int num) {
    int x;
    unsigned int mask=32;
    while(mask > 0) {
       if((num & mask) == 0 ) x=x*10+0;
       else x=x*10+1;
      mask = mask >> 1 ;
    }
    return x;
}
// third method using bits
int decToBinary(int n) {
    int s = 0,j=1;
    while(n>0) {
        s = (n&1)*j+s; // &1 gives the least significant bit and >>1 is /2
        n=n>>1;
        j*=10;
    }
    return s;
}
int binaryTOdecimal(int n){
    int dec,i=0;
    while(n!=0) {
        int digit=n%10;
        dec+=digit<<i;
        n=n/10;
        i++;
    }
    return dec;
}
//ends
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    //first method
    printf("%d",firstMethod(n,k));//k=1,so its is giving correct
    
    //second method
    n=decimalTObinary(n);//making n binary
    int digits=(int)log10(n);//total number of digits
    int firstDigit = n/(int)pow(10,digits);//getting the first digit out
    n=n%(int)pow(10,digits)*10+firstDigit;//putting the first digit in last
    printf("%d",binaryTOdecimal(n));
}