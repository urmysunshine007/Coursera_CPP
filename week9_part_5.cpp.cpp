#include <iostream>
#include <map>
using namespace std;
// #pragma warning(disable:4996)

int main(){
	// freopen("C:\\Users\\New User\\Downloads\\in.txt", "r", stdin);
	//freopen("C:\\Users\\New User\\Downloads\\oooooo.txt", "w", stdout);
	typedef map<int, int> mymm;
	mymm pairs;
	pairs[1000000000] = 1;
	int n;
	cin >> n;
	for (; n>0; n--){
		int id;
		int power;
		cin >> id >> power;
		pairs[power] = id;
		mymm::iterator p = pairs.find(power);
		if (p == pairs.begin() || p == pairs.end()--){
			if (p == pairs.begin()){
				p++;
				cout << id << ' ' << p->second << endl;
			}
			else{
				p--;
				cout << id << ' ' << p->second << endl;
			}
		}
		else{
			mymm::iterator p0 = p;
			mymm::iterator p1 = p;
			p1--;
			mymm::iterator p2 = p;
			p2++;
			int n1 = power - p1->first;
			int n2 = p2->first - power;
			if (n1>n2){
				cout << id << ' ' << p2->second << endl;
			}
			else{
				cout << id << ' ' << p1->second << endl;
			}
		}
	}
	return 0;
}