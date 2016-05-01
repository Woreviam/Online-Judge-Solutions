
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 100005
#define MOD 1000000007

using namespace std;

long long fastPow(long long b, int e){
	
	long long ans = 1;
	if(b == 0)return 0;
	
	while(e > 0){
	
		if(e&1)ans = ans * b;
		if(ans >= MOD)ans %= MOD;
		
		b = b * b;
		if(b >= MOD)b %= MOD;
		
		e >>= 1;
	}
	return ans;
}

int main(){

	int tc = 0;
	scanf("%d", &tc);

	while(tc--){
		
		int n, k;
		scanf("%d%d", &n, &k);
		
		if(n == 1)printf("%d\n", k);
		else{
			
			long long ans = fastPow(k - 1, n - 1) * k;
			ans %= MOD;
			printf("%lld\n", ans);
		}
	}
		
}



