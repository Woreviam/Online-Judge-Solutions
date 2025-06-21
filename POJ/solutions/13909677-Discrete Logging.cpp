Source Code

*Problem:* 2417 <http://poj.org/problem?id=2417>		*User:* previus
<http://poj.org/userstatus?user_id=previus>
*Memory:* 1396K		*Time:* 1329MS
*Language:* G++		*Result:* Accepted

  * Source Code

    #include<cstdio>
    #include<algorithm>
    #include<cmath>
    #include<vector>

    #define pb(x) push_back(x)
    #define all(x) x.begin(), x.end()
    #define cout2(x, y) cout << x << " " << y <<  endl

    using namespace std;

    long long P;

    long long fastPow(long long b, long long e){
    	
    	long long ans = 1;
    	while(e > 0){
    		
    		if(e&1)ans = ans * b;
    		if(ans >= P)ans %= P;
    		
    		b = b * b;
    		if(b >= P)b %= P;
    		
    		e >>= 1;
    	
    	}
    	return ans;
    }

    pair<long long, long long>res[65540];

    int main(){

    	long long B, N;
    	while(scanf("%lld%lld%lld", &P, &B, &N) == 3){
    		
    		// 	B ^ L = N mod P ---> B^(D * Q + r) --> B ^ (D*Q) X B^r  / D = sqrt(L) ^ r && sqrt(L)
    		
    		long long SQRT = sqrt(1.0 * P);
    		int top = 0;
    		
    		for(long long q = 0; q * SQRT < P; q++)
    			res[top++] = make_pair(fastPow(B, q * SQRT), q * SQRT);

    		
    		sort(res, res + top);
    		
    		long long aux, ans = P;
    		int pos;
    		
    		for(long long r = 0; r < SQRT; r++){
    			
    			aux = fastPow(B, r);
    			aux = (fastPow(aux, P - 2) * N) % P;
    			
    			pos = lower_bound(res, res + top, make_pair(aux, -1LL)) - res;
    			if(pos >= top || res[pos].first != aux)continue;
    			
    			ans = min(ans, res[pos].second + r);
    		}
    		
    		if(ans < P)printf("%lld\n", ans);
    		else puts("no solution");
    		
    	}

    }

