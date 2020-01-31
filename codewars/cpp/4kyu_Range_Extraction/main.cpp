#include <vector>
#include <string>
#include <string.h>
#include <igloo/igloo_alt.h>
static const size_t npos = -1;
using namespace igloo;
using namespace std;
#include <string>
#include <vector>
std::string range_extraction(std::vector<int> args)
{
    string out;
    vector<int> startVec;
    vector<int> endVec;

    for (auto iter = args.begin(); iter != args.end(); iter++) {
        if (iter != args.begin()) {
            if (*iter != *(iter - 1) + 1) {
                endVec.push_back(*(iter-1));

                if (iter != args.end()-1) {
                    startVec.push_back(*iter);
                }
                else{
                    startVec.push_back(*iter);
                    endVec.push_back(*iter);

                }
            }
            else{
                if(iter==args.end()-1) {
                    endVec.push_back(*iter);
                }
            }
        } else {
            startVec.push_back(*iter);
        }
    }

    for (unsigned int index = 0; index < startVec.size(); index++) {
        if (startVec[index] == endVec[index]) {
            out= out+to_string(startVec[index]);
        } 
        else if(endVec[index] - startVec[index]==1) {
            out= out+to_string(startVec[index])+string(",")+to_string(endVec[index]);
        }
        else{
            out = out+to_string(startVec[index])+"-"+to_string(endVec[index]);
        }
        if(index!=startVec.size()-1)
            out +=string(",");
    }

    return out;
}

Describe(Sample_Tests)
{
    It(Tests)
    {
        Assert::That(range_extraction({-6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20}), Equals("-6,-3-1,3-5,7-11,14,15,17-20"));
        Assert::That(range_extraction({-3,-2,-1,2,10,15,16,18,19,20}), Equals("-3--1,2,10,15,16,18-20"));
    }
};
int main(int argc,  char *argv[])
{
      return TestRunner::RunAllTests(argc, argv);

}
