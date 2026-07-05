#include<stdio.h>
#include<stdlib.h>
#define MAX 2000000
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void insertion_sort(int a[],int l,int r)//插入排序
{
    for (int i=l+1;i<=r;i++)
    {
        int key=a[i];
        int j=i-1;
        while(j>=l&&a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int select(int ar[],int l,int r,int k)
{
    while(1)
    {
        if(r-l+1<=75)
        {
            insertion_sort(ar,l,r);
            return ar[k];
        }
        int num=0;
        for(int i=l;i<=r;i+=5)//五个一组求出每组的中位数并依次放在数组的前面
        {
            int right=i+4;
            if(right>r) right=r;
            insertion_sort(ar,i,right);
            int mid=(i+right)/2;
            swap(&ar[mid],&ar[l+num]);
            num++;
        }
        int pivot=select(ar,l,l+num-1,l+num/2);
        int less=l;
        int greater=r;
        int i=l;
        while(i<=greater)
        {
            if(ar[i]<pivot)
            {
                swap(&ar[i],&ar[less]);
                less++;
                i++;
            }
            else if(ar[i]>pivot)
            {
                swap(&ar[i],&ar[greater]);
                greater--;
            }
            else i++;
        }
        if(k<less) r=less-1;
        else if(k>greater) l=greater+1;
        else return pivot;
    }
}
int main(void){
    int x,y,n=0;
    int *ar=(int*)malloc(sizeof(int)*MAX);
    while (scanf(" %d %*[, ] %d",&x,&y)==2)
    {
        ar[n++]=y;//n是油井的个数
    }
    if(n==0)
    {
        free(ar);
        return 0;
    }
    int k=(n-1)/2;
    int ans=select(ar,0,n-1,k);
    printf("%d\n",ans);
    free(ar);
    return 0;
}
