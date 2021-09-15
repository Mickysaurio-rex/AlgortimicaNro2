#include <bits/stdc++.h>

using namespace std;
 
#define N 128
int cap[N][N], padres[N], n, s, t;
 
bool bfs() {
    queue<int> q;
    q.push(s);
    memset(padres, -1, sizeof padres);
    padres[s] = s;
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (u == t)
            return true;
        for (int v = 0; v < n; ++v)
            if (padres[v] == -1 && cap[u][v])
                padres[v] = u, q.push(v);
    }
    return false;
}
 
int maxFlow() {
    int mf = 0, f, v;
    while (bfs()) {
        // min
        v = t;
        f = numeric_limits<int>::max();
        while (padres[v] != v)
            f = min(f, cap[padres[v]][v]), v = padres[v];
        // update
        v = t;
        mf += f;
        while (padres[v] != v)
            cap[padres[v]][v] -= f, cap[v][padres[v]] += f, v = padres[v];
    }
    return mf;
}
 
#define con(i, j, c) cap[i][j] += c, cap[j][i] += c
int main() {
    int c, caseI = 0;
    while (scanf("%d", &n) == 1 && n) {
        // input
        memset(cap, 0, sizeof cap);
        scanf("%d %d %d", &s, &t, &c);
        --s, --t;
        for (int i = 0, x, y, z; i < c; ++i)
            scanf("%d %d %d", &x, &y, &z), con(x - 1, y - 1, z);
        // solve
        printf("Network %d\n", ++caseI);
        printf("The bandwidth is %d.\n\n", maxFlow());
    }
    return 0;
}