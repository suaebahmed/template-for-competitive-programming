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

bool query(){
    cout<<"NO"<<endl;
    return 0;
}

void answer(int x){
    cout<<"! "<<x<<endl;
    exit(0);
}

void solve(){
    
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