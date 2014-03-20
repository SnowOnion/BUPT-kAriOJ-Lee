#include<iostream>
#include<string>
#include<stack>
#include<cstdio>
using namespace std;

stack<string> s;

int main(){
    char line[1010];

    while(gets(line)!=NULL){
        char word[1000];
        while(sscanf(line,"%s",word)>0){
            s.push(string(word));
        }
        while(s.size()>1){
            cout<<s.top()<<' ';
            s.pop();
        }
        if(!s.empty()){
            cout<<s.top()<<endl;
            s.pop();
        }
    }

    return 0;
}
