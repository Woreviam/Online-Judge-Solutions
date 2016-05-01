
#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define cout2(x, y) cout << x << " " << endl;
#define N 10005
#define MOD 21092013

using namespace std;

vector<int>L[N];
int low[N], hi[N], ways[N][52][2];

void solve(int u, int pd, int d){
	
	int v;
	long long ans1 = 0, ans2 = 0, aux;

	for(int i = 0; i < L[u].size(); i++){
	     
        v = L[u][i];
	    if(v == pd)continue;

	    solve(v, u, d);
	     
	    ans2 += (ways[v][d][1] * ans1) % MOD;
	    if(ans2 >= MOD)ans2 -= MOD;
	     
	    ans1 += ways[v][d][1];
	    if(ans1 >= MOD)ans1 -= MOD;
	}
	
	long long ans = 0;
	for(int i = low[u]; i <= hi[u]; i++){
		
	   if(i%d == 0){
	   		
			ways[u][d][0] += (1 + ans2 + ans1)%MOD;
			if(ways[u][d][0] >= MOD)ways[u][d][0] -= MOD;
			
			ways[u][d][1] += (1 + ans1)%MOD;
			if(ways[u][d][1] >= MOD)ways[u][d][1] -= MOD;
	   }
	}

}

int fact[55];

void criba(){
	
    for(int i = 2; i * i <= 50; i++)
		if(!fact[i])for(int j = i * i; j <= 50; j += i)fact[j] = i;
     
    for(int i = 2; i <= 50; i++)if(fact[i] == 0)fact[i] = i;
}

int mu(int x){
	
	int f, ct = 0, e = 0;
	while(x > 1){
		
		f = fact[x];
		e = 0;
		
		while(x%f == 0)x /= f, e++;
		if(e > 1)return 0;
		ct++;
	}
	
	if(ct%2 == 0)return 1;
	return -1;
}

int res[N], ans[N];

int main(){

	criba();
	
	int tc = 0, caso = 1;
	scanf("%d", &tc);

	while(tc--){

		int n;
		scanf("%d", &n);
		
		for(int i = 0; i <= n; i++){
			
			L[i].clear();
			res[i] = ans[i] = 0;
			for(int j = 0; j <= 50; j++)ways[i][j][0] = ways[i][j][1] = 0;
		}
		
		int u, v;
		for(int i = 0; i < n - 1; i++){
			
			scanf("%d%d", &u, &v);
			u--; v--;
			
			L[u].pb(v);
			L[v].pb(u);
		}

		for(int i = 0; i < n; i++)scanf("%d", &low[i]);
		for(int i = 0; i < n; i++)scanf("%d", &hi[i]);

		for(int i = 1; i <= 50; i++){
			
			solve(0, 0, i);
			for(int j = 0; j < n; j++){	
				
				res[i] += ways[j][i][0];
				if(res[i] >= MOD)res[i] -= MOD;
			}
		}
		
		for(int i = 1; i <= 50; i++){
			
			ans[i] = res[i];
			for(int j = i + 1; j <= 50; j++){
				
				if(j%i != 0)continue;
				ans[i] += res[j] * mu(j/i);
				
				if(ans[i] >= MOD)ans[i] -= MOD;
				else if(ans[i] < 0)ans[i] += MOD;
			}
		}
		
		printf("Case %d:\n", caso++);
		
		for(int i = 1; i <= 50; i++)
			printf("%d: %d\n", i, ans[i]);
		
	}
}
