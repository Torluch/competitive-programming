#include <bits/stdc++.h>
using namespace std; 
int main(){
    int n = 4; 
    vector<int> v(n); 
    for(int &i: v) cin >> i; 
    sort(v.begin(), v.end()); 

    if(v[0] == v[1] && v[2] == v[3]){
        cout << 2 << endl;
        return 0; 
    }

    int diff = 0; 
    for(int i = 1; i < 4; i++){
        if(v[i] == v[i - 1]) diff = 1; 
    }

    cout << diff << endl; 
}
