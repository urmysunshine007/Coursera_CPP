#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;

class A{
public:
        int value;
        char type;
        A(int num){
                value = num;
                type = 'A';
        }
        A(){}
};
class B:public A{
public:
        B(int num){
                value = num;
                type = 'B';
        }
};


class print{
public:
        void operator()(const A* a){
                cout<<a->type<<' '<<a->value<<endl;
        }
};
print Print;

class Comp{
public:
        bool operator()(const A* a, const A* b){
                return a->value < b->value;
        }
};


// 在此处补充你的代码
int main()
{

        int t;
        cin >> t;
        set<A*,Comp> ct;
        while( t -- ) {
                int n;
                cin >> n;
                ct.clear();
                for( int i = 0;i < n; ++i)	{
                        char c; int k;
                        cin >> c >> k;

                        if( c == 'A')
                                ct.insert(new A(k));
                        else
                                ct.insert(new B(k));
                }
                for_each(ct.begin(),ct.end(),Print);
                cout << "****" << endl;
        }
}