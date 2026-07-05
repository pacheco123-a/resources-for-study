//dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+p)
//dp[i][i]=0
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<vector<int>> splitPos;
void display(int i,int j)
{
    if(i==j){
        cout<<'A'<<i;
        return;
    }
    cout<<'(';
    int k=splitPos[i][j];
    display(i,k);
    display(k+1,j);
    cout<<')';
}
int main(){
    int n;
    cin>>n;
    vector<vector<long long>> dp(n+1,vector<long long>(n+1,0));
    splitPos.assign(n+1,vector<int>(n+1,0));
    vector<long long> a(n+2);
    for(int i=1;i<=n+1;i++)
    {
        cin>>a[i];
    }
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            dp[i][j]=LLONG_MAX;
            for(int k=i;k<j;k++)
            {
                long long cost=dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1];
                if(cost<dp[i][j])
                {
                    dp[i][j]=cost;
                    splitPos[i][j]=k;//记录从i到j最小值是从k断开
                }
            }
        }
    }
    cout<<dp[1][n]<<endl;
    if(n==1){
        cout<<"(A1)";
    }else{
        display(1,n);
    }
    cout<<endl;
    return 0;
}
