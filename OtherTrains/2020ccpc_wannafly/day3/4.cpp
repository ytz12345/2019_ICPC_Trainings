#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, k) for (int i = int(j); i <= int(k); ++ i)
typedef long long ll;
const int N = 1e6 + 7;
int pr[N], phi[N]; 
bool isp[N];
ll mod, pre[N]; 
map<int, ll> mp;
const __int128 one = 1;

void sieve() {
	memset(isp, 1, sizeof(isp));
	phi[1] = 1;
	rep(i, 2, N - 1) {
		if (isp[i]) { 
			pr[++ pr[0]] = i; phi[i] = i - 1; 
		}
		rep(j, 1, pr[0]) {
			if (1ll * i * pr[j] >= N) break;
			isp[i * pr[j]] = 0;
			phi[i * pr[j]] = phi[i] * (pr[j] - 1);
			if (i % pr[j] == 0) {
				phi[i * pr[j]] = phi[i] * pr[j];
				break;
			}
		}
	}
	rep(i, 1, N - 1) phi[i] %= mod;
	rep(i, 1, N - 1) pre[i] = (pre[i - 1] + phi[i]) % mod;
}
ll qpow(ll a, ll b) {
	ll c = 1;
	while (b) {
		if (b & 1) c = c * a % mod;
		a = a * a % mod; b >>= 1;
	}
	return c;
}
ll f(ll n) {
	return (one * n * (n + 1) * (2 * n + 1) / 6) % mod;
}
inline ll calc(ll n) {
    if (n < N) return pre[n];
    if (mp.count(n)) return mp[n];
    ll m = sqrt(n + 0.5), ret = (one * n * (n + 1) / 2) % mod;

    // rep(i, 2, n / m) ret += mod - calc(n / i), ret %= mod;
    // rep(i, 1, m - 1) ret += 1ll * ((n / i) - (n / (i + 1)) + mod) * calc(i) % mod, ret %= mod;
    for (ll l = 2, r; l <= n; l = r + 1) {
    	r = n / (n / l);
    	ret += mod - 1ll * (r - l + 1) * calc(n / l) % mod; 
    	ret %= mod;
    }
    return mp[n] = ret;
}

int main() {
	int n;
	cin >> n >> mod;
	sieve();
    ll ans = 0;
	for (ll l = 1, r; l <= n; l = r + 1) {
		r = n / (n / l);
        //cout << n / l << ' ' << f(n / l) << endl;
		ans += f(n / l) * (calc(r) - calc(l - 1) + mod) % mod;
		ans %= mod;
	}
	cout << ans << endl;
}