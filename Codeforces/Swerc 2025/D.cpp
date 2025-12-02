#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n; 
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    map<int, int> freq;
    for(int x : a) freq[x]++;

    int ans = 0; 
    for(auto [val, count] : freq){
        if(val != count){
            if(count > val){
                ans += count - val; 
            } else {
                ans += count; 
            }
        }  
    }
    cout << ans << endl; 
}

int main(){
    int t; cin >> t; 
    while(t--){
        solve(); 
    }
}