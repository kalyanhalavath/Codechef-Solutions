#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb push_back
//vector<int> d1(n);

int main(){
	ll q = 1;
	cin >> q;
	while(q--){
	ll n, m;
	cin >> n >> m;
	ll a[n][m], b[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			//b[j][i] = a[i][j];
		}
	}
	int d[n][m], d2[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			d[i][j] = 1000000;
			d2[i][j] = 1000000;
		}
	}
	
	for(int i1 = 0; i1 < n; i1++){
		vector<ll> s;
		for(int j = 0; j < m; j++){
			s.pb(a[i1][j]);
		}
		for (int i = 0, l = 0, r = -1; i < m; i++) {
    int k = (i > r) ? 1 : min(d[i1][l + r - i], r - i + 1);
    while (0 <= i - k && i + k < m && s[i - k] == s[i + k]) {
        k++;
    }
    d[i1][i] = k--;
    if (i + k > r) {
        l = i - k;
        r = i + k;
    }
}
	}
	//int d2[n][m];
	
	for(int i1 = 0; i1 < m; i1++){
		vector<ll> s;
		for(int j = 0; j < n; j++){
			s.pb(a[j][i1]);
		}
		for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 1 : min(d2[l + r - i][i1], r - i + 1);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
        k++;
    }
    d2[i][i1] = k--;
    if (i + k > r) {
        l = i - k;
        r = i + k;
    }
}
	}
	ll out = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			out += min(d[i][j],d2[i][j]);
		}
	}
	cout << out << endl;

}}
