#include <vector>
#include <string>
#include <igloo/igloo_alt.h>
static const size_t npos = -1;
using namespace igloo;
using namespace std;
#include <string>
#include <vector>

template <typename T> std::vector<T> uniqueInOrder(const std::vector<T>& iterable){
    std::vector<T> tempV;
    if(iterable.size()==0) return tempV;
    tempV.push_back(*iterable.begin());
    for(auto iter = iterable.begin()+1; iter != iterable.end(); iter++) {
        if(*(tempV.end()-1)==*iter)continue;
        tempV.push_back(*iter);
    }
    return tempV;
}
std::vector<char> uniqueInOrder(const std::string& iterable){
    std::vector<char> tempV;
    if(iterable.size()==0) return tempV;
    tempV.push_back(*iterable.begin());
    for(auto iter = iterable.begin()+1; iter != iterable.end(); iter++) {
        if(*(tempV.end()-1)==*iter)continue;
        tempV.push_back(*iter);
    }
    return tempV;
}

using VI = std::vector<int>;
using VC = std::vector<char>;

Describe(UniqueInOrder){
  It(BasicTests){
    Assert::That(uniqueInOrder(""), Equals(VC{}));
    Assert::That(uniqueInOrder("AA"), Equals(VC{'A'}));
    Assert::That(uniqueInOrder("A"), Equals(VC{'A'}));
    Assert::That(uniqueInOrder("AAAABBBCCDAABBB"), Equals(VC{'A', 'B', 'C', 'D', 'A', 'B'}));
    Assert::That(uniqueInOrder("AADD"), Equals(VC{'A', 'D'}));
    Assert::That(uniqueInOrder("AAD"), Equals(VC{'A', 'D'}));
    Assert::That(uniqueInOrder("ADD"), Equals(VC{'A', 'D'}));
    Assert::That(uniqueInOrder("ABBCcAD"), Equals(VC{'A', 'B', 'C', 'c', 'A', 'D'}));
    Assert::That(uniqueInOrder(VI{1,2,3,3}), Equals(VI{1,2,3}));
    Assert::That(uniqueInOrder(VC{'a','b','b'}), Equals(VC{'a','b'}));
  }
};

int main(int argc,  char *argv[])
{
      return TestRunner::RunAllTests(argc, argv);

}
