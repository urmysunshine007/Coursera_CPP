#include <iostream>
using namespace std;
// 在此处补充你的代码


class CType{
public:
	int num;
	void setvalue(int n){
		num = n;
	}
	CType& operator++(int){
		CType* temp = new CType();
		temp->setvalue(num);
		num *= num;
		return *temp;
	}

	friend ostream & operator<< (ostream &o, CType &c);
};

ostream & operator<< (ostream &o, CType &c){
		o << c.num;
		return o;
}
int main(int argc, char* argv[]) {
	CType obj;
	int n;
	cin >> n;
	while (n) {
		obj.setvalue(n);
		cout << obj++ << " " << obj << endl;
		cin >> n;
	}
	return 0;
}
