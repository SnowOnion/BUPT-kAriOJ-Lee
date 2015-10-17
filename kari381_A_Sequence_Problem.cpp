/**
 
 381. A Sequence Problem
 时间限制 2000 ms 内存限制 65536 KB
 题目描述
 There is a sequence A which is a permuation of 1 to N.Can you split it into two sequences that for each sequence ,it is sorted in order.
 
 Hint:
 
 The first case ,you can get two sequence "1 4 5 " and "8 7 6 3 2".
 
 The second case, you can get two sequence "3 5 6" and "1 2 4".
 
 输入格式
 The first line contatins an integer T(1≤T≤20) that is the number of cases.For each cases the first line contains an integer N(3≤N≤5000).The second line contains N integers between 1 and N describing the number permutation.
 
 输出格式
 If the sequence can be splitted into two ordered sequence,Output "Yes",otherwise output "No".
 
 输入样例
 3
 8
 
 引理：
 对于i<j,若a[i]<a[j」，若有可行解，则必有 a[i]属于上升序列
 对于i<j,若a[i]>a[j」，若有可行解，则必有 a[j]属于下降序列
 不对！shit
 
 SHIIIIIIIIIT！！！！理解完全错了！@！@！可以两个都是上升或下降！！！！
 http://10.105.240.51/problem/p/381/
 
 a_up a_down b_up b_down 四种可能
 第一个数就 a_up a_down 两种好了…… 不过使得每轮多判断，或产生丑陋代码…… 先不优化 TODO
 
 全排列 这个信息还没用到…… TLE 再说 TODO
 
 优先up
 8 7 1 6 4 3 5 2
 u d d x
 d u d x
 d d u u d d x
 d d u d u d u d √
 
 6
 3  5  1  2  6  4
 au au bu x
 etc.
 
 6
 3 5 2 1 6 4
 u u d d u x
 u d d d u x
 d u d d u x
 ×
 
 输出样例
 Yes
 Yes
 No
 
 */

#include <cstdio>
//#include <cstdlib>
//#include <memory.h>  // memset

// 3 ≤ N ≤ 5000
// 用不可达到的值作为边界
// 好吧！实际上没有用到
#define MAX 5001
#define MIN -1

int T;
int N;
int seq[5010];

/**
 a_state 和 b_state: 
 这次尝试开始时，a和b子序列的状态
 0 未使用
 1 上升
 2 下降
 按照 a/up a/down b/up b/down 的顺序尝试把一个数塞进一个序列。
 初始： dfs(0,0,0,0,0)
 */
bool dfs(int depth,int a_state,int a_tail,int b_state,int b_tail){
//    printf("depth %d, a_state %d, a_tail %d, b_state %d, b_tail %d\n",depth,a_state,a_tail,b_state,b_tail);
    
    // 数组撸完，即找到可行解
    if(depth>=N){
        return true;
    }
    
    // (也就第0个数可以成立)
    // a 序列未使用
    if(a_state==0){
        // 让 a 序列上升，让当前数属于 a/up
        if(dfs(depth+1,1,seq[depth],b_state,b_tail)){
            return true;
        }
        // 上面不行的话，让 a 序列下降，让当前数属于 a/down
        if(dfs(depth+1,2,seq[depth],b_state,b_tail)){
            return true;
        }
    }
    
    // a 已用，且为 up
    if(a_state==1){
        // 尝试继续 a
        if(seq[depth]>a_tail){
            if(dfs(depth+1,a_state,seq[depth],b_state,b_tail)){
                return true;
            }
        }
        // 继续 a 不行，尝试 b。后面再叙。
    }
    
    // a 已用，且为 down
    if(a_state==2){
        // 尝试继续 a
        if(seq[depth]<a_tail){
            if(dfs(depth+1,a_state,seq[depth],b_state,b_tail)){
                return true;
            }
        }
        // 继续 a 不行，尝试 b。后面再叙。
    }
    
    // a 序列不可用，b 序列是否可用
    // b 未使用
    if(b_state==0){
        // 让 b 序列上升，让当前数属于 b/up
        if(dfs(depth+1,a_state,a_tail,1,seq[depth])){
            return true;
        }
        // 上面不行的话，让 b 序列下降，让当前数属于 b/down
        if(dfs(depth+1,a_state,a_tail,2,seq[depth])){
            return true;
        }
    }
    
    // b 已用，且为 up
    if(b_state==1){
        // 尝试继续 b
        if(seq[depth]>b_tail){
            if(dfs(depth+1,a_state,a_tail,b_state,seq[depth])){
                return true;
            }
        }
    }
    
    // b 已用，且为 down
    if(b_state==2){
        // 尝试继续 b
        if(seq[depth]<b_tail){
            if(dfs(depth+1,a_state,a_tail,b_state,seq[depth])){
                return true;
            }
        }
    }

    // 不行的话，
    // 上不去下不来，failed！
    return false;

}

int main(){

    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        
        // 无论是边读边处理，还是读完再处理，都要确保把数据读完…… 要不会影响下一个 test case.
        for(int i=0;i<N;i++){
            scanf("%d",&seq[i]);
        }
        if(dfs(0,0,0,0,0)){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }

    return 0;
}
