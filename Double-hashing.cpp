#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define dbg(x...)
#endif

#define int long long
const int M1 = 1000000007;
const int M2 = 1000000009;
const int p1 = 257;
const int p2 = 263;
const int N = 1e6 + 5;


vector<int> ppow1(N), ppow2(N);
set<pair<int, int>> mp;

pair<int, int> getHashValue(string &s) {
    int n = s.size();
    int hash1 = 0, hash2 = 0; 
    for (int i = 0; i < n; i++) {
        hash1 = (hash1 + (s[i] - 'a' + 1) * ppow1[i]) % M1;
        hash2 = (hash2 + (s[i] - 'a' + 1) * ppow2[i]) % M2;
    }
    return {hash1, hash2};
}

bool isThere(string &s) {
    int n = s.size();
    auto [hash1, hash2] = getHashValue(s);

    for (int i = 0; i < n; i++) {
        int currHash1 = (hash1 - (s[i] - 'a' + 1) * ppow1[i] % M1 + M1) % M1;
        int currHash2 = (hash2 - (s[i] - 'a' + 1) * ppow2[i] % M2 + M2) % M2;

        for (char c = 'a'; c <= 'c'; c++) {
            if (c != s[i]) {
                int newHash1 = (currHash1 + (c - 'a' + 1) * ppow1[i] % M1) % M1;
                int newHash2 = (currHash2 + (c - 'a' + 1) * ppow2[i] % M2) % M2;

                if (mp.count({newHash1, newHash2})) return true;
            }
        }
    }
    return false;
}

// UVa 11512 - GATTACA
// Using Double Hashing: https://codeforces.com/contest/514/submission/290288349

void solve() {
    int n, m;
    cin >> n >> m;

    ppow1[0] = ppow2[0] = 1; 
    for (int i = 1; i < N; i++) {
        ppow1[i] = (ppow1[i - 1] * p1) % M1;
        ppow2[i] = (ppow2[i - 1] * p2) % M2;
    }

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        mp.insert(getHashValue(s));
    }

    while (m--) {
        string query; cin >> query;
        if (isThere(query)) cout << "YES\n";
        else cout << "NO\n";
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
