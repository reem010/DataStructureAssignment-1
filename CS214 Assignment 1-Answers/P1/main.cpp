#include <iostream>
#include <string>
using namespace std;

class BigDecimalInt
{
public:



    string num;
    int sum, carry;

    BigDecimalInt(string decstr);
    BigDecimalInt(int decint);
    BigDecimalInt();

    BigDecimalInt operator+(BigDecimalInt b);
    BigDecimalInt operator-(BigDecimalInt b);

    friend ostream& operator<< (ostream& output, BigDecimalInt a);
    friend bool checkvalid(BigDecimalInt& b);
    friend bool checksign(BigDecimalInt& b);
    friend bool checkequality(string a, string b);
    friend bool checkbigger(string a, string b);
    friend void removeleftzeros(string& a);

    int size();

};


//making a function to reverse string
void reverseStr(string& str)
{
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}



//making the constructors of the class

BigDecimalInt::BigDecimalInt()
{
    num = "";
}


BigDecimalInt::BigDecimalInt(string decstr)
{
    num = decstr;
}

BigDecimalInt::BigDecimalInt(int decint)
{
    if (decint < 0)
    {
        decint *= -1;

        while (decint != 0)
        {

            num += (decint % 10) + '0';
            decint -= decint % 10;
            decint /= 10;

        }
        num += '-';
    }



    else   if (decint == 0)
    {
        //cout<<"i'm here\n";
        num = "0";
    }


    else if (decint > 0) {
        while (decint != 0)
        {

            num += (decint % 10) + '0';
            decint -= decint % 10;
            decint /= 10;

        }
    }
    reverseStr(num);

}


// function for printing the class

ostream& operator<< (ostream& output, BigDecimalInt a)
{
    cout << a.num;
    return output;
}


//function to delete left zeros

void removeleftzeros(string& a)
{
    if (a[0] == '0')
    {
        int i = 0;
        while (a[i] == '0')
            i++;

        if (i == (a.length()))
            a.erase(0, i - 1);
        else
            a.erase(0, i);
    }

    else if (a[0] == '-' && a[1] == '0')
    {
        int i = 0;
        while (a[i + 1] == '0')
            i++;
        if (i == a.length())
            a.erase(1, i - 1);
        else
            a.erase(1, i);
    }
}

//function to check valid of the num

bool checkvalid(BigDecimalInt& b)
{
    if (b.num[0] != '+' && b.num[0] != '-' && b.num[0] > '9' && b.num[0] < '0')
    {
        return 0;
    }
    for (int i = 1; i < b.num.length(); i++)
    {
        if (b.num[i] > '9' && b.num[i] < '0')
        {
            return 0;
        }
    }
    return 1;
}

//function to check sign of class
bool checksign(BigDecimalInt& b)
{
    string c = "";
    switch (b.num[0])
    {
    case '-':
        for (int i = 1; i < b.num.length(); i++)
        {
            c += b.num[i];
        }
        b.num = c;
        return 1;
        break;
    case '+':
        for (int i = 1; i < b.num.length(); i++)
        {
            c += b.num[i];
        }
        b.num = c;
        return 0;
        break;

    default: return 0;
        break;
    }

}

//check which class is bigger

bool biggerthan(string a, string b)
{
    if (a.length() == b.length())
    {
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] > b[i])
            {

                return 1;
            }
            else if (b[i] > a[i])
            {

                return 0;
            }
        }

    }

}


bool checkequality(string num1, string num2)
{

    for (int i = 0; i < num1.length(); i++)
    {
        if (num1[i] == num2[i])
        {
            continue;
        }
        else
            return 0;

    }

    return 1;
}


