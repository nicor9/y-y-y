#include<iostream> 
using namespace std;

/*class RationalNumber //�������� 
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
};*/ 
class RationalNumber {
private:
    int numerator;
    int denominator;
    void optimize();  // �� optimize ��������Ϊ˽�г�Ա����
public:
    RationalNumber(int n=0, int d=1);
    double toDouble() const;
    friend RationalNumber operator+(const RationalNumber& r1, const RationalNumber& r2);
    friend RationalNumber operator-(const RationalNumber& r1, const RationalNumber& r2);
    friend RationalNumber operator*(const RationalNumber& r1, const RationalNumber& r2);
    friend RationalNumber operator/(const RationalNumber& r1, const RationalNumber& r2);
    friend bool operator==(const RationalNumber& r1, const RationalNumber& r2);
    friend std::ostream& operator<<(std::ostream& os, const RationalNumber& r);
    friend std::istream& operator>>(std::istream& is, RationalNumber& r);
    int getDenominator() const;

    RationalNumber operator-() const {
        return RationalNumber(-numerator, denominator);
    }

    RationalNumber operator+() const {
        return *this;
    }
};
