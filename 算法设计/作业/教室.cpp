#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>> N;
    vector<long long> s(N),e(N);
    for(int i=0;i<N;i++)
    {
        cin>>s[i]>>e[i];
    }
    sort(s.begin(),s.end());
    sort(e.begin(),e.end());
    int i=0,j=0;
    int current=0;
    int ans=0;
    while(i<N)
    {
        if(s[i]<e[j])
        {
            current++;
            ans=max(ans,current);
            i++;
        }
        else
        {
            current--;
            j++;
        }
    }
    cout<<ans<<endl;
    return 0;
}