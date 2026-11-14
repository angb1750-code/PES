#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

void solve(){
    lli n,ans=0;
    string cad;
    cin>>n>>cad;
    // for(int i=4;i<=1e5+4;i++){
    //     cout<<i%10;
    // }
    // cout<<cad;
    for(int i=0;i<n;i++){
        map<char,lli> fr;
        lli ds=0,frmx=0;
        for(int j=i;j<n;j++){
            fr[cad[j]]++;
            frmx=max(frmx,fr[cad[j]]);
            if(frmx>10)break;
            // cout<<frmx<<" ";
            if(fr[cad[j]]==1)ds++;
            // cout<<ds<<'\n';
            if(frmx<=ds)ans++;
        }
    }
    cout<<ans<<'\n';
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    lli t=1;
    cin>>t;
    while(t--){
        solve();
    }
return 0;  
}