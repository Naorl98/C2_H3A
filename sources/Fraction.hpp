#include "math.h"
#include <fstream>
#include <sstream>


using namespace std;
namespace ariel{

    class Fraction
    {
        private:
        int numerator ;
        int denominator;
        
        public:
            Fraction();
            Fraction(int , int);
            Fraction(const Fraction& other);
            Fraction(double);
            ~Fraction();

            int getNumerator() const;
            int getDenominator() const;
            int gcd(int a, int b);
            Fraction operator+(const Fraction& other) const;
            Fraction operator-(const Fraction& other) const;
            Fraction operator*(const Fraction& other) const;
            Fraction operator/(const Fraction& other) const;
            bool operator==(const Fraction& other) const;
            bool operator!=(const Fraction& other) const;
            bool operator>(const Fraction& ) const ;
            bool operator>=(const Fraction& other) const;
            bool operator<(const Fraction& ) const;           
            bool operator<=(const Fraction& ) const;


            Fraction& operator++();
            Fraction operator++(int);
            Fraction& operator--();
            Fraction operator--(int);
            
            // Type conversions
            explicit operator double() const;

            friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
            const Fraction operator*(const float& num) const;    
            friend Fraction operator*(const float& num, const Fraction& fraction);
            const Fraction operator+(const float& num) const;    
            friend Fraction operator+(const float& num, const Fraction& fraction);
            const Fraction operator-(const float& num) const;    
            friend Fraction operator-(const float& num, const Fraction& fraction);
            const Fraction operator/(const float& num) const;    
            friend Fraction operator/(const float& num, const Fraction& fraction);
            friend std::istream& operator>>(std::istream& is, Fraction& fraction);        
    };
     
}