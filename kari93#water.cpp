#include<cstdio>
#include<cstring>
#include<memory.h>

#include<iostream>
#include<string>
using namespace std;

// AC

int inint(int* in)
{
    return scanf("%d",in);
}

void init()
{

}

void solve()
{
    int cases;
    inint(&cases);

    while(cases--)
    {
        int n;
        inint(&n);
        int i;
        int result=1;
        for(i=0; i<n; i++)
        {
            int pre;
            int current;
            inint(&current);
            if(i>0)
            {
                if(current<pre)
                {
                    result=0;
//                    puts("No");
//                    break; // @GET 不能这样.. 得读完..
                }
            }
            pre=current;
        }
        if(result){
            puts("Yes");
        }
        else{
            puts("No");
        }
    }

}

int main()
{
    init();
    solve();

    return 0;
}

