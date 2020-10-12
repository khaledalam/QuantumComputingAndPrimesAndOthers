/**
 *    Author: Khaled Alam (ninjo)
 *    Email : khaledalam.net@gmail.com
 **/

#include <bits/stdc++.h>
using namespace std;



long long int gcd(long long int a, long long int b)
{
    if (!a) return b;
    if (!b) return a;
    if (a == b) return a;
    if (a > b) return gcd(a-b, b);
    return gcd(a, b-a);
}

long long int lcm(long long int a, long long int b){
    return a * b / gcd(a, b);
}

vector<long long int> primeFactors(long long int n){
    vector<long long int> ret;
    while (n % 2 == 0)
    {  
        ret.push_back(2);
        n = n/2;  
    }
    long long int mx = sqrt(n);
    for (int i = 3; i <= mx; i = i+2){
        while (n%i == 0){
            ret.push_back(i);
            n = n/i;
        }
    }
    if (n > 2)
        ret.push_back(n);
    return ret;
}


// mersennePrimes -------------------------- START!

void generatePrimes(bool *primes, int n){
   fill(primes, primes + n + 1, true);
   for (int p = 2; p * p <= n; ++p) {
      if (primes[p] == true) {
         for (int i = p * 2; i <= n; i += p) {
            primes[i] = false;
         }
      }
   }
}

vector<long long int> mersennePrimes(int n){
   bool primes[n + 1];
   vector<long long int> ret;
   generatePrimes(primes, n);
   for (long long int i = 2; ((1 << i) - 1) <= n; ++i) {
      long long int num = (1 << i) - 1;
      if (primes[num]) ret.push_back(num);
   }
   return ret;
}
// mersennePrimes -------------------------- END!


vector<long long int> sieve(long long int n)
{
    vector<long long int> ret;
    bool primes[n+1];
    memset(primes, true, sizeof(primes));
    long long int mx = sqrt(n);
    for (int i=2; i <= mx; i++)
    {
        if (primes[i] == true)
        {
            for (int j=i*2; j<=n; j += i) primes[j] = false;
        }
    }
    for (int i=2; i<=n; i++)
       if (primes[i])
          ret.push_back(i);
    return ret;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
//	freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);

}

