
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 100005
#define ones(x) __builtin_popcount(x)


using namespace std;

char car[3] = {'a', 'b', 'c'};
vector<vector<char> > masks[28];
int n, A;

void back(int pos, vector<char>&state){
	
	if(pos > 0)masks[pos].pb(state);
	if(pos == n)return;	
	
	
	for(int p = 0; p < A; p++){
		
		bool ok = true;
		char bit = car[p];
		
		for(int i = 0, j; i < pos && ok; i++){
			
			if(state[i] != bit)continue;
			j = 2 * i - pos;
			if(j >= 0 && state[j] == bit)ok = false;	
		}
		
		if(ok){
			
			state.pb(bit);
			back(pos + 1, state);
			state.pop_back();
		}
	}
	
	
}

char s[N];
bool check(int mask){
	
	int l;
	for(int i = 0; i < n; i++){
		
		for(int j = 0; j < i; j++){
			
			if(((mask>>j)&1) != ((mask>>i)&1))continue;
			l = 2 * j - i;
			
			if(l >= 0 && ((mask>>l)&1) == ((mask>>i)&1))return false;
		}
	}
	return true;
}

int main(){

	int tc = 0;
	scanf("%d", &tc);
	
	vector<char>state;
	n = 26; A = 3;
	back(0, state);
	
	while(tc--){
		
		int K;
		
		scanf("%d%d%s", &A, &K, s);
		n = strlen(s);

		if(A == 1){
			
			if(n >= 3)puts("0");
			else puts("1");
			continue;	
		}
		
		if(A == 2){
			
			if(n >= 9)puts("0");
			else{
				
				int mask = 0, ans = 0;
				
				for(int i = 0; i < n; i++)
					if(s[i] == 'b')mask |= (1<<i);
	
				for(int i = 0; i < (1<<n); i++)
					if(check(i) && ones(mask^i) <= K)ans++;
						
				printf("%d\n", ans);	
			}
			continue;	
		}
		
		if(n >= 27 && A == 3){
			
			puts("0");
			continue;	
		}
		
		int ans = 0;
		
		for(int i = 0; i < masks[n].size(); i++){

			int dif = 0;
			for(int j = 0; j < n && dif <= K; j++)if(masks[n][i][j] != s[j])dif++;
			if(dif <= K)ans++;
		}
		
		printf("%d\n", ans);
	}
}

