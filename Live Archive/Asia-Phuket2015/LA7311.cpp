
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 200000

using namespace std;


int main(){

	int n;
	scanf("%d", &n);

	int f[3] = {0, 0, 0};
	int c[3];
	
	for(int i = 0; i < n; i++){
		
		for(int j = 0; j < 3; j++)scanf("%d", &c[j]);
		for(int j = 0; j < 3; j++)f[j] += c[j];

		int mini = min(min(f[0], f[1]), f[2]);
		
		if(mini >= 30){
			
			printf("%d\n", mini);
			for(int j = 0; j < 3; j++)f[j] -= mini;
		}
		else puts("NO");
	}

}

