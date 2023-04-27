#include <iostream>

using namespace std; 

class Car {
    public: 
    string m_brand; 
    string m_model; 
    int m_year; 
    int m_maxSeating; 
    Car (string x, string y, int z, int s) {
        m_brand = x; 
        m_model = y; 
        m_year = z; 
        m_maxSeating = s; 
    }
    int get_m_maxSeating() {
        return m_maxSeating; 
    }
}; 

class BMW_car : public Car {
    private:
    string m_driveMode; 

    public: 
    BMW_car(string y, int z, int s) : Car("BMW", y, z, s) {
        cout << "Constructing BMW_Car\n";
        m_driveMode = "Rear-wheel";
    }

    string get_driveMode() {
        return m_driveMode; 
    }
};

class AUDI_car : public Car {
    private:
    string m_driveMode; 

    public: 
    AUDI_car(string y, int z, int s) : Car("AUDI", y, z, s) {
        cout << "Constructing AUDI_car\n";
        m_driveMode = "Front-wheel";
    }

    string get_driveMode() {
        return m_driveMode; 
    }
};

class BENZ_car : public Car {
    private:
    string m_driveMode; 

    public: 
    BENZ_car(string y, int z, int s) : Car("BENZ", y, z, s) {
        cout << "Constructing BENZ_car\n";
        m_driveMode = "Front-wheel";
    }

    string get_driveMode() {
        return m_driveMode; 
    }
};

int main() {
    BMW_car car_1("X5", 2023, 6); 
    cout << car_1.m_brand << " : Drive Mode = " << car_1.get_driveMode() << endl; 
    AUDI_car car_2("A1", 2023, 5); 
    cout << car_2.m_brand << " : Drive Mode = " << car_2.get_driveMode() << endl; 
    BENZ_car car_3("ABC", 2021, 2); 
    cout << car_3.m_brand << " : Drive Mode = " << car_3.get_driveMode() << endl; 
    return 0; 
};
