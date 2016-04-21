
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 100005
#define LOGN 24
#define INF (1<<30)

using namespace std;

vector<int>G[N], W[N], ID[N];

struct edge{
	
	int u, v, w;
	edge(){}
	edge(int _u, int _v, int _w){ u = _u; v = _v; w = _w; }
};

edge E[N];
int P[LOGN][N], D[LOGN][N], A[N], B[N], H[N];
vector<int>in[N], out[N];

void DFS(int u, int pd, int h, int lastW){
	
	H[u] = h;
	P[0][u] = pd;
	D[0][u] = lastW;
	
	for(int i = 1; (1<<i) <= h; i++){
		
		P[i][u] = P[i - 1][P[i - 1][u]];
		D[i][u] = max(D[i - 1][u], D[i - 1][P[i - 1][u]]);
	}
	
	for(int i = 0, v, w; i < G[u].size(); i++){
	
		v = G[u][i];
		w = W[u][i];
		
		if(v == pd)continue;
		DFS(v, u, h + 1, w);
	}
}

multiset<int>s[N];
void solve(int u, int pd, int id){
	
	for(int i = 0, v, j; i < G[u].size(); i++){
	
		v = G[u][i];
		j = ID[u][i];
		
		if(v == pd)continue;
		solve(v, u, j);
		
		if(s[v].size() > s[u].size())swap(s[u], s[v]);
		while(s[v].size() > 0){
			
			s[u].insert(*s[v].begin());
			s[v].erase(s[v].begin());
		}
	}
	
	for(int i = 0; i < in[u].size(); i++)s[u].insert(in[u][i]);
	multiset<int>::iterator it;
	
	for(int i = 0; i < out[u].size(); i++){
		
		it = s[u].find(out[u][i]);
		if(s[u].size() > 0 && it != s[u].end())s[u].erase(s[u].find(out[u][i]));
		else while(true){};
	}
		
	if(id >= 0){
		
		if(s[u].size() == 0)A[id] = -1;
		else A[id] = min(A[id], *s[u].begin());
		B[id] = -1;
	}
}

int getMax(int u, int v, int &lca){
    
    if(u == v){
		
		lca = u;
		return 0;
	}
	
    if(H[u] < H[v])swap(u, v);// u es el de mayor altura
    
    int bit = 31 - __builtin_clz(H[u]);
    int ans = 0;
    
    for(int i = bit; i >= 0; i--){
        if(H[P[i][u]] > H[v]){
			
			ans = max(ans, D[i][u]);
			u = P[i][u]; 
		}
	}
	
	if(H[u] > H[v]){
		
		ans = max(ans, D[0][u]);
		u = P[0][u];
	}
	
	if(u == v){
		
		lca = u;
		return ans; //misma rama
	}
	
    bit = 31 - __builtin_clz(H[u]);
    
    for(int i = bit; i >= 0; i--){
        if(P[i][u] != P[i][v]){
			
			ans = max(ans, D[i][u]);
			ans = max(ans, D[i][v]);
			u = P[i][u], v = P[i][v];
		}
	}
    
    ans = max(ans, D[0][u]);
	ans = max(ans, D[0][v]);

    lca = P[0][u];
    return ans;
}

int main(){

	int tc = 0, caso = 1;
	scanf("%d", &tc);

	while(tc--){
		
		int n, m;
		scanf("%d%d", &n, &m);
		
		int u, v, w, type;
		for(int i = 0; i <= n; i++){
			
			G[i].clear();
			W[i].clear();
			ID[i].clear();
			in[i].clear();
			out[i].clear();
			s[i].clear();
			
			for(int j = 0; j < LOGN; j++)P[j][i] = 0, D[j][i] = -1;
			A[i] = INF;
		}
		
		for(int i = 0; i < m; i++){
			
			scanf("%d%d%d", &u, &v, &w);
			u--; v--;
			
			E[i] = edge(u, v, w);
			
			if(i < n - 1){
				
				G[u].pb(v);
				G[v].pb(u);
				
				W[u].pb(w);
				W[v].pb(w);
				
				ID[u].pb(i);
				ID[v].pb(i);
			}	
		}

		DFS(0, 0, 0, 0);
		int lca;
		
		for(int i = n - 1; i < m; i++){
			
			u = E[i].u; v = E[i].v;
			w = E[i].w;
			 
			A[i] = -1;
			B[i] = w - getMax(u, v, lca);
			
			//printf("%d %d %d %d\n", u, v, lca, getMax(u, v, lca));
			
			in[u].pb(w);
			in[v].pb(w);
			
			if(lca < 0 || lca >= n)while(true){};
			out[lca].pb(w);
			out[lca].pb(w);
		}
		
		solve(0, 0, -1);
		
		for(long long i = 0; i < n - 1; i++)if(A[i] >= 0)A[i] = A[i] - E[i].w;
		long long ans = 0;
		
		for(long long i = 1; i <= m; i++)
			ans += i * (A[i - 1] + B[i - 1] * i);
		
		printf("Case %d: %lld\n", caso++, ans);
	}
}

