/////1. Friend function: able to visit private member


class CCar;  //claim class CCar for use in class CDriver

class CDriver{
public:
	void ModifyCar(CCar *pCar);
};

class CCar{
private:
	int price;
	friend int MostExpensiveCar(CCar cars[], int total); // proclaim as friend function
	friend void CDriver::ModifyCar(CCar *pCar);
};


void CDriver::ModifyCar(CCar *pCar){
	pCar->price+=1000;        //// price of car increase by 1000 after modification
} 

int MostExpensiveCar(CCar cars[], int total){  //get the price of most expensive car
	int tempMax = -1;
	for(int i =0; i<total; ++i)
		if(cars[i].price>tempMax)
			tempMax = cars[i].price;
	return tempMax;
}

int main(){
	return 0;
}


/////2. Friend Class: function of friend class can visit privite member

class CCar{
private:
	int price;
	friend class CDriver;  //proclaim as friend class
};

class CDriver{
public:
	CCar myCar;
	void ModifyCar(){
		myCar.price += 1000;  //since CDriver is a friend class of CCar, it can visit its private member, i.e. price
	}
};


///not transitive