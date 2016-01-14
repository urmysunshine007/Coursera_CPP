#include <iostream> 
#include <iterator> 
#include <list> 
#include <cstdio>
#include <string>
#include <set>
#include <vector>
// #pragma warning(disable:4996)
using namespace std;

class mylist{
public:
	int Id;
	list<int> l1;
	mylist(int id){ Id = id; }
};
class printlist{
public:
	void operator()(list<int> & l2){
		if (l2.empty()) cout << endl;
		else{
			list<int>::iterator first = l2.begin();
			list<int>::iterator last = l2.end();
			for (; first != last; first++){
				cout << *first << ' ';
			}
			cout << endl;
		}
	}
};
class findid{
public:
	mylist & operator()(int id, vector<mylist> & v1){
		vector<mylist>::iterator first = v1.begin();
		vector<mylist>::iterator last = v1.end();
		for (; first != last; first++){
			if ((*first).Id == id){
				return *first;
			}
		}
	}
};
int main(){

	// freopen("C:\\Users\\New User\\Downloads\\in.txt", "r", stdin);
	// freopen("C:\\Users\\New User\\Downloads\\oooooo.txt", "w", stdout);
	long n;
	cin >> n;
	vector<mylist> v;
	for (; n>0; n--){
		string a;
		cin >> a;
		char init;
		init = a[0];
		int id, num, id2;
		switch (init){
		case 'n': {
			cin >> id;
			v.push_back(mylist(id));
			break;
		};
		case 'a':{
			cin >> id >> num;
			findid findfunc;
			mylist & temp = findfunc(id, v);
			temp.l1.push_back(num);
			break;
		}
		case 'o':{
			cin >> id;
			findid findfunc;
			mylist & temp = findfunc(id, v);
			temp.l1.sort();
			printlist printfunc;
			printfunc(temp.l1);
			break;
		}
		case 'm':{
			cin >> id >> id2;
			findid findfunc;
			findfunc(id, v).l1.merge(findfunc(id2, v).l1);
			break;
		}
		case 'u':{
			cin >> id;
			findid findfunc;
			findfunc(id, v).l1.sort();
			findfunc(id, v).l1.unique();
			break;
		}
		break;
		}

	}
	return 0;
}