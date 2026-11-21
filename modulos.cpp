#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli n,x,aux;
vector<lli> vec;

lli fn(lli act,map<lli,bool> visit,lli nm){
    lli newnm=nm%act;
    bool band=true;
    for(int i=0;i<n;i++){
        if(vec[i]>newnm)visit[vec[i]]=true;
        else band=false;
    }
    if(band) return newnm;
    bool ex=false;
    lli mx=0;
    for(int i=0;i<n;i++){
        if(visit[vec[i]])continue;
        ex=true;
        map<lli,bool> visit2=visit;
        visit2[vec[i]]=true;
        mx=max(fn(vec[i],visit2,newnm),mx);
    }
    return (ex)? mx:newnm;
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>aux;
        vec.push_back(aux);
    }
    cin>>x;
    lli mx=0;
    for(int i=0;i<n;i++){
        map<lli,bool> visit;
        visit[22]=true;
        mx=max(fn(vec[i],visit,x),mx);
        // cout<<'\n';
        // cout<<i<<" "<<mx<<"\n";
    } 
    cout<<mx;
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