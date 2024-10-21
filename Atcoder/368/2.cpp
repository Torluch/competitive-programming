#include <bits/stdc++.h> 
using namespace std; 

int main(){
    int n; cin >> n; 
    
    vector<int> v(n); 
    for(int &i: v) cin >> i; 

    int cnt = 0; 
    while(1){
        sort(v.rbegin(), v.rend()); 
        if(v[0] == 0 || v[1] == 0) break; 

        v[0]--; 
        v[1]--; 
        cnt++; 
    }

    cout << cnt << endl; 
}