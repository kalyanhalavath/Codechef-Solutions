#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int 
#define pb push_back
#define MAX 1000006
#define ff first
#define ss second
#define endl '\n'
ll mod  = 1e9 + 7;
ll fac[MAX];
void fill(){
	fac[0] = 1;
	for(int i = 1; i < MAX; i++){
		fac[i] = (fac[i - 1] * i) % mod;
	}
}
ll p(ll x, ll m){
	if(m == 0){
		return 1;
	}
	else if(m % 2){
		return (x * p(x, m - 1)) % mod;
	}
	else{
		ll dum = p(x, m / 2);
		return (dum * dum) % mod;
	}
}
ll modi(ll x){
	return p(x, mod - 2);
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll q = 1;
	cin >> q;
	fill();
	while(q--){
	ll n;
	cin >> n;
	ll out = 0, a[2 * n];
	unordered_map<ll, ll> m;
	m.reserve(2 * n);
	for(int i = 0; i < 2 * n; i++){
		cin >> a[i];
		out += a[i];
		if(!m.count(a[i])){
			m.insert({a[i], 1});
		}
		else{
			m[a[i]]++;
		}
	}
	out /= (n + 1);
	if(m[out] < 2){
		cout << 0 << endl;
		continue;
	}
	m[out] -= 2;
	vector<ll> diff;
	vector<ll> same;
	bool pos = 1;
	for(auto x:m){
		ll key = x.ff;
		ll val = x.ss;
		if(val != 0){
		if(key == out / 2 && out % 2 == 0){
			if(val % 2){
				cout << 0 << endl;
				pos = false;
				break;
			}
			else{
				same.pb(val / 2);
			}
		}
		else if(val == m[out - key]){
			//cout << key << endl;
			m[out - key] -= val;
			diff.pb(val);
		}
		else{
			cout << 0 << endl;
			pos = false;
			break;
		}
	}}
	if(pos){
		ll denom = 1;
		ll num = fac[n - 1];
		for(int i = 0;i < diff.size(); i++){
			denom = (denom * fac[diff[i]]) % mod;
		}
		for(int i = 0;i < same.size(); i++){
			denom = (denom * fac[same[i]]) % mod;
		}
		num = (num * modi(denom)) % mod;
		for(int i = 0; i < diff.size(); i++){
			num = (num * p(2, diff[i])) % mod;
		}
		cout << num << endl;
	}
}}
