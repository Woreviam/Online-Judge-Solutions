 
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 3mldirmk00005
#define MOD 1000000007

using namespace std;

char s[N];
long long fastPow(long long b, int e){
	
	long long ans = 1;
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

	int n, m;
	while(scanf("%d%d", &n, &m) == 2){
		
		int mod = 0, ct = 0;
		
		for(int i = 0; i < n; i++){
			
			mod = mod * 10 + s[i] - '0';
			if(mod >= m)mod %= m;
			if(mod == 0)ct++;
		}
		
		long long ans = 0;
		
		if(ct == 0)puts("0");
		else{
			
			ans = fastPow(2, ct - 1);
			printf("%lld\n", ans);	
		}
	}


}

