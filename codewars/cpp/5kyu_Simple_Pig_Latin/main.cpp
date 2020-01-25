#include <vector>
#include <string>
#include <string.h>
#include <igloo/igloo_alt.h>
static const size_t npos = -1;
using namespace igloo;
using namespace std;
using namespace std;
bool notInAlphabTable(string in)
{
    if (in.length() == 1 && (in < string("A") || (in > string("Z") && in < string("a")) || in > string("z")))
    { return true;  }

    return false;
}

std::string pig_it(std::string str)
{
    string word, output = string("");
    size_t startpos = 0;
    size_t pos = 0;
    bool wordEndFlag = false;
    bool wordStartFlag = false;
    while (pos <= str.length()) {
        if (str.data()[pos] == ' ' && wordStartFlag == false && wordEndFlag == false) {
            output.append(string(" "));

        }

        if (str.data()[pos] != ' ' && wordStartFlag == false) {
            startpos = pos;
            wordStartFlag = true;
            wordEndFlag = false;
        }

        if ((str.data()[pos] == ' ' && wordStartFlag == true && wordEndFlag == false)) {
            word = str.substr(startpos, pos - startpos);
            string temp;
            if (!notInAlphabTable(word))
            { temp = word.substr(1) + (word.data()[0]) + string("ay"); }
            else
            {temp = word;}

            output += temp;
            wordStartFlag = false;
            wordEndFlag = true;

        }

        if (pos == (str.length()) && wordStartFlag == true) {
            word = str.substr(startpos, pos - startpos);
            string temp;
            if (word.length() == 0)
            { break; }
            if (!notInAlphabTable(word))
            { temp = word.substr(1) + (word.data()[0]) + string("ay"); }
            else
            {temp = word;}
            output.append(temp);
            wordEndFlag = true;
        }
        if (str.data()[pos] == ' ' && wordEndFlag == true && wordStartFlag == false) {
            output += ' ';
        }
        pos++;
    }
    return output;
}
Describe(Tests)
{
    It(fixed_tests)
    {
        Assert::That(pig_it("This  is my string"), Equals("hisTay  siay ymay tringsay"));
        Assert::That(pig_it("Pig latin i cool !"), Equals("igPay atinlay iay oolcay !"));
        Assert::That(pig_it("Acta est fabula"), Equals("ctaAay steay abulafay"));
        Assert::That(pig_it(" gTs  AhUKts eOKRq YITLCQ ! "), Equals(" Tsgay  hUKtsAay OKRqeay ITLCQYay ! "));

    }
};

int main(int argc,  char *argv[])
{
    return TestRunner::RunAllTests(argc, argv);
}
