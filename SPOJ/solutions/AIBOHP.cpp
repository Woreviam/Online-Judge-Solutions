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
//^
using namespace std;
int memo[6105][2];
char s[6105];
int main(){
    int c=0;
    cin>>c;
    while(c--){
        scanf("%s",s +1 );
        int t=strlen(s+1);
        t++;
        for(int i=0;i<=t;i++){memo[i][0]=0;memo[i][1]=0;}
        for(int j=1;j<t;j++){
            for(int i=t-1;i>=1;i--){
                if(i>j)continue;
                int c=1<<30;
                if(s[i]==s[j])c=memo[i+1][(j-1)&1];
                memo[i][j&1]=min(c,min(1+memo[i][(j-1)&1],1+memo[i+1][j&1]));
            }
        }  
        printf("%d\n",memo[1][(t-1)&1]);
    }
                  
}
