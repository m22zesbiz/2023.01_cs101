#include <iostream>

using namespace std;

class Engine {
    private: 
        int m_EngineCapacity; 
        int m_Horsepower; 
        bool m_EngineRunning; 
    public: 
        Engine (int EngineCapacity=2000, int Horsepower=200) {
            m_EngineCapacity = EngineCapacity; 
            m_Horsepower = Horsepower; 
            m_EngineRunning = false; 
        }
        bool EngineStart() {
            m_EngineRunning = true; 
            return true; 
        }
        bool EngineStop() {
            m_EngineRunning = false; 
            return true; 
        }
        bool get_EngineStatus() {
            return m_EngineRunning; 
        }
};

class Fueltank
{
private:
    int m_FueltankCapacity;
    int m_GasGrade;

public:
    Fueltank(int FueltankCapacity = 3000, int Gas = 98) {
        m_FueltankCapacity = FueltankCapacity; 
        m_GasGrade = Gas; 
    };
    int fuelUp(int v, int gas) {
        if(gas != m_GasGrade && v > m_FueltankCapacity) {
            cout << "Error: FueltankCapacity: " << m_FueltankCapacity << " but fuel up: " << v << endl; 
            cout << "Error: Gas_grade: " << gas << " Correct Gas_grade: " << m_GasGrade << endl; 
        } else if (gas != m_GasGrade) {
            cout << "Error: Gas_grade: " << gas << " Correct Gas_grade: " << m_GasGrade << endl; 
        } else if (v > m_FueltankCapacity) {
            cout << "Error: FueltankCapacity: " << m_FueltankCapacity << " but fuel up: " << v << endl; 
        } else {
            cout << "fuel_up: " << v << " Gas_grade: " << gas << endl; 
        }
        return true; 
    };
    int setGasGrade(int GasGrade) {
        m_GasGrade = GasGrade; 
        return true; 
    }; 
    int getGasGrade() {
        return m_GasGrade; 
    };
};

class Car
{
private: 
    string m_brand;
    string m_model;
    int m_year;
    int m_maxSeating;
    int m_price; 
    int m_base; 
    Engine m_Engine; 
    Fueltank m_Fueltank; 
    void m_updatePrice(int base=500000) {
        m_price = m_maxSeating * base; 
    }
public:
    Car(string x, string y, int z, int s)
    {
        m_brand = x;
        m_model = y;
        m_year = z;
        m_maxSeating = s;
    }
    int get_m_maxSeating()
    {
        return m_maxSeating;
    }
    int get_Price() {
        return m_price; 
    }
    void set_base(int n) {
        m_base = n; 
    }
    string get_brand() {
        return m_brand; 
    }
    bool get_EngineStatus() {
        return m_Engine.get_EngineStatus(); 
    }
    bool startEngine() {
        return m_Engine.EngineStart(); 
    }
    bool stopEngine() {
        return m_Engine.EngineStop(); 
    }
    int get_Gas_grade() {
        return m_Fueltank.getGasGrade();
    }
    int set_Gas_grade(int gas = 98) {
        return m_Fueltank.setGasGrade(gas); 
    }
    int fuel_up(int v, int gas = 98) {
        return m_Fueltank.fuelUp(v, gas);
    }
};

class BMW_car : public Car
{
private:
    string m_driveMode;

public:
    BMW_car(string y, int z, int s) : Car("BMW", y, z, s)
    {
        cout << "Constructing BMW_Car\n";
        m_driveMode = "Rear-wheel";
    }

    string get_driveMode()
    {
        return m_driveMode;
    }
};

class AUDI_car : public Car
{
private:
    string m_driveMode;

public:
    AUDI_car(string y, int z, int s) : Car("AUDI", y, z, s)
    {
        cout << "Constructing AUDI_car\n";
        m_driveMode = "Front-wheel";
    }

    string get_driveMode()
    {
        return m_driveMode;
    }
};

class BENZ_car : public Car
{
private:
    string m_driveMode;

public:
    BENZ_car(string y, int z, int s) : Car("BENZ", y, z, s)
    {
        cout << "Constructing BENZ_car\n";
        m_driveMode = "Front-wheel";
    }

    string get_driveMode()
    {
        return m_driveMode;
    }
};

int main()
{
    AUDI_car car_2("A1", 2023, 5);
    cout << car_2.get_brand() << " : Gas_grade = " << car_2.get_Gas_grade() << endl;
    car_2.set_Gas_grade(95); 
    cout << car_2.get_brand() << " : Gas_grade = " << car_2.get_Gas_grade() << endl;
    car_2.fuel_up(300, 95); 
    car_2.fuel_up(300, 99); 
    car_2.fuel_up(300000000, 95); 
    car_2.fuel_up(300000000, 99); 
    return 0;
};
