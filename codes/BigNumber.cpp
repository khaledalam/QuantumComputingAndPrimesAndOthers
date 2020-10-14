/**
 *    Author: Khaled Alam (ninjo)
 *    Email : khaledalam.net@gmail.com
 **/

#include <bits/stdc++.h>

#include "BigNumberCPP/bignumber.h"

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);

	BigNumber base(2);

	cout << base.pow(3).getString() << endl;
	cout << (base + BigNumber(5)).getString() << endl;

}

