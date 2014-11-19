#include<iostream>
#include<cstring>
using namespace std;

class employee
{    protected:
    char *name;    //����
    int individualEmpNo;   //���˱��
    int grade;    //����
    float accumPay;    //��н�ܶ�
    static int employeeNo;   //����˾ְԱ���Ŀǰ���ֵ
public:
    employee();     //���캯��
    virtual ~employee();      //��������
    virtual void pay();     //������н����
    void promote(int);    //��������
    virtual void displayStatus();    //��ʾ��Ա��Ϣ
};

class technician : public employee  //������Ա��
{
private:
    float hourlyRate;   //ÿСʱ���
    int workHours;    //���¹���ʱ��
public:
    technician();    //���캯��
    void pay();    //������н����
    void displayStatus();  //��ʾ��Ա��Ϣ
};
class salesman:virtual public employee  //��ְ����Ա��
{
protected:
    float CommRate;  //�����۶���ȡ���İٷֱ�
    float sales;    //�������۶�
public:
    salesman();    //���캯��
    virtual void pay();    //������н����
    virtual void displayStatus();  //��ʾ��Ա��Ϣ
};

class manager:virtual public employee  //������
{
protected:
    float monthlyPay;   //�̶���н��
public:
    manager();    //���캯��
    virtual void pay();    //������н����
    virtual void displayStatus();  //��ʾ��Ա��Ϣ
};
class salesmanager : public manager,public salesman  //���۾�����
{
public:
    salesmanager ();  //���캯��
    void pay();  //������н����
    void displayStatus();  //��ʾ��Ա��Ϣ
};

employee::employee()
{
    char namestr[50];
    //���˹�Ա����ʱ������ʱ�����namestr��
    cout<<"��������һ����Ա������:";
    cin>>namestr;
    name=new char[strlen(namestr)+1];
    //��̬�������ڴ���������ڴ�ռ�
    strcpy(name, namestr);
    //����ʱ��ŵ��������Ƶ� name
    individualEmpNo= employeeNo++;
    //�����˵�Ա��������ΪĿǰ����ż�1
    grade=1;  //�����ֵΪ1
    accumPay=0.0;  //��н�ܶ��ֵΪ0
}

employee :: ~employee()
{
    delete name ;
    //������������ɾ��Ϊ���������̬������ڴ�ռ�
}
void employee :: pay( )  //������н���պ���
{
}
void employee ::promote(int increment)
{
    grade += increment ;
    //�����������ļ����� incrementָ��
}
void employee :: displayStatus( )  //��ʾ��Ա��Ϣ���պ���
{
}

technician :: technician()
{  hourlyRate=100;  //ÿСʱ���100Ԫ
}
void technician::pay()
{   cout<<"������"<<name<<"���µĹ���ʱ��:";
    cin>>workHours;
    accumPay=hourlyRate* workHours;
    //������н����Сʱ�Ƴ�
    cout<<"��ְ������Ա"<<name<<"���"<<individualEmpNo
            <<"���¹���"<<accumPay<<endl;
}
void technician::displayStatus()
{   cout<<"��ְ������Ա"<<name<<"���"<< individualEmpNo << "����Ϊ" <<grade<<
            "�����Ѹ����¹���"<<accumPay<<endl;
}

salesman::salesman()
{
    CommRate=0.04;  //������ɱ���4��
}
void salesman::pay()
{
    cout<<"������"<<name<<"���µ����۶�:";
    cin>>sales;
    accumPay=sales*CommRate;  //��н���������
    cout<<"����Ա"<<name<<"���"<<individualEmpNo
            <<"���¹���"<<accumPay<<endl;
}
void salesman::displayStatus()
{    cout<<"����Ա"<<name<<"���"<<individualEmpNo
            <<"����Ϊ"<<grade<<"�����Ѹ����¹���"<<accumPay<<endl;
}
manager::manager()
{
    monthlyPay=8000;  //�̶���н8000Ԫ
}
void manager :: pay()
{
    accumPay=monthlyPay;  //��н�ܶ�̶���н��
    cout<<"����"<<name<<"���"<<individualEmpNo
            <<"���¹���"<<accumPay<<endl;
}
void manager :: displayStatus()
{
    cout<<"����"<<name<<"���"<<individualEmpNo
            <<"����Ϊ"<<grade<<"�����Ѹ����¹���"<<accumPay<<endl;
}
salesmanager ::salesmanager()
{  monthlyPay=5000;
    CommRate= 0.005;
}
void salesmanager ::pay()
{
    cout<<"������"<<employee ::name<<"����Ͻ���ű��µ������ܶ�:";
    cin>>sales;
    accumPay=monthlyPay+CommRate*sales;  //��н���̶���нʮ�������
    cout<<"���۾���"<<name<<"���"<<individualEmpNo
            <<"���¹���"<<accumPay<<endl;
}
void salesmanager::displayStatus()
{   cout<<"���۾���"<< name<<"���"<<individualEmpNo
            <<"����Ϊ"<<grade<<"�����Ѹ����¹���"<<accumPay<<endl;
}
int employee::employeeNo=0;
int main()
{
    employee *p;
    manager m1;
    technician t1;
    salesmanager sm1;
    salesman s1;

    p = &m1;
    p->promote(3);    //����m1����3��
    p->pay();     //����m1��н
    p->displayStatus();   //��ʾm1��Ϣ

    p = &t1;
    p->promote(2);    //t1����2��
    p->pay();     //����t1��н
    p->displayStatus();   //��ʾtl��Ϣ

    p = &sm1;
    p->promote(2);    //sml����2��
    p->pay();    //����sml��н
    p->displayStatus();   //��ʾsml��Ϣ

    p = &s1;
    p->pay();     //����s1��н
    p->displayStatus();   //��ʾs1��Ϣ
    return 0;
}
