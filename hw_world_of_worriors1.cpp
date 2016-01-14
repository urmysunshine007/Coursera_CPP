int timer;

class RWarrior{
private:
	int life;
	char * pname;
public:
	static int Rlife;
	Warrior(int life_, char * name_);
};

class BWarrior{
private:
	int life;
	char * pname;
public:
	static int Blife;
	Warrior(int life_, char * name_);
};

static int Rlife;
static int Blife; 

int main(){
	int ncase;
	cin>>ncase;
	for (int i = 0; i<ncase; i++){
		int M;
		cin>>M;
		Rlife = Blife = M;	
	}
}

