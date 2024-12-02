#include <bits/stdc++.h> 
using namespace std; 

int main(){
    int n; cin >> n; 
    
    vector<string> ans; 

    function<string (int, string)> merge = [&](int pos, string suffix) -> string {
        if(pos == suffix.size()) return ("1" + suffix); 
        return merge(pos, "0" + suffix); 
    }; 

    function<string (string)> fill = [&](string suffix) -> string {
        if(suffix.size() == n) return suffix; 
        return fill("0" + suffix); 
    }; 

    function<void (int)> f = [&](int n) {
        if(n == 1){
            ans.push_back("0"); 
            ans.push_back("1"); 
            return; 
        }

        f(n - 1); 

        int sz = ans.size(); 
        for(int i = sz - 1; i >= 0; i--) ans.push_back(merge(n - 1, ans[i])); 
    };

    f(n); 

    for(auto i: ans){
        cout << fill(i) << endl; 
    }
}
