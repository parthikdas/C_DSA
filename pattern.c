#include <stdio.h>
/* Steps: 1. No of lines = No of rows = No of times the outer loop will run
          2. Identify for every row no:
            * how many cols are there
            * types of elements in cols
          3. What do you need to print
    Note: Try to find the formula relating rows and cols
*/
// Pattern 1
// *
// * *
// * * *
// * * * *
void pattern1(int n){
    for(int row=1;row<=n;row++){
        for(int col=1;col<=row;col++){
            printf("* ");
        }
        printf("\n");
    }
}
// Pattern 2
// *****
// ****
// ***
// **
// *
void pattern2(int n){
    for(int row=1;row<=n;row++){
        for(int col=1;col<=n-row+1;col++){
            printf("* ");
        }
        printf("\n");
    }
}
// Pattern 3
//  *
//  **
//  ***
//  ****
//  *****
//  ****
//  ***
//  **
//  *
void pattern3(int n){
    for(int row=0; row < 2*n; row++){
        int totalColsInRow = row > n ? 2*n-row : row; // n-(n-row) = 2n-row, how much we will have to skip
        for(int col=0;col<totalColsInRow;col++){
            printf("* ");
        }
        printf("\n");
    }
}
// Pattern 4
//      *
//     **
//    ***
//   ****
//  *****
void pattern4(int n){
    for(int i=0;i<n;i++){
        // for(int j=0;j<n-i;j++){
        //     printf(" ");
        // }
        // for(int j=0;j<i;j++){
        //     printf("*");
        // }
        for(int j=0;j<n;j++){
            printf(j<n-i-1?" ":"*");
        }
        printf("\n");
    }
}
// Pattern 5
//  *****
//   ****
//    ***
//     **
//      *
void pattern5(int n){
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            printf(j<n-i-1?" ":"*");
        }
        printf("\n");
    }
}
// Pattern 6
//     *
//    ***
//   *****
//  *******
// *********
void pattern6(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=n+i;j++){
            printf(j<n-i?" ":"*");
        }
        printf("\n");
    }
}
// Pattern 7
// *********
//  *******
//   *****
//    ***
//     *
void pattern7(int n){
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=n+i;j++){
            printf(j<n-i?" ":"*");
        }
        printf("\n");
    }
}
// Pattern 8
//     *
//    * *
//   * * *
//  * * * *
// * * * * *
void pattern8(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf(j<n-i-1?" ":"* ");// remember n-i-1 for this type of triangle
        }
        printf("\n");
    }
}
// Pattern 9
// * * * * *
//  * * * *
//   * * *
//    * *
//     *
void pattern9(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf(j<i?" ":"* ");
        }
        printf("\n");
    }
}
// Pattern 10
// * * * * *
//  * * * *
//   * * *
//    * *
//     *
//     *
//    * *
//   * * *
//  * * * *
// * * * * *
void pattern10(int n){
    for(int i=0;i<n*2;i++){
        for(int j=0;j<n;j++){
            printf(i<n?j<i?" ":"* ":j<n-(i-n)-1?" ":"* ");// for 2nd line took help from 2nd line
        }
        printf("\n");
    }
}
// Pattern 11
//     *
//    * *
//   *   *
//  *     *
// * * * * * 
void pattern11(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf(i==n-1?"* ":j<n-i-1?" ":j==n-i-1||j==n-1?"* ":"  ");//i==n-1 if for last line, j<n-i-1 is for main case(left side space), j==n-i-1||j==n-1 is for 0th and last index print
        }
        printf("\n");
    }
}
// Pattern 12
// * * * * * 
//  *     *
//   *   *
//    * *
//     *
void pattern12(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf(i==0?"* ":
                        j<i?" ":j==i||j==n-1?"* ":"  ");
        }
        printf("\n");
    }
}
// Pattern 13
//     *
//    * *
//   *   *
//  *     *
// ********* 
void pattern13(int n){
    for(int i=0;i<n;i++){
        int x = i==n-1?n*2-1:n;
        for(int j=0;j<x;j++){
            printf(i==n-1?"*":j<n-i-1?" ":j==n-i-1||j==n-1?"* ":"  ");
        }
        printf("\n");
    }
}
// Pattern 14
// ********* 
//  *     *
//   *   *
//    * *
//     *
void pattern14(int n){
    for(int i=0;i<n;i++){
        int x = i==0?n*2-1:n;
        for(int j=0;j<x;j++){
            printf(i==0?"*":j<i?" ":j==i||j==n-1?"* ":"  ");
        }
        printf("\n");
    }
}
// Pattern 15
//     *
//    * *
//   *   *
//  *     *
// *       *
//  *     *
//   *   *
//    * *
//     *
void pattern15(int n){
    for(int i=0;i<n*2-1;i++){
        for(int j=0;j<n;j++){
            printf(i<n?
                j<n-i-1?" ":j==n-i-1||j==n-1?"* ":"  "  :
                j<i-n+1?" ":j==i-n+1||j==n-1?"* ":"  ");
        }
        printf("\n");
    }
}
// Pattern 16
//         1
//       1   1
//     1   2   1
//   1   3   3   1
// 1   4   6   4   1
void pattern16(int n){
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            printf("%d",i-j);
        }
        printf("\n");
    }
}
// Pattern 17
//     1
//    212
//   32123
//  4321234
//   32123
//    212
//     1
void pattern17(int n){
    for(int i=1;i<=n*2-1;i++){
        for(int j=n;j>0;j--){
            if(i<=n?j>i:j>2*n-i) printf(" "); // i is for space triangle, 2*n-i is for 2nd triangle
            else printf("%d",j);
        }
        for(int j=2;j<=(i<=n?i:2*n-i);j++){ // for 2nd half
            printf("%d",j);
        }
        printf("\n");
    }
}
// Pattern 18
// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// **********
void pattern18(int n){

}
// Pattern 19
// *        *
// **      **
// ***    ***
// ****  ****
// **********
// ****  ****
// ***    ***
// **      **
// *        *
void pattern19(int n){

}
// Pattern 20
// ****
// *  *
// *  *
// *  *
// ****
void pattern20(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf(i==0 || i==n-1 || j==0 || j==n-1? "*" : " ");
        }
        printf("\n");
    }
}
// Pattern 21
// 1
// 2  3
// 4  5  6
// 7  8  9  10
// 11 12 13 14 15
void pattern21(int n){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=i*2-i;j++){
            printf("%d ",j);
        }
        printf("\n");
    }
}
// Pattern 22
// 1
// 0 1
// 1 0 1
// 0 1 0 1
// 1 0 1 0 1
void pattern22(int n){

}
// Pattern 23
//       *      *
//     *   *  *   *
//   *      *      *
void pattern23(int n){

}
// Pattern 24
// *        *
// **      **
// * *    * *
// *  *  *  *
// *   **   *
// *   **   *
// *  *  *  *
// * *    * *
// **      **
// *        *
void pattern24(int n){

}
// Pattern 25
//       *****
//      *   *
//     *   *
//    *   *
//   *****
void pattern25(int n){

}
// Pattern 26
//   1 1 1 1 1 1
//   2 2 2 2 2
//   3 3 3 3
//   4 4 4
//   5 5
//   6
void pattern26(int n){
    for(int i=1;i<=n;i++){
        for(int j=n-i+1;j>0;j--) printf("%d ",i);
        printf("\n");
    }
}
// Pattern 27
//   1 2 3 4  17 18 19 20
//     5 6 7  14 15 16
//       8 9  12 13
//         10 11
void pattern27(int n){

}
// Pattern 28
//      *
//     * *
//    * * *
//   * * * *
//  * * * * *
//   * * * *
//    * * *
//     * *
//      *
void pattern28(int n){

}
// Pattern 29      
//    *        *
//    **      **
//    ***    ***
//    ****  ****
//    **********
//    ****  ****
//    ***    ***
//    **      **
//    *        *
void pattern29(int n){

}
// Pattern 30
//         1
//       2 1 2
//     3 2 1 2 3
//   4 3 2 1 2 3 4
// 5 4 3 2 1 2 3 4 5
void pattern30(int n){
    for(int i=1;i<=n;i++){
        // for(int j=1;j<i*2;j++){ // if in the left there were no space triangle then this for loop would be fine
        //     printf("%d ",j<=i?i-j+1:j-i+1);
        // }
        for(int j=n;j>0;j--){
            if(i<=n?j>i:j>2*n-i) printf("  "); // i is for space triangle, 2*n-i is for 2nd triangle
            else printf("%d ",j);
        }
        for(int j=2;j<=(i<=n?i:2*n-i);j++){ // for 2nd half
            printf("%d ",j);
        }
        printf("\n");
    }
}
// Pattern 31
//  4 4 4 4 4 4 4  
//  4 3 3 3 3 3 4   
//  4 3 2 2 2 3 4   
//  4 3 2 1 2 3 4   
//  4 3 2 2 2 3 4   
//  4 3 3 3 3 3 4   
//  4 4 4 4 4 4 4   
void pattern31(int n){

}
// Pattern 32
//    E
//    D E
//    C D E
//    B C D E
//    A B C D E
void pattern32(int n){
    for(int i=n;i>0;i--){
        for(int j=i;j<=n;j++){
            printf("%c ",j+64);
        }
        printf("\n");
    }
}
// Pattern 33
// a
// B c
// D e F
// g H i J
// k L m N o
void pattern33(int n){

}
// Pattern 34
// E D C B A
// D C B A
// C B A
// B A
// A
void pattern34(int n){
    for(int i=65;i<n+65;i++){ // ascii of A is 65
        for(int j=n+64;j>=i;j--){
            printf("%c ",j);
        }
        printf("\n");
    }
}
int main(){
    pattern21(5);
    return 0;
}