BigDecimalInt BigDecimalInt::operator+(BigDecimalInt b)
{

    if (num[0] == '-' && (b.num[0] == '+' || (b.num[0] <= '9' && b.num[0] >= '0')))


    {
        checksign(*this);
        return b - *this;
    }

    if ((num[0] == '+' || (num[0] <= '9' && num[0] >= '0')) && b.num[0] == '-')
    {
        checksign(b);
        return *this - b;
    }


    if (b.num.length() > num.length())
    {

        bool checker = (checksign(b) && checksign(*this));

        int diff = b.num.length() - num.length();

        BigDecimalInt c;
        c.num = "";
        c.carry = 0;

        for (int i = (num.length() - 1); i >= 0; i--)
        {

            c.sum = 0;
            c.sum = num[i] + b.num[i + diff] - 2 * '0' + c.carry;
            c.carry = 0;
            if (c.sum > 9)
            {
                c.sum -= 10;
                c.carry++;
            }
            c.num += c.sum + '0';

        }
        for (int i = diff - 1; i >= 0; i--)
        {
            c.sum = 0;
            c.sum += b.num[i] + c.carry - '0';
            c.carry = 0;
            if (c.sum > 9)
            {
                c.sum -= 10;
                c.carry++;

            }

            c.num += c.sum + '0';
        }
        if (c.carry > 0)
        {
            c.num += c.carry + '0';
        }

        if (checker)
        {
            c.num += '-';
        }
        reverseStr(c.num);
        return c;

    }


    else if (num.length() > b.num.length())
    {

        bool checker = checksign(b) && checksign(*this);
        int diff = num.length() - b.num.length();
        BigDecimalInt c;
        c.num = "";
        c.carry = 0;

        for (int i = (b.num.length() - 1); i >= 0; i--)
        {
            c.sum = 0;
            c.sum = num[i + diff] + b.num[i] - 2 * '0' + c.carry;
            c.carry = 0;
            if (c.sum > 9)
            {
                c.sum -= 10;
                c.carry++;
            }
            c.num += c.sum + '0';

        }
        for (int i = diff - 1; i >= 0; i--)
        {
            c.sum = 0;
            c.sum += num[i] + c.carry - '0';
            c.carry = 0;
            if (c.sum > 9)
            {
                c.sum -= 10;
                c.carry++;

            }
            c.num += c.sum + '0';

        }

        if (c.carry > 0)
        {
            c.num += c.carry + '0';
        }

        if (checker)
        {
            c.num += '-';
        }
        reverseStr(c.num);
        return c;
    }


    else
    {

        bool checker = checksign(b) && checksign(*this);

        BigDecimalInt c;
        c.num = "";
        c.carry = 0;

        for (int i = (num.length() - 1); i >= 0; i--)
        {

            c.sum = 0;
            c.sum = num[i] + b.num[i] - 2 * '0' + c.carry;
            c.carry = 0;
            if (c.sum > 9)
            {
                c.sum -= 10;
                c.carry++;
            }
            c.num += c.sum + '0';

        }

        if (c.carry > 0)
        {
            c.num += c.carry + '0';
        }

        if (checker)
        {
            c.num += '-';
        }


        reverseStr(c.num);
        return c;

    }
}



