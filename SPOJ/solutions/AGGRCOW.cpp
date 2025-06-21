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
#define bit(x) __buitin_popcount(x)
#define MAXN 100004
//^
using namespace std;
int X[MAXN],C,n;
bool check(int dis){
    int ct=C-1,last=X[0];
    for(int i=1;i<n;i++){
        if(ct==0)return 1;
        if(X[i]-last>=dis){
            last=X[i];
            ct--;
        }
    }
    return ct==0;
}
        
int main(){
    int c;
    scanf("%d",&c);
    while(c--){
        scanf("%d%d",&n,&C);
        for(int i=0;i<n;i++)scanf("%d",&X[i]);
        sort(X,X+n); 
        int lo=0,hi=X[n-1]-X[0];
        while(lo<hi){
            int me=lo+(hi-lo+1)/2;
            if(check(me))lo=me;
            else hi=me-1;
            
        }
        printf("%d",lo);
        puts("");   
    }
}
        
