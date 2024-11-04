#include <bits/stdc++.h> 
using namespace std; 

int main(){
    int n; cin >> n; 
    vector<int> v(n); 

    map<int, int> posMag; 
    for(int i = 0; i < n; i++){
        int a; cin >> a; 
        if(!posMag.count(a)) v[i] = -1; 
        else v[i] = posMag[a]; 

        posMag[a] = i + 1; 
    }

    for(int i: v) cout << i << " "; 
    cout << endl; 
}