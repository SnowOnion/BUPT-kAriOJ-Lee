#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

/**
http://code.bupt.edu.cn/problem/p/449/
��������8.2M 1ms 65536KiB
@status ��д���� TLE
std::sort TLE
����ȡֵ[0,10000], ����Ͱ����
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
