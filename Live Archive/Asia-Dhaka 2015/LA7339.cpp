
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 100005

using namespace std;

char s[N];
int frec[26];

int main(){

	int tc = 0, caso = 1;
	scanf("%d", &tc);

	while(tc--){
		
		memset(frec, 0, sizeof frec);
		
		scanf("%s", s);
		for(int i = 0; s[i]; i++)frec[s[i] - 'a']++;
		
		int mini = (1<<30);
		for(int i = 0; i < 26; i++)mini = min(mini, frec[i]);
		
		printf("Case %d: %d\n", caso++, mini);
	}
}

