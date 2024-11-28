#include <bits/stdc++.h>
using namespace std; 
#define int long long

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s; cin >> s; 
    int n = s.size(); 

    vector<int> len(n); 
    char last = 'Z'; 
    for(int i = 0; i < n; i++){
        char a = s[i]; 
        if(a == last) len[i] = len[i - 1] + 1; 
        else len[i] = 1; 
        
        last = a; 
    }

    int ans = 0; 
    for(int i: len) ans = max(ans, i); 
    cout << ans << endl;
}