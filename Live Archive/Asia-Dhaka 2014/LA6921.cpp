
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 30
#define PI (2*acos(0.0))

using namespace std;

int main(){

	int tc = 0, caso = 1;
	scanf("%d", &tc);
	
	while(tc--){
		
		double w, h, x, xe, ye, u;
		scanf("%lf%lf", &w, &h);
		
		scanf("%lf", &x);
		scanf("%lf%lf", &xe, &ye);
		
		scanf("%lf", &u);
		
		if(h <= ye * (w - x)/(xe - x))printf("%.4lf\n", 0.0);
		else{
			
			double hip = sqrt((ye - h) * (ye - h) + (xe - w) * (xe - w));
			double sinTeta1 = (xe - w)/hip;
			double sinTeta2 = sinTeta1/u;
			
			double TgTeta1 = (xe - w)/(ye - h);
			double cosTeta2 = sqrt(1 - sinTeta2 * sinTeta2);
			
			double TgTeta2 = sinTeta2/cosTeta2;
			double hreq = (xe - x - TgTeta1 * ye)/(TgTeta2 - TgTeta1);
			
			if(hreq > h)puts("Impossible");
			else printf("%.4lf\n", hreq);
		}
		
	}
}

