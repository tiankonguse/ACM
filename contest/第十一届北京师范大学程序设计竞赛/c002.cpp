#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll phi(ll n) {
	ll ret = n;
	for(ll i = 2; i * i <= n; i += 2) {
		if(!(n % i)) {
			ret = ret / i * (i - 1);
			while(n % i == 0) n /= i;
		}
		if(i == 2) --i;
	}
	if(n > 1) ret = ret / n * (n - 1);
	return ret;
}

ll powMod(ll a, ll b, ll c) {
	ll ret = 1 % c;
	for(; b; a = a * a % c, b >>= 1)
		if(b & 1) ret = ret * a % c;
	return ret;
}

ll pow(vector<ll> &v, ll mod) {
	ll a, b = 1;
	for(int i = v.size() - 1; i >= 0; i--) {
		a = v[i];
		ll ret = 1;
		for(; b; a *= a, b >>= 1) {
			if(b & 1)
				ret *= a;
			if(ret >= mod || a >= mod){
				return -1;
			}
		}
		b = ret;
	}
	return b;
}

ll powMod(vector<ll> &v, ll mod) {
	if(v.empty())return 1;
	ll phi_mod = phi(mod);
	ll a = v.front();
	v.erase(v.begin());
	ll b = pow(v, phi_mod);
	if(b == -1)
		b = powMod(v, phi_mod) % phi_mod + phi_mod;
	return powMod(a, b , mod);
}


int main() {
	int t;
	cin >> t;
	while(t--) {
		ll n, p;
		cin >> n >> p;
		vector<ll> v;
		bool ok=false;
		for(int i = 0; i < n; i++) {
			ll tmp;
			cin >> tmp;
			if(tmp == 1)ok = true;
			if(ok)continue;
			v.push_back(tmp);
		}
		cout << powMod(v, p) << endl;
	}
	return 0;
}
