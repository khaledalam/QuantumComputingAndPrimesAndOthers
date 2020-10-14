/**
 *    Author: Khaled Alam (ninjo)
 *    Email : khaledalam.net@gmail.com
 **/
#include <bits/stdc++.h>
#include "BigNumberCPP/bignumber.h"

using namespace std;




/*
Output sample:

Author: Khaled Alam(khaledalam.net@gmail.com)

Mersenne Primes:
(2^P)-1 |     value      | time
-----------------------------------------
(2 ^  2)-1 =       3 | Elasped time is 0.00 seconds.
(2 ^  3)-1 =       7 | Elasped time is 0.00 seconds.
(2 ^  5)-1 =      31 | Elasped time is 0.00 seconds.
(2 ^  7)-1 =     127 | Elasped time is 0.00 seconds.
(2 ^ 13)-1 =    8191 | Elasped time is 0.05 seconds.
(2 ^ 17)-1 =  131071 | Elasped time is 1.19 seconds.
(2 ^ 19)-1 =  524287 | Elasped time is 6.08 seconds.
...

*/


map<BigNumber, bool> vis;
map<BigNumber, bool> mem;

bool isPrime(BigNumber &N) {

	if (vis[N])
		return mem[N];

	if (N <= BigNumber(1)) {
		vis[N] = true;
		return mem[N] = false;
	}

	if (N <= BigNumber(3)) {
		vis[N] = true;
		return mem[N] = true;
	}

	BigNumber divBy2 = N / BigNumber(2);
	BigNumber divBy3 = N / BigNumber(3);

	if ((divBy2 * BigNumber(2)) == N || (divBy3 * BigNumber(3)) == N) {
		vis[N] = true;
		return mem[N] = false;
	}

	BigNumber itr(5);

	while (itr * itr <= N) {

		BigNumber divByI = N / itr;
		BigNumber divByIPlus2 = N / (itr + BigNumber(2));

		if (divByI * itr == N || divByIPlus2 * (itr + BigNumber(2)) == N) {
			vis[N] = true;
			return mem[N] = false;
		}

		itr += BigNumber(6);
	}

	vis[N] = true;
	return mem[N] = true;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);

	BigNumber base(2);

	int exp = 1;
	printf("Author: Khaled Alam(khaledalam.net@gmail.com)\n\nMersenne Primes:\n(2^P)-1 |%4s value %4s | time\n-----------------------------------------\n", "", "");

	const int MX = 100;

	while (exp++ <= MX) {
		BigNumber F(base.pow(exp) - BigNumber(1));

		clock_t begin = clock();

		bool result = isPrime(F);

		clock_t end = clock();
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

		if (result) {
			printf("(2 ^%3d)-1 = %7s | Elasped time is %.2lf seconds.\n",
					exp, F.getString().c_str(), elapsed_secs);
		}
	}

}
