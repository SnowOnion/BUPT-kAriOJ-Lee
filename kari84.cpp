/**
CB操作
ctrl-j 自动补完; settings-editor-abbreviation 里改补完出的东西

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

int inint(int* in){
    return scanf("%d",in);
}

int indouble(double* in){
    return scanf("%lf",in);
}

void printarray(int* lst,int len){
    for(int i=0;i<len;i++){
        printf("%d ",lst[i]);
    }
    puts("");
}

void printmatrix(int** mat, int row, int col){
    for(int i=0;i<row;i++){
        printarray(*(mat+i*col),col);
    }
    puts("");
}

/*
int m[5][5];
for(int i=0;i<3;i++){
    for(int j=0;j<4;j++){
        inint(&m[i][j]);
    }
}

*/

/**
"三进制异或"
inspired by
http://bbs.byr.cn/#!article/ACM_ICPC/77745
And (mainly)
http://blog.csdn.net/cheetach119/article/details/12314037

Advanced status design:
b0' = b0(!inp) + (!b1)inp
b1' = b1(!inp) + (b1 XOR b0)inp
= b1^inp

b1b0= 00->01->11->00
无关项. φ. 卡诺图.

@status AC

*/


void init(){

}

void solve(){
    int N;

    while(inint(&N)!=-1){
        // clear solution
        long long oldb0(0),oldb1(0),newb0,newb1,inp;

        while(N--){
            scanf("%lld",&inp);
            newb0=(oldb0&(~inp)) | ((~oldb1)&inp);
            newb1=(oldb1&(~inp)) | (oldb0^oldb1)&inp;
            oldb0=newb0;
            oldb1=newb1;
//            printf("inp %lld\n",inp);
//            printf("newb0 %lld\n",newb0);
//            printf("newb1 %lld\n",newb1);
        }
        printf("%lld\n",newb0^newb1);
    }
}

int main(){
    init();
    solve();

    return 0;
}

