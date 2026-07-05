#include<iostream>
#include<vector>
using namespace std;
//dp[i]是从1到i的最小，dp[j]=min(dp[i]+r[i][j])
int main(){
    int n;
    cin>>n;

    vector<vector<int>> r(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            cin>>r[i][j];
        }
    }
    const int INF=1e9;
    vector<int> dp(n+1,INF);
    dp[1]=0;
    for(int j=2;j<=n;j++)
    {
        for(int i=1;i<j;i++)
        {
            dp[j]=min(dp[j],dp[i]+r[i][j]);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}