#include<cstdio>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;

/**
http://code.bupt.edu.cn/problem/p/449/
��������8.2M 1ms 65536KiB
@status ��д���� TLE
std::sort TLE
����ȡֵ[0,10000], ����Ͱ����
д�˸����ص�Ͱ����, TLE. ��֪����ô��...
*/

int main(){
    int n;
    int radix[10010];
    int in;

    while(scanf("%d",&n)>0){
        memset(radix,0,sizeof(radix));
        for(int i=0;i<n;i++){
            scanf("%d",&in);
            radix[in]+=1;
        }

        for(int i=0;i<=10000;i++){
            for(int j=0;j<radix[i];j++){
                printf("%d ",i);
            }
        }
        printf("\n");
    }
}
