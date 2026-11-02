#include "Lorry.h"
#include <iostream>
#include <sstream>

using namespace std;

int Lorry::lorryCount = 0;
int Lorry::Car::carCount = 0;

Lorry::Car::Car() {
	brand = ""; cylinders = 0; power = 0.0; carCount++;
}
Lorry::Car::Car(const string& brand, int cylinders, double power) {
	if (!SetBrand(brand)) this->brand = "Unknown";
	if (!SetCylinders(cylinders)) this->cylinders = 1;
	if (!SetPower(power)) this->power = 1.0;
	carCount++;
}
Lorry::Car::Car(const Car& other) {
	brand = other.brand; cylinders = other.cylinders; power = other.power; carCount++;
}
Lorry::Car::~Car() { 
	carCount--;
}

string Lorry::Car::GetBrand() const {
	return brand;
}
int Lorry::Car::GetCylinders() const { 
	return cylinders; 
}
double Lorry::Car::GetPower() const {
	return power;
}

bool Lorry::Car::SetBrand(string value) {
	if (!value.empty()) {
		brand = value;
		return true; }
	cout << "Не вказано бренд" << endl;
	return false;
}
bool Lorry::Car::SetCylinders(int value) {
	if (value > 0) {
		cylinders = value;
		return true; 
	} 
	return false;
}
bool Lorry::Car::SetPower(double value) {
	if (value > 0) { 
		power = value;
		return true; 
	} 
	return false;
}

Lorry::Car& Lorry::Car::operator=(const Car& other) {
	if (this != &other) { 
		brand = other.brand; 
		cylinders = other.cylinders;
		power = other.power; 
	}
	return *this;
}
Lorry::Car::operator string() const {
	stringstream sout;
	sout << "(Марка: " << brand << ", Циліндри: " << cylinders << ", Потужність: " << power << ")";
	return sout.str();
}
Lorry::Car& Lorry::Car::operator++() {
	power += 10.0;
	return *this; 
}
Lorry::Car& Lorry::Car::operator--() { 
	if (power > 10.0) power -= 10.0;
	return *this; 
}
Lorry::Car Lorry::Car::operator++(int) {
	Car temp = *this; 
	power += 10.0;
	return temp; 
}
Lorry::Car Lorry::Car::operator--(int) { 
	Car temp = *this; 
	if (power > 10.0) power -= 10.0;
	return temp; 
}

ostream& operator<<(ostream& out, const Lorry::Car& obj) {
	out << string(obj); 
	return out; 
}
istream& operator>>(istream& in, Lorry::Car& obj) {
	string b; int c; double p;
	cout << "Введіть марку: "; in >> b;
	cout << "Введіть кількість циліндрів: "; in >> c;
	cout << "Введіть потужність: "; in >> p;
	obj.SetBrand(b); obj.SetCylinders(c); obj.SetPower(p);
	return in;
}

bool Lorry::Car::ChangePower(double newPower) {
	return SetPower(newPower); 
}
bool Lorry::Car::ReassignBrand(string newBrand) {
	return SetBrand(newBrand); 
}
int Lorry::Car::GetCarCount() { 
	return carCount;
}

Lorry::Lorry() { 
	capacity = 0.0;
	lorryCount++; }
Lorry::Lorry(const Car& car, double capacity) {
	SetCar(car);
	if (!SetCapacity(capacity))
		this->capacity = 1.0;
	lorryCount++;
}
Lorry::Lorry(const Lorry& other) { 
	car = other.car; 
	capacity = other.capacity; 
	lorryCount++;
}
Lorry::~Lorry() {
	lorryCount--; 
}

Lorry::Car Lorry::GetCar() const {
	return car; 
}
double Lorry::GetCapacity() const {
	return capacity; 
}

bool Lorry::SetCar(Car value) { 
	car = value;
	return true; 
}
bool Lorry::SetCapacity(double value) {
	if (value > 0) {
		capacity = value;
		return true;
	}
	cout << "Помилкове значення вантажопідйомності" << endl; return false;
}

Lorry& Lorry::operator=(const Lorry& other) {
	if (this != &other) {
		car = other.car; 
		capacity = other.capacity;
	} 
	return *this;
}
Lorry::operator string() const {
	stringstream sout;
	sout << "Вантажівка: " << string(car) << ", Вантажопідйомність: " << capacity << " т";
	return sout.str();
}
Lorry& Lorry::operator++() { 
	capacity += 5.0; 
	return *this; 
}
Lorry& Lorry::operator--() { 
	if (capacity > 5.0) 
		capacity -= 5.0;
	return *this; 
}
Lorry Lorry::operator++(int) { 
	Lorry temp = *this; 
	capacity += 5.0; 
	return temp;
}
Lorry Lorry::operator--(int) { 
	Lorry temp = *this;
	if (capacity > 5.0) capacity -= 5.0;
	return temp; 
}

ostream& operator<<(ostream& out, const Lorry& obj) { 
	out << string(obj);
	return out; 
}
istream& operator>>(istream& in, Lorry& obj) {
	Lorry::Car c; double cap;
	cout << "--- Дані машини ---" << endl; in >> c;
	cout << "Введіть вантажопідйомність (тонн): "; in >> cap;
	obj.SetCar(c); obj.SetCapacity(cap);
	return in;
}

bool Lorry::ReassignBrand(string newBrand) { 
	return car.SetBrand(newBrand);
}
bool Lorry::ChangeCapacity(double newCapacity) {
	return SetCapacity(newCapacity); 
}
int Lorry::GetLorryCount() {
	return lorryCount;
}