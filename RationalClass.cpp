#include <iostream>
using namespace std;
bool correct = true;
class Rational
{
    int num;
    int den;

public:
    Rational()
    {
        num = 0;
        den = 1;
    }
    Rational(int num, int den)
    {
        if (den == 0)
        {
            cout << "ILLEGAL RATIONAL NUMBER\n";
            correct = false;
        }
        else
        {
            if (num < 0 && den < 0)
            {
                this->num = abs(num);
                this->den = abs(den);
            }
            else if (den < 0)
            {
                this->num = -num;
                this->den = abs(den);
            }
            else
            {
                this->num = num;
                this->den = den;
            }
        }
    }
    Rational(const Rational &obj)
    {
        num = obj.num;
        den = obj.den;
    }
    void operator=(const Rational &);
    int getNum()
    {
        return num;
    }
    int getDen()
    {
        return den;
    }
};
void Rational::operator=(const Rational &obj)
{
    num = obj.num;
    den = obj.den;
}
Rational operator+(Rational &obj1, Rational &obj2)
{

    int res1 = (obj1.getNum() * obj2.getDen()) + (obj2.getNum() * obj1.getDen());
    int res2 = (obj1.getDen() * obj2.getDen());
    Rational res(Rational(res1, res2));
    return res;
}
Rational operator-(Rational &obj1, Rational &obj2)
{
    int res1 = (obj1.getNum() * obj2.getDen()) - (obj2.getNum() * obj1.getDen());
    int res2 = (obj1.getDen() * obj2.getDen());
    Rational res(Rational(res1, res2));
    return res;
}
Rational operator*(Rational &obj1, Rational &obj2)
{
    int res1 = (obj1.getNum() * obj2.getNum());
    int res2 = (obj1.getDen() * obj2.getDen());
    Rational res(Rational(res1, res2));
    return res;
}
Rational operator/(Rational &obj1, Rational &obj2)
{
    if (obj2.getNum() != 0)
    {
        if ((obj1.getNum() < 0 || obj1.getDen() < 0) && (obj2.getNum() < 0 || obj2.getDen() < 0))
        {
            int res1 = (abs(obj1.getNum()) * abs(obj2.getDen()));
            int res2 = (abs(obj2.getNum()) * abs(obj1.getDen()));
            //cout << res1 << res2 << "\n";
            Rational res(Rational(res1, res2));
            return res;
        }
        else if (((obj1.getNum() < 0 || obj1.getDen() < 0) && (obj2.getNum() > 0 || obj2.getDen() > 0)) || ((obj1.getNum() > 0 || obj1.getDen() > 0) && (obj2.getNum() < 0 || obj2.getDen() < 0)))
        {
            cout << "DIVISION NOT POSSIBLE\n";
            correct = false;
        }
        else
        {
            int res1 = (obj1.getNum() * obj2.getDen());
            int res2 = (obj2.getNum() * obj1.getDen());
            //cout << res1 << res2 << "\n";
            Rational res(Rational(res1, res2));
            return res;
        }
    }
    else
    {
        cout << "DIVISION NOT POSSIBLE\n";
    }
}
Rational operator-(Rational &obj)
{
    if (obj.getNum() > 0 && obj.getDen() > 0)
    {
        return Rational(-obj.getNum(), obj.getDen());
    }
    else
    {
        if (obj.getNum() < 0)
            return Rational(-obj.getNum(), obj.getDen());
        else
            return Rational(obj.getNum(), -obj.getDen());
    }
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int lcm(int a, int b)
{
    return ((a * b) / gcd(a, b));
}
Rational operator>(Rational &obj1, Rational &obj2)
{
    if (obj1.getDen() == obj2.getDen())
    {
        if (obj1.getNum() > obj2.getNum())
        {
            cout << obj1.getNum() << "/" << obj1.getDen() << " IS GREATER\n";
        }
        else
        {
            cout << obj2.getNum() << "/" << obj2.getDen() << " IS GREATER\n";
        }
    }
    else if (obj1.getNum() == obj2.getNum())
    {
        if (obj1.getNum() < 0 && obj2.getNum() < 0)
        {
            if (obj1.getDen() > obj2.getDen())
            {
                cout << obj1.getNum() << "/" << obj1.getDen() << " IS GREATER\n";
            }
            else
            {

                cout << obj2.getNum() << "/" << obj2.getDen() << " IS GREATER\n";
            }
        }
        else if (obj1.getDen() > obj2.getDen())
        {
            cout << obj2.getNum() << "/" << obj2.getDen() << " IS GREATER\n";
        }
        else
        {
            cout << obj1.getNum() << "/" << obj1.getDen() << " IS GREATER\n";
        }
    }
    else
    {
        int LCM = lcm(abs(obj1.getDen()), abs(obj2.getDen()));
        int num1 = obj1.getNum() * (LCM / obj1.getDen());
        int den1 = obj1.getDen() * (LCM / obj1.getDen());
        int num2 = obj2.getNum() * (LCM / obj2.getDen());
        int den2 = obj2.getDen() * (LCM / obj2.getDen());
        if ((num1 < 0 || den1 < 0) && (num2 < 0 || den2 < 0))
        {
            if (num1 > num2)
            {

                cout << obj1.getNum() << "/" << obj1.getDen() << " IS GREATER\n";
            }
            else
            {
                cout << obj2.getNum() << "/" << obj2.getDen() << " IS GREATER\n";
            }
        }
        else if (num1 > num2)
        {
            cout << obj1.getNum() << "/" << obj1.getDen() << " IS GREATER\n";
        }
        else
        {
            cout << obj2.getNum() << "/" << obj2.getDen() << " IS GREATER\n";
        }
    }
}
Rational operator>=(Rational &obj1, Rational &obj2)
{
    if (obj1.getDen() == obj2.getDen())
    {
        if (obj1.getNum() == obj2.getNum())
        {
            cout << "BOTH FRACTIONS ARE EQUAL\n";
        }
        else if (obj1.getNum() > obj2.getNum())
        {
            cout << obj1.getNum() << "/" << obj1.getDen() << " IS GREATER\n";
        }
        else
        {
            cout << obj2.getNum() << "/" << obj2.getDen() << " IS GREATER\n";
        }
    }
    else if (obj1.getNum() == obj2.getNum())
    {
        if (obj1.getNum() < 0 && obj2.getNum() < 0)
        {
            if (obj1.getDen() > obj2.getDen())
            {
                cout << obj1.getNum() << "/" << obj1.getDen() << " IS GREATER\n";
            }
            else
            {

                cout << obj2.getNum() << "/" << obj2.getDen() << " IS GREATER\n";
            }
        }
        else if (obj1.getDen() > obj2.getDen())
        {
            cout << obj2.getNum() << "/" << obj2.getDen() << " IS GREATER\n";
        }
        else
        {
            cout << obj1.getNum() << "/" << obj1.getDen() << " IS GREATER\n";
        }
    }
    else
    {
        int LCM = lcm(abs(obj1.getDen()), abs(obj2.getDen()));
        int num1 = obj1.getNum() * (LCM / obj1.getDen());
        int den1 = obj1.getDen() * (LCM / obj1.getDen());
        int num2 = obj2.getNum() * (LCM / obj2.getDen());
        int den2 = obj2.getDen() * (LCM / obj2.getDen());
        cout << num1 << den1 << num2 << den2 << "\n";
        if ((num1 < 0 || den1 < 0) && (num2 < 0 || den2 < 0))
        {
            if (num1 > num2)
            {

                cout << obj1.getNum() << "/" << obj1.getDen() << " IS GREATER\n";
            }
            else
            {
                cout << obj2.getNum() << "/" << obj2.getDen() << " IS GREATER\n";
            }
        }
        else if (num1 > num2)
        {
            cout << obj1.getNum() << "/" << obj1.getDen() << " IS GREATER\n";
        }
        else
        {
            cout << obj2.getNum() << "/" << obj2.getDen() << " IS GREATER\n";
        }
    }
}
Rational operator<=(Rational &obj1, Rational &obj2)
{
    if (obj1.getDen() == obj2.getDen())
    {
        if (obj1.getNum() == obj2.getNum())
        {
            cout << "BOTH FRACTIONS ARE EQUAL\n";
        }
        else if (obj1.getNum() < obj2.getNum())
        {
            cout << obj1.getNum() << "/" << obj1.getDen() << " IS LESSER\n";
        }
        else
        {
            cout << obj2.getNum() << "/" << obj2.getDen() << " IS LESSER\n";
        }
    }
    else if (obj1.getNum() == obj2.getNum())
    {
        if (obj1.getNum() < 0 && obj2.getNum() < 0)
        {
            if (obj1.getDen() < obj2.getDen())
            {
                cout << obj1.getNum() << "/" << obj1.getDen() << " IS LESSER\n";
            }
            else
            {

                cout << obj2.getNum() << "/" << obj2.getDen() << " IS LESSER\n";
            }
        }
        else if (obj1.getDen() < obj2.getDen())
        {
            cout << obj2.getNum() << "/" << obj2.getDen() << " IS LESSER\n";
        }
        else
        {
            cout << obj1.getNum() << "/" << obj1.getDen() << " IS LESSER\n";
        }
    }
    else
    {
        int LCM = lcm(abs(obj1.getDen()), abs(obj2.getDen()));
        int num1 = obj1.getNum() * (LCM / obj1.getDen());
        int den1 = obj1.getDen() * (LCM / obj1.getDen());
        int num2 = obj2.getNum() * (LCM / obj2.getDen());
        int den2 = obj2.getDen() * (LCM / obj2.getDen());
        if ((num1 < 0 || den1 < 0) && (num2 < 0 || den2 < 0))
        {
            if (num1 < num2)
            {

                cout << obj1.getNum() << "/" << obj1.getDen() << " IS LESSER\n";
            }
            else
            {
                cout << obj2.getNum() << "/" << obj2.getDen() << " IS LESSER\n";
            }
        }
        else if (num1 < num2)
        {
            cout << obj1.getNum() << "/" << obj1.getDen() << " IS LESSER\n";
        }
        else
        {
            cout << obj2.getNum() << "/" << obj2.getDen() << " IS LESSER\n";
        }
    }
}
Rational operator<(Rational &obj1, Rational &obj2)
{
    if (obj1.getDen() == obj2.getDen())
    {
        if (obj1.getNum() < obj2.getNum())
        {
            cout << obj1.getNum() << "/" << obj1.getDen() << " IS LESSER\n";
        }
        else
        {
            cout << obj2.getNum() << "/" << obj2.getDen() << " IS LESSER\n";
        }
    }
    else if (obj1.getNum() == obj2.getNum())
    {
        if (obj1.getNum() < 0 && obj2.getNum() < 0)
        {
            if (obj1.getDen() < obj2.getDen())
            {
                cout << obj1.getNum() << "/" << obj1.getDen() << " IS LESSER\n";
            }
            else
            {

                cout << obj2.getNum() << "/" << obj2.getDen() << " IS LESSER\n";
            }
        }
        else if (obj1.getDen() < obj2.getDen())
        {
            cout << obj2.getNum() << "/" << obj2.getDen() << " IS LESSER\n";
        }
        else
        {
            cout << obj1.getNum() << "/" << obj1.getDen() << " IS LESSER\n";
        }
    }
    else
    {
        int LCM = lcm(abs(obj1.getDen()), abs(obj2.getDen()));
        int num1 = obj1.getNum() * (LCM / obj1.getDen());
        int den1 = obj1.getDen() * (LCM / obj1.getDen());
        int num2 = obj2.getNum() * (LCM / obj2.getDen());
        int den2 = obj2.getDen() * (LCM / obj2.getDen());
        if ((num1 < 0 || den1 < 0) && (num2 < 0 || den2 < 0))
        {
            if (num1 < num2)
            {

                cout << obj1.getNum() << "/" << obj1.getDen() << " IS LESSER\n";
            }
            else
            {
                cout << obj2.getNum() << "/" << obj2.getDen() << " IS LESSER\n";
            }
        }
        else if (num1 < num2)
        {
            cout << obj1.getNum() << "/" << obj1.getDen() << " IS LESSER\n";
        }
        else
        {
            cout << obj2.getNum() << "/" << obj2.getDen() << " IS LESSER\n";
        }
    }
}
Rational operator!=(Rational &obj1, Rational &obj2)
{
    int LCM = lcm(abs(obj1.getDen()), abs(obj2.getDen()));
    int num1 = obj1.getNum() * (LCM / obj1.getDen());
    int den1 = obj1.getDen() * (LCM / obj1.getDen());
    int num2 = obj2.getNum() * (LCM / obj2.getDen());
    int den2 = obj2.getDen() * (LCM / obj2.getDen());
    if (num1 != num2 || den1 != den2)
    {
        cout << "TRUE. BOTH FRACTIONS ARE NOT EQUAL\n";
    }
    else
    {
        cout << "FALSE. BOTH FRACTIONS ARE EQUAL\n";
    }
}
Rational operator==(Rational &obj1, Rational &obj2)
{
    int LCM = lcm(abs(obj1.getDen()), abs(obj2.getDen()));
    int num1 = obj1.getNum() * (LCM / obj1.getDen());
    int den1 = obj1.getDen() * (LCM / obj1.getDen());
    int num2 = obj2.getNum() * (LCM / obj2.getDen());
    int den2 = obj2.getDen() * (LCM / obj2.getDen());
    if (num1 == num2 && den1 == den2)
    {
        cout << "TRUE. BOTH FRACTIONS ARE EQUAL\n";
    }
    else
    {
        cout << "FALSE. BOTH FRACTIONS ARE NOT EQUAL\n";
    }
}
int main()
{
    char ch = 'Y';
    while (ch == 'Y')
    {

        cout << "ENTER NUMERATOR AND DENOMINATOR FOR TWO FRACTIONS\n";
        int num1, den1, num2, den2;
        while (true)
        {
            if (cin >> num1 >> den1 >> num2 >> den2)
            {
                Rational obj1(num1, den1), obj2(num2, den2);
                if (!correct)
                {
                    cout << "ILLEGAL ENTRIES THEREFORE NO OPERATION WILL BE PERFORMED\nENTER ENTRIES AGAIN\n";
                    correct = true;
                    continue;
                }
                cout << "1 -> ADD TWO FRACTIONS\n";
                cout << "2 -> SUBTRACT TWO FRACTIONS\n";
                cout << "3 -> MULTIPLY TWO FRACTIONS\n";
                cout << "4 -> DIVIDE TWO FRACTIONS\n";
                cout << "5 -> COMPARISON 1 -> >\n";
                cout << "6 -> COMPARISON 2 -> >=\n";
                cout << "7 -> COMPARISON 3 -> <\n";
                cout << "8 -> COMPARISON 4 -> <=\n";
                cout << "9 -> COMPARISON 5 -> !=\n";
                cout << "10 -> COMPARISON 6 -> ==\n";
                cout << "11 -> UNARY NEGATIVE\n";
                int input;
                cin >> input;
                switch (input)
                {
                case 1:
                {
                    Rational res(obj1 + obj2);
                    if (!correct)
                    {
                        correct = true;
                        break;
                    }
                    if (res.getNum() == 0)
                    {
                        cout << "ANSWER AFTER ADDITION IS -> " << 0 << "\n";
                    }
                    else
                    {
                        cout << "ANSWER AFTER ADDITION IS -> " << res.getNum() << "/" << res.getDen() << "\n ";
                    }
                }
                break;
                case 2:
                {
                    Rational res(obj1 - obj2);
                    if (!correct)
                    {
                        correct = true;
                        break;
                    }
                    if (res.getNum() == 0)
                    {
                        cout << "ANSWER AFTER SUBTRACTION IS -> " << 0 << "\n";
                    }
                    else
                    {
                        cout << "ANSWER AFTER SUBTRACTION IS -> " << res.getNum() << "/" << res.getDen() << "\n ";
                    }
                }
                break;
                case 3:
                {
                    Rational res(obj1 * obj2);
                    if (!correct)
                    {
                        correct = true;
                        break;
                    }
                    if (res.getNum() == 0)
                    {
                        cout << "ANSWER AFTER MULTIPLICATION IS -> " << 0 << "\n";
                    }
                    else
                    {
                        cout << "ANSWER AFTER MULTIPLICATION IS -> " << res.getNum() << "/" << res.getDen() << "\n ";
                    }
                }
                break;
                case 4:
                {
                    Rational res(obj1 / obj2);
                    if (!correct)
                    {
                        correct = true;
                        break;
                    }
                    if (res.getNum() == 0)
                    {
                        cout << "ANSWER AFTER DIVISION IS -> " << 0 << "\n";
                    }
                    else
                    {
                        cout << "ANSWER AFTER DIVISION IS -> " << res.getNum() << "/" << res.getDen() << "\n ";
                    }
                }
                break;
                case 5:
                {
                    Rational res(obj1 > obj2);
                }
                break;
                case 6:
                {
                    Rational res(obj1 >= obj2);
                }
                break;
                case 7:
                {
                    Rational res(obj1 < obj2);
                }
                break;
                case 8:
                {
                    Rational res(obj1 <= obj2);
                }
                break;
                case 9:
                {
                    Rational res(obj1 != obj2);
                }
                break;
                case 10:
                {
                    Rational res(obj1 == obj2);
                }
                break;
                case 11:
                {
                    cout << "BEFORE UPDATING 1ST RATIONAL NUMBER -> " << obj1.getNum() << "/" << obj1.getDen() << "\n";
                    cout << "BEFORE UPDATING 2ND RATIONAL NUMBER -> " << obj2.getNum() << "/" << obj2.getDen() << "\n";
                    obj1 = -obj1;
                    obj2 = -obj2;
                    cout << "UPDATED FIRST RATIONAL NUMBER -> " << obj1.getNum() << "/" << obj1.getDen() << "\n";
                    cout << "UPDATED SECOND RATIONAL NUMBER -> " << obj2.getNum() << "/" << obj2.getDen() << "\n";
                }
                break;
                default:
                    cout << "ILLEGAL INPUT\n";
                }
                break;
            }
            else
            {
                cout << "INVALID INPUT TRY AGAIN!!\n";
                cin.clear();              // to clear error flag
                while (cin.get() != '\n') // validates until enter is entered
                    ;
            }
        }
        cout << "WANT TO CONTINUE?(Y/N)\n";
        cin >> ch;
    }
}
