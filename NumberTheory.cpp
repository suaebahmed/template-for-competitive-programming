#include<bits/stdc++.h>
using namespace std;
#define int long long

int extd_gcd(int a,int b,int *x,int *y)
{
    if(a == 0)
    {
        *x = 0; *y = 1;
        return b;
    }
    int x1,y1;
    int d = extd_gcd(b%a,a,&x1,&y1);
    *x = y1 - (b/a)*x1;
    *y = x1;
    return d;
}

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
bitset<MXN> isPrime;
int phi[MXN+5];

void SIEVE(){
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

void SIEVE(){
    spf[1] = 1;
    for(int i=2; i<N; i++) spf[i] = i;

    for(int i=4; i<N; i+=2) spf[i] = 2;
    for(int i=3; i<N; i+=2){
        if(spf[i]==i){
            PRIME.pb(i);
            for(int j=i*i; j<N; j+=i){
                if(spf[j]==j) spf[j] = i;
            }
        }
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

// ** prime factorization using seive Ai = 1e6 / 1e7
int PRIME_RANGE = 31622 + 5; // = sqrt(1e9)
// ** prime factorization using seive Ai = 1e9

// ** check prime or not using seive Ai = 1e9
// ** find eular phi value using seive Ai = 1e9
// optimized sieve
vector<int> prime;
bool marked[PRIME_RANGE];

void SIEVE(){
    marked[1] = true;
    for(int i=2; i<PRIME_RANGE; i++){
        if(!marked[i]){
            prime.push_back(i);
            for(int j=2*i; j<PRIME_RANGE; j+=i)
                marked[j] = true;
        }
    }
}
bool fun_isPrime(int n){
    if(n == 0 || n==1) return 0;
    for(int i=0; i<prime.size() && prime[i]*prime[i]<=n; i++){
        if(n%prime[i]==0) return 0;
    }
    return 1;
}

int divSum(int n){
    int sum = 1;
    for(int i=0; i<PRIME.size() && PRIME[i]*PRIME[i]<=n; i++){
        if(n%PRIME[i]==0){
            int a = PRIME[i];
            while(n%PRIME[i]==0){
                a = a*PRIME[i];
                n/=PRIME[i];
            }
            sum = sum*((a-1)/(PRIME[i]-1));
        }
    }
    if(n > 1){
        sum = sum*(1+n);
    }
    return sum;
}
long long lcm(long long a,long long b){ return ((a*b)/__gcd(a,b))};

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