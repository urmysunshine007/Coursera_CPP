#include <iostream>
#include <set>
using namespace std;

template<class T>
class myclass{
	T x;
	multiset<T> mtset;
	set<T> set1;
public:
	void add(const T &input){
		x = input;
		mtset.insert(x);
		set1.insert(x);
		cout<<mtset.count(x)<<endl;
	}
	void del(const T &input){
		x = input;
		int n = mtset.count(x);
		if(n!=0){
			typename multiset<T>::iterator p1 = mtset.lower_bound(x);
			typename multiset<T>::iterator p2 = mtset.upper_bound(x);
			mtset.erase(p1, p2);
		}
		cout<< n<<endl;
	}
	void ask(const T &input){
		x = input;
		if(set1.find(x)==set1.end()){
			cout<<0<<' '<<0<<endl;
		}
		else cout<<1<<' '<<mtset.count(x)<<endl;

	}
};

int main(){
	myclass<int> a;
	int n;
	cin>>n;
	string cmd;
	int x;
	for(;n>0;n--){
		cin>>cmd;
		cin>>x;
		if (cmd =="add"){
			a.add(x);
		}
		else if(cmd == "del"){
			a.del(x);
		}
		else if(cmd =="ask"){
			a.ask(x);
		}
		else{
			cout<<"error";
		}
	}

	return 0;
}