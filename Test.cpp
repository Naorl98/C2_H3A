
#include "doctest.h"
#include "sources/Fraction.hpp"
#include <sstream>

using namespace std;
using namespace ariel;

TEST_CASE("Test constructor")
{
    CHECK_NOTHROW(Fraction());
    CHECK_NOTHROW(Fraction(0, 7));
    CHECK_NOTHROW(Fraction(3.2));
    CHECK_NOTHROW(Fraction(45, 89));
}

TEST_CASE("Test two int")
{
    Fraction a(2,5);
    Fraction b(6,9);
    CHECK(a + b == Fraction(16,15));
    CHECK(b - a == Fraction(4, 15));
    CHECK(a * b == Fraction(4, 15));
    CHECK(a / b == Fraction(9, 15));

}

TEST_CASE("Test stream")
{
    Fraction f;
    std::stringstream stre("1/4");
    stre >> f;
    CHECK(f == Fraction(2,8));

    Fraction b;
    std::stringstream ss1("1/3");
    ss1 >> b;
    CHECK(b == Fraction(3,9));

}

TEST_CASE("Test float")
{
    Fraction f(2,5);
    CHECK_NOTHROW(f + 2.5);
    CHECK_NOTHROW(f - 2.5);
    CHECK_NOTHROW(f * 2.5);
    CHECK_NOTHROW(f / 2.5);
}

TEST_CASE("Test inc ")
{
    Fraction f(1,2);
    Fraction preInc = ++f;
    CHECK(preInc == Fraction(3,2));
    CHECK(f == Fraction(3,2));

    Fraction postInc = f++;
    CHECK(postInc == Fraction(3,2));
    CHECK(f == Fraction(5,2));

    Fraction preDec = --f;
    CHECK(preDec == Fraction(3,2));
    CHECK(f == Fraction(3,2));

    Fraction postDec = f--;
    CHECK(postDec == Fraction(3,2));
    CHECK(f == Fraction(1,2));
}

TEST_CASE("Test bool ")
{
    Fraction a(11,22);
    Fraction b(2.5);
    Fraction c(6,15);
    CHECK(a != c);
    CHECK(a < b);
    CHECK(a <= b);
    CHECK_FALSE(a > b);
    CHECK_FALSE(a >= b);

}


TEST_CASE("Test out stream")
{
    Fraction f(3,9);
    std::stringstream ss;
    ss << f;
    CHECK(ss.str() == "1/3");

    Fraction h(16,32);
    std::stringstream ss1;
    ss1 << h;
    CHECK(ss1.str() == "1/2");

    Fraction r(0.25);
    std::stringstream ss2;
    ss2 << r;
    CHECK(ss2.str() == "1/4");


}
