#include <bits/stdc++.h>
#define rep(i,j,n) for(int i=j;i<n;i++)
#define pb push_back
#define mp make_pair
using namespace std;


int main(){
  int n;cin>>n;
  map<int,int> rs;
  vector<vector<int>> pages;  // only for primary keys
  pages.pb({});

  vector<int> pc; // pc[i] = space left in page[i]
  pc.pb(n-16);

  int x;
  while(cin>>x){
    if(x==1){
      int a,b;cin>>a>>b;
      // b is pk, a is its size
      rs[b]=a+4;
      int id=-1;

      rep(i,0,pc.size())
        if(pc[i]>=a+4)
          {id=i;break;}
      
      if(id+1){pages[id].pb(b);pc[id]-=(rs[b]);}
      else{pages.pb({b});pc.pb(n-16-rs[b]);}

    }
    else if(x==3){
      int pk;cin>>pk;
      pair<int,int> p = {-1,-1};
      rep(i,0,pages.size()) rep(j,0,pages[i].size()) if(pages[i][j]==pk){p={i,j};break;}
      cout<<p.first<<" "<<p.second<<"\n";
    }
    else if(x==2){
      if(pages[0].empty()) cout<<0<<"\n";
      else{cout<<pages.size()<<" ";for(auto pg:pages) cout<<pg.size()<<" ";cout<<"\n";}
    }
    else break;
  }
  
  return 0;
}
