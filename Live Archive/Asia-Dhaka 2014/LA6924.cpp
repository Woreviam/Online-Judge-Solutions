
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 100005
#define MOD 1000000007
#define INF (1<<30)

using namespace std;

int frec[162];

int main(){

    int tc = 0, caso = 1;
    scanf("%d", &tc);
    
    while(tc--){
    	
    	int n, x;
    	scanf("%d", &n);
    	
    	memset(frec, 0, sizeof frec);
    	for(int i = 0; i < n; i++)scanf("%d", &x), frec[x]++;
    	
    	vector<int>f(3, 0), ans(3, 0);
    	long double dis = INF, aux;
    	
    	for(int i = 0; i < 158; i++){
    		
    		f[0] += frec[i];
    		f[1] = 0;
    		
    		for(int j = i + 1; j < 159; j++){
    			
    			f[1] += frec[j];
    			f[2] = 0;
    			
				for(int k = j + 1; k < 160; k++){
				    
				    f[2] += frec[k];
				    aux = fabs(n/4.0 - f[0]) + fabs(n/4.0 - f[1]) + fabs(n/4.0 - f[2]) + fabs(n/4.0 - (n - f[0] - f[1] - f[2]));
				    
				    if(dis > aux){
				    	
				    	dis = aux;
				    	ans[0] = i;
				    	ans[1] = j;
				    	ans[2] = k;
				    }
				}
			}
    	}
    	
    	printf("Case %d: %d %d %d\n", caso++, ans[0], ans[1], ans[2]);
    	

    }
}


