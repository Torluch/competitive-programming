#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<string> v(n); 
    for(auto &s: v) cin >> s; 


    function< pair<int, int> (string&, string&)> getarch = [&] (string & first, string & second) -> pair<int, int> {
        for(int i = 0; i < first.size(); i++){
            if(second.size() <= i) return {-1, 1}; 
            if(first[i] != second[i]){
                return {first[i] - 'a', second[i] - 'a'};
            }
        }
        return {-1, -1};
    };

    vector<vector<int>> g(26); 
    vector<int> indegree(26, 0);
    for(int i = 0; i < v.size() - 1; i++){
        auto [start, end] = getarch(v[i], v[i + 1]); 
        if(start == -1 && end == 1){
            cout << "Impossible\n"; 
            return 0; 
        }
        if(start == -1 && end == -1){
            continue;
        }


        g[start].push_back(end);
        indegree[end]++;
    }

    queue<int> q;
    for(int i = 0; i < 26; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
        
    vector<int> ans;
    while(!q.empty()){
        int node = q.front(); q.pop(); 
        ans.push_back(node);
        
        for(auto &child: g[node]){
            indegree[child]--;
            if(indegree[child] == 0){
                q.push(child);
            } 
        }
    }

    vector<char> remaining;
    for(auto &x: ans){
        remaining.push_back((char)(x + 'a'));
    }
    if(remaining.size() < 26){
        cout << "Impossible\n";
        return 0; 
    }

    for(auto &x: remaining){
        cout << x; 
    }
    cout << "\n";
    
}