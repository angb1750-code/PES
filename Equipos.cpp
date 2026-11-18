#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli n,t,m,ans=0;
map<lli,vector<lli>> incom;
set<vector<vector<lli>>> hechos;

void rec(lli act,vector<vector<lli>> team){
    if(act==n+1){
        for(int i=0;i<t;i++){
            if(team[i].size()==0)return;
            sort(team[i].begin(),team[i].end());
        }
        sort(team.begin(),team.end());
        hechos.insert(team);
        return;
    }
    lli tf=0;
    for(int i=0;i<t;i++)if(team[i].empty())tf++;
    if(n-act+1<tf)return;

    for(int i=0;i<t;i++){
        vector<bool> num(n+1,false);
        for(auto x:team[i])num[x]=true;
        lli xx=0;
        for(auto x:incom[act]){
            xx=x;
            if(num[xx])break;
        }
        if(num[xx])continue;
        
        vector<vector<lli>> newteam=team;
        newteam[i].push_back(act);
        rec(act+1,newteam);
        if(team[i].empty())break;
    }
}

void solve(){
    cin>>n>>t>>m;
    if(t==1&&m>0){
        cout<<0;
        return;
    }
    lli a,b;
    vector<vector<lli>> teams(t);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        incom[a].push_back(b);
        incom[b].push_back(a);
    }
    rec(1,teams);
    cout<<hechos.size()<<'\n';
    // for(auto x:hechos){
    //     for(int i=0;i<t;i++){
    //         for(int j=0;j<x[i].size();j++){
    //             cout<<x[i][j]<<" ";
    //         }
    //         cout<<'\n';
    //     }
    //     cout<<'\n';
    // }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    lli t=1;
    // cin>>t;
    while(t--){
        solve();
    }
return 0;  
}