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
