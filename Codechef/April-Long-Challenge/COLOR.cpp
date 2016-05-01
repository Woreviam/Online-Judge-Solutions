
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 100005

using namespace std;

char s[N];

int main(){

	int tc = 0;
	scanf("%d", &tc);

	while(tc--){
		
		int n;
		scanf("%d", &n);
			
		scanf("%s", s);
		int r = 0, b = 0, g = 0;
		
		for(int i = 0; i < n; i++){
			
			if(s[i] == 'G')g++;
			if(s[i] == 'B')b++;
			if(s[i] == 'R')r++;
		}
		
		int ans = min(n - r, n - b);
		ans = min(ans, n - g);
		
		printf("%d\n", ans);
	}
}



