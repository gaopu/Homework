#include <iostream>

class employee
{
public:
    char *name;
    int individualEmpNo;
    int garde;
    float accumPay;
    static int employeeNo;
public:
    employee();
    ~employee();
    virtual void pay();
    virtual void promote();
    virtual void displayStatus();
};

class technician : public employee
{
    float hourlyRate;
    int workHours;
public:
    technician();
    void pay();
    void displayStatus();
};

class manager : virtual public employee
{
    float monthlyPay;
public:
    manager();
    void pay();
    void displayStatus();
};

class salesman : virtual public employee
{
    float CommRate;
    float sales;
public:
    salesman();
    void pay();
    void displayStatus();
};

class salesmanager : public manager,public salesman
{
    salesmanager();
    void pay();
    void displayStatus();
};

int main()
{

}
