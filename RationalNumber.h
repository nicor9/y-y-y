#include<iostream> 
using namespace std;



class RationalNumber //�������� 
{
private:
    int numerator;    // ����
    int denominator;  // ��ĸ
public:
  RationalNumber(int n = 0, int d = 1);  // ���캯��
   void optimize();  // �Ż�����
    double toDouble() const;  // ת��Ϊʵ��
    friend RationalNumber operator+(const RationalNumber& r1, const RationalNumber& r2);  // ���ؼӷ������
    friend RationalNumber operator-(const RationalNumber& r1, const RationalNumber& r2);  // ���ؼ��������
    friend RationalNumber operator*(const RationalNumber& r1, const RationalNumber& r2);  // ���س˷������
    friend RationalNumber operator/(const RationalNumber& r1, const RationalNumber& r2);  // ���س��������
    friend bool operator==(const RationalNumber& r1, const RationalNumber& r2);  // ������������
    friend ostream& operator<<(ostream& os, const RationalNumber& r);  // ������������
    friend istream& operator>>(istream& is, RationalNumber& r);  // �������������
    int getDenominator() const 
	{
        return denominator;
    }
};

