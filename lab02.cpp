#include <iostream>

using namespace std;
class Rational
{
    int numerator;
    int denominator;
public:
    Rational(int n=0,int d=1)
    {
        numerator=n;
        denominator=d;
    }
    void set(int n,int den)
    {
        numerator=n;
        denominator=den;
    }
    int num()
    {
        return numerator;
    }
    int den()
    {
        return denominator;
    }
    void set_num(int n)
    {
        numerator=n;
    }
    void set_den(int d)
    {
        denominator=d;
    }
    Rational operator+(Rational &b)
    {
        int anum=numerator,aden=denominator,bden=b.den(),bnum=b.num(),nnum,nden;
        if(aden!=bden)
        {
            bnum*=aden;
            anum*=bden;
            nden=aden*bden;
        }
        else
            nden=aden;

        nnum=anum+bnum;
        if(nnum%nden==0)
        {
            nnum/=nden;
            nden=1;
        }
        if(nden%nnum==0)
        {
            nden/=nnum;
            nnum=1;
        }
        Rational n(nnum,nden);
        return n;
    }
    Rational operator-(Rational &b)
    {
        int anum=numerator,aden=denominator,bden=b.den(),bnum=b.num(),nnum,nden;
        if(aden!=bden)
        {
            bnum*=aden;
            anum*=bden;
            nden=aden*bden;
        }
        else
            nden=aden;

        nnum=anum-bnum;
        if(nnum%nden==0)
        {
            nnum/=nden;
            nden=1;
        }
        if(nden%nnum==0)
        {
            nden/=nnum;
            nnum=1;
        }
        Rational n(nnum,nden);
        return n;
    }
    void print()
    {
        if(numerator==0)
            cout<<0;
        else if(denominator==1)
            cout<<numerator;
        else
            cout<<numerator<<"/"<<denominator;

    }
   friend ostream& operator<<(ostream &str, Rational &rhs){
        if (rhs.denominator == 1 or rhs.numerator==0) {
            str << rhs.numerator;
        }
        else {
            str << rhs.numerator << "/" << rhs.denominator;
        }
        return str;
    }

};

int main()
{
    Rational quarter(1, 4);
    Rational one_third(1, 3);

    Rational add_result, sub_result;
    add_result = one_third+quarter;
    sub_result = one_third-quarter;

    std::cout<<one_third << " + "<< quarter<< " = "<< add_result << std::endl;
    std::cout<<one_third << " - "<< quarter<< " = "<< sub_result << std::endl;

}
