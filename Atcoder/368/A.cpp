#include <bits/stdc++.h> 
using namespace std; 

int main(){
    int n, k; cin >> n >> k; 

    vector<int> v(n); 
    for(int &i: v) cin >> i; 

    vector<int> tmp; 
    for(int i = 0; i < k; i++){
        tmp.push_back(v[n - i - 1]);  
        v.pop_back();
    }

    reverse(tmp.begin(), tmp.end()); 

    for(int i: tmp) cout << i << " "; 

    for(int i: v) cout << i << " "; 
}
