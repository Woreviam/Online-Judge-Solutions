
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout<<x<<" "<<y<<endl
#define MAXN 100005


using namespace std;

int A[52], res[52], top;
long long AC[52];

int main(){

	int tc = 0, k;
	scanf("%d", &tc);
	
	while(tc--){
		
		long long n;
		scanf("%lld%d", &n, &k);
		
		for(int i = 0; i < k; i++)scanf("%d", &A[i]);
		AC[0] = A[0];
		
		for(int i = 1; i < k; i++)
			AC[i] = AC[i - 1] * 2 + A[i];
		
		top = 0;
		
		for(int i = k - 1; i >= 0; i--)
			if(AC[i] <= n)n -= AC[i], res[top++] = i + 1;	
		
		if(n == 0){
			
			printf("%d", res[top - 1]);
			for(int i = top - 2; i >= 0; i--)printf(" %d", res[i]);
			puts("");
			
		}
		else puts("-1");
	}


}
