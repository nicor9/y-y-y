#include<iostream> //C++ 标准库中头 文件之一，主要包含了使用标准输入输出流所需的定义。本程序中 包含 cin cout 的使用 

#include<algorithm>//C++ 标准库中的头文件，主要包含了大量的算法函数及其他常用函数。本程序中 包含 求公约数 的算法函数 

#include<string>//C++ 标准库中包含字符串类的头文件，可以使用其中的类和函数来方便地操作字符串，string 类类型和常用的字符串操作函数。本程序中 包含 find() substr() 的应用 

#include <sstream>//标准库中用于支持字符串流的头文件，提供了在内存中进行字符串流操作的类和函数。本程序包含 istringstream的使用 

#include <limits>//包含数值类型极值的信息 本程序中 包含使用 numeric_limits 的 max() 方法 

#include"RationalNumber.h"
using namespace std;
void RationalNumber::optimize()  //对创建该有理数对象时传入的分子和分母进行了优化处理。如果分母为 0，则将其设置为 1 
{
    int gcd = __gcd(numerator, denominator);  // 使用algorithm头文件中的__gcd函数求最大公约数
    numerator /= gcd;                         //分子约分 
    denominator /= gcd;                       //分母约分 
    if (denominator < 0) {             // 如果分母为负数，则将分子和分母都变为相反数    在进行有理数类的处理过程中 我们通常要求分母为正整数，否则就需要对有理数进行转化，将其变为最简形式。保证在坐标轴正方向上的有效性
        numerator = -numerator;
        denominator = -denominator;
    }
}
 RationalNumber::RationalNumber(int n, int d)  //分子 分母 初始化 
 {
    numerator = n;
    denominator = d; //== 0 ? 1 : d;  //避免分母为零的情况 
    optimize();     // 在构造函数里立即执行优化函数
}



RationalNumber operator+(const RationalNumber& r1, const RationalNumber& r2) //有理数 加法 的重载  
{
    int n = r1.numerator * r2.denominator + r2.numerator * r1.denominator;  //分子 
    int d = r1.denominator * r2.denominator;                                 //分母通分 
    return RationalNumber(n, d);
}

RationalNumber operator-(const RationalNumber& r1, const RationalNumber& r2) //有理数 减法 的重载 
{
    int n = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
    int d = r1.denominator * r2.denominator;
    return RationalNumber(n, d);
}

RationalNumber operator*(const RationalNumber& r1, const RationalNumber& r2) //有理数 乘法 的重载 
{
    int n = r1.numerator * r2.numerator;
    int d = r1.denominator * r2.denominator;
    return RationalNumber(n, d);
}

RationalNumber operator/(const RationalNumber& r1, const RationalNumber& r2) //有理数 除法 的重载 
{
    int n = r1.numerator * r2.denominator;
    int d = r1.denominator * r2.numerator;
    return RationalNumber(n, d);
}

bool operator==(const RationalNumber& r1, const RationalNumber& r2)         //进行判断的两个有理数对象 同时判断它们的分子和分母是否相等。只有分子和分母均相等时，才返回 true，表示这两个有理数对象相等，否则返回 false。       
{
    return r1.numerator == r2.numerator && r1.denominator == r2.denominator;
}

double RationalNumber::toDouble() const //转换 成double 数据进行运算 以获得更高的计算精度
{
    return (double)numerator / denominator;
}

ostream& operator<<(ostream& os, const RationalNumber& r)  //输出重载 
 {
    if (r.denominator == 1)  // 分母为1时，输出 “分子/1 ” 
	{                             
        os << r.numerator<<"/"<<1;
    } 
	else 
	{
        os << r.numerator << "/" << r.denominator;
    }
    return os;
}

istream& operator>>(istream& is, RationalNumber& r)  //输入重载 
 {    
    string s;
    is >> s;            // 输入一个字符串
    int pos = s.find('/');   // 找到字符串中分数线的位置
    if (pos != string::npos)    //在字串中 找到了分数线 返回一个非零数 或者string：：npos返回一个 无意义或无效的值 
	{                     // 如果找到了分数线
        int num, den; 
stringstream ss;
ss << s.substr(0, pos);     //提取分子 
ss >> num;
ss.clear();
ss << s.substr(pos+1);        // 提取分母 
ss >> den;             
        
        r = RationalNumber(num, den);  //创建一个新的有理数对象
    } 
else 
{                      // 如果没有找到分数线
        int num, den;
istringstream(s.substr(0, pos)) >> num;
istringstream(s.substr(pos+1)) >> den;  // 则将整个字符串视为分子
		r=RationalNumber(num,den);  // 创建一个新的有理数对象，分母默认为1
    }
    return is;
}
    
