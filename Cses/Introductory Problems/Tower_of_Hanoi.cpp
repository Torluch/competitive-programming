#include <bits/stdc++.h> 
using namespace std; 

int main(){
    int n; cin >> n; 
    
    vector<pair<int, int>> v; 

    function<void (int, int, int, int)> f = [&](int n, int start, int end, int intermedium)  {
        if(n == 1) {
            v.push_back({start + 1, end + 1});
            return;  
        }

        f(n - 1, start, intermedium, end); 
        v.push_back({start + 1, end + 1});
        f(n - 1, intermedium, end, start);  
    }; 
    
    f(n, 0, 2, 1); 

    cout << v.size() << endl; 
    for(auto i: v) cout << i.first << " " << i.second << endl; 
}
