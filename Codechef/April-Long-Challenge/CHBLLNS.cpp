#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 100005

using namespace std;

long long C[3];

int main(){

	int tc = 0;
	scanf("%d", &tc);

	while(tc--){
		
		long long k;
		
		for(int i = 0; i < 3; i++)scanf("%lld", &C[i]);
		scanf("%lld", &k);
		
		long long ans = 0;
		vector<long long>v;
		
		for(int i = 0; i < 3; i++){
			
			if(C[i] >= k)v.pb(C[i]);
			else ans += C[i];
		}

		int len = v.size();
		ans += (k - 1) * len + 1;
		
		printf("%lld\n", ans);
	}
		
}

