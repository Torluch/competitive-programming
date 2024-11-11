#include <bits/stdc++.h> 
using namespace std; 

struct st{
    struct Node {
        int val = 0; 
        void join(const Node &l, const Node &r){
            val = max(l.val, r.val); 
        }
    }; 

    vector<Node> v;
    int sz = 1; 

    void init(int n, vector<int> &a){
        while(sz < n) sz *= 2; 

        int real_size = n; 
        v.resize(2*sz, Node()); 

        build(1, 0, sz, a); 
    }

    void build(int u, int l, int r, vector<int>  &a){
        if(l == r - 1){
            if(l < a.size()){
                v[u].val = a[l]; 
            }
            return; 
        }

        int mid = l + (r - l) / 2; 
        build(2*u, l, mid, a); 
        build(2*u + 1, mid, r, a); 

        v[u].join(v[2*u], v[2*u + 1]); 
    }

    int mx_get(int u, int l, int r, int x, int y){
        if(l >= y || r <= x) return 0; 
        if(l >= x && r <= y){
            return v[u].val; 
        }

        int mid = l + (r - l) / 2; 
        return max(mx_get(2*u, l, mid, x, y), mx_get(2*u + 1, mid, r, x, y)); 
    }

    int left_most(int u, int l, int r, int x, int y, int val){
        int mid = l + (r - l) / 2;
        if(l >= y || r <= x) return 1e9; 
        if(l >= x && r <= y){
            if(l == r - 1) {
                if(v[u].val >= val) return l; 
                else return 1e9; 
            }
            
            if(v[2*u].val >= val) return left_most(2*u, l, mid, x, y, val); 
            if(v[2*u + 1].val >= val) return left_most(2*u + 1, mid, r, x, y, val);
            return 1e9; 
        }

        return min(left_most(2*u, l, mid, x, y, val), left_most(2*u + 1, mid, r, x, y, val)); 
    }


    int ind_mag_sx(int l, int r){
        r = r + 1; 
        int mx = mx_get(1, 0, sz, l + 1, r);

        return left_most(1, 0, sz, r, sz, mx); 
    }
}; 

int main(){
    int n, q; 
    cin >> n >> q;  

    vector<int> v(n); 
    for(int &i: v) cin >> i; 

    vector<int> nextBigger(n, -1); 
    stack<pair<int, int>> monotonic_prec; 
    
    monotonic_prec.push({v[n - 1], n - 1}); 
    for(int i = n - 2; i >= 0; i--){
        while(!monotonic_prec.empty() && monotonic_prec.top().first < v[i]){
            monotonic_prec.pop(); 
        }

        nextBigger[i] = (monotonic_prec.empty()) ? -1: monotonic_prec.top().second; 
        monotonic_prec.push({v[i], i}); 
    }

    vector<int> suffix_ans(n); 
    for(int i = n - 1; i >= 0; i--){
        suffix_ans[i] = 1; 
        if(nextBigger[i] != -1) suffix_ans[i] += suffix_ans[nextBigger[i]];
    }



    st st;
    st.init(n, v); 

 
    while(q--){
        int l, r; cin >> l >> r; 
        l--; r--; 
        
        int ind = st.ind_mag_sx(l, r); 
        if(ind >= n) cout << 0 << "\n"; 
        else cout << suffix_ans[st.ind_mag_sx(l, r)] << "\n"; 

    } 
}
