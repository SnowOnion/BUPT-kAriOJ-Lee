/**
http://code.bupt.edu.cn/problem/contest/117/problem/C/
悍然蒙特卡洛
*/

#include <memory.h>
#include <ctime>


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

/*init as 0*/
int exist[110];
int remain;
int N;

/*before init*/
void test(){

}

void init(){
    srand(time(NULL));
}

void caseInit(){
    memset(exist,0,sizeof(exist));
    remain=N;
}


void solve(){

    while(inint(&N)>0){

        int sum=0;
        int testtimes=1000;

        f1n(t,testtimes){
            caseInit();
            int i;
            for(i=1;i<=1000;i++){
                int num=rand()%N;
                if(!exist[num]){
                    remain--;
                    exist[num]=1;
                }
                if(remain==0){
                    break;
                }
            }// here i is the times of trying. if i>10000, i:=10001.
            sum+=i;
        }
        printf("%.6lf\n",((double)sum)/testtimes);
    }
}

int main(){
    test();
    init();
    solve();

    return 0;
}
