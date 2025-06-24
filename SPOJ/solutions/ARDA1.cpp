
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define MAXN 2105
#define cout2(x, y) cout << x << " " << y << endl;

using namespace std;

typedef unsigned long long hash;

hash PO[2][MAXN], H[MAXN][MAXN], S[MAXN][MAXN];
char s[MAXN];

int K[2] = {31, 1001};
bool board[MAXN][MAXN];


int main(){

	PO[0][0] = PO[1][0] = 1;
	for(int i = 1; i < MAXN; i++){
		
		PO[0][i] = PO[0][i - 1] * K[0];
		PO[1][i] = PO[1][i - 1] * K[1];
	}
	
	int n1, n2;
	while(scanf("%d%d", &n1, &n2) == 2){
		
		hash h = 0, aux;
		for(int i = 0; i < n1; i++){
			
			scanf("%s", s);
			aux = 0;
			
			for(int j = 0; j < n2; j++)aux = aux * K[0] + (s[j] - 'a' + 1);
			h = h * K[1] + aux;
		}
		
		
		
		int m1, m2;
		scanf("%d%d", &m1, &m2);
		
		//vector<vector<hash> >H(m1 + 1, vector<hash>(m2 + 1, 0));
		//vector<vector<hash> >S(m1 + 1, vector<hash>(m2 + 1, 0));
		
		
		for(int i = 0; i < m1; i++){
			
			scanf("%s", s);	
			for(int j = 0; j < m2; j++){
				
				H[i + 1][j + 1] = H[i + 1][j] * K[0] + (s[j] - 'a' + 1);
				S[i + 1][j + 1] = S[i][j + 1] * K[1] + H[i + 1][j + 1];
			}
		}
		
		hash mat1, mat2, mat;
		//vector<pair<int, int> >res;
		int ct = 0;
		
		for(int i = n1; i <= m1; i++){
			for(int j = n2; j <= m2; j++){
				
				mat2 = S[i][j] - S[i][j - n2] * PO[0][n2];
				mat1 = S[i - n1][j] - S[i - n1][j - n2] * PO[0][n2];
				
				mat = mat2 - mat1 * PO[1][n1];
				if(mat == h){
					board[i - n1 + 1][j - n2 + 1] = true;
					ct++;
				}
					//res.pb(make_pair(i - n1 + 1, j - n2 + 1));	
			}
		}
		
		if(ct == 0)printf("NO MATCH FOUND...");
		else{
			
			for(int i = 1; i <= m1; i++)
				for(int j = 1; j <= m2; j++){
					
					if(board[i][j])printf("(%d,%d)\n", i, j), board[i][j] = false;
				}
			
			
		}
		
	}

}
