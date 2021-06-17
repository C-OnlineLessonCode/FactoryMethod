#include <iostream>
#include <fstream>
#include <windows.h>


class ICar {
public:
	virtual ~ICar() {}
	virtual int GetEngineVolume() const = 0;
};

class BmwX3 : public ICar {
public:
	int GetEngineVolume() const {
		return 3;
	}
};
class BmwX5 : public ICar {
public:
	int GetEngineVolume() const {
		return 4;
	}
};

std::shared_ptr<ICar> CreateCar(int expectedEngineVolume) {
	if (expectedEngineVolume == 3) {
		return std::make_shared<BmwX3>();
	}
	else if (expectedEngineVolume == 4) {
		return std::make_shared<BmwX5>();
	}
	else {
		throw std::runtime_error("Can't produce the car with expected engine volume");
	}
}

void ShowCarInfo(std::shared_ptr<ICar> car) {
	std::cout << car->GetEngineVolume();
}

int main()
{
	std::shared_ptr<ICar> car = CreateCar(4);
	ShowCarInfo(car);

	/*
	
	Factory method
	 
	*/
}
