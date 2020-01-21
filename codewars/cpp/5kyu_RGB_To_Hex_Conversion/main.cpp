#include <math.h>
#include <iostream>  //printf
// #include <algorithm>
#include <vector>
#include <string>
#include <igloo/igloo_alt.h>
#include<iomanip>
using namespace igloo;
using namespace std;
class RGBToHex
{
    public:
        static std::string rgb(int r, int g, int b);

};

void roundValue(int &i)
{
    if (i < 0) { i = 0; }
    if (i > 255) { i = 255; }
}

void roundAllValue(int &r, int & g,int &b)
{
    roundValue(r);
    roundValue(g);
    roundValue(b);
}

string RGBToHex::rgb(int r, int g, int b)
{
    string output="";
    roundAllValue(r,g,b);
    std::ostringstream rstring;
    rstring << resetiosflags(ios::basefield)<<setiosflags(ios::hex|ios::uppercase)<<setw(2)<<std::setfill('0');
    rstring<<r;
    std::ostringstream gstring;
    gstring << resetiosflags(ios::basefield)<<setiosflags(ios::hex|ios::uppercase)<<setw(2)<<std::setfill('0');
    gstring<<g;
    std::ostringstream bstring;
    bstring << resetiosflags(ios::basefield)<<setiosflags(ios::hex|ios::uppercase)<<setw(2)<<std::setfill('0');
    bstring<<b;
    output = rstring.str()+gstring.str()+bstring.str();
    return output;
}

// TODO: Replace examples and use TDD development by writing your own tests
//
Describe(ExampleTests)
{
    It(BasicTests) {
        Assert::That(RGBToHex::rgb(0, 0, 0), Equals("000000"));
        Assert::That(RGBToHex::rgb(1, 2, 3), Equals("010203"));
        Assert::That(RGBToHex::rgb(255, 255, 255), Equals("FFFFFF"));
        Assert::That(RGBToHex::rgb(254, 253, 252), Equals("FEFDFC"));
        Assert::That(RGBToHex::rgb(-20, 275, 125), Equals("00FF7D"));
    }
};
int main(int argc,  char *argv[])
{
      return TestRunner::RunAllTests(argc, argv);

}
