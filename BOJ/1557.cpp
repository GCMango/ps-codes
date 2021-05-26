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

const ll MAX = 200000;

ll arr[MAX + 1];

void setup() {
    arr[1] = 1;
    for (ll i = 1; i <= MAX; ++i)
        for (ll j = i * 2; j <= MAX; j += i)
            arr[j] -= arr[i];
}

ll solve(ll n) {
    ll cnt = 0;
    for (ll i = 1; i * i <= n; ++i)
        cnt += arr[i] * n / (i * i);
    return n - cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    setup();
    ll N;
    cin >> N;

    ll s = 0, e = N * 4;
    while (s < e - 1) {
        ll mid = (s + e) / 2;
        if (solve(mid) < N) s = mid;
        else e = mid;
    }

    cout << e << '\n';

    return 0;
}
