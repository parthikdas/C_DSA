/*
Que from JP Morgan coding challenge: kth occurance in arr
Input format:
1st 2 lines are arr_size and X
2nd line is the arr input
3rd line is the query_count
and rest lines are the queries
Output format:
Output the query_count[i] th occurance of X in arr. If not there or exceeds arr size then -1.
Assume 1 based indexing in arr.
Eg: 
4 9
9 8 9 9 
5
1
4
3
2
5
Output:
1
-1
4
3
-1
*/
/*
    my sol here is start with index 0 (j) and there we will put the indexses. So, While traversing the arr if the
    ith index is X then make arr[j++] = i+1 so after all the query_count then j will tell us how many X is there
    and in arr from 0 - j all the indexes will be stored. So after the abpve example the arr will be 1 3 4 9 and
    j will be 3 so there are 3 9's and the first 3 occuring index is 1, 3, 4.
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> find(int X, vector<int> arr, vector<int> query_count) {
    int j = 0;
    for(int i=0;i<arr.size();i++)
        if(arr[i] == X) arr[j++] = i+1;
    for(int i=0;i<query_count.size();i++) 
        query_count[i] = query_count[i] > j ? -1 : arr[query_count[i]-1];
    return query_count;
}
int main() {
    int arr_size, X, query_size;
    cin>>arr_size>>X;
    vector<int> arr, query_count;
    int data;
    for(int i=0;i<arr_size;i++) {
        cin>>data;
        arr.push_back(data);
    }
    cin>>query_size;
    for(int i=0;i<query_size;i++) {
        cin>>data;
        query_count.push_back(data);
    }
    query_count = find(X, arr, query_count);
    for(int i=0;i<query_size;i++) {
        cout<<query_count[i]<<endl;
    }
    return 0;
}
