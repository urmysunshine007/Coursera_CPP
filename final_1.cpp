#include<iostream>
using namespace std;
class Number {
public:
    int num;
    Number(int n=0): num(n) {}
// 在此处补充你的代码
    int const operator *(const Number & nn){
    	return nn.num*num;
    }
    //////　1. 类型转换重载函数的返回值是隐含的，并且不能显示声明，返回值是与转换的类型相同的，即为上面原型中的T2。
　　////2. 不能有参数；
// 　 　3. 支持继承，可以为虚函数；
// 　 　4. 支持使用typedef定义的类型；
    operator int() { 
    	return num;
    }
};

int main() {
    Number n1(10), n2(20);
    Number n3;n3 = n1*n2;
    cout << int(n3) << endl;
    return 0;
}