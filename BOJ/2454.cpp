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

int N, K, cnt[300001], dp[300001];
vector<vector<int>> graph;

void solve(int cur, int pnode) {
    cnt[cur] = dp[cur] = 1;
    for (auto next : graph[cur]) {
        if (next == pnode) continue;
        solve(next, cur);
        cnt[cur] += cnt[next];
        dp[cur] += dp[next];
    }
    dp[cur] = dp[cur] / K + dp[cur] % K;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K; K++;
    graph.resize(N + 1);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    solve(1, 0);

    cout << dp[1] << '\n';

    return 0;
}
