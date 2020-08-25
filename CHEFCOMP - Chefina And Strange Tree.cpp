/*
    Author : Abdullah Al Nayem (BlackNerd)
    Problem : CHEFCOMP - Chefina and Strange Tree
    Problem link : https://www.codechef.com/problems/CHEFCOMP

*/

#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        200007

int n;
vector <ll> prefixSum, prefixDay;
vector <int> A(MAXN), B(MAXN), day(MAXN), res(MAXN), discovered(MAXN), parent(MAXN), graph[MAXN], nGraph[MAXN];

int Find(int u)
{
    return parent[u] = (parent[u] == u ? u : Find(parent[u]));
}

void unite(int u, int v)
{
    v = Find(v);
    parent[v] = u;
    nGraph[u].push_back(v);
}

void dfs(int node)
{
    prefixSum.push_back(prefixSum.size() ? prefixSum.back() + A[node] : A[node]);
    prefixDay.push_back(day[node]);

    int idx = lower_bound(prefixSum.begin(), prefixSum.end(), B[node]) - prefixSum.begin();
    res[node] = idx == prefixSum.size() ? -2 : prefixDay[idx];

    for (auto x : nGraph[node])
        dfs(x);

    prefixSum.pop_back(); prefixDay.pop_back();
}

void init(int lim)
{
    prefixSum.clear(); prefixDay.clear();
    for (int i = 0; i <= lim; ++i)
        discovered[i] = 0, parent[i] = i, graph[i].clear(), nGraph[i].clear();
}

int main ()
{
    __Mammamia__

    int test_case; cin >> test_case;
    while(test_case--)
    {
        cin >> n; init(n);

        for (int i = 1; i < n; ++i)
        {
            int u, v; cin >> u >> v; u--; v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector <int> serial(n);

        for (int i = 0; i < n; ++i) {cin >> serial[i]; --serial[i];}
        for (int i = 0; i < n; ++i) cin >> A[i];
        for (int i = 0; i < n; ++i) cin >> B[i];

        for (int x = n - 1; x >= 0; --x)
        {
            day[serial[x]] = x;

            for (auto i : graph[serial[x]])
                if (discovered[i])
                    unite(serial[x], i);

            discovered[serial[x]] = 1;
        }

        dfs(serial[0]);

        for (int i = 0; i < n; ++i) cout << res[i] + 1 << " "; cout << endl;
    }
    return 0;
}
