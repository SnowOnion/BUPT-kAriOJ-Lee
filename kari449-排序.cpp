#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

/**
http://code.bupt.edu.cn/problem/p/449/
输入数据8.2M 1ms 65536KiB
@status 手写快排 TLE
std::sort TLE
数据取值[0,10000], 考虑桶排序
*/

int main(){
    int n;
    vector<int> v;int vv;

    while(scanf("%d",&n)>0){
        for(int i=0;i<n;i++){
            scanf("%d",&vv);
            v.push_back(vv);
        }

        sort(v.begin(),v.begin()+n);

        for(int i=0;i<n-1;i++){
            printf("%d ",v[i]);
        }
        printf("%d\n",v[n-1]);
    }
}
