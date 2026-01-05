#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n; cin >> n; 
    vector<int> r(n);
    for(auto &x : r) cin >> x;

    vector<int> b(n);
    for(auto &x : b) cin >> x;

    vector<double> avarage(n);
    for(int i = 0; i < n; i++){
        avarage[i] = (r[i] + b[i]) / 2.0;
    }
    
    vector<pair<int, int>> results(n + 1, {0, 0});

    int last = 0; 
    for(int i = 0; i < n; i++){
        last = abs(avarage[i] - results[i].first) > abs(avarage[i] - results[i].second) ? results[i].first: results[i].second;
        results[i + 1].first = last - r[i];
        results[i + 1].second = b[i] - last;
    }

    cout <<  max(results[n].first, results[n].second) << endl;
}

int32_t main(){
    int t; cin >> t;
    while(t--){
        solve(); 
    }
}