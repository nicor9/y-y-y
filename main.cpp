#include<iostream>
#include"RationalNumber.cpp"
using namespace std;
 
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
    
    if (r1 == r2)                         //判断 分子与分母 是否 相等 
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
while (cout << "Please enter a rational number（numerator/denominator）: " && !(cin >> r7) || r7.getDenominator() == 0) //保持分母不为零 否则 一直输入到 成立为止 
{
    cin.clear();                                              // 清空读取错误标志
    cin.ignore(numeric_limits<streamsize>::max(), '\n');    // 忽略本行剩余字符
    cout << "Invalid input, please try again.\n";
}
   /*cout <<"Enter a rational number: ";
    RationalNumber r7;
    cin >> r7;*/ 
    cout << "You entered: " <<r7 << endl; 
    return 0;
}
