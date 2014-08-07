/**
http://code.bupt.edu.cn/problem/p/386/
做过的题型, 嘻嘻
@status AC
*/


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

int candy[100010];
int DP[100010]; // dp[x]:= \sum_{i=1}^x candy[i]

void test(){

}

void init(){

}

void calc(int n){
    DP[0]=0;
    f1n(i,n){
        DP[i]=DP[i-1]+candy[i];
    }
}

void solve(){
    int cases;
    inint(&cases);
    while(cases--){
        //memset(DP,-1,sizeof(DP)); // 直接离线算完, 不lazy
        int N;
        inint(&N);
        f1n(i,N){
            inint(&candy[i]);
        }

        calc(N);

        int M;
        inint(&M);
        int l,r;
        while(M--){
            scanf("%d%d",&l,&r);
            printf("%d\n",DP[r]-DP[l-1]);
        }
    }
}

int main(){
    test();
    init();
    solve();

    return 0;
}
