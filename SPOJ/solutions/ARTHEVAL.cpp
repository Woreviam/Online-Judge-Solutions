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
#define cout3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl
 

#define pb(x) push_back(x)
#define all(x) (x).begin(),(x).end()
using namespace std;
char s[1000005];  
long long val(int ini,int fin){
    for(int i=ini;i<=fin;i++)if(s[i]<'0' || s[i]>'9')return 0LL;
    long long ans=0;
    for(int i=ini;i<=fin;i++)ans=ans*10+s[i]-'0';
    return ans;
}      
long long F(int ini,int fin){
    if(ini>fin)return 0LL;
    if(ini==fin)return s[ini]-'0';
    int c=0;
    for(int i=fin;i>=ini;i--){
        if(s[i]=='(')c++;
        if(s[i]==')')c--;
        if(s[i]=='+' && c==0)return F(ini,i-1)+F(i+1,fin);
        if(s[i]=='-' && c==0)return F(ini,i-1)-F(i+1,fin);
        if(s[i]=='*' && c==0)return F(ini,i-1)*F(i+1,fin);
    }
    if(s[ini]=='(' && s[fin]==')')return F(ini+1,fin-1);
    return val(ini,fin);  
}      
                
int main(){
    scanf("%s",s);
        printf("%lld\n",F(0,strlen(s)-1)); 
       
}    
        

 
 
