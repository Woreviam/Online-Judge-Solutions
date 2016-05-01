
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 100005
#define MOD 1000000007

using namespace std;

int main(){

	int tc = 0, caso = 1;
	scanf("%d", &tc);
	
	while(tc--){
		
		int n;
		scanf("%d", &n);
		
		vector<pair<int, long long> >v(n);
		
		for(int i = 0; i < n; i++)
			scanf("%d%lld", &v[i].first, &v[i].second);
		
		sort(all(v));
		long long ans = 0, ways = 1, ac = 0;
		
		for(int i = 0; i < n; i++){
			
			ans += (ac + v[i].second) * v[i].second;
			ac += v[i].second;

			
			if(i != n - 1){
				
				ways = ways * (v[i].second + 1);
				if(ways >= MOD)ways %= MOD;
			}
		}
		
		printf("Case %d: %lld %lld\n", caso++, ans, ways);
	}


}

