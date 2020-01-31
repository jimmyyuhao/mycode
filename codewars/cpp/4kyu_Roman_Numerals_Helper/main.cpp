#include <vector>
#include <string>
#include <string.h>
#include <igloo/igloo_alt.h>
static const size_t npos = -1;
using namespace igloo;
using namespace std;
class RomanNumerals  
{
public:
    RomanNumerals(){
        val =0 ;
        str = string("");
    };
    string to_roman(unsigned int val);
    unsigned int from_roman(string str);
    ~RomanNumerals(){};

private:
    /* data */
    unsigned int val;
    string str;
};
RomanNumerals RomanNumerals;
// | Symbol | Value | |----------------||I|1||V|5||X|10||L|50||C|100||D|500||M|1000|
vector<string> arr={"I??","XVI","CLX","MDC","??M"};

int getVal(string input, int i)
{
    string nine = string(arr[i - 1], 2, 1).append(string(arr[i - 1], 0, 1));
    string four = string(arr[i - 1], 2, 1).append(string(arr[i - 1], 1, 1));
    if (input == nine) {return 9;}
    else if (input == four) {return 4;}
    else if (npos != input.find(arr[i - 1].data()[1])) { return 5 + input.length() - 1; }
    else { return input.length(); }
}

int getFirstCharNotInArrx(string input, string tofind)
{
    size_t pos;
    unsigned int i = 0;
    for (i = 0; i < input.length(); i++) {
        pos = tofind.find(input.data()[i]);
        if (npos == pos) {
            return i;
        }
    }
    return i;
}

unsigned int RomanNumerals::from_roman(string str)
{
    unsigned int out = 0;
    size_t pos = 0;
    string tmpStr = str;

    for (unsigned int i = arr.size() ; i > 0; i--) {
        if(i!=1)
            out = out * 10;

        pos = getFirstCharNotInArrx(tmpStr, arr[i - 1]);
        if (pos == 0) {
            continue;
        }
        string substr = tmpStr.substr(0, pos);
        out += getVal(substr, i);
        tmpStr = tmpStr.substr(pos);
    }

    return out;
}

string getOne(unsigned int val, string digitStr)
{
    string out = "";
    if (val == 0) {return out; }
    else if (1 <= val && val < 4) {
        for (unsigned int i = 0 ; i < val; i++) { out += digitStr[2]; }
    } else if (val == 4) {
        out = digitStr[2];
        out += digitStr[1];
    } else if (val == 5) {
        out = digitStr[1];
    } else if (5 < val && val < 9) {
        out = digitStr[1];
        for (unsigned int j = 0 ; j < val - 5; j++) { out += digitStr[2]; }
    } else if (val == 9) {
        out = digitStr[2] ;
        out += digitStr[0];
    }

    return out;
}

string RomanNumerals::to_roman(unsigned int val)
{
    unsigned int tmpVal = val;
    unsigned int decVal = 0;
    stack<string> outvec;
    string out;
    unsigned int i = 0;
    while (tmpVal != 0) {
        string tmpStr;
        decVal = tmpVal % 10;
        tmpVal = tmpVal / 10;
        tmpStr =getOne(decVal,arr[i+1]) ;
        outvec.push(tmpStr);
        i++;
    }
    while(outvec.size()){
        out +=outvec.top();
        outvec.pop();
    }

    return out;
}
// TODO: Replace examples and use TDD development by writing your own tests

Describe(any_group_name_you_want)
{
    It(should_do_something)
    {
        Assert::That(RomanNumerals.to_roman(4), Equals("IV"));
        Assert::That(RomanNumerals.to_roman(2), Equals("II"));
        Assert::That(RomanNumerals.to_roman(5), Equals("V"));
        Assert::That(RomanNumerals.to_roman(9), Equals("IX"));
        Assert::That(RomanNumerals.to_roman(19), Equals("XIX"));
        Assert::That(RomanNumerals.to_roman(1900), Equals("MCM"));
        Assert::That(RomanNumerals.to_roman(2008), Equals("MMVIII"));
        Assert::That(RomanNumerals.to_roman(1100), Equals("MC"));
        Assert::That(RomanNumerals.from_roman("MM"), Equals(2000));
        Assert::That(RomanNumerals.from_roman("MMCM"), Equals(2900));
        Assert::That(RomanNumerals.from_roman("MMXVIII"), Equals(2018));
        Assert::That(RomanNumerals.from_roman("M"), Equals(1000));
    }
};

int main(int argc,  char *argv[])
{
      return TestRunner::RunAllTests(argc, argv);

}
