#include<memory.h>

#include <cmath>
#include <ctime>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <map>
using namespace std;

const double eps=1e-8;
const double pi=atan(1.0)*4;

int inint(int* in){
    return scanf("%d",in);
}


typedef long long LL;

void printArray(LL lst[],int l,int r,char split){
	for(int i=l;i<=r;i++){
		printf("%lld",lst[i]);
		printf("%c",split);
	}
	puts("");
}

int N,Q;

LL    S[100010];
LL   S2[100010];
LL    a[100010]; // 总是最新的 战力值
// LL olda[100010]; // olda[m]: 当前（可能过时的） S[m] 和 S2[m] 被计算的时候的 a[m] 值  // SB！！！
// 版本控制思想万万岁！！
set<int> changed;
// map<int,map<int,LL> > mmm; // mmm[k][m] := 当 S[k] 和 S2[k] 被计算时的 a[m] 值

vector<map<int,LL> > cvs; // cvs[m][k] := 第m人能力值 在第S/S2[k]被计算时 的值。

LL x(int i,int j){
	// printf("CCCCCCACL %d %d\n",i,j);
	// printf("S2j %lld S2i-1 %lld Sj %lld Si-1 %lld \n",S2[j],S2[i-1],S[j],S[i-1] );

	LL one = (LL)(j-i+1) * ( S2[j] - S2[i-1] );
	LL another = ( S[j] - S[i-1] );
	return one - another * another;
}

// void update(int i,LL ai){ 
// 	// 旧值还有用
// 	for(int m=i;m<=N;m++){ // TLE! 2015-04-11 15:11:22
// 		S[m] -= a[i] ;
// 		S[m] += ai ;
// 		S2[m]-= ((LL)a[i])*a[i] ;
// 		S2[m]+= ((LL)ai)*ai ;

// 		   		// 		puts("===updated S:====");
// 		   		// printArray(S,1,N,'\n');
// 		   		// puts("===updated S2:====");
// 		   		// printArray(S2,1,N,'\n');
// 	}
// 	a[i]=ai; // 最后把人换掉
// }

void update_only(int l,int r,int i){ 
// 只为了 l 和 r 服务！
	// 更新 S/S2 的 [r] 和 [l-1]

	map<int,LL> &m = cvs.at(i); // 存着 a[i] 的一些历史值。map 里有东西，意味着更计算过。
	if(m.count(r)>0){
		//
	}
	else{
		m[r] = a[i];
	}
	LL oldr=m[r];
	S[r] =  S[r] -   oldr +   a[r];
	S2[r] =  S2[r] -   ((LL)oldr) * oldr +   ((LL)a[r]) * a[r];
	m[r] = a[r];

	// printf("updating------------- oldr %lld a[r] %lld s[r] %lld\n",oldr,a[r],S[r]);

	if(m.count(l-1)>0){
		//
	}
	else{
		m[l-1] = a[i];
	}
	LL oldl_1=m[l-1];
	S[l-1] =  S[l-1] -   oldl_1 +   a[l-1];
	S2[l-1] =  S2[l-1] -   ((LL)oldl_1) * oldl_1 +   ((LL)a[l-1]) * a[l-1];
	m[l-1] = a[l-1];


	// printf("updating------------- oldl_1 %lld a[l-1] %lld s[l-1] %lld\n",oldl_1,a[l-1],S[l-1]);

	// printf("after update_only(%d,%d,%d)",l,r,i);
	// puts("===updated S:====");
	// printArray(S,1,N,'\n');
	// puts("===updated S2:====");
	// printArray(S2,1,N,'\n');
	
}



void solve(){

   int cases;
   inint(&cases);
   while(cases--){

	   	changed.clear();
	   	cvs.clear();
	   	map<int,LL> tmp;
	   	cvs.push_back(tmp);


   		inint(&N);
   		a[0]=0; // 顺手一打！！！坑预备
   		// olda[0]=0; // 顺手一打！！！坑预备
   		for(int i=1;i<=N;i++){
   			scanf("%lld",&a[i]);
   			// olda[i]=a[i];
   		}

   		S[0]=0;
   		S2[0]=0;
   		for(int i=1;i<=N;i++){ // O(N)
   			S[i] = S[i-1]+a[i];
   			S2[i]= S2[i-1] + a[i]*a[i];
   			map<int,LL> ver;
   			// ver[i]=a[i]; // 超内存？？ 并不 // 但是仅仅是对角线 没有用
   			cvs.push_back(ver);

   		} // 离线计算

   		// puts("===S:====");
   		// printArray(S,1,N,'\n');
   		// puts("===S2:====");
   		// printArray(S2,1,N,'\n');
   		

   		inint(&Q);
   		while(Q--){
   			LL opt,var1,var2;
   			scanf("%lld%lld%lld",&opt,&var1,&var2);
   			if(1==opt){
   				LL i=var1,
   				ai=var2;
   				
   				a[i]=ai;
   				// changed.push(i);
   				changed.insert(i);

   				// update(i,ai);// 级联变化 // O(N^2)！！！！
   				
   				// puts("===updated S:====");
		   		// printArray(S,1,N,'\n');
		   		// puts("===updated S2:====");
		   		// printArray(S2,1,N,'\n');
   			}
   			else{ // 2==opt
   				int
   				l=var1,
   				r=var2;

   				// printf("---- now set size and ctt: %lu\n",changed.size());
	   // 			for(set<int>::iterator iter=changed.begin();iter!=changed.end();++iter){
				// 	printf("-  %d\n",*iter);
				// }

	   			// 查询过时。队列！集合！
	   	// 		for(set<int>::iterator iter=changed.begin();iter!=changed.end();++iter){
					// if((l<=*iter) && (*iter<=r)){

				update_only(l,r,*iterator); 

						// update_only(l,r,*iter); 
				// 	}
				// }

				printf("%lld\n",x(l,r));// 计算辣！
				// printf("=======%lld %lld %lld %lld\n",a[0],olda[0],S[0],S2[0]);
   			}
   		}

   }


}

int main(){
    solve();

    return 0;
}