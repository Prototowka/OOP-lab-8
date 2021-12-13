#include <iostream>
#include <locale>
using namespace std;

class Vagon
{
public:
	float Weight, Count;
	virtual void output()
	{
		cout << endl << "Вагон пассажирский" << endl;
		cout << "Вес вагона:" << Weight << endl;
		cout << "Кол-во людей:" << Count << endl;
	}

	void Input(float weight, float count)
	{
		Weight = weight;
		Count = count;
	}
};

class VagonForCars:public Vagon
{
public:
	float Weight, count;
	void output() override
	{
		cout << endl << "Вагон для машин" << endl;
		cout << "Вес вагона:" << Weight << endl;
		cout << "Кол-во товара:" << Count << endl;
	}

	void Input(float weight, float count)
	{
		Weight = weight;
		Count = count;
	}
};

class VagonCistern : public Vagon
{
public:
	float Weight, count;
	void output() override
	{
		cout << endl << "Вагон-цистерна" << endl;
		cout << "Вес вагона:" << Weight << endl;
		cout << "Кол-во литров жидкости:" << Count << endl;
	}

	void Input(float weight, float count)
	{
		Weight = weight;
		Count = count;
	}
};

class Function
{
public:
	virtual void Calculate() = 0;
};

class Parabola : public Function
{
public:
	float X, Y ;

	void SetX(float x)
	{
		X = x;
	}

	void Calculate() override
	{
		Y = pow(X, 2);
		cout << "X=" << X << " Y=" << Y << endl;
	}
};

class Hiperbola : public Function
{
public:
	float X, Y, K;

	void SetX(float x)
	{
		X = x;
	}

	void SetK(float k)
	{
		K = k;
	}

	void Calculate() override
	{
		Y = K/X;
		cout << "X=" << X << " K=" << K << " Y=" << Y << endl;
	}
};

class Elipse : public Function
{
public:
	float X, Y, A, B;

	void SetX(float x)
	{
		X = x;
	}

	void SetCoef(float a, float b)
	{
		A = a;
		B = b;
	}

	void Calculate() override
	{
		Y = (1 - (pow(X, 2) / pow(A, 2)) * pow(B, 2));
		Y = sqrt(Y);
		cout << "X=" << X << " A=" << A << " B=" << B << " Y=" << Y << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	//Здание №1
	cout << "Задание №1" << endl;
	Vagon vagon;
	vagon.Input(1692, 25);

	VagonForCars vagonForCars;
	vagonForCars.Input(1259, 10);

	VagonCistern vagonCistern;
	vagonCistern.Input(1900, 1000);

	Vagon *type;
	type = &vagon;
	type->output();

	type = &vagonForCars;
	type->output();

	type = &vagonCistern;
	type->output();

	//Задание №2
	cout << endl << "Задание №2" << endl;
	Parabola one;
	one.SetX(1.25);
	one.Calculate();

	Hiperbola two;
	two.SetK(2);
	two.SetX(12);
	two.Calculate();

	Elipse three;
	three.SetCoef(2, 2);
	three.SetX(0);
	three.Calculate();

	return 0;
}