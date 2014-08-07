#include<memory.h>

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <map>
using namespace std;

const double eps=1e-8;
const double pi=atan(1.0)*4;
const int inf=2147483600;
int tenpower[7]= {1,10,100,1000,10000,100000,1000000};
// pow10 is dangerous

#define __ printf("------------------------------------------\n");

#define f0n_1(_x,n) for(int _x=0;_x<n;_x++)
#define f1n_1(_x,n) for(int _x=1;_x<n;_x++)
#define f0n(_x,n) for(int _x=0;_x<=n;_x++)
#define f1n(_x,n) for(int _x=1;_x<=n;_x++)
#define fn_10(_x,n) for(int _x=n-1;_x>=0;_x--)
#define fn_11(_x,n) for(int _x=n-1;_x>0;_x--)
#define fn0(_x,n) for(int _x=n;_x>=0;_x--)
#define fn1(_x,n) for(int _x=n;_x>0;_x--)

/**
    int a[][3]={{1,2,3},{4,5,6}};
    int b[][3]={9,8,7,6,5,4};

    printMatrix(a,2,3);
    __
    printMatrix(b,2,3);
    __
    printArray(b[1],3);
*/
#define printArray(lst,len) f0n_1(_i,(len)){printf("%d ",lst[_i]);} puts("");
#define printMatrix(mat,row,col) f0n_1(_j,(row)){printArray(mat[_j],(col));}

int inint(int* in){
    return scanf("%d",in);
}

int indouble(double* in){
    return scanf("%lf",in);
}

/** 这个看起来像是上限? 8G 32位 等等 似乎有点傻逼
一个开大了不行 开多个却可以... */
// int viola[500000];
//    int viola2[500000];
//    int viola3[500000];
//    int viola4[500000];
//    int viola5[500000];

void test(){
    /**
    试一试: 分格子算半径为1的圆的面积, 格子要多细才能精确到小数点后5位?
    圆心(0,0), 半径1.
    当g=0.001, sum=3.141547
    当g=0.0001, sum=3.141591, 但已经用了好几秒...
    */
    double x0=0,y0=0,r=1,g=0.0001,s=g*g;
    double sum=0;
    for(double x=-1.;x<1;x+=g){
        for(double y=-1;y<1;y+=g){
            if((x-x0)*(x-x0)+(y-y0)*(y-y0)-r*r<eps){
                sum+=s;
            }
        }
    }
    printf("%lf",sum);

    /**
    不要总是判断, 而是去"刷漆", 然后再数有漆的格子呢? 这样100个圆也不会增长很多了...
    然后不要用判断法, 要用计算法来刷=.=
    不行这个画布太占内存了...
    */



}

void init(){

}

void solve(){

//    int cases;
//    inint(&cases);
//    while(cases--){
//
//    }

    // input var
    // while(scanf("")>0){
    //
    // }

}

int main(){
    test();
    init();
    solve();

    return 0;
}
