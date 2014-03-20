#include<cstdio>
#include<cstring>
#include<memory.h>

#include<iostream>
#include<string>
using namespace std;

/** 练习写两种吧. 1. 自己写reverse和replace 2. 用 std::string
1. AC
2. ING
*/


/**
粗测通过
    char str[100]="0123456";
    iStrReverse(str,2,3);
*/
void iStrReverse(char* str, int start, int revLen){
    for(int l=start,r=start+revLen-1;l<r;l++,r--){
        char temp=str[l];
        str[l]=str[r];
        str[r]=temp;
    }
}

/**
粗测通过
    char str[100]="0123456";
    char rep[100]="poikasanao";
    iStrReplace(str,2,strlen(rep),rep);
*/
void iStrReplace(char* str, int start, int revLen, char* newComer){
    for(int cur=start;cur<start+revLen;cur++){
        str[cur]=newComer[cur-start];
    }
}

int main(){

    char str[210];

    while(scanf("%s",str)!=-1){
        int t;
        scanf("%d",&t);
        while(t--){
            int type;
            scanf("%d",&type);
            if(type==0){
                int i,len;
                scanf("%d%d",&i,&len);
                iStrReverse(str,i,len);
            }
            else{
                int i,len;
                char snew[200];
                scanf("%d%d%s",&i,&len,snew);
                iStrReplace(str,i,len,snew);
            }
            puts(str);
        }

    }

    return 0;
}
