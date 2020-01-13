#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb push_back
void print(ll val){
	if(val == 0){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
}
int main(){
	ll q = 1;
	//cin >> q;
	while(q--){
		ll n, t;
		cin >> n >> t;
		ll a[n], pre1[n], pre2[n], sing1[n], sing2[n];
		pre1[0] = 1;
		pre2[0] = 1;
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		if(a[0] > a[1]){
			sing1[0] = 1;
			sing2[0] = 0;
		}
		else{
			sing1[0] = 0;
			sing2[0] = 1;
		}
		for(int i=1;i<n-1;i++){
			if(a[i-1]>a[i]&&a[i]>a[i+1]){
				sing1[i] = sing1[i-1] + 1;
			}
			else{
				sing1[i]  = sing1[i-1];
			}
			if(a[i-1] < a[i]&&a[i] < a[i+1]){
				sing2[i] = sing2[i - 1] + 1;
			}
			else {
				sing2[i] = sing2[i-1];
			}
		}
		//ll cur1 = 1, cur2 = 1;
		for(int i = 1; i < n; i++){
			if(a[i] > a[i - 1]){
				pre1[i] = pre1[i - 1];
			}
			else{
				pre1[i] = pre1[i - 1] + 1;
				//cur1 = 1;
			}
			if(a[i] < a[i - 1]){
				pre2[i] = pre2[i - 1];
			}
			else{
				pre2[i] = pre2[i - 1] + 1;
				//cur2 = 1;
			}
		}
			while(t--){
			ll l, r;
			cin >> l >> r;
			l--;r--;
			ll cnt1, cnt2;
			if(l == 0){
				cnt1 = pre1[r];
				cnt2 = pre2[r];
			}
			else{
				if(a[l - 1] < a[l]){
					cnt1 = pre1[r] - pre1[l - 1] + 1;
					cnt2 = pre2[r] - pre2[l - 1];
				}
				else{
					cnt1 = pre1[r] - pre1[l - 1];
					cnt2 = pre2[r] - pre2[l - 1] + 1;
				}
			}
			if(r - l == 1){
				cout << "NO" << endl;
			}
			else{
				cnt1 -= (sing1[r - 1] - sing1[l]);
				cnt2 -= (sing2[r - 1] - sing2[l]);
				if(a[l] < a[l + 1]){
					cnt2 --;
				}
				else{
					cnt1--;
				}
				if(a[r-1] < a[r]){
					cnt2--;
				}
				else{
					cnt1--;
				}
				print(cnt1-cnt2);
			}
			//print((cnt1 - cnt2));
		}

	}
}
