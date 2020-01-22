#include <vector>
#include <string>
#include <igloo/igloo_alt.h>
static const size_t npos = -1;
using namespace igloo;
using namespace std;
unsigned long long gcd(unsigned long long m,unsigned long long n)//求最大公约数 
{
    unsigned long long r,t;
    if(m<n) { t=m; m=n; n=t; }
    while(n!=0) { r=m%n; m=n; n=r; }
    return m;
}

unsigned long long lcm(unsigned long long m,unsigned long long n)
{
    unsigned long long t, r;
    r = gcd(m,n);
    t=m*n/r;
    return t;
}

class Fracts
{
public:
    static string convertFrac(vector<vector<unsigned long long>> &lst);
};

void formatInputVector(vector<unsigned long long>&firstVal ,vector<unsigned long long >&secondVal ,vector<vector<unsigned long long>> lst)
{
    for(auto iter = lst.begin(); iter != lst.end(); iter++) {
        firstVal.push_back((*iter)[0]);
        secondVal.push_back((*iter)[1]);
    }
}

void getTotalGcd(unsigned long long &lcmout,vector<unsigned long long >secondVal )
{
    lcmout = secondVal[0];
    for(auto iter = secondVal.begin(); iter != secondVal.end()-1; iter++) {
       lcmout = lcm(lcmout,*(iter+1)); 
    }
}

void transData(vector<unsigned long long>&firstVal, vector<unsigned long long >&secondVal, unsigned long long lcm)
{
    unsigned long i = 0;
    for (auto iter = firstVal.begin(); iter != firstVal.end(); iter++) {
        auto mul = lcm/secondVal[i];
        *iter = *iter * mul;
        secondVal[i] = lcm;
        i++;
    }
}

void transOutput(vector<unsigned long long>&firstVal, vector<unsigned long long >&secondVal, string & output)
{
    unsigned long i = 0;
    for (unsigned long n = 0; n < firstVal.size(); n++) {
        output+=string("(")+to_string(firstVal[n])+string(",")+to_string(secondVal[n])+string(")");
        i++;
    }
}

string Fracts::convertFrac(vector<vector<unsigned long long>> &lst)
{
    string output;
    vector<unsigned long long>firstVal, secondVal;
    unsigned long long lcmout=0;
    
    formatInputVector(firstVal,secondVal,lst);
    getTotalGcd(lcmout,secondVal);
    transData(firstVal,secondVal,lcmout);
    transOutput(firstVal,secondVal,output);
    return output;
}
void testequal(string ans, string sol) {
    Assert::That(ans, Equals(sol));
}
Describe(convertFract_Tests)
{
    It(test1)
    {
        vector<vector<unsigned long long>> r1 = { {1, 2}, {1, 3}, {1, 4} };
        string ans1 = Fracts::convertFrac(r1);
        string sol1 = "(6,12)(4,12)(3,12)";
        testequal(ans1, sol1);
    }
};
int main(int argc,  char *argv[])
{
      return TestRunner::RunAllTests(argc, argv);

}
