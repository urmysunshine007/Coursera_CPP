class Complex{
	public:
		double real, imag;
		Complex(int i){                      /// this is a conversion constructor
			cout<<"IntConstructor called"<<endl;
			real = i;imag = 0;
		}
		Complex(double r, double i)
		{ real = r, imag = i;}
};

int main(){
	Complex c1(7, 8);
	Complex c2 = 12;              /// this calls the conversion constructor
	c1 = 9;                       /// this calls the conversion constructor, a temporary object is constructed with parameter 9
	cout<<c1.real<<","<<c1.imag<<endl;
	return 0;
}



//conversion constructor only has one parameter, which is not a reference of the object of class

