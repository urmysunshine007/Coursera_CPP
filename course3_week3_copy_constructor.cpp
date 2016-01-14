class Complex{
	public:
		double real, imag;
	Complex(){}
	Complex(const Complex &c){            /// copy constructor; there is only one copy constructor; 
										  /// the parameter of a copy constructor is the reference of a object of its class
		real = c.real;
		imag = c.imag;
		cout<<"Copy Constructor called";
	}
};

Complex c1;
Complex c2(c1); ///call copy constructor


//copy constructor works in three ways:
//1. initiate an object with another existing one of the same class. eg: Complex c2(c1) or Complex c2 = c1
//2. if a function has a parameter which is an object of class A, when the function is called, 
//   the copy constructor of A is called to initialize the parameter
//3. if a function returns an object of class A, the copy constructor of A is called to initialize the returns a value.