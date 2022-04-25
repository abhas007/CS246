#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll MOD=((1e9)+7);
const ll INF=1e18;

#define F first
#define S second

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // for getting input frm input.txt
    freopen("output.txt", "w", stdout);
    // for getting output frm output.txt
    #else
    #endif
    ll b, rpp, n;
    cin>>b>>rpp>>n;
    vector<ll> r(n);
    for (ll i=0; i<n; i++) cin>>r[i];
    vector<vector<ll>> p;
    for (ll i=0; i<n; i+=rpp){
        vector<ll> te;
        for (ll j=i; j<min(i+rpp,n); j++){
            te.push_back(r[j]);
        }
        p.push_back(te);
    }
    for (auto &u: p){
        sort(u.begin(),u.end());
    }
    // debug(p);
    // debug(b-1,p.size());
    while (p.size()>1){
        vector<vector<ll>> te;
        for (ll i=0; i<p.size(); i+=b-1){
            vector<ll> te2;
            for (ll j=i; j<min(i+b-1,ll(p.size())); j++){
                for (auto u: p[j]){
                    te2.push_back(u);
                }
            }
            sort(te2.begin(),te2.end());
            te.push_back(te2);
        }
        p=te;
        // debug(p.size());
    }
    for (ll i=0; i<n; i+=rpp){
        for (ll j=i; j<min(i+rpp,n); j++){
            cout<<p[0][j]<<endl;
        }
    }
    // for (ll i=25; i>=1; i--) cout<<i<<endl;
    return 0;
}
