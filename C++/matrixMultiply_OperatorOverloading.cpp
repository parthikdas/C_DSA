#include <iostream>
using namespace std;
void xx(){}
class matrix{
  public:
    int r, c, a[5][5];
    void create(){
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++) scanf("%d",&a[i][j]);
    }
    void print(){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++) printf("%d ",a[i][j]);
            printf("\n");
        }
    }
    friend matrix operator *(matrix&, matrix&);
};
matrix operator *(matrix &a, matrix &b){
    matrix ans;
    ans.r = a.r;
    ans.c = b.c;
    for(int i=0;i<ans.r;i++){
        for(int j=0;j<ans.c;j++) {
            for(int k=0;k<ans.c;k++) ans.a[i][j] += a.a[i][k] * b.a[k][j];
        }
    }
    return ans;
}
int main(){
    matrix m1, m2, ans;
    cin>>m1.r>>m1.c>>m2.r>>m2.c;
    m1.create();
    m2.create();
    ans = m1 * m2;
    ans.print();
	return 0;
}