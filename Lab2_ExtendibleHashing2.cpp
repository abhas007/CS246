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

ll hhhh(ll x){
    return x;
}

ll gt;

bool insert(vector<vector<ll>> &dir, vector<pair<bool,vector<ll>>>& bu, ll val, ll& gd, ll bc){
    if (gd>20) {
        return false;
    }
    ll h=hhhh(val);
    ll ind=(h&((1ll<<gd)-1));
    ll pos=dir[ind][0];
    // debug(pos,val);
    ll ld=dir[ind][1];
    ll nel=(bu[dir[ind][0]].S).size();
    // debug(pos,val,bu[pos].S,ld,gd);
    if (nel<bc) {
        // debug(val,ld);
        bu[dir[ind][0]].S.push_back(val);
    }
    else{
        if (ld<gd){
            // debug(true);
            ll npos=pos+(1ll<<ld);
            // debug(pos,npos,ld);
            bu[npos].F=true;
            gt++;
            vector<ll> temp;
            for (auto u: bu[pos].S) temp.push_back(u);
            bu[pos].S.clear();
            temp.push_back(val);
            dir[ind][1]++;
            // debug(val,dir[ind][1],ind);
            // debug(true);
            for (ll i=0; i<dir.size(); i++){
                if ((i&((1ll<<(ld+1))-1))==(npos)){
                    dir[i][0]=npos;
                    // debug(npos,true);
                    dir[i][2]=gt;
                    dir[i][1]=ld+1;
                }
                else if ((i&((1ll<<(ld+1))-1))==(pos)){
                    dir[i][1]=ld+1;
                }
            }
            for (auto u: temp){
                insert(dir,bu,u,gd,bc);
            }
        }
        else if (ld==gd){
            vector<ll> temp;
            for (auto u: bu[pos].S) temp.push_back(u);
            bu[pos].S.clear();
            temp.push_back(val);
            vector<vector<ll>> dir2;
            dir2=dir;
            for (auto u: dir2){
                dir.push_back(u);
                bu.push_back({false,{}});
            }
            gd++;
            for (auto u: temp){
                // debug(gd);
                insert(dir,bu,u,gd,bc);
            }
        }
    }
    return true;
}

bool del(vector<vector<ll>>& dir, vector<pair<bool,vector<ll>>>& bu, ll val, ll& gd, ll bc){
    ll h=hhhh(val);
    ll ind=(h&((1ll<<gd)-1));
    ll fl=0;
    vector<ll> temp;
    for (auto u: bu[dir[ind][0]].S){
        if (u==val && fl==0) fl=1;
        else temp.push_back(u);
    }
    bu[dir[ind][0]].S=temp;
    if (fl) return true;
    return false;
}

bool search(vector<vector<ll>>& dir, vector<pair<bool,vector<ll>>>& bu, ll val, ll& gd, ll bc){
    ll h=hhhh(val);
    ll ind=(h&((1ll<<gd)-1));
    for (auto u: bu[dir[ind][0]].S){
        if (u==val) return true;
    }
    return false;
}

void stat(vector<vector<ll>>& dir, vector<pair<bool,vector<ll>>>& bu, ll& gd, ll bc){
    cout<<gd<<endl;
    vector<pair<ll,pair<ll,ll>>> bucks;
    set<ll> s;
    for (auto u: dir){
        if (s.find(u[0])==s.end()){
            bucks.push_back({u[2],{bu[u[0]].S.size(),u[1]}});
            s.insert(u[0]);
        }
    }
    sort(bucks.begin(),bucks.end());
    cout<<bucks.size()<<endl;
    for (auto u: bucks){
        cout<<u.S.F<<" "<<u.S.S<<endl;
    }
}

int main() {
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // // for getting input frm input.txt
    // freopen("output.txt", "w", stdout);
    // // for getting output frm output.txt
    // #else
    // #endif
    ll gd, bc;
    cin>>gd>>bc;
    ll a;
    gt=1;
    vector<vector<ll>> dir((1ll<<gd), vector<ll> (3));
    for (ll i=0; i<(1ll<<gd); i++){
        dir[i][0]=0;
        dir[i][1]=0;
        dir[i][2]=0;
    }
    vector<pair<bool,vector<ll>>> bu((1ll<<gd),{false,{}});
    while (cin>>a){
        // debug(a);
        if (a==6) break;
        else if (a==2 || a==3 || a==4){
            ll val;
            cin>>val;
            if (a==2) insert(dir,bu,val,gd,bc);
            else if (a==4) del(dir,bu,val,gd,bc);
            else search(dir,bu,val,gd,bc);
        }
        else stat(dir,bu,gd,bc);
    }
    return 0;
}
