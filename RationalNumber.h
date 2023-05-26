#include<iostream> 
using namespace std;



class RationalNumber //有理数类 
{
private:
    int numerator;    // 分子
    int denominator;  // 分母
public:
  RationalNumber(int n = 0, int d = 1);  // 构造函数
   void optimize();  // 优化函数
    double toDouble() const;  // 转换为实数
    friend RationalNumber operator+(const RationalNumber& r1, const RationalNumber& r2);  // 重载加法运算符
    friend RationalNumber operator-(const RationalNumber& r1, const RationalNumber& r2);  // 重载减法运算符
    friend RationalNumber operator*(const RationalNumber& r1, const RationalNumber& r2);  // 重载乘法运算符
    friend RationalNumber operator/(const RationalNumber& r1, const RationalNumber& r2);  // 重载除法运算符
    friend bool operator==(const RationalNumber& r1, const RationalNumber& r2);  // 重载相等运算符
    friend ostream& operator<<(ostream& os, const RationalNumber& r);  // 重载输出运算符
    friend istream& operator>>(istream& is, RationalNumber& r);  // 重载输入运算符
    int getDenominator() const 
	{
        return denominator;
    }
};

