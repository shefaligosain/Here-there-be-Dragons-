#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vpi vector<pair<int,int> >
#define all(v) (v).begin(), (v).end() //v is replaced by a in code i.e our vector pair vpi
#define pb push_back
const int inf=INT_MAX;

int u, v;
int dp[350][350],dist[350][350];//dp is dynamic programming


int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r,c,k,d;
    cin>>r>>c>>k>>d;

    vpi a;//vector pair
    a.pb({0,0});
    for(int i=0;i<d;++i){
        cin>>u>>v;
        a.pb({u,v});
    }

    sort(all(a));

    for(int i=1;i<=d;++i)
        for(int j=1;j<=d;++j)
            if(not dist[i][j])
                dist[i][j]=dist[j][i]=abs(a[i].first-a[j].first)+abs(a[i].second-a[j].second);
    for(int i=1;i<=d-k+1;++i)
        dp[1][i]=a[i].first+a[i].second;


    for(int i=2;i<=k;++i){
        for(int j=i;j<=d;++j){
            int temp=inf;
            for(int p=j-1;p>=1;--p){
                    if(dp[i-1][p] and temp>dist[p][j]+dp[i-1][p])
                        temp=dist[p][j]+dp[i-1][p];
            }
            dp[i][j]=temp;
        }
    }

    int ans=inf;
    for(int i=k;i<=d;++i)ans=min(ans,dp[k][i]);
    cout<<ans<<"\n";
    return 0;
}
