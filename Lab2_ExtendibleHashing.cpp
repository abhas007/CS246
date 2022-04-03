#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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

ll gd=0;
ll bs=0;
ll caze;
ll gt=0;

ll hush(ll x){
  return x;
}

// data structures
vector<ll*> dir;

// Insert
bool insert(ll val){
  if(gd>20){cout<<"Memory limit exceeded!" ;return 0;}

  ll hash_value = hush(val);
  ll ind = hash_value&((1ll<<gd)-1);

  ll *ptr = dir[ind];
  ll ld = ptr[bs+1];

  if(ptr[bs]<bs){
    ptr[ptr[bs]]=val;
    ptr[bs]++;
  }
  else{
    if(ld<gd){

      ll tmp[bs+1];
      tmp[bs]=val;
      for(ll i=0;i<ptr[bs];i++) tmp[i]=ptr[i];


      ll *nptr = new ll(bs+3);
      nptr[bs]=0;
      nptr[bs+1] = ld+1;
      nptr[bs+2] = ++gt;

      ptr[bs] = 0;
      ptr[bs+1] = ld+1;

      for(ll i=0;i<(1ll<<gd);i++){
        if(dir[i]==ptr){
          if(i&(1ll<<ld)){
            dir[i]=nptr;
          }
        }
      }

      for(auto u: tmp){
        insert(u);
      }
    }else if(ld==gd){
      gd++;
      vector<ll*> dir2 = dir;

      for(auto u:dir2) dir.push_back(u);

      insert(val);
    }
  }
  return 1;
}

bool search_or_delete(bool s_or_d,int val){
  
  ll hash_value = hush(val);
  ll ind = hash_value&((1ll<<gd)-1);

  ll *ptr = dir[ind];
  bool found=0;
  for(ll i=0;i<ptr[ptr[bs]];i++){
    if(ptr[i]==val) found=1;
  }

  if(!s_or_d){
    if(found) {cout<<val<<" found\n";return 1;}
    else{cout<<val<<" not found\n";return 0;}
  }

  bool ok=0;
  for(ll i=0;i<bs;i++){
    if(ptr[i]==val){ok=1;continue;}
    if(ok) ptr[i]=ptr[i-1];
  }

  if(ok) ptr[bs]--;

  cout<<val<<" deleted!\n";
  return 1;
}

signed main(){
  cin>>gd>>bs;
  gt=1;

  dir.resize(1ll<<gd);
  ll *b1 = new ll(bs+3);
  b1[bs] = 0;       // no of elememts
  b1[bs+1] = 0;     // local depth
  b1[bs+2] = gt;    // time of creation

  for(ll i=0;i<(1ll<<gd);i++) dir[i]=b1;

  while(cin>>caze){
    if(caze==6){cout<<"Exiting";return 0;}
    
    ll val;
    switch(caze){
      case 2:{
        cin>>val;
        insert(val);
      }break;

      case 3:{    // searchin s_or_d==0
        cin>>val;
        search_or_delete(0,val);
      }break;

      case 4:{    // delete s_or_d==1
        cin>>val;
        search_or_delete(1,val);
      }break;

      case 5:{
        // cout<<"Global Depth: "<<gd<<'\n';

        vector<pair<ll,pair<ll,ll>>> res;
        set<ll*> s;

        for(ll i=0;i<dir.size();i++){
          auto u = dir[i];

          // cout<<"Local depth of index "<<i<<"(dir) pointing at "<<u<<"(bucket {";
          // for(ll i=0;i<u[bs];i++) cout<<u[i]<<" ";
          // cout<<"}) is "<<u[bs+1]<<'\n';

          if(!s.count(u)){
            res.push_back({u[bs+2],{u[bs],u[bs+1]}});
            s.insert(u);
          }
        }

        cout<<gd<<'\n';
        sort(res.begin(),res.end());
        cout<<(ll)(res.size())<<'\n';
        for(auto e:res){
          cout<<e.S.F<<' '<<e.S.S<<'\n';
        } 

      }break;
    }

  }
}