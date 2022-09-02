#include <iostream>
using namespace std;
template <class sort>
void bubbleSort(sort *a, sort n) {
    for(int i=0;i<n-1; i++) {
        for(int j=0;j<n-i-1;j++) {
            if(a[j] > a[j+1]) {
                sort temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
int main()
{
    int a[5] = {5,4,3,2,1};
    char b[5] = {'z','x','a','f','e'};
    float c[5] = {9.9,-7.4,8.1,1.9,-5.5};
    bubbleSort<int>(a, 5); // By same function both int char float array will be sorted
    bubbleSort<char>(b, 5);
    bubbleSort<float>(c, 5);
    for(int i=0;i<5;i++) cout<<a[i]<<" ";
    cout<<endl;
    for(int i=0;i<5;i++) cout<<b[i]<<" ";
    cout<<endl;
    for(int i=0;i<5;i++) cout<<c[i]<<" ";
    return 0;
}
