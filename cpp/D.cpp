#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
#ifndef ONLINE_JUDGE
#include<debug.h>
#else
#define dbg(x...)
#endif
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define srt(v) sort(all(v))
#define rsrt(v) sort(rall(v))
#define ff first
#define ss second
#define pii pair<int,int>
#define mod 1000000007
int dx[]={0,+1,0,-1};
int dy[]={+1,0,-1,0};
#define vi vector<int>
typedef tree<int, null_type, less_equal<int>,rb_tree_tag,
tree_order_statistics_node_update> ordered_multiset;
#define scanv(a) for(auto &x: a) cin>>x;
#define ll long long
#define int long long 
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
const int N = 200100, inf = 1e9;
const int MOD = 998244353;
int egcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = egcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1 * (a/b);
    return d;
}
void solve(){
    int n; cin >> n;
    ll ans = 1;
    int a = 1, b = 1;
    for (int i = n/3; i > n/6; i--) {
        a *= i;
        a %= MOD;
    }
    for (int i = n/6; i >= 1; i--) {
        deb(i);
        b *= i;
        b %= MOD;
    }
    deb(b);
    int xx, yy;
    egcd(b, MOD, xx, yy);
    ans = a;
    xx = (xx % MOD + MOD) % MOD;
    ans *= xx;
    ans %= MOD;
    ll diff = 1;
    for (int i = 0; i < n/3; i++) {
        std::vector<int> tmp;
        for (int j = 0; j < 3; j++) {
            int x; cin >> x;
            tmp.push_back(x);
        }
        std::sort(tmp.begin(), tmp.end());
        if (tmp[0] == tmp[2]) diff *= 3;
        else if (tmp[0] == tmp[1]) diff *= 2;
        diff %= MOD;
    }
    ans = ans * diff;
    ans %= MOD;
    cout << ans << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tt=1;
    // cin>>tt;
    for(int i=1; i<=tt; i++){
        // cout<<"Case "<<i<<":\n";
        solve();
    }
    return 0;
}
