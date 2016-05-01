
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 100005

using namespace std;

int main(){

	int tc = 0, caso = 1;
	scanf("%d", &tc);
	
	while(tc--){
		
		long long A, B;
		scanf("%lld%lld", &A, &B);
		
		long long or_res = 0, and_res = 0;
		for(int i = 0; i < 63; i++){
			
			if(((A>>i)&1LL) == ((B>>i)&1LL)){
				
				if((A>>i)&1LL){
					
					or_res ^= (1LL<<i);
					if((B - A + 1) <= (1LL<<i))and_res ^= (1LL<<i);
				}
				else{
					
					if((B - A + 1) > (1LL<<i))or_res ^= (1LL<<i);	
				}
			}
			else or_res ^= (1LL<<i);
		}
		
		printf("Case %d: %lld %lld\n", caso++, or_res, and_res);
		
	}


}

