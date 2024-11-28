#include <bits/stdc++.h>
using namespace std; 
#define int long long

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n; 


    if(n <= 3 && n != 1) {
        cout << "NO SOLUTION \n"; 
        return 0; 
    }

    for(int i = 2; i <= n; i += 2){
        cout << i << " "; 
    }
    for(int i = 1; i <= n; i += 2){
        cout << i << " "; 
    }
}