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

std::map 的实现是红黑树, 访问 O(log n). http://bbs.byr.cn/#!article/ACM_ICPC/80885
"其实两组1000000卡sort，1000000组5卡计数～
有一种很丑的姿势过这题就是
if n>200000: 用计数
else: 用sort "
↑ It works!!!!!!! 骗分第一课...
*/

int main()
{
    int n;
    int radix[10010];
    vector<int> v;
    int vv;
    int in;

    while(scanf("%d",&n)>0)
    {
        int casefirst=1;
        if(n>200000)
        {
            memset(radix,0,sizeof(radix));

            for(int i=0; i<n; i++)
            {
                scanf("%d",&in);
                radix[in]+=1;
            }

            for(int i=0; i<=10000; i++)
            {
                for(int j=0; j<radix[i]; j++)
                {
                    if(casefirst){
                        casefirst=0;
                        printf("%d",i);
                    }
                    else{
                        printf(" %d",i);
                    }

                }
            }
            printf("\n");
        }
        else
        {
            v.clear();
            for(int i=0; i<n; i++)
            {
                scanf("%d",&vv);
                v.push_back(vv);
            }

            sort(v.begin(),v.begin()+n);

            for(int i=0; i<n-1; i++)
            {
                printf("%d ",v[i]);
            }
            printf("%d\n",v[n-1]);
        }
    }
    return 0;
}
