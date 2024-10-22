#include <bits/stdc++.h>
using namespace std; 

int main(){
    int n; cin >> n; 
    
    vector<char> v(n); 
    for(char &i: v) cin >> i; 

    int ans = 0; 
    for(int i = 1; i < n - 1; i++){
        if(v[i] == '#') continue; 

        if(v[i - 1] == v[i + 1] && v[i - 1] == '#') ans++; 
    }

    cout << ans << endl; 
}
