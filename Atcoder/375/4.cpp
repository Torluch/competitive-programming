#include <bits/stdc++.h> 
using namespace std; 

#define int long long

int32_t main(){
    string s; cin >> s; 
    
    vector<int> ans(s.size()); 
    map<char, pair<int, int>> pos_viste; 
    for(int i = 0; i < s.size(); i++){
        char a = s[i]; 
        if(!pos_viste.count(a)){
            pos_viste[a] = {i, 1}; 
            continue;
        }

        int pos = pos_viste[a].first;
        int quante = pos_viste[a].second; 
        ans[i] = ans[pos] + 1 * (i - pos - 1) + (quante - 1) * (i - pos); 

        pos_viste[a] = {i, quante + 1}; 
    }

    int sol = 0; 
    for(int i: ans) sol += i;


    cout << sol << endl;  
}