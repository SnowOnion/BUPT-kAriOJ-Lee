#include<cstdio>
#include<cstring>
#include<memory.h>

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<utility> // std::pair
using namespace std;

// 艹.. 有std::pair
struct Pair{
    int x;
    int y;
    Pair(int xx,int yy){
        x=xx;
        y=yy;
    }
    bool operator==(Pair& another){
        return (x==another.x)&&(y=another.y);
    }
};

// multimap 可以一试 // 被欺骗了...  multiple elements can have equivalent keys
map<pair<int,int>, bool> pmap;
int distinct;

void init(){
    distinct=0;
}

void solve(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
        int segments;
        int E,V;//R=2-V+E
        scanf("%d",&segments);
        E=segments;

        int points=segments*2;
        while(points--){
            int x,y;
            scanf("%d%d",&x,&y);
            if(pmap.find(Pai)){ //@GET map 中 key 的存在性

            }

        }

    }
}

int main(){
    init();
    solve();

    return 0;
}

