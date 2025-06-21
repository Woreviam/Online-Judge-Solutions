Source Code

*Problem:* 1941 <http://poj.org/problem?id=1941>		*User:* previus
<http://poj.org/userstatus?user_id=previus>
*Memory:* 2720K		*Time:* 282MS
*Language:* G++		*Result:* Accepted

  * Source Code

    #include<iostream>
    #include<cstring>
    #include<cstdio>


    #define pb(x)push_back(x)
    #define all(x) x.begin(), x.end()
    #define cout2(x, y) cout << x << " " << y << endl
    #define cout3(x, y, z) cout << x << " " << y << " " << z << endl
    #define N 100005

    using namespace std;

    char table[1025][2050];

    void printFractal(int fil, int col, int n){
    	
    	if(n == 1){
    		
    		table[fil][col] = '/';
    		table[fil + 1][col - 1] = '/';
    		table[fil + 1][col] = '_';
    		table[fil + 1][col + 1] = '_';
    		table[fil + 1][col + 2] = '\\';
    		table[fil][col + 1] = '\\';
    		return;
    	}
    	
    	printFractal(fil, col, n - 1);
    	printFractal(fil + (1<<(n - 1)), col - (1<<(n - 1)), n - 1);
    	printFractal(fil + (1<<(n - 1)), col + (1<<(n - 1)), n - 1);
    	
    } 

    int main(){

    	int n;
    	while(cin >> n){
    		
    		if(n == 0)break;
    		// (1<<n) = 2^n
    		// 00000.....00000000000001 
    		// 0000001000...n veces ..0 = 2^n
    		
    		for(int i = 0; i < (1<<n); i++)memset(table[i], ' ', sizeof(char) * (1<<n)*2);
    		printFractal(0, (1<<n) - 1, n);
    		
    		
    		for(int i = 0; i < (1<<n); i++){
    			
    			for(int j = (1<<(n + 1)) - 1; j >= 0; j--){
    				
    				if(table[i][j] != ' '){
    					
    					table[i][j + 1] = 0;
    					break;
    				}
    			}
    			printf("%s\n", table[i]);
    		}
    		puts("");
    	}
    }

