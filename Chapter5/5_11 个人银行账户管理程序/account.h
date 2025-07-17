#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
class SavingsAccount{
private:
    int id;          //�˻�ID
    double balance;  //�˻����
    double rate;      //����
    int lastDate;   //�ϴα����������
    double accumulation;    //�����ۼ�֮��
    static double total;    //�����˻����ܽ��
    //��¼һ���ˣ�dateΪ���ڣ�amountΪ��descΪ˵��
    void record(int date,double amount);
    //��õ�ָ������Ϊֹ�Ĵ������ۻ�ֵ
    double accumulate(int date) const{    //����Ա����
        return accumulation+balance*(date-lastDate);
    }
public:
    //���캯��,idΪ�˻�ID��balanceΪ��rateΪ����
    //����Ա������ֻ�ܵ��ó�����
    SavingsAccount(int date, int id,double rate);
    int getId() const{return id;}  //��ȡ�˻�ID
    int getBalance() const{return balance;}  //��ȡ�˻����
    double getRate() const{return rate;}  //��ȡ�˻�����
    //��ʾ�˻���Ϣ
    void show() const;
    static double getTotal() {return total;}  //��ȡ�����˻����ܽ�� ��̬��Ա������ӵ��������
    void deposit(int date,double amount);  //�����ֽ�
    void withdraw(int date,double amount); //ȡ���ֽ�
    //������Ϣ,ÿ��1��1�յ���һ�θú���
    void settle(int date);
};
#endif // __ACCOUNT_H__