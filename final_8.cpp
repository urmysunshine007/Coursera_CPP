#include <iostream>
#include <string>
#include <bitset>
#include <sstream>
using namespace std;


int main(){
	int t;
	cin >> t;
	while (t--){
		int n, i, j, k;
		cin >> n >> i >> j;
		bitset<31> n1(n);
		// cout<<n1;
		bitset<31> k1;
		if (n1[i]) k1[i] = 1;
		if (n1[j] == 0) k1[j] = 1;
		for (int a = i + 1; a<j; a++){
			k1[a] = 1;
		}

		stringstream ss;
		ss << k1.to_ulong();
		ss >> k;
		cout << hex << k <<endl;
	}
	return 0;
}