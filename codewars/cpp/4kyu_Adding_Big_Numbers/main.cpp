#include <vector>
#include <string>
#include <string.h>
#include <igloo/igloo_alt.h>
static const size_t npos = -1;
using namespace igloo;
using namespace std;
#include <string>

std::string add(std::string a, std::string b)
{

    string ra = a;
    string rb = b;
    string rc = "0";
    string rd = "0";

    reverse(ra.begin(), ra.end());
    reverse(rb.begin(), rb.end());
    unsigned int size = max(ra.length(), rb.length());
    unsigned char* rcmem = new unsigned char[size + 1];
    memset(rcmem, 0, size + 1);
    unsigned int  i = 0 ;

    for (i = 0; i < size; i++) {
        unsigned char j = i >= ra.length() ? 0 : ra.data()[i] - 48;
        unsigned char k = i >= rb.length() ? 0 : rb.data()[i] - 48;

        unsigned char a = rcmem[i];
        unsigned char l = (j + k + a) / 10;
        unsigned char m = (j + k + a) % 10;

        if (l) {rcmem[i + 1] = 1;}
        else {rcmem[i + 1] = 0;}

        rcmem[i] = m + 48;
    }

    if (rcmem[i]) {
        rcmem[i] += 48;
        rc = string((char*)rcmem, size + 1);
    } else
    { rc = string((char*)rcmem, size); }

    reverse(rc.begin(), rc.end());

    if (rc.find_first_of("0") == 0 && rc.length() != 1) {
        unsigned int position = rc.find_first_not_of("0");
        rd = rc.substr(position);
    } else { rd = rc; }

    delete rcmem;
    return rd;
}

Describe(Sample_Tests)
{
    It(Tests) {
        Assert::That(add("0124", "456"), Equals("580"));
        Assert::That(add("099", "22"), Equals("121"));
        Assert::That(add("0", "0"), Equals("0"));
        Assert::That(add("61146661397420037885","796463472358663451700745948759420386623870957404794968465552416665259657844584154572610"), Equals("796463472358663451700745948759420386623870957404794968465552416665320804505981574610495"));
    }
};

int main(int argc,  char *argv[])
{
      return TestRunner::RunAllTests(argc, argv);

}
