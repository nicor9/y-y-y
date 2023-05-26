#include<iostream> //C++ ��׼����ͷ �ļ�֮һ����Ҫ������ʹ�ñ�׼�������������Ķ��塣�������� ���� cin cout ��ʹ�� 

#include<algorithm>//C++ ��׼���е�ͷ�ļ�����Ҫ�����˴������㷨�������������ú������������� ���� ��Լ�� ���㷨���� 

#include<string>//C++ ��׼���а����ַ������ͷ�ļ�������ʹ�����е���ͺ���������ز����ַ�����string �����ͺͳ��õ��ַ��������������������� ���� find() substr() ��Ӧ�� 

#include <sstream>//��׼��������֧���ַ�������ͷ�ļ����ṩ�����ڴ��н����ַ�������������ͺ�������������� istringstream��ʹ�� 

#include <limits>//������ֵ���ͼ�ֵ����Ϣ �������� ����ʹ�� numeric_limits �� max() ���� 

#include"RationalNumber.h"
using namespace std;
void RationalNumber::optimize()  //�Դ���������������ʱ����ķ��Ӻͷ�ĸ�������Ż����������ĸΪ 0����������Ϊ 1 
{
    int gcd = __gcd(numerator, denominator);  // ʹ��algorithmͷ�ļ��е�__gcd���������Լ��
    numerator /= gcd;                         //����Լ�� 
    denominator /= gcd;                       //��ĸԼ�� 
    if (denominator < 0) {             // �����ĸΪ�������򽫷��Ӻͷ�ĸ����Ϊ�෴��    �ڽ�����������Ĵ�������� ����ͨ��Ҫ���ĸΪ���������������Ҫ������������ת���������Ϊ�����ʽ����֤���������������ϵ���Ч��
        numerator = -numerator;
        denominator = -denominator;
    }
}
 RationalNumber::RationalNumber(int n, int d)  //���� ��ĸ ��ʼ�� 
 {
    numerator = n;
    denominator = d; //== 0 ? 1 : d;  //�����ĸΪ������ 
    optimize();     // �ڹ��캯��������ִ���Ż�����
}



RationalNumber operator+(const RationalNumber& r1, const RationalNumber& r2) //������ �ӷ� ������  
{
    int n = r1.numerator * r2.denominator + r2.numerator * r1.denominator;  //���� 
    int d = r1.denominator * r2.denominator;                                 //��ĸͨ�� 
    return RationalNumber(n, d);
}

RationalNumber operator-(const RationalNumber& r1, const RationalNumber& r2) //������ ���� ������ 
{
    int n = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
    int d = r1.denominator * r2.denominator;
    return RationalNumber(n, d);
}

RationalNumber operator*(const RationalNumber& r1, const RationalNumber& r2) //������ �˷� ������ 
{
    int n = r1.numerator * r2.numerator;
    int d = r1.denominator * r2.denominator;
    return RationalNumber(n, d);
}

RationalNumber operator/(const RationalNumber& r1, const RationalNumber& r2) //������ ���� ������ 
{
    int n = r1.numerator * r2.denominator;
    int d = r1.denominator * r2.numerator;
    return RationalNumber(n, d);
}

bool operator==(const RationalNumber& r1, const RationalNumber& r2)         //�����жϵ��������������� ͬʱ�ж����ǵķ��Ӻͷ�ĸ�Ƿ���ȡ�ֻ�з��Ӻͷ�ĸ�����ʱ���ŷ��� true����ʾ������������������ȣ����򷵻� false��       
{
    return r1.numerator == r2.numerator && r1.denominator == r2.denominator;
}

double RationalNumber::toDouble() const //ת�� ��double ���ݽ������� �Ի�ø��ߵļ��㾫��
{
    return (double)numerator / denominator;
}

ostream& operator<<(ostream& os, const RationalNumber& r)  //������� 
 {
    if (r.denominator == 1)  // ��ĸΪ1ʱ����� ������/1 �� 
	{                             
        os << r.numerator<<"/"<<1;
    } 
	else 
	{
        os << r.numerator << "/" << r.denominator;
    }
    return os;
}

istream& operator>>(istream& is, RationalNumber& r)  //�������� 
 {    
    string s;
    is >> s;            // ����һ���ַ���
    int pos = s.find('/');   // �ҵ��ַ����з����ߵ�λ��
    if (pos != string::npos)    //���ִ��� �ҵ��˷����� ����һ�������� ����string����npos����һ�� ���������Ч��ֵ 
	{                     // ����ҵ��˷�����
        int num, den; 
stringstream ss;
ss << s.substr(0, pos);     //��ȡ���� 
ss >> num;
ss.clear();
ss << s.substr(pos+1);        // ��ȡ��ĸ 
ss >> den;             
        
        r = RationalNumber(num, den);  //����һ���µ�����������
    } 
else 
{                      // ���û���ҵ�������
        int num, den;
istringstream(s.substr(0, pos)) >> num;
istringstream(s.substr(pos+1)) >> den;  // �������ַ�����Ϊ����
		r=RationalNumber(num,den);  // ����һ���µ����������󣬷�ĸĬ��Ϊ1
    }
    return is;
}
    
