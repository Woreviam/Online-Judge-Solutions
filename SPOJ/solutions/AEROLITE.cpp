
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout<<x<<" "<<y<<endl
#define MAXN 100005
#define MOD 11380

using namespace std;

long long memo[11][11][11][31];

long long DP(int L1, int L2, int L3, int D){
	
	if(D < 0)return 0;
	if(L1 == 0 && L2 == 0 && L3 == 0)return 1;
	
	long long &ret = memo[L1][L2][L3][D];
	
	if(memo[L1][L2][L3][D] != -1)return memo[L1][L2][L3][D]; 
	long long ans = 0;

	for(int i = 0; i <= L1; i++){ //{
		for(int j = 0; j <= L2; j++){ //[
			for(int k = 0; k <= L3; k++){ //(
				 
				if(i + j + k == 0)continue;
				 
				if(i > 0)ans += DP(i - 1, j, k, D - 1) * DP(L1 - i, L2 - j, L3 - k, D);
				if(j > 0 && i == 0)ans += DP(i, j - 1, k, D - 1) * DP(L1 - i, L2 - j, L3 - k, D);
				if(k > 0 && i == 0 && j == 0)ans += DP(i, j, k - 1, D - 1) * DP(L1 - i, L2 - j, L3 - k, D);
				if(ans >= MOD)ans %= MOD;
			}
		}
	}
	
	return ret = ans;
	
}

int main(){

	int L1, L2, L3, D;
	memset(memo, -1, sizeof memo);
	
	while(scanf("%d%d%d%d", &L1, &L2, &L3, &D) == 4){

		long long ans = DP(L1, L2, L3, D) - DP(L1, L2, L3, D - 1);
		ans %= MOD;
		
		if(ans < 0)ans = (ans + MOD)%MOD;
		printf("%lld\n", ans);

	}

}
