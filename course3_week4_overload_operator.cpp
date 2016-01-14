class String{
	private:
		char *str;
	public:
		String(): str(NULL){}  //constructor function, initialize str as NULL
		const char *c_str(){return str;}  //member function, return str as a constant
		char* operator = (const char*s);
		~String();
};

//overload operator "="
char * String::operator = (const char*s){
	if (str) delete [] str;
	if (s){
		str = new char[strlen(s)+1];
		strcpy(str,s);
	}
	else
		str = NULL;
	return str;
}
