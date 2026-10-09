#include <bits/stdc++.h>
using namespace std; 

int main(){
    int n; 
    cin >> n; 

    vector<int> v(n);
    for(auto &i: v) cin>>i; 

    sort(v.begin(), v.end()); 

    for(int i = 0; i < n; i++){
        if(v[i] != i){
            cout << i << "\n"; 
            return 0; 
        }
    }
}