#include<iostream>
#include<cstring>
using namespace std;

class employee
{    protected:
    char *name;    //姓名
    int individualEmpNo;   //个人编号
    int grade;    //级别
    float accumPay;    //月薪总额
    static int employeeNo;   //本公司职员编号目前最大值
public:
    employee();     //构造函数
    virtual ~employee();      //析构函数
    virtual void pay();     //计算月薪函数
    void promote(int);    //升级函数
    virtual void displayStatus();    //显示人员信息
};

class technician : public employee  //技术人员类
{
private:
    float hourlyRate;   //每小时酬金
    int workHours;    //当月工作时数
public:
    technician();    //构造函数
    void pay();    //计算月薪函数
    void displayStatus();  //显示人员信息
};
class salesman:virtual public employee  //兼职推销员类
{
protected:
    float CommRate;  //按销售额提取酬金的百分比
    float sales;    //当月销售额
public:
    salesman();    //构造函数
    virtual void pay();    //计算月薪函数
    virtual void displayStatus();  //显示人员信息
};

class manager:virtual public employee  //经理类
{
protected:
    float monthlyPay;   //固定月薪数
public:
    manager();    //构造函数
    virtual void pay();    //计算月薪函数
    virtual void displayStatus();  //显示人员信息
};
class salesmanager : public manager,public salesman  //销售经理类
{
public:
    salesmanager ();  //构造函数
    void pay();  //计算月薪函数
    void displayStatus();  //显示人员信息
};

employee::employee()
{
    char namestr[50];
    //输人雇员姓名时首先临时存放在namestr中
    cout<<"请输入下一个雇员的姓名:";
    cin>>namestr;
    name=new char[strlen(namestr)+1];
    //动态申请用于存放姓名的内存空间
    strcpy(name, namestr);
    //将临时存放的姓名复制到 name
    individualEmpNo= employeeNo++;
    //新输人的员工，其编号为目前最大编号加1
    grade=1;  //级别初值为1
    accumPay=0.0;  //月薪总额初值为0
}

employee :: ~employee()
{
    delete name ;
    //在析构函数中删除为存放姓名动态分配的内存空间
}
void employee :: pay( )  //计算月薪，空函数
{
}
void employee ::promote(int increment)
{
    grade += increment ;
    //升级，提升的级数由 increment指定
}
void employee :: displayStatus( )  //显示人员信息，空函数
{
}

technician :: technician()
{  hourlyRate=100;  //每小时酬金100元
}
void technician::pay()
{   cout<<"请输入"<<name<<"本月的工作时数:";
    cin>>workHours;
    accumPay=hourlyRate* workHours;
    //计算月薪，按小时计酬
    cout<<"兼职技术人员"<<name<<"编号"<<individualEmpNo
            <<"本月工资"<<accumPay<<endl;
}
void technician::displayStatus()
{   cout<<"兼职技术人员"<<name<<"编号"<< individualEmpNo << "级别为" <<grade<<
            "级，已付本月工资"<<accumPay<<endl;
}

salesman::salesman()
{
    CommRate=0.04;  //销售提成比例4％
}
void salesman::pay()
{
    cout<<"请输入"<<name<<"本月的销售额:";
    cin>>sales;
    accumPay=sales*CommRate;  //月薪＝销售提成
    cout<<"推销员"<<name<<"编号"<<individualEmpNo
            <<"本月工资"<<accumPay<<endl;
}
void salesman::displayStatus()
{    cout<<"推销员"<<name<<"编号"<<individualEmpNo
            <<"级别为"<<grade<<"级，已付本月工资"<<accumPay<<endl;
}
manager::manager()
{
    monthlyPay=8000;  //固定月薪8000元
}
void manager :: pay()
{
    accumPay=monthlyPay;  //月薪总额即固定月薪数
    cout<<"经理"<<name<<"编号"<<individualEmpNo
            <<"本月工资"<<accumPay<<endl;
}
void manager :: displayStatus()
{
    cout<<"经理"<<name<<"编号"<<individualEmpNo
            <<"级别为"<<grade<<"级，已付本月工资"<<accumPay<<endl;
}
salesmanager ::salesmanager()
{  monthlyPay=5000;
    CommRate= 0.005;
}
void salesmanager ::pay()
{
    cout<<"请输入"<<employee ::name<<"所管辖部门本月的销售总额:";
    cin>>sales;
    accumPay=monthlyPay+CommRate*sales;  //月薪＝固定月薪十销售提成
    cout<<"销售经理"<<name<<"编号"<<individualEmpNo
            <<"本月工资"<<accumPay<<endl;
}
void salesmanager::displayStatus()
{   cout<<"销售经理"<< name<<"编号"<<individualEmpNo
            <<"级别为"<<grade<<"级，已付本月工资"<<accumPay<<endl;
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
    p->promote(3);    //经理m1提升3级
    p->pay();     //计算m1月薪
    p->displayStatus();   //显示m1信息

    p = &t1;
    p->promote(2);    //t1提升2级
    p->pay();     //计算t1月薪
    p->displayStatus();   //显示tl信息

    p = &sm1;
    p->promote(2);    //sml提升2级
    p->pay();    //计算sml月薪
    p->displayStatus();   //显示sml信息

    p = &s1;
    p->pay();     //计算s1月薪
    p->displayStatus();   //显示s1信息
    return 0;
}
