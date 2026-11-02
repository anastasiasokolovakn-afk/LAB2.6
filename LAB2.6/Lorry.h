#pragma once
#include <string>
#include <iostream>

class Lorry
{
public:
	class Car {
	private:
		std::string brand = "";
		int cylinders = 0;
		double power = 0.0;
		static int carCount;
	public:
		Car();
		Car(const std::string& brand, int cylinders, double power);
		Car(const Car& other);
		~Car();

		std::string GetBrand() const;
		int GetCylinders() const;
		double GetPower() const;

		bool SetBrand(std::string value);
		bool SetCylinders(int value);
		bool SetPower(double value);

		Car& operator=(const Car& other);

		operator std::string() const;

		Car& operator++();   
		Car& operator--();
		Car operator++(int); 
		Car operator--(int);

		friend std::ostream& operator<<(std::ostream& out, const Car& obj);
		friend std::istream& operator>>(std::istream& in, Car& obj);

		bool ChangePower(double newPower);
		bool ReassignBrand(std::string newBrand);

		static int GetCarCount();
	};

private:
	Car car;
	double capacity = 0.0;
	static int lorryCount;
public:
	Lorry();
	Lorry(const Car& car, double capacity);
	Lorry(const Lorry& other);
	~Lorry();

	Car GetCar() const;
	double GetCapacity() const;
	bool SetCar(Car value);
	bool SetCapacity(double value);

	Lorry& operator=(const Lorry& other);

	operator std::string() const;

	Lorry& operator++();
	Lorry& operator--();
	Lorry operator++(int);
	Lorry operator--(int);

	friend std::ostream& operator<<(std::ostream& out, const Lorry& obj);
	friend std::istream& operator>>(std::istream& in, Lorry& obj);

	bool ReassignBrand(std::string newBrand);
	bool ChangeCapacity(double newCapacity);

	static int GetLorryCount();
};
