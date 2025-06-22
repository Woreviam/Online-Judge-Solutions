#include<iostream>
#include<cmath>
#include<cstdio>
#define EPS 1e-8 
#define PI acos(-1) 
#define Vector Point 
#define MAXN 1002

using namespace std;

struct Point 
{ 
    double x, y; 
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
    return a.y + EPS < b.y; 
} 
  
//### FUNCIONES BASICAS ############################################################# 
  
double dist(const Point &A, const Point &B)    { return hypot(A.x - B.x, A.y - B.y); } 
double cross(const Vector &A, const Vector &B) { return A.x * B.y - A.y * B.x; } 
double dot(const Vector &A, const Vector &B)   { return A.x * B.x + A.y * B.y; } 
double area(const Point &A, const Point &B, const Point &C) { return cross(B - A, C - A); } 
  
// Heron triangulo y cuadrilatero ciclico 
// http://mathworld.wolfram.com/CyclicQuadrilateral.html 
// http://www.spoj.pl/problems/QUADAREA/ 
  
double areaHeron(double a, double b, double c) 
{ 
    double s = (a + b + c) / 2; 
    return sqrt(s * (s-a) * (s-b) * (s-c)); 
} 
  
double circumradius(double a, double b, double c) { return a * b * c / (4 * areaHeron(a, b, c)); } 
  
double areaHeron(double a, double b, double c, double d) 
{ 
    double s = (a + b + c + d) / 2; 
    return sqrt((s-a) * (s-b) * (s-c) * (s-d)); 
} 
  
double circumradius(double a, double b, double c, double d) { return sqrt((a*b + c*d) * (a*c + b*d) * (a*d + b*c))  / (4 * areaHeron(a, b, c, d)); } 
  
//### DETERMINA SI P PERTENECE AL SEGMENTO AB ########################################### 
bool between(const Point &A, const Point &B, const Point &P) 
{ 
    return  P.x + EPS >= min(A.x, B.x) && P.x <= max(A.x, B.x) + EPS && 
            P.y + EPS >= min(A.y, B.y) && P.y <= max(A.y, B.y) + EPS; 
} 
  
bool onSegment(const Point &A, const Point &B, const Point &P) 
{ 
    return abs(area(A, B, P)) < EPS && between(A, B, P); 
} 
  
//### DETERMINA SI EL SEGMENTO P1Q1 SE INTERSECTA CON EL SEGMENTO P2Q2 ##################### 
//funciona para cualquiera P1, P2, P3, P4 
bool intersects(const Point &P1, const Point &P2, const Point &P3, const Point &P4) 
{ 
    double A1 = area(P3, P4, P1); 
    double A2 = area(P3, P4, P2); 
    double A3 = area(P1, P2, P3); 
    double A4 = area(P1, P2, P4); 
      
    if( ((A1 > 0 && A2 < 0) || (A1 < 0 && A2 > 0)) &&  
        ((A3 > 0 && A4 < 0) || (A3 < 0 && A4 > 0)))  
            return true; 
      
    else if(A1 == 0 && onSegment(P3, P4, P1)) return true; 
    else if(A2 == 0 && onSegment(P3, P4, P2)) return true; 
    else if(A3 == 0 && onSegment(P1, P2, P3)) return true; 
    else if(A4 == 0 && onSegment(P1, P2, P4)) return true; 
    else return false; 
} 
  
  
pair<Point, Point> P[MAXN];
int pd[MAXN];


int Find(int x){
    if(pd[x] == x)return x;
    return pd[x] = Find(pd[x]);
}


void Union(int x, int y){
   pd[Find(x)] = Find(y);
}


int main(){
    
    int t = 0;
    scanf("%d", &t);
    
    while(t--){
        
        int n, m;
        scanf("%d%d", &n, &m);
        
        Point p1, p2;
        for(int i = 0; i< n; i++){
            scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);
            P[i] = make_pair(p1, p2);
        }
        
        for(int i = 0; i < n; i++)pd[i] = i;
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(Find(i) != Find(j) && intersects(P[i].first, P[i].second, P[j].first, P[j].second)){

                    Union(i, j);       
                }
            }
        }
        
        int x, y;
        for(int i = 0; i < m; i++){
            scanf("%d%d", &x, &y);
            x--; y--;
            if(Find(x) == Find(y))puts("YES");   
            else puts("NO");
        }
        
    }  
}
