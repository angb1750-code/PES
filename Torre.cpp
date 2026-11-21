#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
 
pair<lli,lli> ans={0,0};
 
void fn(lli nm,lli act,lli ps){
    if(nm<=0){
        ans=max(ans,{ps, act});
        return;
    }
    lli n=1;
    while(pow(n+1,3)<=nm)n++;
 
    fn(nm-pow(n,3),act+pow(n,3),ps+1);
    if(n-1>0)fn(3*n*(n-1),act+pow(n-1,3),ps+1);
}
 
void solve(){
    lli m;
    cin>>m;
    fn(m,0,0);
    cout<<ans.first<<" "<<ans.second;
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
