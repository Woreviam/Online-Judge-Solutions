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
#define INF 1000000005
#define MOD 100000000

//^
using namespace std;

typedef pair<int, int> par;
par P[MAXN];
int n;

int memo[MAXN];
string trans(int num){

	if(num == 0)return "00000000";
	string ans;
	while(num > 0)ans.pb(num % 10 + '0'), num /= 10;
	
	reverse(all(ans));
	int tam = ans.size();
	
	return string(8 - tam, '0') + ans;
}

int main(){

	while(scanf("%d", &n) == 1){
		
		if(n <= 0)break;
		
		for(int i = 0; i < n; i++){
			scanf("%d%d", &P[i].first, &P[i].second);
		}
		
		sort(P, P + n);
		
		memo[n] = 1;
		for(int i = n - 1; i >= 0; i--)memo[i] = ( memo[i + 1] + memo[lower_bound(P + i + 1, P + n, make_pair(P[i].second, 0)) - P] )%MOD;
		
		string ans = trans((memo[0] - 1 + MOD) %MOD);
		printf("%s\n", ans.c_str());
	
	}
}




