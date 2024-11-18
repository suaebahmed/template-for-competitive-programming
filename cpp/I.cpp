#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(x...)
#endif
#define int long long
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define srt(v) sort(all(v))
#define rsrt(v) sort(rall(v))
#define lowb(a, x) lower_bound(all(a),x)
#define sz(v) (int)v.size()
#define ff first
#define ss second
#define pii pair<int,int>
#define mod 1000000007
#define vi vector<int>
#define cinv(a) for(auto &x: a) cin>>x
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
const int N = 2e5 + 5, inf = 1e9;
// https://codeforces.com/contest/2037/submission/292125237

int query(int l, int r){
    cout<<"? "<<l<<" "<<r<<endl;
    int a; cin>>a;
    return a;
}

void answer(string x){
    cout<<"! "<<x<<endl;
}

void solve(){
    int n; cin>>n;
    for(int i=2; i<=n; i++){
        int res = query(1, i);
        if(res > 0){
            string s;
            for(int j = 0; j+res+1 < i; j++) s.push_back('1');
            for(int j = 0; j<res; j++) s.push_back('0');
            s.push_back('1');

            // cout<<"debug #"<<s<<" "<<i<<" "<<res<<endl;

            vector<int> a = {res};
            for(int j=i+1; j<=n; j++){
                int rs = query(1, j);
                if(rs > a.back()){
                    s.push_back('1');
                    a.push_back(rs);
                }
                else s.push_back('0');
            }
            answer(s);
            return;
        }
    }
    answer("IMPOSSIBLE");
}

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int tc=1;
    cin>>tc;
    for(int i=1; i<=tc; i++){
        // cout<<"Case "<<i<<": ";
        solve();

    }
    return 0;
}