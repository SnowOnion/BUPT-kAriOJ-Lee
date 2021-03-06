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

double x[110],y[110];
double k[110][110];

// <斜率, 从同一点连出的 斜率为该值的线段的数量>
map<double,int> di;

void init(){

}

void solve(){
    int cases;
    inint(&cases);
    while(cases--){

        di.clear();

        int N;
        inint(&N);
        for(int i=1;i<=N;i++){
            indouble(&x[i]);
            indouble(&y[i]);
        }

        bool result=false;

        //O(N^2)
        for(int i=1;i<=N;i++){

            for(int j=1;j<=N;j++){
                if(i==j) k[i][j]=inf+1;// 刘汝佳：特殊值
                else if(x[i]==x[j]) k[i][j]=inf;
                else k[i][j]=(y[j]-y[i])/(x[j]-x[i]);

                if(i!=j) di[k[i][j]]+=1;
            }
            for(map<double,int>::iterator it=di.begin();it!=di.end();++it){
                if((it->second)>1){
                    result=true;
                    break;
                }
            }

            if(result){ // 第二层跳
                break;
            }

            di.clear();
        }

        if(result){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }

    }

}

int main(){
    init();
    solve();

    return 0;
}

