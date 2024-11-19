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

// https://codeforces.com/contest/1886/problem/B

void solve(){
    int px, py; cin>>px>>py;
    int a1, b1; cin>>a1>>b1;
    int a2, b2; cin>>a2>>b2;

    if(px==0 && py==0){
        printf("%.10lf\n", 0);
        return;
    }

    // distance points A and B center (0,0)
    double ac1 = sqrtl(a1*a1 + b1*b1);
    double ac2 = sqrtl(a2*a2 + b2*b2);
    
    // distance between his house and points A, B
    double ap1 = sqrtl((a1-px)*(a1-px) + (b1-py)*(b1-py));
    double ap2 = sqrtl((a2-px)*(a2-px) + (b2-py)*(b2-py));
 
    // distance between circle
    double ccx = sqrtl((a1-a2)*(a1-a2) + (b1-b2)*(b1-b2)); 


    double l = 0.0, r = 1e6;
    for(int i=0; i<100; i++){
        double mid = l + (r - l)/2;
        auto good = [&]() -> bool {
            if((ap1 <= mid && ac1 <= mid) || (ap2 <= mid && ac2 <= mid)) return true;
            return ((ap1 <= mid || ap2 <= mid) && (ac1 <= mid || ac2 <= mid) && (2 * mid >= ccx));
        };

        if(good()) r = mid;
        else l = mid;
    }
    printf("%.10lf\n", r);
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