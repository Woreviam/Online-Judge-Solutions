#include<bits/stdc++.h>
#define MAXN 1005

#define cout2(x, y) cout<<x<<" "<<y<<endl
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()

using namespace std;

#define EPS 1e-6
#define PI (3.141)
#define Vector Point

struct Point
{
    double x, y;
    int id;
    
    Point(){}
    Point(double a, double b) { x = a; y = b; }
    double mod2() { return x*x + y*y; }
    double mod()  { return sqrt(x*x + y*y); }
    double arg()  { return atan2(y, x); }
    Point ort()   { return Point(-y, x); }
    Point unit()  { double k = mod(); return Point(x/k, y/k); }
};

Point operator +(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator -(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
Point operator /(const Point &a, double k) { return Point(a.x/k, a.y/k); }
Point operator *(const Point &a, double k) { return Point(a.x*k, a.y*k); }

bool operator ==(const Point &a, const Point &b)
{
    return abs(a.x - b.x) < EPS && abs(a.y - b.y) < EPS;
}
bool operator !=(const Point &a, const Point &b)
{
    return !(a==b);
}
bool operator <(const Point &a, const Point &b)
{
    if(abs(a.x - b.x) > EPS) return a.x < b.x;
    if(abs(a.y - b.y) > EPS)return a.y + EPS < b.y;
    return a.id < b.id;
}


Point P[MAXN], C1, C2;
bool vis[MAXN];

int n;

int cuenta(double r){
	
	int ans = 0;
	
	for(int i = 0; i < n; i++){
		
		if(vis[i])continue;
		if(fabs(r - (P[i] - C2).mod2()) < EPS || r > (P[i] - C2).mod2())ans++;
		//if(r >= (P[i] - C2).mod2())ans++;
	}	
	
	return ans;
	
}


int main(){

	int caso = 1;
	while(cin>>n){

		if(n == 0)break;
		double area;
		
		scanf("%lf%lf%lf%lf%lf", &C1.x, &C1.y, &C2.x, &C2.y, &area);
		
		vector<pair<double, Point> >V;
		double r;
		
		for(int i = 0; i < n; i++){
			
			scanf("%lf%lf", &P[i].x, &P[i].y);
			P[i].id = i;
			
			r = (P[i] - C1).mod2();
			V.pb(make_pair(r, P[i]));
			
		}
		
		sort(all(V));
		int maxi = 0;
		
		memset(vis, false, sizeof vis);
		double S;
		
		maxi = max(maxi, cuenta(area/PI));
		
		for(int i = 0; i < n; i++){
		
			S = V[i].first * PI;
			if(S > area)break;

			vis[V[i].second.id] = true;
			double radio = (area - S)/PI;
			
			maxi = max(maxi, i + 1 + cuenta(radio));
			
		}
		
		printf("%d. %d\n", caso++, n - maxi);
	
	}

}



