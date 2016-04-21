
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 100005
#define ones(x) __builtin_popcount(x)
#define MOD 1000000007

using namespace std;

long long nums[1<<10];
string cad;

long long memo[11][2][2], C[1<<10];

long long DP(int pos, int menor, int push, int mask){
	
	if(pos == cad.size())return push;
	long long &ret = memo[pos][menor][push];
	
	if(ret != -1)return ret;
	int ans = 0;
	
	if(menor && push)ans = ones(mask) * DP(pos + 1, menor, push, mask);
	if(menor && !push){
		
		for(int i = 1; i < 10; i++)if((mask>>i)&1)ans += DP(pos + 1, menor, 1, mask);
		ans += DP(pos + 1, menor, push, mask);	
	}
	
	if(!menor && push){
		
		int d = cad[pos] - '0';
		for(int i = 0; i < d; i++){
			
			if((mask>>i)&1)
				ans += DP(pos + 1, 1, push, mask);	
		}
		if((mask>>d)&1)ans += DP(pos + 1, 0, push, mask);
	}
	
	if(!menor && !push){
		
		ans += DP(pos + 1, 1, push, mask);
		int d = cad[pos] - '0';
		
		for(int i = 1; i < d; i++){
			
			if((mask>>i)&1)
				ans += DP(pos + 1, 1, 1, mask);	
		}
		
		if(d != 0 && ((mask>>d)&1))ans += DP(pos + 1, 0, 1, mask);
	}
	
	return ret = ans;
}

string toString(int num){
	
	string ans = "";
	if(num == 0)return "0";
	
	while(num > 0){
	
		ans += char('0' + num % 10);
		num /= 10;
	}
	
	reverse(all(ans));
	return ans;
}

long long F[1<<10][1<<10];
long long ways(int pos, int mask){
	
	if(pos == (1<<10))return mask != 0;
	long long &ret = F[pos][mask];
	
	if(ret != -1)return ret;
	long long ans = ways(pos + 1, mask);
	if((pos&mask) == 0)ans += (C[pos] * ways(pos + 1, mask^pos))%MOD;
	
	if(ans >= MOD)ans -= MOD;
	return ret = ans;	
}

int main(){

	int tc = 0, caso = 1;
	scanf("%d", &tc);
	
	while(tc--){
		
		int n;
		
		scanf("%d", &n);
		cad = toString(n);
		
		for(int i = 1; i < (1<<10); i++){
			
			memset(memo, -1, sizeof memo);
			nums[i] = DP(0, 0, 0, i);
		}
		
		for(int i = 1; i < (1<<10); i++){
			
			C[i] = 0;
			for(int j = i; j > 0; j = (j - 1)&i){
			
				if((ones(i) - ones(j))&1)C[i] -= nums[j];
				else C[i] += nums[j]; 
			}
		}
		
		memset(F, -1, sizeof F);
		long long ans = ways(0, 0);

		printf("Case %d: %lld\n", caso++, ans);
		
	}
}

