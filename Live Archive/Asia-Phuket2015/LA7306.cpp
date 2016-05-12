
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 10000005
#define EPS 1e-4
#define MOD 1000000007

using namespace std;

bool prime[N];
int prod_primes[N];

void criba(){
	
	for(int i = 2; i * i < N; i++){
	
		if(!prime[i])for(int j = i * i; j < N; j += i)prime[j] = true;
	}
	
	prod_primes[0] = prod_primes[1] = 1;
	long long prod = 1;
	
	for(int i = 2; i < N; i++){
		
		if(!prime[i]){
			
			prod = prod * i;
			if(prod >= MOD)prod %= MOD;
			prod_primes[i] = prod;
		}
		else prod_primes[i] = prod;
	}
}

long long fastPow(long long b, int e){
	
	if(b == 0)return 0;
	long long ans = 1;
	
	while(e > 0){
		
		if(e&1)ans *= b;
		if(ans >= MOD)ans %= MOD;
		
		b = b * b;
		if(b >= MOD)b %= MOD;
		
		e >>= 1;
	}
	return ans;
}

int check(int sq, int e, long long n){
	
	int last = sq;
	long long aux;
	
	for(int i = sq - 4; i <= sq + 4; i++){
		
		if(i < 0)continue;
		bool ok = true;
		aux = 1;
		
		for(int j = 0; j < e && ok; j++){
			
			if(aux * i > n)ok = false;
			aux *= i;
		}
		
		if(ok)last = i;
	}
	
	return last;
}

int main(){

	criba();

	int tc = 0, caso = 1;
	scanf("%d", &tc);
	
	while(tc--){
		
		long long n;
		scanf("%lld", &n);
		
		int sq = (sqrt(n) + EPS);

		long long ans = prod_primes[sq];
		ans = (ans * ans)%MOD;
		
		for(int i = 3; i < 62; i++){
			
			sq = (pow(n, 1.0/i) + EPS);
			sq = check(sq, i, n);
			
			if(sq == 1)break;
			ans = (ans * prod_primes[sq])%MOD;
		}
	
		sq = (sqrt(n)+ EPS);
		ans = (ans * fastPow(prod_primes[sq], MOD - 2))%MOD;
		
		printf("Case %d: %lld\n", caso++, ans);
	}
}

