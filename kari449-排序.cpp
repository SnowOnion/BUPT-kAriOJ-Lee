#include<cstdio>
//#include<vector>
//using namespace std;

/**
http://code.bupt.edu.cn/problem/p/449/
输入数据8.2M 1ms 65536KiB
@status 手写快排 TLE
*/

int parti(int a[], int low, int high){
    int pvalue=a[low];
    while(low<high){
        while(low<high && a[high]>pvalue) high--;
        a[low]=a[high];
        while(low<high && a[low]<pvalue) low++;
        a[high]=a[low];
    }
    a[low]=pvalue;
    return low;
}

void qsort(int a[], int low, int high){
    if(low<high){
        int pivot=parti(a,low,high);
        qsort(a,low,pivot-1);
        qsort(a,pivot+1,high);
    }
}


/** sort [0,n) ascending */
void mysort(int a[],int n){
    qsort(a,0,n-1);
}

int main(){
    int n;
    int arr[500000];

    while(scanf("%d",&n)>0){
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }

        mysort(arr,n);

        for(int i=0;i<n-1;i++){
            printf("%d ",arr[i]);
        }
        printf("%d\n",arr[n-1]);
    }
}
