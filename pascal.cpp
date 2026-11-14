#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

vector<lli> fac(17,1);
map<lli,lli> mem;
lli t;

lli cent(lli n,lli k){
    lli res=1;
    for(int i=1;i<=k;i++){
            res=res*(n-k+i)/i;
            // res*=n-i;
            //cout<<n-i<<" "<<"\n";
            if(res>t)return t+1;
        }
    return res;
}

void solve(){
    if(mem[t]!=0){
        cout<<mem[t]<<'\n';
        return;
    }
    lli ans=0;

    for(int i=1;i<=16;i++){
        if(cent(2*i,i)>t)break;
        lli ini=2*i,fin=t,mitad;
        lli mj=2*i;
        while(fin>=ini){
            mitad=(fin+ini)/2;
            lli es=cent(mitad,i);
            // cout<<mitad<<": "<<es<<" ";
            if(es>t){
                fin=mitad-1;
            }
            else{
                mj=mitad;
                ini=mitad+1;
            }
        }
        // cout<<mj<<" ";
        ans+=(mj-2*i)*2+1;
    }
    mem[t]=ans;
    cout<<mem[t]<<'\n';
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    for(int i=1;i<=16;i++){
        fac[i]=fac[i-1]*i;
        //cout<<fac[i]<<" ";
    }

    // lli t=1;

    while(true){
        cin>>t;
        if(t==-1)break;
        solve();
    }
return 0;  
}