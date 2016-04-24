
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 100005
#define LOG 19

using namespace std;

vector<int>L[N], W[N];
int P[LOG][N], dis[N], H[N], res[N];

int getLCA(int u, int v){
    
    if(u == v)return u;
    if(H[u] < H[v])swap(u, v);// u es el de mayor altura
    
    int bit = 31 - __builtin_clz(H[u]);
        
    for(int i = bit; i >= 0; i--)
        if(H[P[i][u]] > H[v])u = P[i][u];  
	
	if(H[u] > H[v])u = P[0][u];
	if(u == v)return u; //misma rama
	
    bit = 31 - __builtin_clz(H[u]);
    
    for(int i = bit; i >= 0; i--)
        if(P[i][u] != P[i][v])u = P[i][u], v = P[i][v];
    
    
    return P[0][u];
}


int solve(int u, int v, int anc){
	
	int diam = dis[u] + dis[v] - 2 * dis[anc];
	if(dis[u] == dis[v])return dis[u] - dis[anc];
	
	int cur1 = u, cur2 = v;
	int d1, d2;
	
	for(int i = LOG - 1; i >= 0; i--){
		
		if(H[P[i][cur1]] >= H[anc] && 2 * (dis[u] - dis[P[i][cur1]]) < diam)cur1 = P[i][cur1];
		if(H[P[i][cur2]] >= H[anc] && 2 * (dis[v] - dis[P[i][cur2]]) < diam)cur2 = P[i][cur2];
	}
	
	if(cur1 != anc){
		
		d1 = dis[u] - dis[P[0][cur1]];
		d2 = dis[cur1] + dis[v] - 2 * dis[anc];
	}
	else{
		
		d1 = dis[v] - dis[P[0][cur2]];
		d2 = dis[cur2] + dis[u] - 2 * dis[anc];	
	}
	
	return min(d1, d2); 
}

int DFS(int u, int pd, int len, int h, int &ext1, int &ext2){
	
	P[0][u] = pd; dis[u] = len;
	H[u] = h;
	
	for(int i = 1; (1<<i) <= h; i++)
		P[i][u] = P[i - 1][P[i - 1][u]];
	
	int e1, e2, best1 = u, best2 = u, diam = 0, aux_d1, aux_d2, anc;
	for(int i = 0; i < L[u].size(); i++){
		
		int v = L[u][i];
		int w = W[u][i];
		
		if(v == pd)continue;
		aux_d1 = DFS(v, u, len + w, h + 1, e1, e2);
		
		anc = getLCA(best1, e1);
		aux_d2 = dis[e1] + dis[best1] - 2 * dis[anc];
		
		if(diam < aux_d2){
			
			if(aux_d1 >= aux_d2){
				
				diam = aux_d1;
				best1 = e1;
				best2 = e2;
			}
			else{
				
				diam = aux_d2;
				best2 = e1;
				if(dis[best1] < dis[best2])swap(best1, best2);
			}
		}	
	}
	
	ext1 = best1; ext2 = best2;
	anc = getLCA(ext1, ext2);
	
	res[u] = solve(ext1, ext2, anc);
	return dis[ext1] + dis[ext2] - 2 * dis[anc];
}


int main(){

	int tc = 0;
	scanf("%d", &tc);
	
	while(tc--){
		
		int n;
		scanf("%d", &n);
		
		for(int i = 0; i <= n; i++){
			
			L[i].clear();	
			W[i].clear();
			
			dis[i] = 0;
			for(int j = 0; j < LOG; j++)P[j][i] = 0;
		}
		
		int u, v, w;
		for(int i = 0; i < n - 1; i++){
			
			scanf("%d%d%d", &u, &v, &w);
			u--; v--;
			
			L[u].pb(v);
			L[v].pb(u);
			
			W[u].pb(w);
			W[v].pb(w);
		}
		
		int e1 = 0, e2 = 0;
		DFS(0, 0, 0, 0, e1, e2);
		
		for(int i = 0; i < n; i++)
			printf("%d\n", res[i]);	

	}


}

