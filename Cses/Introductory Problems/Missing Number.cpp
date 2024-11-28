#include <bits/stdc++.h>
using namespace std; 
#define int long long

int32_t main(){
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;

    vector<int> v(n + 1); 
    for(int i = 0; i < n - 1; i++){
        int a; cin >> a; 
        v[a]++; 
    }

    int mex = 0; 
    for(int i = n; i > 0; i--) if(v[i] == 0) mex = i;   
    cout << mex << endl; 
}