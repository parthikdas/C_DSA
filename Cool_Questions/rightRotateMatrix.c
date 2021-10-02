// Rotate matrix 90degree
/*
Test1: 1
       2
       56 96 91 54
  output: 91 56 54 96 
Test2: 2
       4
       23 12 45 67 41 24 76 54 10 11 13 17 33 37 49 68
       2
       12 34 56 78
  output: 33 10 41 23 37 11 24 12 49 13 76 45 68 17 54 67 
          56 12 78 34 
*/

//If u dont want to take another matrix and do it in 1 matrix only do this (We are taking input differently)
#include <stdio.h>
int main()
{
    int a[10][10];
    for(int i=2;i>=0;i--) for(int j=0;j<3;j++) scanf("%d",&a[j][i]);
    for(int i=0;i<3;i++){ for(int j=0;j<3;j++) {printf("%d ",a[i][j]);}printf("\n");}
    return 0;
}

// If u want to use another matrix then
/* //https://www.techiedelight.com/place-rotate-matrix-90-degrees-clock-wise-direction/
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
 
// In-place rotate it by 90 degrees in a clockwise direction
void rotate(vector<vector<int>> &mat)
{
    // `N × N` matrix
    int N = mat.size();
 
    // base case
    if (N == 0) {
        return;
    }
 
    // Transpose the matrix
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
 
    // swap columns
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N/2; j++) {
            swap(mat[i][j], mat[i][N - j - 1]);
        }
    }
}
 
// Function to print the matrix
void printMatrix(vector<vector<int>> const &mat)
{
    for (auto &row: mat) {
        for (auto &i: row) {
            cout << setw(3) << i;
        }
        cout << endl;
    }
    cout << endl;
}
 
int main()
{
    vector<vector<int>> mat =
    {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };
 
    rotate(mat);
    printMatrix(mat);
 
    return 0;
}
*/
