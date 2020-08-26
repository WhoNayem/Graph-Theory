#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        1000007

int n, root, total, target;
vector <int> res, sum(MAXN, 0), graph[MAXN];

bool dfs(int node, int parent)
{
    for (auto x : graph[node])
        if (x != parent)
            if (!dfs(x, node))
                sum[node] += sum[x];

    if (node != root && sum[node] == target) {res.push_back(node); return true;}
    return false;
}

int main ()
{
    __Mammamia__

    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        int node, val; cin >> node >> val;
        if (node) graph[i].push_back(node), graph[node].push_back(i);
        else root = i;
        total += sum[i] = val;
    }

    if (total % 3) {cout << -1 << endl; return 0;}

    target = total / 3;
    dfs(root, -1);

    if (res.size() > 1) cout << res[0] << " " << res[1] << endl;
    else cout << -1 << endl;



    return 0;
}