BigDecimalInt BigDecimalInt::operator-(BigDecimalInt b)
{
    if (b.num[0] == '-' && (num[0] == '+' || (num[0] <= '9' && num[0] >= '0')))
    {
        checksign(b);
        return *this + b;
    }


    else if (num[0] == '-' && (b.num[0] == '+' || (b.num[0] <= '9' && b.num[0] >= '0')))
    {

        checksign(*this);
        return *this + b;

    }

    else if (b.num[0] == '-' && num[0] == '-')
    {
        checksign(b);
        checksign(*this);
        return b - *this;
    }


    if (num.length() > b.num.length())
    {

        int diff = num.length() - b.num.length();
        BigDecimalInt c;
        c.num = "";
        c.carry = 0;
        for (int i = (b.num.length() - 1); i >= 0; i--)
        {


            c.sum = 0;
            c.sum = num[i + diff] - b.num[i] + c.carry;
            c.carry = 0;
            if (c.sum < 0)
            {
                c.sum += 10;
                c.carry--;
            }
            c.num += c.sum + '0';


        }

        for (int i = diff - 1; i >= 0; i--)
        {
            c.sum = 0;
            c.sum += num[i] + c.carry - '0';
            c.carry = 0;
            if (c.sum < 0)
            {
                c.sum += 10;
                c.carry--;
            }

            c.num += c.sum + '0';
        }

        reverseStr(c.num);

        removeleftzeros(c.num);
        return c;




    }




    if (b.num.length() > num.length())
    {

        int diff = b.num.length() - num.length();
        BigDecimalInt c;
        c.num = "";
        c.carry = 0;
        for (int i = (num.length() - 1); i >= 0; i--)
        {


            c.sum = 0;
            c.sum = b.num[i + diff] - num[i] + c.carry;
            c.carry = 0;
            if (c.sum < 0)
            {
                c.sum += 10;
                c.carry--;
            }
            c.num += c.sum + '0';


        }

        for (int i = diff - 1; i >= 0; i--)
        {
            c.sum = 0;
            c.sum += b.num[i] + c.carry - '0';
            c.carry = 0;
            if (c.sum < 0)
            {
                c.sum += 10;
                c.carry--;
            }
            c.num += c.sum + '0';
        }

        c.num += '-';

        reverseStr(c.num);
        removeleftzeros(c.num);

        return c;




    }

    if (num.length() == b.num.length())
    {
        if (checkequality(num, b.num))
        {
            BigDecimalInt c;
            c.num = "0";
            return c;
        }

        if (biggerthan(num, b.num))
        {



            BigDecimalInt c;
            c.num = "";
            c.carry = 0;
            for (int i = (num.length() - 1); i >= 0; i--)
            {


                c.sum = 0;
                c.sum = num[i] - b.num[i] + c.carry;
                c.carry = 0;
                if (c.sum < 0)
                {
                    c.sum += 10;
                    c.carry--;
                }
                c.num += c.sum + '0';


            }


            reverseStr(c.num);

            removeleftzeros(c.num);
            return c;
        }

        else if (biggerthan(b.num, num))
        {

            BigDecimalInt c;
            c.num = "";
            c.carry = 0;
            for (int i = (b.num.length() - 1); i >= 0; i--)
            {
                c.sum = 0;
                c.sum = b.num[i] - num[i] + c.carry;
                c.carry = 0;
                if (c.sum < 0)
                {
                    c.sum += 10;
                    c.carry--;
                }
                c.num += c.sum + '0';
            }
            c.num += '-';
            reverseStr(c.num);
            removeleftzeros(c.num);

            return c;
        }
    }
}

int BigDecimalInt::size()
{
    return num.length();
}


int main()
{
    cout<<"Test #1"<<endl;
    BigDecimalInt num1(3333);
    BigDecimalInt num2(-3333);
    cout <<"num1 = " << num1 << endl;
    cout <<"num2 = " << num2 << endl;
    cout << "num1 + num2 = " << num1 + num2 << endl; cout<<endl;



    cout<<"Test #2"<<endl;
    BigDecimalInt num3("20574838108473");
    BigDecimalInt num4("111111493949");
    cout <<"num1 = " << num3 << endl;
    cout <<"num2 = " << num4 << endl;
    cout << "num1 + num2 = " << num3 + num4 << endl; cout<<endl;

    cout<<"Test #3"<<endl;
    BigDecimalInt num5("1000000");
    BigDecimalInt num6("999999");
    cout <<"num1 = " << num5 << endl;
    cout <<"num2 = " << num6 << endl;
    cout << "num1 + num2 = " << num5 + num6 << endl; cout<<endl;

    cout<<"Test #4"<<endl;
    BigDecimalInt num7("1043785285");
    BigDecimalInt num8("-25945928943");
    cout <<"num1 = " << num7 << endl;
    cout <<"num2 = " << num8 << endl;
    cout << "num1 + num2 = " << num7 + num8 << endl; cout<<endl;

    cout<<"Test #5"<<endl;
    BigDecimalInt num9("2594");
    BigDecimalInt num10("-55");
    cout <<"num1 = " << num9 << endl;
    cout <<"num2 = " << num10 << endl;
    cout << "num1 + num2 = " << num9 + num10 << endl; cout<<endl;

}