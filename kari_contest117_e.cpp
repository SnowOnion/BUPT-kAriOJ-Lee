
/**
东风将船向x+1,y方向吹； 南风将船向x,y-1方向吹； 西风将船向x-1,y方向吹； 北风将船向x,y+1方向吹。 请问叔叔和小妹妹最早什么时间回到码头？注意，小妹妹的船是有锚的～她不希望船动的话叔叔就在第一时间把锚抛下去。

输入格式
输入包含多组数据。每组输入第一行包含五个整数，t,sx,sy,ex,ey，第二行包含t个字符，仅含'E','S','W','N'。

坐标绝对值小于1000000000。t<=100000。输入保证起点重、终点坐标不相同。

输出格式
输出一个t表示最早到达码头的时间，如果到达不了则输出-1。

@status 想提交的时候比赛结束了.
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

void test(){

}

void init(){

}

void solve(){
    int t,sx,sy,ex,ey;
    char wind;

    while(scanf("%d%d%d%d%d",&t,&sx,&sy,&ex,&ey)>0){

        int xdelta=ex-sx,ydelta=ey-sy;
        int result=0;

        f0n_1(i,t){
            scanf("%c",&wind);
            switch(wind){
        case 'E':
            if(xdelta>0) xdelta--;
            break;
        case 'W':
            if(xdelta<0) xdelta++;
            break;
        case 'N':
            if(ydelta>0) ydelta--;
            break;
        case 'S':
            if(ydelta<0) ydelta++;
            break;
            }
            if(!(xdelta||ydelta)){
                printf("%d\n",i);
                result=1;
                break;
            }
        }
        if(!result) printf("%d\n",-1);
    }
}

int main(){
    test();
    init();
    solve();

    return 0;
}
