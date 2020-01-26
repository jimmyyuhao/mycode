#include <vector>
#include <string>
#include <string.h>
#include <igloo/igloo_alt.h>
static const size_t npos = -1;
using namespace igloo;
using namespace std;
std::string uint32_to_ip(uint32_t ip)
{
    return to_string(ip>>24)+"."
            +to_string((ip&0x00ff0000)>>16)+"."
            +to_string((ip&0x0000ff00)>>8)+"."
            +to_string((ip&0x000000ff));
}

Describe(test_cases)
{
    It(sample_tests)
    {
        Assert::That(uint32_to_ip(2154959208), Equals("128.114.17.104"));
        Assert::That(uint32_to_ip(0), Equals("0.0.0.0"));
        Assert::That(uint32_to_ip(2149583361), Equals("128.32.10.1"));
    }
};

int main(int argc,  char *argv[])
{
      return TestRunner::RunAllTests(argc, argv);

}
