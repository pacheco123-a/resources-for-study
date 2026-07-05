#include<iostream>
#include<vector>
using namespace std;
//dp[n][n],dp[i][j]=a[i][j]+max{dp[i-1][j],dp[i-1][j-1]}
int main(){
    int n;
    cin >>n;
    int a[105][105];//记录每个值
    int dp[105][105];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin>> a[i][j];
        }
    }
    dp[1][1]=a[1][1];
    for(int i=2;i<=n;i++)//从第二行开始
    {
        for(int j=1;j<=i;j++)
        {
            if(j-1==0)
            {
                dp[i][j]=a[i][j]+dp[i-1][j];
            }
            else if(i==j)
            {
                dp[i][j]=a[i][j]+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=a[i][j]+max(dp[i-1][j],dp[i-1][j-1]);
            }
        }
    }
    int ans=dp[n][1];
    for(int j=2;j<n;j++)
    {
        ans=max(ans,dp[n][j]);
    }
    cout<<ans<<endl;
    return 0;
}