
/**
���罫����x+1,y���򴵣� �Ϸ罫����x,y-1���򴵣� ���罫����x-1,y���򴵣� ���罫����x,y+1���򴵡� ���������С��������ʲôʱ��ص���ͷ��ע�⣬С���õĴ�����ê�ġ�����ϣ�������Ļ�������ڵ�һʱ���ê����ȥ��

�����ʽ
��������������ݡ�ÿ�������һ�а������������t,sx,sy,ex,ey���ڶ��а���t���ַ�������'E','S','W','N'��

�������ֵС��1000000000��t<=100000�����뱣֤����ء��յ����겻��ͬ��

�����ʽ
���һ��t��ʾ���絽����ͷ��ʱ�䣬������ﲻ�������-1��

@status ���ύ��ʱ�����������.
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
