#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <igloo/igloo_alt.h>
static const size_t npos = -1;
using namespace igloo;
using namespace std;
#include <list>
#include <iostream>
void print(list<int> array)
{
    cout<<"input[";
    for(auto iter=array.begin(); iter!=array.end();iter++){
        cout<<*iter<<",";
    }
    cout<<"]"<<endl;

}
using namespace std;
int getLastNum(int a, int b)
{
    int d = a;
    unsigned int b1 =b<4?b:b%4+4;
    d =pow(a,b1); 
    // for (auto i = 0 ; i < b - 1; i++) {
        // // d = d * a % 10;
        // d = d * a ;
    // }

    cout <<  a << "^" << b1 << "=" << d << endl;
    return d;
}
int last_digit(list<int> array) {
    print(array);
    if(array.size()==0) return 1;
    if(array.front()==1) return 1;
    if(array.front()==0 && array.size()==2) return 1;
    if(array.front()==0 && array.size()>2) return 0;
    vector<int> vec;
        cout<<"vec=";
    for(list<int>::reverse_iterator iter=array.rbegin(); iter!=array.rend();iter++){ 
        vec.push_back(*iter);
        cout<<*iter<<",";
    }
    cout<<endl;
    
    int d = vec[0];
    
    for(auto iter=vec.begin(); iter!=vec.end();iter++){
        if(iter!=vec.begin())
            d = getLastNum(*iter,d);
    }

    cout<<d%10<<endl; 
    return d%10;
}

#include <math.h>
Describe(Last_digit_of_a_huge_number) {
    It(Sample_test) {
        Assert::That(last_digit({}),         Equals(1));
        Assert::That(last_digit({0,0}),      Equals(1));
        Assert::That(last_digit({0,0,0}),    Equals(0));
        Assert::That(last_digit({1,2}),      Equals(1));
        Assert::That(last_digit({17,2}),     Equals(9));
        Assert::That(last_digit({13,2,2}),   Equals(1));
        Assert::That(last_digit({3,4,1}),    Equals(1));
        Assert::That(last_digit({4,3,1}),    Equals(4));
        Assert::That(last_digit({7,6,2}),    Equals(1));
        Assert::That(last_digit({12,30,21}), Equals(6));
        Assert::That(last_digit({2,2,2,0}),  Equals(4));
        // Assert::That(last_digit({937640,767456,981242}),  Equals(0));
        Assert::That(last_digit({123232,694022,140249}),  Equals(6));
        Assert::That(last_digit({499942,898102,846073}),  Equals(6));
        
        int rand1 = rand()%100;
        int rand2 = rand()%10;
        Assert::That(last_digit({rand1}), Equals(rand1%10));
        Assert::That(last_digit({rand1,rand2}), Equals((int)pow(rand1%10,rand2)%10));
    }
};
int main(int argc,  char *argv[])
{
    return TestRunner::RunAllTests(argc, argv);
}
