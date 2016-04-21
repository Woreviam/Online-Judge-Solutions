
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 20001

using namespace std;

int cm[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string m[] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
string d[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

map<string, int>months, days;

int main(){
	
	for(int i = 0; i < 12; i++)months[m[i]] = cm[i];
	for(int i = 0; i < 7; i++)days[d[i]] = i;
	
	int tc = 0;
	scanf("%d", &tc);
	
	while(tc--){
		
		string cad1, cad2;
		cin >> cad1 >> cad2;
		
		int ct = months[cad1];
		int ini = days[cad2];
		int ans = 0;
		
		for(int i = 0; i < ct; i++){
			
			if(ini%7 == 5 || ini%7 == 6)ans++;
			ini++;
		}
		
		printf("%d\n", ans);
	}
}

