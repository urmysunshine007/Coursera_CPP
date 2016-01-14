//Eg1:

class String{
	private:
		char *p;
	public:
		String(){
			p = new char[10];
		}
		~String();
};
String::~String(){
	delete []p;
}


// a class can have at most one destructor

//Eg2: an array of objects

class Ctest{
	public:
		~Ctest(){ cout<<"destructor called"<<endl;}
};

int main(){
	Ctest array[2];
	cout<<"End Main"<<endl;
	return 0; // destructor is called twice
}


//Eg3: delete pointer to object

Ctest * pTest;
pTest = new Ctest; // constructor is called
delete pTest;      //destructor is called

pTest = new Ctest[3];  // constructor is called three times
delete [] pTest;      // destructor is called three times

////note: objects that are created by pointer "new" must be deleted manually, or the destructor functon will not be called automatically