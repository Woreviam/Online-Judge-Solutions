
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 100005
#define MOD 1000000007

#define v1 2 * node
#define v2 2 * node + 1
#define me (ini + fin)/2

using namespace std;


struct nod{
	
	long long s1, s2;//s1 > s2
	nod(){}
	nod(long long _s1, long long _s2){ s1 = _s1; s2 = _s2; };
};

nod operator +(const nod &n1, const nod &n2){
	
	nod ans(0, 0);
	long long aux1 = (((n1.s1 + n1.s2) * n2.s1)%MOD  + (n1.s1 * n2.s2)%MOD + n1.s1 + n2.s1)%MOD;
	long long aux2 = ((n1.s1 * n2.s1)%MOD  + (n1.s2 * n2.s2)%MOD + n1.s2 + n2.s2)%MOD;
	return nod(aux1, aux2);	
}

nod tree[4 * N];

void update(int node, int ini, int fin, int pos, const nod &val){
	
	if(ini > pos || fin < pos)return;
	if(ini == fin){
	
		if(pos == ini)tree[node] = val;
		return;
	}
	
	update(v1, ini, me, pos, val);
	update(v2, me + 1, fin, pos, val);
	
	tree[node] = tree[v1] + tree[v2];
}

nod query(int node, int ini, int fin, int b, int e){
	
	if(ini > e || fin < b)return nod(0, 0);
	if(ini >= b && fin <= e)return tree[node];
	return query(v1, ini, me, b, e) + query(v2, me + 1, fin, b, e);		
}

#define size 2

struct Matrix{
	
	long long M[size][size];
	
	Matrix(){}
	void init(){ 
		
		memset(this -> M, 0, sizeof(this -> M));
		for(int i = 0; i < size; i++)(this -> M[i][i]) = 1;
	}
	
	Matrix operator *(const Matrix &aux){
		
		Matrix ans;
		memset(ans.M, 0, sizeof(ans.M));
		
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				
				long long ac = 0;
				for(int k = 0; k < size; k++){
					
					ac += ((this -> M[i][k]) * aux.M[k][j])%MOD;
					if(ac >= MOD)ac -= MOD;	
				}
				ans.M[i][j] = ac;
			}
		}
		
		return ans;
	}
	
	Matrix pow(long long e){
		
		Matrix ans, b = (*this);
		ans.init();
		
		if(e == 0)return ans;
		while(e > 0){
			
			if(e&1)ans = ans * b;
			b = b * b;
			e >>= 1;	
		}
		return ans;
	}
};

long long getFibo(long long n){
	
	if(n == 0)return 0;
	if(n <= 2)return 1;
	
	Matrix fibo;
	fibo.M[0][0] = fibo.M[0][1] = fibo.M[1][0] = 1;
	fibo.M[1][1] = 0;
	
	fibo = fibo.pow(n - 2);
	return (fibo.M[0][0] + fibo.M[0][1]) % MOD;
}	

int main(){
	
	int n, m;
	scanf("%d%d", &n, &m);
		
	for(int i = 0; i <= 4 * n; i++)tree[i] = nod(0, 0);
	int x, y, l, r;
	
	char type[2];	
	nod s;
	
	for(int i = 0; i < n; i++){
		
		scanf("%d", &x);
		s = nod(getFibo(x), getFibo(x - 1));
		update(1, 0, n - 1, i, s);
	}
		
	for(int i = 0; i < m; i++){
			
		scanf("%s", type);
		if(type[0] == 'C'){
				
			scanf("%d%d", &x, &y);
			x--;
			update(1, 0, n - 1, x, nod(getFibo(y), getFibo(y - 1)));	
		}
		else{
				
			scanf("%d%d", &l, &r);
			l--; r--;
			
			s = query(1, 0, n - 1, l, r);
			printf("%lld\n", s.s1);
		}
	}
		
}



