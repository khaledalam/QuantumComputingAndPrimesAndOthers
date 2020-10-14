/**
 *    Author: Khaled Alam (ninjo)
 *    Email : khaledalam.net@gmail.com
 **/
#include <bits/stdc++.h>
#include "BigNumberCPP/bignumber.h"

using namespace std;

//map<BigNumber, bool> vis;
//map<BigNumber, bool> mem;
//map<string, bool> fileState;

/*
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

 // Properties check (by khaled alam)
 // 1. all primes except 2 are odd (last dig % 2 != 0)
 if ((N.getString().back() - '0') % 2 == 0) {
 vis[N] = true;
 return mem[N] = false;
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
 */

map<BigNumber, bool> primesMark;
vector<BigNumber> primes;

void sieve(BigNumber &n) {

	for (BigNumber i = BigNumber(2); i * i <= n; i++) {
		if (!primesMark[i]) {
			for (BigNumber j = i * BigNumber(2); j <= n; j += i)
				primesMark[j] = true;
		}
	}
	for (BigNumber i = BigNumber(2); i <= n; i++)
		if (!primesMark[i]) {
			primes.push_back(i);
		}
}

int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
//	freopen("primes_first_100_million.txt", "r", stdin);
//	freopen("MersennePrimes_in.txt", "r", stdin);
//	freopen("MersennePrimes_out.txt", "w", stdout);

//	// Backup state file
//	std::ifstream src("src/MersennePrimes_in.txt", std::ios::binary);
//	std::ofstream dst("src/backup_MersennePrimes_in.txt", std::ios::binary);
//	dst << src.rdbuf();
//



//
//	string line;
//	while (cin>>line) {
//		cout<<line<<endl;
////		primesMark[BigNumber(line)] = true;
//	}

//	BigNumber a("1000000");
//	sieve(a);
//	for (auto &prime : primes) {
//		cout << prime << endl;
//	}

	BigNumber base(2);
	int exp = 1;
	printf(
			"Author: Khaled Alam(khaledalam.net@gmail.com)\n\nMersenne Primes:\n(2^P)-1 |%4s value %4s | time\n-----------------------------------------\n",
			"", "");

	const int MX = 100;

	while (exp++ <= MX) {
		BigNumber F(base.pow(exp) - BigNumber(1));

		clock_t begin = clock();

		bool result = false; //isPrime(F);
		string cmd = "grep -c ^";
		cmd += F.getString();
		cmd += "$ primes_first_100_million.txt";

		FILE *fp = popen(cmd.c_str(), "r");
		char buf[2];

//		cout << cmd << endl;
		fgets(buf, 1024, fp);
		result = (buf[0] != '0');
		fclose(fp);

		clock_t end = clock();
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

		if (result) {
			printf("(2 ^%3d)-1 = %7s | Elasped time is %.2lf seconds.\n", exp,
					F.getString().c_str(), elapsed_secs);
		}
	}

}


