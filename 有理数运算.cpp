#include<iostream> //C++ ��׼����ͷ �ļ�֮һ����Ҫ������ʹ�ñ�׼�������������Ķ��塣�������� ���� cin cout ��ʹ�� 

#include<algorithm>//C++ ��׼���е�ͷ�ļ�����Ҫ�����˴������㷨�������������ú������������� ���� ��Լ�� ���㷨���� 

#include<string>//C++ ��׼���а����ַ������ͷ�ļ�������ʹ�����е���ͺ���������ز����ַ�����string �����ͺͳ��õ��ַ��������������������� ���� find() substr() ��Ӧ�� 

#include <sstream>//��׼��������֧���ַ�������ͷ�ļ����ṩ�����ڴ��н����ַ�������������ͺ�������������� istringstream��ʹ�� 

#include <limits>//������ֵ���ͼ�ֵ����Ϣ �������� ����ʹ�� numeric_limits �� max() ���� 

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
    int getDenominator() const {
        return denominator;
    }
};

RationalNumber::RationalNumber(int n, int d)  //���� ��ĸ ��ʼ�� 
 {
    numerator = n;
    denominator = d; //== 0 ? 1 : d;  //�����ĸΪ������ 
    optimize();     // �ڹ��캯��������ִ���Ż�����
}

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
        os << r.numerator;
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

int main() 
{
    RationalNumber r1(2, 3);
    RationalNumber r2(5, 7);
    RationalNumber r3 = r1 + r2;
    RationalNumber r4 = r1 - r2;
    RationalNumber r5 = r1 * r2;
    RationalNumber r6 = r1 / r2;
    cout << r1 << " + " << r2 << " = " << r3 << endl;
    cout << r1 << " - " << r2 << " = " << r4 << endl;
    cout << r1 << " * " << r2 << " = " << r5 << endl;
    cout << r1 << " / " << r2 << " = " << r6 << endl;
    
    if (r1 == r2)                         //�ж� �������ĸ �Ƿ� ��� 
	 {
        cout << r1 << " equals " << r2 << endl;
    } 
	else 
	{
        cout << r1 << " does not equal " << r2 << endl;
    }
    cout << "r1 as a double is " << r1.toDouble() << endl;
    
    cout << "r2 as a double is " << r2.toDouble() << endl;
    RationalNumber r7;
while (cout << "Please enter a rational number��numerator/denominator��: " && !(cin >> r7) || r7.getDenominator() == 0) //���ַ�ĸ��Ϊ�� ���� һֱ���뵽 ����Ϊֹ 
{
    cin.clear();                                              // ��ն�ȡ�����־
    cin.ignore(numeric_limits<streamsize>::max(), '\n');    // ���Ա���ʣ���ַ�
    cout << "Invalid input, please try again.\n";
}
   /*cout <<"Enter a rational number: ";
    RationalNumber r7;
    cin >> r7;*/ 
    cout << "You entered: " <<r7 << endl; 
    return 0;
}
