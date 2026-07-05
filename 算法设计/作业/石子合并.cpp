#include<iostream>
#include<vector>
#include <climits>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long> a(2*n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i];
    }
    vector<long long> prefix(2*n+1,0);
    for(int i=1;i<=2*n;i++)
    {
        prefix[i]=prefix[i-1]+a[i];
    }
    vector<vector<long long>> dpMin(2*n+1,vector<long long>(2*n+1,0));
    vector<vector<long long>> dpMax(2*n+1,vector<long long>(2*n+1,0));
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i+len-1<=2*n;i++)
        {
            int j=i+len-1;
            long long sum=prefix[j]-prefix[i-1];
            dpMax[i][j]=LLONG_MIN;
            dpMin[i][j]=LLONG_MAX;
            for(int k=i;k<j;k++)
            {
                dpMin[i][j]=min(dpMin[i][j],dpMin[i][k]+dpMin[k+1][j]+sum);
                dpMax[i][j]=max(dpMax[i][j],dpMax[i][k]+dpMax[k+1][j]+sum);
            }
        }
    }
    long long ansMin = LLONG_MAX;
    long long ansMax = LLONG_MIN;
    for(int i=1;i<=n;i++)
    {
        ansMin=min(ansMin,dpMin[i][i+n-1]);
        ansMax=max(ansMax,dpMax[i][i+n-1]);
    }
    cout<<ansMin<<endl<<ansMax<<endl;
    return 0;
}