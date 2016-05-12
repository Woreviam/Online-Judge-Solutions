
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 100005

using namespace std;

int t[N];

int main(){

	int tc = 0, caso = 1;
	scanf("%d", &tc);
	
	while(tc--){
		
		int n, L;
		scanf("%d%d", &n, &L);
		
		for(int i = 0; i < n; i++)scanf("%d", &t[i]);
		sort(t, t + n);
		
		int ac = 0, ans = 0, last = 0;
		long long penalty = 0;
		
		for(int i = 0; i < n; i++){
			
			ac += t[i];
			if(ac <= L)ans++, penalty += ac, last = ac;
			else break;	
		}
		
		printf("Case %d: %d %d %lld\n", caso++, ans, last, penalty);
	}


}

