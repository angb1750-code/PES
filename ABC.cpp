#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;

void solve(){
    lli n;
    cin>>n;
    lli ans=0;
    for(lli i=1;i*i*i<=n;i++){
        // cout<<i<<": ";
        for(lli j=i;j*j<=(n/i);j++){
            ans+=floor((double)(n)/(double)(i*j))-j+1;
        }
        // cout<<'\n';
    }
    cout<<ans;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    lli t=1;
    // cin>>t;
    while(t--)solve();
}