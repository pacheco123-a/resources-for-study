#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while(cin>>n)
    {
        string line;
        getline(cin,line);

        vector<vector<int>> g(n);
        for(int i=0;i<n;)
        {
            getline(cin, line);
            if (line.empty()) continue;
            for(char &c:line)
            {
                if(c<'0'||c>'9')
                {
                    c=' ';
                }
            }
            stringstream ss(line);
            int u,k;
            ss>>u>>k;
            for(int j=0;j<k;j++)
            {
                int v;
                ss>>v;
                g[u].push_back(v);
                g[v].push_back(u);
            }
            i++;
        }
        vector<int> parent(n, -2);//记录父节点
        vector<int> order;//栈弹出的顺序
        for(int root=0;root<n;root++)
        {
            if(parent[root]!=-2) continue;
            parent[root]=-1;
            stack<int> st;
            st.push(root);
            while(!st.empty())
            {
                int u=st.top();
                st.pop();
                order.push_back(u);
                for(int v:g[u])
                {
                    if(parent[v]==-2)
                    {
                        parent[v]=u;
                        st.push(v);
                    }
                }
            } 
        }
        vector<bool> soldier(n, false);
        int ans=0;
        for(int i=order.size()-1;i>= 0;i--)
        {
            int u=order[i];
            int p=parent[u];
            if (p==-1) continue; // 根节点没有父亲
            // 如果 u 和 p 都没有士兵，那么边 u-p 没被覆盖
            if (!soldier[u] && !soldier[p]) {
                soldier[p] = true;
                ans++;
            }
        }
        cout << ans << '\n';
    }
}