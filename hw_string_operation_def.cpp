#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <sstream>
#include <cstdlib>
using namespace std;


class oper{
public:
	oper(string * pointer, int n) :pointer(pointer), n(n){}

	int toInt(const string &str){
		return atoi(str.c_str());
	}

	int NXL(string a){
		if (a == "find")return find();
		else if (a == "rfind") return rfind();
		int output = toInt(a);
		return output;
	}
	string S12(string a){
		if (a == "copy") return copy();
		else if (a == "add") return add();
		else return a;
	}
	void rsetpt(string a){
		if (a == "insert")insert();
		else if (a == "reset")reset();
		else if (a == "print")print();
		else return;
	}
	inline string copy(){
		int N, X, L;
		string temp;
		cin >> temp;
		N = NXL(temp);
		cin >> temp;
		X = NXL(temp);
		cin >> temp;
		L = NXL(temp);
		string tempout;
		tempout.assign(pointer[N - 1], X, L);
		return tempout;
	}
	inline string add(){
		string S1, S2;
		string temp;
		cin >> temp;
		S1 = S12(temp);
		cin >> temp;
		S2 = S12(temp);
		if (Isint(S1) && Isint(S2)){
			int output = toInt(S1) + toInt(S2);
			stringstream ss;
    		ss << output;
    		string ansStr;
    		ss >> ansStr;
    		return ansStr;
		}
		else{
			return S1 + S2;
		}
	}
	inline bool Isint(const string & str){
	    // for (int i = 0; i < str.length(); i++) {
     //    	if (str[i] < '0' || str[i] > '9') return false;
    	// }
    	// int ai = toInt(str);
    	// if (ai > 99999) {
     //    	return false;
    	// }
    	// return true;


		if (str.size()>5) return false;
		for (int i = 0; i<str.length(); i++){
			if (str[i] < '0' || str[i] > '9') return false;
		}
		// int ai = toInt(str);
		// if (ai>99999) return false;	
		return true;
	}
	inline int find(){
		string S;
		int N;
		string temp;
		cin >> temp;
		S = S12(temp);
		cin >> temp;
		N = NXL(temp);
		if (pointer[N - 1].find(S) == string::npos) return pointer[N - 1].size();
		return pointer[N - 1].find(S);
	}
	inline int rfind(){
		string S;
		int N;
		string temp;
		cin >> temp;
		S = S12(temp);
		cin >> temp;
		N = NXL(temp);
		if (pointer[N - 1].rfind(S) == string::npos) return pointer[N - 1].size();
		return pointer[N - 1].rfind(S);

	}
	inline void insert(){
		string S;
		int N, X;
		string temp;
		cin >> temp;
		S = S12(temp);
		cin >> temp;
		N = NXL(temp);
		cin >> temp;
		X = NXL(temp);
		pointer[N - 1].insert(X, S);
		return;
	}
	inline void reset(){
		string S;
		int N;
		string temp;
		cin >> temp;
		S = S12(temp);
		cin >> temp;
		N = NXL(temp);
		pointer[N - 1].replace(0, pointer[N - 1].size(), S, 0, S.size());
		return;
	}
	inline void print(){
		string temp;
		int N;
		cin >> temp;
		N = NXL(temp);
		cout << pointer[N - 1] << endl;
		return;
	}
	inline void printall(){
		for (int i = 0; i < n; i++){
			cout << pointer[i] << endl;
		}
		return;
	}


private:
	string * pointer;
	int n;
};

int main(int argc, char * argv[]){
	// freopen("C:\\Users\\New User\\Downloads\\in.txt", "r", stdin);
	// freopen("C:\\Users\\New User\\Downloads\\oooooo.txt", "w", stdout);
	int n;
	cin >> n;
	string* p;
	p = new string[n];

	for (int i = 0; i<n; i++){
		cin >> p[i];
	}

	string a;
	while (1){
		cin >> a;
		if (a == "over"){
			return 0;
		}
		else{
			oper input(p, n);
			if (a == "find") input.find();
			else if (a == "rfind") input.rfind();
			else if (a == "copy") input.copy();
			else if (a == "add") input.add();
			else if (a == "insert") input.insert();
			else if (a == "reset") input.reset();
			else if (a == "print") input.print();
			else if (a == "printall") input.printall();
			else return 0;
		}
	}
	delete[]p;
	return 0;
}