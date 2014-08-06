/**
http://code.bupt.edu.cn/problem/contest/117/problem/A/
¿Ï¶¨T
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

/*init as -1; bound PRIME[2]=1, PRIME[1]=0*/
int PRIME[32768];
int

int isprime(int n){
    if((n<32768) && (PRIME[n]!=-1)){
        return PRIME[n];
    }
    else{
        //printf("Eval: isprime(%d)\n",n);
        for(int fa=2;fa*fa<=n;fa++){
            if(!isprime(fa)){
                //printf("Skp: (%d)\n",fa);
                continue;
            }
            //printf("Mod: (%d)\n",fa);
            if(n%fa==0){
                if(n<32768) PRIME[n]=0;
                return 0;
            }
        }
        if(n<32768) PRIME[n]=1;
        return 1;
    }
}

/*before init*/
void test(){

}

void init(){
    memset(PRIME,-1,sizeof(PRIME));
    PRIME[2]=1;
}

void solve(){
    int N;
    while(inint(&N)>0){
        int mei=0;
        for(int i=2;i<=N;i++){
            if(isprime(i))mei+=1;
        }
        printf("%d\n",mei);
    }
}

int main(){
    test();
    init();
    solve();

    return 0;
}
