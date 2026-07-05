#include <iostream>
#include <vector>
using namespace std;

int c, n;
vector<int> w;
vector<int> suffix;   // suffix[i] 表示从第 i 个到第 n 个的总重量
vector<int> x, bestx;

int bestw = 0;

void update(int t, int cur)
{
    if (bestw < cur)
    {
        bestw = cur;

        // 前 t-1 个箱子已经决定了
        for (int i = 1; i < t; i++)
        {
            bestx[i] = x[i];
        }

        // 后面的箱子还没决定，默认不选
        for (int i = t; i <= n; i++)
        {
            bestx[i] = 0;
        }
    }
}

void backtrack(int t, int cur)
{
    // 如果刚好装满，直接更新并返回
    if (cur == c)
    {
        update(t, cur);
        return;
    }

    // 当前 cur 本身也是一个合法方案
    update(t, cur);

    // 所有箱子都考虑完了
    if (t > n)
    {
        return;
    }

    // 限界剪枝：
    // 当前重量 + 剩下所有箱子重量 都不能超过 bestw，就不用搜了
    if (cur + suffix[t] <= bestw)
    {
        return;
    }

    // 左子树：选择第 t 个箱子
    // 为了得到第一最优解，先选 1，再选 0
    if (cur + w[t] <= c)
    {
        x[t] = 1;
        backtrack(t + 1, cur + w[t]);
        x[t] = 0; // 回溯
    }

    // 右子树：不选择第 t 个箱子
    // 如果不选后还有可能超过 bestw，才继续搜
    if (cur + suffix[t + 1] > bestw)
    {
        x[t] = 0;
        backtrack(t + 1, cur);
    }
}

int main()
{
    cin >> c >> n;

    w.resize(n + 1);
    suffix.resize(n + 2);
    x.resize(n + 1, 0);
    bestx.resize(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }

    suffix[n + 1] = 0;
    for (int i = n; i >= 1; i--)
    {
        suffix[i] = suffix[i + 1] + w[i];
    }

    backtrack(1, 0);

    cout << bestw << endl;

    for (int i = 1; i <= n; i++)
    {
        if (bestx[i] == 1)
        {
            cout << i << ' ';
        }
    }

    cout << endl;

    return 0;
}