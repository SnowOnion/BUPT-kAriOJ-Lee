#include<cstdio>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<map>

using namespace std;

/**
http://code.bupt.edu.cn/problem/p/449/
输入数据8.2M 1ms 65536KiB
@status 手写快排 TLE
std::sort TLE
数据取值[0,10000], 考虑桶排序
写了个朴素的桶排序, T. 不知道怎么办...
数组改成map, 还是T.
*/

int main(){
    int n;
    //int radix[10010];
    map<int,int> radix;
    int in;

    while(scanf("%d",&n)>0){
        //memset(radix,0,sizeof(radix));
        radix.clear();
        for(int i=0;i<n;i++){
            scanf("%d",&in);
            radix[in]+=1;
        }

        //for(int i=0;i<=10000;i++){
        for(map<int,int>::iterator iter=radix.begin();iter!=radix.end();++iter){
            for(int j=0;j<iter->second;j++){
                printf("%d ",iter->first);
            }
        }
        printf("\n");
    }
    return 0;
}
