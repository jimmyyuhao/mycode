#include <vector>
#include <set>
#include <string>
#include <string.h>
#include <igloo/igloo_alt.h>
static const size_t npos = -1;
using namespace igloo;
using namespace std;
#include <vector>
#include <utility>
set<pair<int,int>> order;

void insertInSet(pair<int, int> & interval)
{
    int first,second=0;
    for (auto orderiter = order.begin(); orderiter != order.end();) {
        if (orderiter->first <= interval.first &&orderiter->second >= interval.second ) {
            return;
        }
        else if (orderiter->first >= interval.first &&orderiter->second >= interval.second&& orderiter->first<=interval.second ) {
            interval.second = orderiter->second;
            orderiter = order.erase(orderiter);
            continue;
        }
        else if (orderiter->first >= interval.first &&orderiter->second <= interval.second ) {
            orderiter = order.erase(orderiter);
            continue;
        }
        else if (orderiter->first <= interval.first &&orderiter->second <= interval.second && orderiter->second>interval.first) {
            interval.first = orderiter->first;
            orderiter = order.erase(orderiter);
            continue;
        }
        else{    orderiter++; }
    }

    order.insert({interval.first, interval.second});
}

void print(void)
{
    unsigned int i =0;
    for (auto orderiter = order.begin(); orderiter != order.end(); orderiter++) {
        cout << "order " << i << "=[" << orderiter->first << "," << orderiter->second << "]" << endl;
        i++;
    }
}

void printin(vector<pair<int, int>> intervals)
{
    unsigned int i =0;
    for (auto orderiter = intervals.begin(); orderiter != intervals.end(); orderiter++) {
        cout << "order in " << i << "=[" << orderiter->first << "," << orderiter->second << "]" << endl;
        i++;
    }
}

int sum_intervals(vector<pair<int, int>> intervals)
{
    int sum = 0;
    cout<<"start"<<endl;
    order.clear();
    printin(intervals);

    for (auto viter = intervals.begin(); viter != intervals.end(); viter++) {
        insertInSet(*viter);
    }

    for (auto iter = order.begin(); iter != order.end(); iter++) {
        sum += iter->second - iter->first;
    }

    print();
    return sum;
}

Describe(Sample_Tests)
{
    It(Tests) {
        vector<pair<int, int>> intervals = {{1, 5}};
        Assert::That(sum_intervals(intervals), Equals(4));

        intervals = {{1, 5}, {1, 5}};
        Assert::That(sum_intervals(intervals), Equals(4));
        intervals = {{1,2}, {6, 10}, {11, 15}};
        Assert::That(sum_intervals(intervals), Equals(9));
        intervals ={ {43,246} ,{-110,-95} ,{64,415} ,{-294,84} ,{-442,-331} ,{401,405} ,{-268,364} ,{122,144} ,{172,187} ,{367,489} ,{-180,452} ,{-122,1} ,{-310,21} ,{197,323} ,{124,320} ,{-444,76} ,{204,243}};
        Assert::That(sum_intervals(intervals), Equals(933));
    }
};

int main(int argc,  char *argv[])
{
      return TestRunner::RunAllTests(argc, argv);
}
