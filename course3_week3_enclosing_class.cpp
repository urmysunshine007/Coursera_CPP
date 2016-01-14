class CTyre{
private:
	int radius;
	int width;
public:
	CTyre(int r, int w):radius(r), width(w){}  ///initialization list
};

class CEngine{};

class CCar{
private:
	int price;
	CTyre tyre;      ///object member
	CEngine engine;  ///object member
public:
	CCar(int p, int tr, int tw);
};

CCar::CCar(int p, int tr, int tw):price(p), tyre(tr, tw){}  ///initialization list

int main(){
	CCar car(20000, 17, 225);
	return 0;
}


//First construct member object, then construct the enclosing object
//First destruct enclosing object, then destruct member object
