#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> z_function(string s){
    int n = s.size();
    vector<int> z(n);
    for(int i=1,l=0,r=0; i<n; i++){
        if(i <= r){
            z[i] = min(r-i+1, z[i-l]);
        }
        while(i+z[i]<n && s[z[i]] == s[i + z[i]]){
            z[i]++;
        }
        if(i+z[i]-1 > r){
            l = i, r = i+z[i]-1;
        }
    }
    return z;
}

vector<int> prefix_functoin(string &s){
    int n = s.size();
    vector<int> pi(n);
    for(int i=1; i<n; i++){
        int j = pi[i-1];
        while(j>0 && s[i]!=s[j]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int rabin_karp(string const& s, string const& t) {
    const int p = 31; 
    const int m = 1e9 + 9; // 1e18
    int S = s.size(), T = t.size();

    vector<long long> ppow(max(S, T)); 
    ppow[0] = 1; 
    for (int i = 1; i < (int)ppow.size(); i++) ppow[i] = (ppow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++) h[i+1] = (h[i] + (t[i] - 'a' + 1) * ppow[i]) % m; 
    
    long long hash = 0; 
    for (int i = 0; i < S; i++) hash = (hash + (s[i] - 'a' + 1) * ppow[i]) % m; 

    // number of substring such that each character belongs to exactly one substring
    int occ = 0, j = S;
    for (int i = 0; i + S - 1 < T; i++) {
        long long currHash = (h[i+S] + m - h[i]) % m;
        j++;
        if (currHash == hash * ppow[i] % m && j>=S && t.substr(i,S)==s){
            j = 0;
            occ++;
        }
    }
    return occ;
}

void solve(){
    
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tt = 1;
    // cin>>tt;
    for(int i=1; i<=tt; i++){
        // cout<<"Case "<<i<<": ";
        solve();
    }
    return 0;
}