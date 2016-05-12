
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 200000

using namespace std;

char s[N];

int main(){

	while(scanf("%s", s) == 1){
		
		int n = strlen(s);
		int num, d1, d2;
		
		for(int i = 0; i < n; i += 2){
			
			if(s[i] >= '0' && s[i] <= '9')d1 = s[i] - '0';
			else d1 = 10 + s[i] - 'A';
				
			if(s[i + 1] >= '0' && s[i + 1] <= '9')d2 = s[i + 1] - '0';
			else d2 = 10 + s[i + 1] - 'A';
			
			num = d1 * 16 + d2;
			putchar(num);
		}
		puts("");
	}


}

