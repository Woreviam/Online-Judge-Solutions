
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 20000001

using namespace std;

int fact[N];
int criba(){
	
	for(int i = 2; i * i < N; i++)
		if(!fact[i])
			for(int j = i * i; j < N; j += i)fact[j] = i;
	
	for(int i = 2; i < N; i++)
		if(fact[i] == 0)fact[i] = i;
}

long long getSum(long long n){
	
	long long ans = 1, f, aux;
	
	while(n > 1){
	
		f = fact[n];
		aux = 1;
		while(n%f == 0)n /= f, aux *= f;
		ans *= (aux * f - 1)/(f - 1);
	}
	return ans;
}

long long ac[N];

int main(){

	criba();
	for(int i = 2; i < N; i++)ac[i] = ac[i - 1] + getSum(i);
	
	int n;
	while(scanf("%d", &n) == 1){
		
		if(n == 0)break;
		printf("%lld\n", ac[n]);
		
	}
}

