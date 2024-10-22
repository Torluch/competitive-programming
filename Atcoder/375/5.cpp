#include <bits/stdc++.h> 
using namespace std; 
int main(){ 
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n; 
    vector<int> a(n), b(n); 

    int sum = 0; 
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i], sum += b[i];   
    
    int target = sum / 3; 
    if(target * 3 != sum){
        cout << -1 << endl; 
        return 0;
    }

    vector<vector<vector<int>>> memo(n + 1, vector<vector<int>> (target + 1, vector<int> (target + 1, -1))); 

    function<int (int, int, int)> f = [&] (int i, int sumA, int sumB) -> int {
        if(sumA > target || sumB > target) return 1e9; 
        if((i >= n) && (sumA != target || sumB != target)) return 1e9; 
        if((i >= n)) return 0; 

        if(memo[i][sumA][sumB] != -1) return memo[i][sumA][sumB]; 

        int inA = (a[i] != 1) + f(i + 1, sumA + b[i], sumB); 
        int inB = (a[i] != 2) + f(i + 1, sumA, sumB + b[i]); 
        int inC = (a[i] != 3) + f(i + 1, sumA, sumB); 

        return memo[i][sumA][sumB] = min(inA, min(inB, inC)); 

    };

    int ans = f(0, 0, 0); 
    cout << ((ans >= 1e9) ? -1: ans) << endl;
}
