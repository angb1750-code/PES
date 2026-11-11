#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

vector<bool> dv(1e6+20,true);
map<int,int> memo;

void solve(){
    lli n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        map<int,int> pd;
        cin>>x;
        if(memo[x]!=0){
            cout<<memo[x]<<'\n';
            continue;
        }
        int og=x;
        while(x>1){
            bool dvd=false;
            for(int ii=2;ii<=sqrt(x);ii++){
                if(dv[ii]){
                    if(x%ii==0){
                        pd[ii]++;
                        x/=ii;
                        dvd=true;
                        break;
                    }
                }
            }
            if(!dvd){
                pd[x]++;
                break;
            }
        }
        lli res=1;
        for(auto x:pd)res*=(x.second+1);
        memo[og]=res;
        cout<<res<<'\n';
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    dv[0]=dv[1]=false;
    for(lli i=2;i<1e6;i++){
        if(dv[i]){
            for(lli ii=i*i;ii<1e6;ii+=i){
                dv[ii]=false;
            }
        }
    }
    lli t=1;

    //cin>>t;
    while(t--)solve();
return 0;  
}