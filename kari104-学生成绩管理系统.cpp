#include<cstdio>
#include<map>
#include<cstring>

using namespace std;



/**
每样例人数 E [0,100]

输入样例
2
2
Insert 0 10
Find 0
5
Insert 1 1
Find 2
Insert 2 2
Find 2
Find 1
输出样例
name:0 score:10
No result!
name:2 score:2
name:1 score:1

@status AC
*/


void inint(int* in)
{
    scanf("%d",in);
}

map<int,int> mii;

int main()
{

    int T;
    inint(&T);
    while(T--)
    {
        mii.clear();

        int n;
        inint(&n);
        while(n--)
        {

            char query[10];
            scanf("%s",query);
            if(!strcmp(query,"Insert"))
            {
//                puts("insert");
                int id,score;
                inint(&id);
                inint(&score);
                mii[id]=score;
            }
            else
            {
                int id;
                inint(&id);
                map<int,int>::iterator it=mii.find(id);
                if(it==mii.end())
                {
                    puts("No result!");
                }
                else
                {
                    printf("name:%d score:%d\n",it->first,it->second);
                }
            }

//            for(map<int,int>::iterator it=mii.begin(); it!=mii.end(); ++it)
//            {
//                printf("%d\t\t",it->first);
//                printf("%d\n",it->second);
//            }
        }
    }

    return 0;
}
