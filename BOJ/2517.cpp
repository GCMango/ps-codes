#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define compress(x) sort(all(x)), (x).erase(unique(all(x)), (x).end())
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, v[500005], a[500005], b[500005], ans[500005];
vector<int> comp;

void dfs(int s, int e) {
    if (s == e) return;

    int m = (s + e) / 2;
    dfs(s, m); dfs(m + 1, e);

    int i = s, j = m + 1, idx = s, cnt = 0;
    while (i <= m || j <= e) {
        if (i > m)
            b[idx++] = a[j++];
        else if (j > e)
            b[idx++] = a[i++];
        else if (a[i] >= a[j])
            b[idx++] = a[i++];
        else {
            b[idx++] = a[j];
            ans[a[j]] += j - i - cnt;
            j++; cnt++;
        }
    }

    for (i = s; i <= e; ++i) a[i] = b[i];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

	cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
        comp.push_back(v[i]);
    }

    compress(comp);

    for (int i = 1; i <= N; ++i) {
        int pos = lower_bound(all(comp), v[i]) - comp.begin();
        v[i] = a[i] = pos + 1;
    }

    dfs(1, N);

    for (int i = 1; i <= N; ++i)
        cout << i - ans[v[i]] << '\n';
    
    return 0;
}
