#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
	string Serial_number;
	string engine_type;

public:
	Vehicle(string serial, string engine) : Serial_number(serial), engine_type(engine) {}

	virtual void display_info() {}
	virtual ~Vehicle() {}
};

class Gasoline : virtual public Vehicle {
protected:
	int oil_gauge;

public:
	Gasoline(string serial, string engine, int oil) : Vehicle(serial, engine), oil_gauge(oil) {}

	void display_info() override {
		cout << "���� Ÿ��: Gasoline" << endl;
		cout << "�ø��� ��ȣ: " << Serial_number << endl;
		cout << "���� Ÿ��: " << engine_type << endl;
		cout << "�⸧ ������: " << oil_gauge << endl;
	}

};

class Electric : virtual public Vehicle {
protected:
	int charged_gauge;

public:
	Electric(string serial, string engine, int charge) : Vehicle(serial, engine), charged_gauge(charge) {}

	void display_info() override {
		cout << "���� Ÿ��: Electric" << endl;
		cout << "�ø��� ��ȣ: " << Serial_number << endl;
		cout << "���� Ÿ��: " << engine_type << endl;
		cout << "���� ������: " << charged_gauge << endl;
	}

};

class Hybrid : public Gasoline, public Electric {
public:
    Hybrid(string serial, string engine, int oil, int charge)
        : Gasoline(serial, engine, oil), Electric(serial, engine, charge), Vehicle(serial, engine) {}

    void display_info() override {
        cout << "���� Ÿ��: Hybrid" << endl;
        cout << "�ø��� ��ȣ: " << Serial_number << endl;
        cout << "���� Ÿ��: " << engine_type << endl;
        cout << "�⸧ ������: " << Gasoline::oil_gauge << endl;
        cout << "���� ������: " << Electric::charged_gauge << endl;
    }
};

int main() {
	Vehicle* v1 = new Gasoline("G123", "���ָ� ����", 50);
	Vehicle* v2 = new Electric("E456", "���� ����", 80);
	Vehicle* v3 = new Hybrid("H789", "���̺긮��", 50, 80);

	v1->display_info();
	v2->display_info();
	v3->display_info();

	Hybrid* newHybrid1 = dynamic_cast<Hybrid*>(v1);
	if (newHybrid1) {
		cout << "���� ����ȯ ����" << endl;
		newHybrid1->display_info();
	}
	else {
		std::cout << "���� ����ȯ ����" << endl;
	}

	Hybrid* newHybrid = dynamic_cast<Hybrid*>(v3);
	if (newHybrid) {
		cout << "���� ����ȯ ����" << endl;
		newHybrid->display_info();
	}
	else {
		std::cout << "���� ����ȯ ����" << endl;
	}

	delete v1;
	delete v2;
	delete v3;

	return 0;

}