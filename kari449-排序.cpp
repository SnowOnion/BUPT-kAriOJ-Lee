#include<cstdio>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<map>

using namespace std;

/**
http://code.bupt.edu.cn/problem/p/449/
��������8.2M 1ms 65536KiB
@status ��д���� TLE
std::sort TLE
����ȡֵ[0,10000], ����Ͱ����
д�˸����ص�Ͱ����, T. ��֪����ô��...
����ĳ�map, ����T.

std::map ��ʵ���Ǻ����, ���� O(log n). http://bbs.byr.cn/#!article/ACM_ICPC/80885
"��ʵ����1000000��sort��1000000��5��������
��һ�ֺܳ�����ƹ��������
if n>200000: �ü���
else: ��sort "
�� It works!!!!!!! ƭ�ֵ�һ��...
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
