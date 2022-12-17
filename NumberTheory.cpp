#include<bits/stdc++.h>
using namespace std;
#define int long long

ll fastexpo(ll a,ll b,int md)
{
    ll res=1;
    while(b)
    {
        if(b&1) res = (res*a)%md;
        a = (a*a)%md;
        b>>=1;
    }
    return res;
}
int modInverse(ll n,int md){
    return fastexpo(n,md-2,md);
}
const int MXN = 1e5;
bool isPrime[MXN+5];
int phi[MXN+5];

void seive(){
    isPrime[1] = 0;
    for(int i=2; i<MXN; i++) isPrime[i] = 1;

    for(int i=4; i<MXN; i+=2) isPrime[i] = 0;
    for(int i=3; i<MXN; i+=2){
        if(isPrime[i]){
            // j = i*i;
            for(int j=2*i; j<MXN; j+=i){
                isPrime[j] = 0;
            }
        }
    }
}

void phi_1_to_n(){
    for(int i=0; i<MXN; i++) phi[i] = i;
    for(int i=2; i<MXN; i++){
        if(phi[i]==i){
            for(int j=i; j<MXN; j+=i){
                phi[j] -= phi[j]/i;
            }
        }
    }
}

const int N = 1e6+1;
vector<int> PRIME;
int spf[N];

void seivePimeFactor(){
    spf[1] = 1;
    for(int i=2; i<N; i++) spf[i] = i;

    for(int i=4; i<N; i+=2) spf[i] = 2;
    for(int i=3; i<N; i+=2){
        if(spf[i]==i){
            for(int j=i*i; j<N; j+=i){
                if(spf[j]==j) spf[j] = i;
            }
        }
    }
    for(int i=2; i<N; i++){
        if(spf[i]==i) PRIME.push_back(i); 
    }
}
vector<int> getFactorize(int n){
    vector<int> ans;
    while(n != 1){
        ans.pb(spf[n]);
        n /= spf[n];
    }
    return ans;
}

// prime factorization using seive Ai = 1e6 / 1e7
// prime factorization using seive Ai = 1e9
// check prime or not using seive Ai = 1e9

void solve(){
    
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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