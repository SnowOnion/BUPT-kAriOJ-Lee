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

typedef long long LL;

int main(){



	vector<map<int,LL> > cvs;
	map<int,LL> tmp;
	cvs.push_back(tmp);

	for(int i=1;i<=3;i++){
		map<int,LL> m;
		m[i*10]=i*1000;
		m[i*10+1]=i*1000+1;
		cvs.push_back(m);
	}


	for(int i=1;i<=3;i++){
		map<int,LL> m = cvs.at(i);
		printf("%lld\n",m.find(i*10)->second);
	}

	map<int,LL> &m=cvs.at(1);
	m[10]=999;
	// 是引用就可以更改！！

	for(int i=1;i<=3;i++){
		map<int,LL> m = cvs.at(i);
		printf("%lld\n",m.find(i*10)->second);
	}



	// queue<int> q;

	// q.push(1); // push to back
	// q.push(2);
	// q.push(3);

	// printf("front %d\n",q.front());
	// printf("back %d\n",q.back());

	// q.pop(); // pop from front.

	// printf("front %d\n",q.front());
	// printf("back %d\n",q.back());	

	// set<int> changed;
	// changed.insert(44);
	// changed.insert(99);
	// changed.insert(99);
	// for(set<int>::iterator iter=changed.begin();iter!=changed.end();++iter){
	// 	printf("%d\n", *iter);
	// }



	return 0;
}