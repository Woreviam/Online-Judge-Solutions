#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
 
#define eps 1e-8
#define vi vector<int>
#define pb(x) push_back(x)
#define f(i,x,y) for(int i=x;i<y;i++)
#define rf(i,y,x) for(int i=y;i>=x;i--)
#define all(x) (x).begin(),(x).end()
#define cout1(x) cout<<x<<endl
#define cout2(x,y) cout<<x<<" "<<y<<endl
#define cout3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl
#define MAXN 100005
#define INF 1000
using namespace std;
int in[MAXN],out[MAXN];
vector<int>L[MAXN];
bool color[MAXN];
int memo[MAXN];
int dfs(int node){
    if(L[node].size()==0)return 1;
    if(memo[node]!=-1)return memo[node];
    int ans=0;
    for(int i=0;i<L[node].size();i++){
        int to=L[node][i];
        if(color[node]!=color[to])ans=max(ans,1+dfs(to));
        else ans=max(ans,dfs(to));
    }
    return memo[node]=ans;
}   
int main(){
    int n1,n2,m;
    while(scanf("%d%d%d",&n1,&n2,&m)==3){
        memset(in,0,sizeof in);
        memset(out,0,sizeof out);
        memset(color,0,sizeof color);
        memset(memo,-1,sizeof memo);
        for(int i=0;i<=n1+n2;i++)L[i].clear();
        if(n1==0 && n2==0 && m==0)break;
        int ct=0;
        
        for(int i=0;i<n1;i++)color[i]=0;
        for(int i=n1;i<n1+n2;i++)color[i]=1;
        int x,y;
        for(int i=0;i<m;i++){
            scanf("%d%d",&x,&y);
            x--;y--;
            in[x]++;
            out[y]++;
            ct++;
            L[y].pb(x);
        }
        int ans1=0,ans2=0,res;
        for(int i=0;i<n1;i++){
            if(out[i]==0 && in[i]==0)continue;
            if(in[i]==0){
                ans1=max(dfs(i),ans1);
            }
        }
        //cout1(ans1);
        ans1--;
        for(int i=n1;i<n1+n2;i++){
            if(out[i]==0 && in[i]==0)continue;
            if(in[i]==0){  
                ans2=max(dfs(i),ans2);
            }
        }
        //cout1(ans2);
        ans2--;
        
        if(ans1==ans2)res=ans1+1;
        else res=max(ans1,ans2);
        printf("%d\n",max(3,res+2));
    }
}