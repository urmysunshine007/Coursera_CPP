#include <iostream>
using namespace std;

template <class T>
class CArray3D{
public:
    class CArray2D{
    public:
        class CArray1D{
        public:
            CArray1D() :p(NULL){}
            void set(int a){
                p = new T[a];
            }
            inline T & operator[](int elem) const{
                return p[elem];
            }
            ~CArray1D(){ delete[] p; }

        private:
            T * p;
        };

        CArray2D() :p(NULL){}
        void set(int a, int b){
            p = new CArray1D[a];
            for (int i = 0; i < a; i++){
                p[i].set(b);
            }
        }
        inline CArray1D & operator[](int elem) const{
            return p[elem];
        }
        ~CArray2D(){
            delete[]p;
        }

    private:
        CArray1D * p;
    };

    CArray3D(int a, int b, int c){
        p = new CArray2D[a];
        for (int i = 0; i < a; i++){
            p[i].set(b, c);
        }
    }
    inline CArray2D & operator[](int elem) const{
        return p[elem];
    }
    ~CArray3D(){
        delete[]p;
    }

private:
    CArray2D *p;
};
int main()
{
    CArray3D<int> a(3, 4, 5);
    int No = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 5; ++k)
                a[i][j][k] = No++;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 5; ++k)
                cout << a[i][j][k] << ",";
    return 0;
}