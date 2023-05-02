#include "Fraction.hpp" 
#include "iostream"
#include <math.h>
#include <iomanip>      // std::setprecision
using namespace std;
namespace ariel{

    Fraction ::Fraction (){
        this->numerator =0;
        this->denominator =0;
    }
    Fraction :: Fraction (int coun, int deno){
        int r = gcd(coun, deno);
        this->numerator =coun / r;
        this->denominator=deno / r;
    }
    Fraction :: Fraction (double num){
        int ten = 1;
        while (std::fmod(num,10) != 0)
        {
        num *= 10;
        ten *= 10;
        }
        int r = gcd((int)num, ten);
        this->numerator =((int)num) / r;
        this->denominator=ten / r;
    }
    Fraction :: Fraction (const Fraction& copy):numerator(copy.numerator),denominator(copy.denominator){}
    Fraction :: ~Fraction(){}

    int Fraction::gcd(int a, int b)     // gcd 
    {
        if(b ==0) return a;
        return gcd(b, a% b);
    }
    int Fraction :: getDenominator () const{
        return denominator;
    }
    int Fraction :: getNumerator () const{
        return numerator;
    }
    Fraction Fraction :: operator+(const Fraction& newfrac) const{
        int newnumber =numerator * newfrac.getDenominator() + denominator * newfrac.getNumerator();
        int ten =  denominator * newfrac.getDenominator();
        int i = 1;
        int r = 1;
        while ( i <= newnumber && i <= ten ) {
            if ( (int)newnumber % i == 0 && ten % i == 0 ) 
                r = i;
            i++;
        }        
        newnumber /= r;
        ten /= r;

        return Fraction((int) newnumber, ten);
    }
    const Fraction Fraction::operator+(const float& num) const
    {
        float newnumber = num;
        int ten = 1;
        while (std::fmod(newnumber,10) != 0)
        {
        newnumber *= 10;
        ten *= 10;
        }

        newnumber = (int) newnumber;
        int numerator2 = numerator * ten + denominator * newnumber;
        int denominator2 = denominator * ten;        
        int i = 1;
        int r = 1;
        while ( i <= numerator2 && i <= denominator2 ) {
            if ( (int)numerator2 % i == 0 && denominator2 % i == 0 ) 
                r = i;
            i++;
        }        
        numerator2 /= r;
        denominator2 /= r;

        return Fraction(numerator2, denominator2);
    }    
    Fraction operator+(const float& num, const Fraction& frac) {
        double newnumber = num;
        int ten = 1;
        while (std::fmod(newnumber,10) != 0)
        {
        newnumber *= 10;
        ten *= 10;
        }
        newnumber = (int) newnumber;
        int numerator2 = frac.getNumerator() * ten + frac.getDenominator() * newnumber;
        int denominator2 = frac.getDenominator() * ten;
        int i = 1;
        int r = 1;
        while ( i <= numerator2 && i <= denominator2 ) {
            if ( (int)numerator2 % i == 0 && denominator2 % i == 0 ) 
                r = i;
            i++;
        }        
        numerator2 /= r;
        denominator2 /= r;

        return Fraction(numerator2, denominator2);
    }
    Fraction Fraction :: operator-(const Fraction &newfrac) const{
        int newnumber =  numerator * newfrac.denominator - denominator * newfrac.numerator;
        int ten =  denominator * newfrac.denominator;
        int i = 1;
        int r = 1;
        while ( i <= newnumber && i <= ten ) {
            if ( (int)newnumber % i == 0 && ten % i == 0 ) 
                r = i;
            i++;
        }        
        newnumber /= r;
        ten /= r;

        return Fraction((int) newnumber, ten);
    }
    const Fraction Fraction::operator-(const float& num) const{
        double newnumber = num;
        int ten = 1;
        while (std::fmod(newnumber,10) != 0)
        {
        newnumber *= 10;
        ten *= 10;
        }
        newnumber = (int) newnumber;
        int numerator2 =  ten * numerator - newnumber * denominator;
        int denominator2 = ten * denominator;
        int i = 1;
        int r = 1;
        while ( i <= numerator2 && i <= denominator2 ) {
            if ( (int)numerator2 % i == 0 && denominator2 % i == 0 ) 
                r = i;
            i++;
        }        
        numerator2 /= r;
        denominator2 /= r;

        return Fraction(numerator2, denominator2);
    }  
    Fraction operator-(const float& num, const Fraction& frac) {
        double newnumber = num;
        int ten = 1;
        while (std::fmod(newnumber,10) != 0)
        {
        newnumber *= 10;
        ten *= 10;
        }
        newnumber = (int) newnumber;
        int numerator2 = newnumber * frac.getDenominator() - ten * frac.getNumerator();
        int denominator2 = ten * frac.getDenominator();
        int i = 1;
        int r = 1;
        while ( i <= numerator2 && i <= denominator2 ) {
            if ( (int)numerator2 % i == 0 && denominator2 % i == 0 ) 
                r = i;
            i++;
        }        
        numerator2 /= r;
        denominator2 /= r;

        return Fraction(numerator2, denominator2);
    }  

