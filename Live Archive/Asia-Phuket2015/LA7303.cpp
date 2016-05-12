
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 200

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct edge{
	
	int u, v, w;
	edge(){}
	edge(int _u, int _v, int _w){ u = _u; v = _v; w = _w; }
};

bool operator <(const edge &e1, const edge &e2){ return e1.w < e2.w; }	
vector<edge>E;

void addEdge(int u, int v, char c1, char c2, int dir){
	
	if(dir == 0){
		
		if(c1 == '/'){
			
			if(c2 == '/')E.pb(edge(u, v^1, 0));
			else E.pb(edge(u, v, 0));
		}
		else{
			
			if(c2 == '/')E.pb(edge(u^1, v^1, 0));
			else E.pb(edge(u^1, v, 0));
		}
	}
	if(dir == 1){
		
		if(c1 == '/'){
			
			if(c2 == '/')E.pb(edge(u^1, v, 0));
			else E.pb(edge(u^1, v^1, 0));
		}
		else{
			
			if(c2 == '/')E.pb(edge(u, v, 0));
			else E.pb(edge(u, v^1, 0));
		}
	}
	if(dir == 2)E.pb(edge(u, v^1, 0));
	if(dir == 3)E.pb(edge(u^1, v, 0));

	
}

int P[N * N];
int Find(int x){
	
	if(x == P[x])return x;
	return P[x] = Find(P[x]);	
}

void Union(int x, int y){
	
	x = Find(x);
	y = Find(y);
	P[x] = y;	
}

char T[N][N];
int cost[N][N];

int main(){

	int tc = 0, caso = 1;
	scanf("%d", &tc);
	
	while(tc--){
		
		int r, c;
		scanf("%d%d", &r, &c);
		
		for(int i = 0; i < r; i++)
			scanf("%s", T[i]);

		
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)scanf("%d", &cost[i][j]);
			
		int r1, c1, id1, id2;
		E.clear();
		
		for(int i = 0; i < r; i++){
			
			for(int j = 0; j < c; j++){
				
				id1 = 2 * (i * c + j);
				E.pb(edge(id1, id1^1, cost[i][j]));
				
				for(int k = 0; k < 4; k++){
				
					r1 = i + dx[k];
					c1 = j + dy[k];
					
					if(r1 < 0 || r1 >= r || c1 < 0 || c1 >= c)continue;
					id2 = 2 * (r1 * c + c1);
					
					addEdge(id1, id2, T[i][j], T[r1][c1], k);
					
				}
			}
		}
		
		for(int i = 0; i < 2 * r * c; i++)P[i] = i;
		sort(all(E));
		
		long long ans = 0;
		int u, v, w;
	
		for(int i = 0; i < E.size(); i++){
			
			u = E[i].u;
			v = E[i].v;
			w = E[i].w;	
			
			if(Find(u) == Find(v))continue;
			else{
				
				ans += w;
				Union(u, v);
			}		
		}
		
		printf("Case %d: %lld\n", caso++, ans);
			
				
		
		
	}


}

