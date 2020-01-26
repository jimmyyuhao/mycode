#include <vector>
#include <string>
#include <string.h>
#include <igloo/igloo_alt.h>
static const size_t npos = -1;
using namespace igloo;
using namespace std;

string rot13(string msg)
{
    char * chararray = (char*)malloc(msg.length());
    for (unsigned int i = 0; i < msg.length(); i++) {
        char chr = msg.data()[i] ;
        if ('A' <= chr && chr<= 'Z') {
            chararray[i] = ((char(chr) - char('A')) + 13) % 26 + char('A');
        } else if ('a' <= chr && chr<= 'z') {
            chararray[i] = ((char(chr) - char('a')) + 13) % 26 + char('a');
        } else {
            chararray[i] = chr;
        }
    }
    return string(chararray, msg.length());
}

Describe(Rot13)
{
    It(sample_tests)
    {
        Assert::That(rot13("test"), Equals("grfg"));
        Assert::That(rot13("Test"), Equals("Grfg"));
        Assert::That(rot13("AbCd"), Equals("NoPq"));
    }
};

int main(int argc,  char *argv[])
{
      return TestRunner::RunAllTests(argc, argv);

}