    Fraction Fraction :: operator*(const Fraction &newfrac) const{
        int newnumber = newfrac.getNumerator() * numerator;
        int ten = newfrac.getDenominator() * denominator;
        int i = 1;
        int r = 1;
        while ( i <= newnumber && i <= ten ) {
            if ( (int)newnumber % i == 0 && ten % i == 0 ) 
                r = i;
            i++;
        }        
        newnumber /= r;
        ten /= r;

        return Fraction((int) newnumber, ten);
    }
    const Fraction Fraction::operator*(const float& num) const{
        double newnumber = num;
        int ten = 1;
        while (std::fmod(newnumber,10) != 0)
        {
        newnumber *= 10;
        ten *= 10;
        }
        newnumber = numerator * newnumber;
        ten =denominator * ten;
        int i = 1;
        int r = 1;
        while ( i <= newnumber && i <= ten ) {
            if ( (int)newnumber % i == 0 && ten % i == 0 ) 
                r = i;
            i++;
        }        
        newnumber /= r;
        ten /= r;

        return Fraction((int) newnumber, ten);
    }

    Fraction operator*(const float& num, const Fraction& frac) {
        float newnumber = num;
        int ten = 1;
        while (std::fmod(newnumber,10) != 0)
        {
        newnumber *= 10;
        ten *= 10;
        }
        newnumber = frac.getNumerator() * newnumber;
        ten = frac.getDenominator() * ten;
        int i = 1;
        int r = 1;
        while ( i <= newnumber && i <= ten ) {
            if ( (int)newnumber % i == 0 && ten % i == 0 ) 
                r = i;
            i++;
        }        
        newnumber /= r;
        ten /= r;

        return Fraction((int) newnumber, ten);
    }
    Fraction Fraction :: operator/(const Fraction &newfrac) const{
        int newnumber = newfrac.getDenominator() * numerator;
        int ten = newfrac.getNumerator() * denominator;
        int i = 1;
        int r = 1;
        while ( i <= newnumber && i <= ten ) {
            if ( (int)newnumber % i == 0 && ten % i == 0 ) 
                r = i;
            i++;
        }        
        newnumber /= r;
        ten /= r;

        return Fraction((int) newnumber, ten);
    }
    const Fraction Fraction::operator/(const float& num) const{
        float newnumber = num;
        int ten = 1;
        while (std::fmod(newnumber,10) != 0)
        {
        newnumber *= 10;
        ten *= 10;
        }
        newnumber = denominator * newnumber;
        ten = numerator * ten;
        int i = 1;
        int r = 1;
        while ( i <= newnumber && i <= ten ) {
            if ( (int)newnumber % i == 0 && ten % i == 0 ) 
                r = i;
            i++;
        }        
        newnumber /= r;
        ten /= r;

        return Fraction((int) newnumber, ten);
    }
    Fraction operator/(const float& num, const Fraction& frac) {
        double newnumber = num;
        int ten = 1;
        while (std::fmod(newnumber,10) != 0)
        {
        newnumber *= 10;
        ten *= 10;
        }
        newnumber = frac.getDenominator() * newnumber;
        ten = frac.getNumerator() * ten;
        int i = 1;
        int r = 1;
        while ( i <= newnumber && i <= ten ) {
            if ( (int)newnumber % i == 0 && ten % i == 0 ) 
                r = i;
            i++;
        }        
        newnumber /= r;
        ten /= r;

        return Fraction((int) newnumber, ten);
    }

    Fraction& Fraction ::operator++(){
        numerator += denominator;
        int r = gcd(numerator,denominator);
        numerator = numerator / r;
        denominator = denominator / r;
        return *this;
        
    }
    Fraction Fraction::operator++(int)
    {
        Fraction fr = (*this);
        numerator += denominator;
        int r = gcd(numerator,denominator);
        numerator = numerator / r;
        denominator = denominator / r;
        return fr;
    }
    Fraction& Fraction ::operator--(){
        numerator -= denominator;
        int r = gcd(numerator,denominator);
        numerator = numerator / r;
        denominator = denominator / r;
        return *this;
        
    }
    Fraction Fraction::operator--(int)
    {
        Fraction fr = (*this);
        numerator -= denominator;
        int r = gcd(numerator,denominator);
        numerator = numerator / r;
        denominator = denominator / r;
        return fr;
    }
    bool Fraction :: operator==(const Fraction& newfrac)const{
        return numerator * newfrac.denominator == newfrac.numerator * denominator;
    }

    bool Fraction :: operator!=(const Fraction& newfrac)const{
        return numerator * newfrac.denominator != newfrac.numerator * denominator;
    }
    bool Fraction :: operator>(const Fraction& newfrac)const{
        return numerator * newfrac.denominator > newfrac.numerator * denominator;
    }

    bool Fraction::operator>=(const Fraction& newfrac) const {
        return numerator * newfrac.denominator >= newfrac.numerator * denominator;
    }
    bool Fraction :: operator<(const Fraction& newfrac)const{
        return numerator * newfrac.denominator < newfrac.numerator * denominator;
    }
    bool Fraction :: operator<=(const Fraction& newfrac)const{
        return numerator * newfrac.denominator <= newfrac.numerator * denominator;
    }


    std::ostream& operator<<(std::ostream& os, const Fraction& fraction)
    {  
        os << fraction.getNumerator()  << "/"  << fraction.getDenominator();
        return os;
    }
    std::istream& operator>>(std::istream& is, Fraction& fraction)
    {
        int num, den;
        char ch;
        is >> num >> ch >> den;
        if(ch != '/' || den == 0) throw invalid_argument("Invalid input");
        fraction = Fraction(num, den);
        return is;
    }
}