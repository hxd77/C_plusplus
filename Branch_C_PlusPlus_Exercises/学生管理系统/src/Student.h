#include<iostream>
#include<vector>
#include<map>
using namespace std;

class StudentBase
{
public:
    void buildBaseData();
    void modifyData();
    vector<long>getmNum();
    vector<string>getmName();
    vector<int>getmSex();
    vector<int>getmAge();
    vector<string>getmAddr();
    long getNumAtIndex(int index);
    string getNameAtIndex(int index);
    int getSexAtIndex(int index);
    int getAgeAtIndex(int index);
    string getAddrAtIndex(int index);
    int getmPosition(long index);
private:
    vector<long>mNum;//学号
    vector<string>mName;//姓名
    vector<int>mSex;//性别
    vector<int>mAge;//年龄
    vector<string>mAddr;//住址
    vector<string>mMajor;//主修专业
    map<long,int>mPosition;//键值对映射
};
//第四种方案
//主修专业A类
class FirstA:virtual public StudentBase//虚基类 //系(专业)A
{
public:
    FirstA();
    void inputA_MajorScore();//输入专业A主修课程成绩表
    void inputA_SecondScore();//专业A学生的第二专业成绩
    void outputA_Good();//A专业合格
    void outputA_MajorFail();//A专业不合格
    void outputA_SecondFail();//第二专业合格
    char*getA_MajorDepName();//返回A专业系名
    vector<long> getA_MajorNum();//返回主修学生的学号列表
    vector<long>getA_SecondNum();//返回双专业学生的学号列表
    vector<vector<int>>getA_FirstScore();//返回主修课程成绩表
    vector<vector<int>>getA_FScore();//最终成绩表

private:
    char mA_MajorDepName[30];//专业A的系名
    vector<string>A_Second_MajorName;//第二专业名
    vector<vector<int>>mA_FirstScore;//主修成绩表(二维数组，每个学生x课程)
    vector<vector<int>>A_Fscore;////最终成绩
    vector<long>secondA_Num;//双专业学生学号
    vector<long>majorA_Num;//主修学生的学号
};

//主修专业B类
class FirstB:virtual public StudentBase
{
public:
    FirstB();
    void inputB_MajorScore();
    void inputB_SecondScore();
    void outputB_Good();
    void outputB_MajorFail();
    void outputB_SecondFail();
    char*getB_MajorDepName();
    vector<long>getB_MajorNum();
    vector<long>getB_SecondNum();
    vector<vector<int>>getB_FirstScore();
    vector<vector<int>>getB_FScore();
private:
    char mB_MajorDepName[30];
    vector<string>B_Second_MajorName;
    vector<vector<int>>mB_FirstScore;
    vector<vector<int>>B_Fscore;
    vector<long>secondB_Num;
    vector<long>majorB_Num;
};

//主修专业C类
class FirstC:virtual public StudentBase
{
public:
    FirstC();
    void inputC_MajorScore();
    void inputC_SecondScore();
    void outputC_Good();
    void outputC_MajorFail();
    void outputC_SecondFail();
    char*getC_MajorDepName();
    vector<long>getC_MajorNum();
    vector<long>getC_SecondNum();
    vector<vector<int>>getC_FirstScore();
    vector<vector<int>>getC_FScore();
private:
    char mC_MajorDepName[30];
    vector<string>C_Second_MajorName();
    vector<vector<int>>mC_FistScore;
    vector<vector<int>>C_Fscore;
    vector<long>secondC_Num;
    vector<long>majorC_Num;
};

class StudentMIS:public FirstA,public FirstB,public FirstC
{
public:
    StudentMIS();
    void degreeStanderOfFirst();
    void degreeStanderOfSecond();
    void degree();
private:
    int SA,SB,SC;
    int KA,KB,KC;
};