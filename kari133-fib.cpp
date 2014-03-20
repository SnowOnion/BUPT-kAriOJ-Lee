#include<cstdio>
#include<cstring>
#include<memory.h>

#include<iostream>
#include<string>
using namespace std;

int Fib[30];
//int F[20000][20000]; //xktest

int fib(int n){
    if(Fib[n]!=-1)  return Fib[n];

    return (Fib[n]=fib(n-1)+fib(n-2));
}

void init(){
    memset(Fib,-1,sizeof(Fib));
    Fib[1]=Fib[2]=1;
}


int main(){
    init();

    int N;
    scanf("%d",&N);
    printf("%d",fib(N));
    // WTF... 根本就是WA啊 怎么AC了..

    return 0;
}
