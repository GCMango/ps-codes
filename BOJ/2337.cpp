#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, M;
vector<vector<int>> graph;
vector<vector<int>> dp;
vector<int> cnt;
vector<int> tmp;

void solve(int cur, int pnode) {
    dp[cur][1] = 0;
    for (auto next : graph[cur]) {
        if (next == pnode) continue;
        solve(next, cur);
        for (int i = 1; i <= cnt[cur]; ++i) {
            for (int j = 0; j <= cnt[next]; ++j) {
                if (j)
                    tmp[i + j] = min(tmp[i + j], dp[cur][i] + dp[next][j]);
                else
                    tmp[i + j] = min(tmp[i + j], dp[cur][i] + 1);
            }
        }
        cnt[cur] += cnt[next];
        for (int i = 1; i <= N; ++i) {
            dp[cur][i] = tmp[i];
            tmp[i] = 1e9;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    graph.resize(N + 1);
    cnt.resize(N + 1, 1);
    tmp.resize(N + 1, 1e9);
    dp.resize(N + 1, vector<int>(N + 1, 1e9));
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    solve(1, 0);

    int mn = 1e9;
    for (int i = 1; i <= N; ++i)
        mn = min(mn, dp[i][M] + (i == 1 ? 0 : 1));

    cout << (mn == 1e9 ? -1 : mn) << '\n';

    return 0;
}
