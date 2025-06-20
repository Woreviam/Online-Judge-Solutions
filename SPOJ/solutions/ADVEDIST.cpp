#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout<<x<<" "<<y<<endl
#define cout3(x, y, z) cout<<x<<" "<<y<<" "<<z<<endl;
#define MAXN 1002
#define INF (1<<26)


using namespace std;

int next1[MAXN][26], next2[MAXN][26], last[26], len1, len2;
int memo[MAXN][MAXN];

char s1[MAXN], s2[MAXN];

int DP(int p1, int p2){
	
	if(p1 == len1)return len2 - p2;	
	if(p2 == len2)return len1 - p1;
	
	if(memo[p1][p2] != -1)return memo[p1][p2];
	int ans = INF, NEXT;
	
	if(s1[p1] == s2[p2])ans = DP(p1 + 1, p2 + 1);
	else{
		
		ans = min(ans, 1 + DP(p1, p2 + 1));//erase
		ans = min(ans, 1 + DP(p1 + 1, p2 + 1));//reeplace
		ans = min(ans, 1 + DP(p1 + 1, p2));//insert
		
		NEXT = next1[p2][s1[p1] - 'a'];
		if(p1 < len1 - 1 && s1[p1 + 1] == s2[p2] && NEXT < len2){
			ans = min(ans, NEXT - p2 + DP(p1 + 2, NEXT + 1));
		}
		
		NEXT = next2[p1][s2[p2] - 'a'];
		if(p2 < len2 - 1 && s2[p2 + 1] == s1[p1] && NEXT < len1){
			ans = min(ans, NEXT - p1 + DP(NEXT + 1, p2 + 2));
		}
		
	}
	
	return memo[p1][p2] = ans;
}

int main(){

	while(scanf("%s%s", s1, s2) == 2){
		
		if(s1[0] == '*')break;
		
		len1 = strlen(s1);
		len2 = strlen(s2);
		
		for(int i = 0; i < 26; i++)last[i] = len2;
		
		for(int i = len2 - 1; i >= 0; i--){
			for(int j = 0; j < 26; j++)next1[i][j] = last[j];
			last[s2[i] - 'a'] = i;
		}
		
		for(int i = 0; i < 26; i++)last[i] = len1;
		
		for(int i = len1 - 1; i >= 0; i--){
			for(int j = 0; j < 26; j++)next2[i][j] = last[j];
			last[s1[i] - 'a'] = i;
		}

		memset(memo, -1, sizeof memo);
		int ans = DP(0, 0);
		
		printf("%d\n", ans);
		
	}


}

