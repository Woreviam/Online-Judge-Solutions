
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 1000005

using namespace std;

int mapa[26];
bool vis[26];

char s[N];

int main(){

	int tc = 0;
	scanf("%d", &tc);
	
	while(tc--){
		
		scanf("%s", s);
		int n = strlen(s);
		
		memset(vis, false, sizeof vis);
		
		for(int i = 0; i < n; i++)
			if(s[i] != '_')vis[s[i] - 'A'] = true;
			
		int m;
		scanf("%d", &m);
		
		char c1[2], c2[2];
		for(int i = 0; i < 26; i++)mapa[i] = -1;
		
		for(int i = 0; i < m; i++){
			
			scanf("%s %s", c1, c2);
			if(!vis[c2[0] - 'A'])continue;
			
			for(int j = 0; j < 26; j++)if(mapa[j] == c2[0] - 'A')mapa[j] = c1[0] - 'A';
			mapa[c2[0] - 'A'] = c1[0] - 'A';
			
			vis[c2[0] - 'A'] = false;
			vis[c1[0] - 'A'] = true;
		}
		
		for(int i = 0; i < n; i++){
			
			if(s[i] == '_' || mapa[s[i] - 'A'] == -1)continue;
			s[i] = char('A' + mapa[s[i] - 'A']);	
		}
		
		printf("%s\n", s);
	}
	
	
	
	


}

