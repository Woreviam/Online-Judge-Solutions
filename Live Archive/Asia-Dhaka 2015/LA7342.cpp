
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 100005

#define y second
#define x first
#define INF (1<<28)

using namespace std;

int x[N], y[N];
pair<int, int>p[6];
pair<long long, long long>L, R, LU, RU, LD, RD, point; 

int dirx[] = {0, 1, 1, 0, -1, -1};
int diry[] = {1, -1, 0, 1, 1, -1};

int acx[] = {0, 1, 2, 2, 1, 0};
int acy[] = {0, -1, -1, 0, 1, 1};

bool check(pair<int, int>p, int len){
	
	len--;
	
	if(p.x > L.x)return false;
	p.x += len; p.y -= len;
	
	if(p.x + p.y > LD.x + LD.y)return false;
	p.x += len;

	if(p.y > RD.y)return false;
	p.y += len;
	
	if(p.x < R.x)return false;
	p.x -= len; p.y += len;
	
	if(p.x + p.y < RU.x + RU.y)return false;
	if(p.y < LU.y)return false;
	
	return true;
}

	
int main(){

	int tc = 0, caso = 1;
	scanf("%d", &tc);
	
	while(tc--){
		
		int n;
		scanf("%d", &n);

		R = make_pair(-INF, 0);
		L = make_pair(INF, 0);
		
		RU = make_pair(-INF, -INF);
		LD = make_pair(INF, INF);
		
		RD = make_pair(-INF, INF);
		LU = make_pair(INF, -INF);
		
		for(int i = 0; i < n; i++){
			
			scanf("%d%d", &x[i], &y[i]);
			point = make_pair(x[i], y[i]);
			
			if(x[i] < L.x)L = point;
			if(x[i] > R.x)R = point;
			
			if(x[i] + y[i] < LD.x + LD.y)LD = point;
			if(x[i] + y[i] > RU.x + RU.y)RU = point;
			
			if(y[i] < RD.y)RD = point;
			if(y[i] > LU.y)LU = point;
			
		}
	
		int k = (LD.x - L.x);
		p[0] = make_pair(L.x, LD.y + k);
		
		k = LD.y - RD.y;
		p[1] = make_pair(LD.x + k, LD.y - k);
		
		p[2] = make_pair(R.x, p[1].y);
		
		k = R.x - RU.x;
		p[3] = make_pair(RU.x + k, RU.y - k);
		
		k = LU.y - RU.y;
		p[4] = make_pair(RU.x - k, RU.y + k);
		
		p[5] = make_pair(L.x, LU.y);
		
		int lo = 1, hi = 40000, me;
		
		while(lo < hi){
			
			me = lo + (hi - lo)/2;
			bool found  = false;
			
			pair<int, int>c, aux;

			for(int i = 0; i < 6 && !found; i++){
				
				aux = p[i];
				for(int j = 0; j <= me && !found; j++){
					
					c.x = p[i].x - acx[i] * (me - 1);
					c.y = p[i].y - acy[i] * (me - 1);
					if(check(c, me))found = true;
					
					p[i].x += dirx[i];
					p[i].y += diry[i];

				}
				p[i] = aux;
			}
			
			if(found)hi = me;
			else lo = me + 1;	
		}
		

		long long ans = lo;
		ans = 1 + 3 * ans * (ans - 1);
		printf("Case %d: %lld\n", caso++, ans);
		
	}
}

