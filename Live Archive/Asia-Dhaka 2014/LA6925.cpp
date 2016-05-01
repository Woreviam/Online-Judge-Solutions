
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 30
#define PI (2*acos(0.0))

using namespace std;

double c[N];
double c2[N];
int n;

long double eval(double x){
	
	long double ans = 0;
	for(int i = n; i >= 0; i--)	
		ans = ans * x + c[i];

	return ans;
}

long double integra(double x){
	
	long double ans = 0;
	for(int i = 2 * n; i >= 0; i--)	
		ans = ans * x + c2[i]/(i + 1);

	ans *= x;
	return PI * ans;
}

int main(){

	int tc = 0, caso = 1;
	scanf("%d", &tc);
	
	while(tc--){
		
		scanf("%d", &n);
		for(int i = n; i >= 0; i--)scanf("%lf", &c[i]);
		
		memset(c2, 0, sizeof c2);
		
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= n; j++)
				c2[i + j] += c[i] * c[j];

		double a, b;
		scanf("%lf%lf", &a, &b);
		
		long double v1 = integra(b) - integra(a), v2 = 0;
		
		int slices;
		scanf("%d", &slices);
		
		int stacks;
		scanf("%d", &stacks);
		
		long double l, r, s1, s2;
		long double h = (b - a)/stacks;
		
		long double teta = (2.0 * PI)/slices;
		
		for(int i = 0; i < stacks; i++){
				
			l = a + i * h;
			r = l + h;
			
			l = eval(l);
			r = eval(r);
			
			s1 = l * l;
			s2 = r * r;
			
			v2 += slices * h * (s1 + s2 + sqrt(s1 * s2))/3.0;
		}
		
		v2 *= sin(teta);
		v2 /= 2.0;
		
		double ans = fabs((v1 - v2)/v1) * 100.0;
		printf("Case %d: %.4lf\n", caso++, ans);
		
	}
}

