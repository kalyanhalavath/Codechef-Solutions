#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int 
#define pb push_back
#define MAX 1000006
#define ff first
#define ss second
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll q = 1;
	cin >> q;
	while(q--){
	ll n;
	cin >> n;
	ll out[n][n];
	if(n == 1){
		cout << "Hooray" << endl;
		cout << 1 << endl;
		continue;
	}
	else if(n % 2){
		cout << "Boo" << endl;
		continue;
	}
	else{
		cout << "Hooray" << endl;
		for(int i = 0; i < n; i++){
			out[i][i] = n;
		}
		for(int i = 1; i < n; i++){
			out[i][0] = i;
			//cout << out[i][0] << endl;
		}
		for(int j = 1; j < n; j++){
			ll used[n + 1] = {};
			for(int i = 0; i < j; i++){
				used[out[j][i]] = 1;
			}
			ll first = (2 + out[j][j - 1]) % (n - 1);
			//cout << first << "wtf" << endl;
			if(first == 0){
				first += n - 1;
			}
			//cout << first << "wtf" << endl;
			vector<ll> use;
			for(int i = first; i <= n - 1; i++){
				if(!used[i]){
					use.pb(i);
				}
			}
			for(int i = 1; i < first; i++){
				if(!used[i]){
					use.pb(i);
				}
			}
			ll start = j + 1;
			while(start < n){
				out[start][j] = use[start - j - 1];
				start++;
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i < j){
					out[i][j] = 2 * n - out[j][i];
				}
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << out[i][j] << " ";
			}
			cout << endl;
		}
	}
}}
