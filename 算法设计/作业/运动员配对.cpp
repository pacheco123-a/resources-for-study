//定义解向量x[i]=j表示第i个男生和第j个女生配对，每层有n个可选
//约束函数：x[i]!=x[j]不同男生不能选一个女生
#include<iostream>
using namespace std;
int n;
int P[15][15],Q[15][15],score[15][15];
int rowmax[15],sufmax[16];
int best=0;
int used[15];
void dfs(int t,int cur)
{
    if(t==n)
    {
        best=max(best,cur);
        return;
    }
    if(cur+sufmax[t]<=best)
    {
        return;
    }
    for(int j=0;j<n;j++)
    {
        if(!used[j])
        {
            used[j]=1;
            dfs(t+1,cur+score[t][j]);
            used[j]=0;
        }
    }
}
int main()
{
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>P[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>Q[i][j];
        }
        used[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        rowmax[i]=0;
        for(int j=0;j<n;j++)
        {
            score[i][j]=P[i][j]*Q[j][i];//第i个男生和第j个女生
            rowmax[i]=max(score[i][j],rowmax[i]);
        }
    }
    sufmax[n]=0;
    for(int i=n-1;i>=0;i--)
    {
        sufmax[i]=sufmax[i+1]+rowmax[i];
    }
    dfs(0,0);
    cout<<best<<endl;
    return 0;
}