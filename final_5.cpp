#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 在此处补充你的代码

class CMy_add{
public:
        int &_sum;
        CMy_add(int &num):_sum(num){}
        void operator() (int num){
                int thr = num%8; 
                _sum+=thr;
        }
};

int main(int argc, char* argv[]) {
        int v, my_sum=0;
        vector<int> vec;
        cin>>v;
        while ( v ) {
                vec.push_back(v);
                cin>>v;
        }
        for_each(vec.begin(), vec.end(), CMy_add(my_sum));
        cout<<my_sum<<endl;
        return 0;
}