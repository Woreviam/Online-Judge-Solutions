
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
		
		long long n, m;
		scanf("%lld%lld", &n, &m);
		
		if(n == 1 || m == 1){
			
			if(max(n, m) == 2)puts("Yes");
			else puts("No");	
		}
		else{
			
			if(n%2 == 0 || m%2 == 0)puts("Yes");
			else puts("No");
			/*
			. . . . .
			. . . . .
			. . . . . 
			. . . . .
			. . . . .
			*/
		}	
	}
		
}



