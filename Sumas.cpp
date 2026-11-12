#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

void solve(){
    lli n,num=-1;
    cin>>n;
    vector<lli> vec(n);
    vector<vector<lli>> pref(2,vector<lli>(n+1,0));

    lli c1=0,c2=0;
    for(lli i=0;i<n;i++){  
        cin>>vec[i];
        pref[0][i+1]+=pref[0][i];
        pref[1][i+1]+=pref[1][i];
        if(vec[i] == -1){
            pref[0][i+1]++;
        }
        else if(vec[i] == 1){
            pref[1][i+1]++;
        }
        else {
            num=i;
            pref[0][i+1]=pref[1][i+1]=0;
        }

    }
    lli arr[]={0,0};
    lli b1=1,b2=1;
    for(int i=1;i<=num;i++){
        //cout<<pref[0][i]<<" "<<pref[1][i]<<" "<<max(arr[1],(pref[1][i]-pref[1][b1-1])-(pref[0][i]-pref[0][b1-1]))<<'\n';
        if((pref[0][i]-pref[0][b1-1])>=(pref[1][i]-pref[1][b1-1]))b1=i;
        if((pref[0][i]-pref[0][b2-1])<=(pref[1][i]-pref[1][b2-1]))b2=i;
        
        //cout<<b1<<" "<<b2<<"\n\n";
        arr[0]=min(arr[0],abs(pref[1][i]-pref[1][b2-1])-abs(pref[0][i]-pref[0][b2-1]));
        arr[1]=max(arr[1],abs(pref[1][i]-pref[1][b1-1])-abs(pref[0][i]-pref[0][b1-1]));
    }
    b1=b2=num+2;
    for(int i=num+2;i<=n;i++){
        //cout<<pref[0][i]<<" "<<pref[1][i]<<" "<<max(arr[1],(pref[1][i]-pref[1][b1-1])-(pref[0][i]-pref[0][b1-1]))<<'\n';
        if((pref[0][i]-pref[0][b1-1])>=(pref[1][i]-pref[1][b1-1]))b1=i;
        if((pref[0][i]-pref[0][b2-1])<=(pref[1][i]-pref[1][b2-1]))b2=i;
        
        //cout<<b1<<" "<<b2<<"\n\n";
        arr[0]=min(arr[0],abs(pref[1][i]-pref[1][b2-1])-abs(pref[0][i]-pref[0][b2-1]));
        arr[1]=max(arr[1],abs(pref[1][i]-pref[1][b1-1])-abs(pref[0][i]-pref[0][b1-1]));
    }
    //cout<<arr[0]<<" "<<arr[1]<<'\n';
    lli mm[]={0,0};
    if(num!=-1){
        lli nd=0,ni=0;
        lli nor=vec[num];
        lli bl[]={0,0};
        lli bd[]={0,0};
        for(int i=num+1;i<n;i++){
            nd+=vec[i];
            bd[0]=min(bd[0],nd);
            bd[1]=max(bd[1],nd);
        }
        for(int i=num-1;i>=0;i--){
            ni+=vec[i];
            bl[0]=min(bl[0],ni);
            bl[1]=max(bl[1],ni);
        }
        mm[0]=nor+bl[0]+bd[0];
        mm[1]=nor+bl[1]+bd[1];

    }
    //cout<<mm[0]<<" "<<mm[1]<<"\n";
    set<lli> ans;

    for(lli i=arr[0];i<=arr[1];i++){
        ans.insert(i);
    }
    for(lli i=mm[0];i<=mm[1];i++){
        ans.insert(i);
    }
    cout<<ans.size()<<'\n';
    for(auto x:ans)cout<<x<<" ";
    cout<<"\n";
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    lli t=1;

    cin>>t;
    while(t--)solve();
return 0;  
}