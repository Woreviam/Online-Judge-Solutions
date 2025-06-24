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
 
#define eps 1e-8
#define vi vector<int>
#define pb(x) push_back(x)
#define f(i,x,y) for(int i=x;i<y;i++)
#define rf(i,y,x) for(int i=y;i>=x;i--)
#define all(x) (x).begin(),(x).end()
#define cout1(x) cout<<x<<endl
#define cout2(x,y) cout<<x<<" "<<y<<endl
#define cout3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl
//^
using namespace std;
#define MAXN 1000005
#define LOGMAX 25
long long M[MAXN][LOGMAX],A[MAXN],n,q,x,y;
void procced(){
    for(int i=0;i<n;i++)M[i][0]=A[i];
    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;i+(1<<j)-1<n;i++){
            if(M[i][j-1]>M[i+(1<<(j-1))][j-1]) 
                M[i][j]=M[i][j-1];
            else M[i][j]=M[i+(1<<(j-1))][j-1];
        }
    }    
}
 
long long query(int xx,int yy){
    if(xx==yy)return M[xx][0];
    if( yy < xx ) swap( xx , yy );
    int r = yy - xx + 1;
    int k = int (floor( log2(r) ) );
    while( (1<<k) <= r ) k++;
    k--;
    if(  M[xx][k]  > M[yy - (1<<k) + 1 ][ k ]  ) 
        return M[xx][k];
    return M[yy - (1<<k) + 1 ][ k ];
}
int main(){
    long long k;
   while(cin>>n){
        long long maxi=-1LL;
        for(int i=0;i<n;i++){
            cin>>A[i];
            if(maxi<A[i])maxi=A[i];
        }
        cin>>k;
        if(n==k){cout<<maxi<<endl;continue;}
        procced();
        
        cout<<query(0,0+k-1);
        for(int i=1;i+k-1<n;i++){
            cout<<" "<<query(i,i+k-1);
        }
        puts("");
    }
        
                  
        
 
}
 
