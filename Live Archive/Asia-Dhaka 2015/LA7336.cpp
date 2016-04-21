
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 20001

using namespace std;

int main(){

	int tc = 0;
	scanf("%d", &tc);
	
	while(tc--){
		
		vector<int>v1, v2;
		char car;
		
		int q, p, leaked;
		scanf("%d", &q);
		
		for(int i = 0; i < q; i++){
			
			scanf("%d %d %c", &p, &leaked, &car);
			if(car == 'c' && leaked == 1)v1.pb(p);
			if(car == 'i' && leaked == 0)v2.pb(p);
		}
		
		
		sort(all(v2));
		long long ans = 0;
		
		for(int i = 0; i < v1.size(); i++)
			ans += lower_bound(all(v2), v1[i]) - v2.begin();
		
		printf("%lld\n", ans);
	}
}

