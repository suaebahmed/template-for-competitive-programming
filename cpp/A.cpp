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
const int N = 1e5 + 5, inf = 1e9;
const int MOD = 998244353;

void solve(){
    int N; cin>>N;
    string ss; cin>>ss;
    int s = 0, n = 0;
    int e = 0, w = 0;
    for(auto c: ss){
        if(c == 'S') s++;
        else if(c == 'N') n++;
        else if(c == 'W') w++;
        else e++;
    }
    if((n%2==1 && s%2==0) || (n%2==0 && s%2==1)){
        cout<<"NO\n";
        return;
    }
    if((e%2==1 && w%2==0) || (e%2==0 && w%2==1)){
        cout<<"NO\n";
        return;
    }

    string ans(N,'#');
    for(int i=0; i<N; i++){
        if(n&1){
            ans[i] = 'R';
            n--;
        }
        if(s&1){
            ans[i] = 'R';
            s--;
        }

        if(e&1){
            ans[i] = 'R';
            e--;
        }
        if(w&1){
            ans[i] = 'R';
            w--;
        }
    }
    int Re = 0, Rw = 0, H


    int R2 = 0, H2 =  0;
    for(int i=0; i<N; i++){
        if(ss[i] == 'E' || ss[i] == 'W'){
            if(R > H) ans[i] = 'H', H++;
            else ans[i] = 'R', R++;
        }
        else{
            if(R2 > H2) ans[i] = 'H', H2++;
            else ans[i] = 'R', R2++;
        }
    }
    if(R != H || R2 != H2){
        cout<<"NO\n";
        return;
    }
    cout<<ans<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tt=1;
    cin>>tt;
    for(int i=1; i<=tt; i++){
        // cout<<"Case "<<i<<":\n";
        solve();
    }
    return 0;
}