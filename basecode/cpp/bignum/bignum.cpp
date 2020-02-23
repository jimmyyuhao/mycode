#include <vector>
#include <string>
#include <string.h>
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

std::string add(unsigned long long a ,unsigned long long b)
{
    return add(std::to_string(a),std::to_string(b));
}

std::string multiply(std::string a, std::string b)
{
    if(a=="0"||b="0") return string("0");
    string loopCnt = "0";
    string c=string("0");
    while(loopCnt<=b) {
       loopCnt = add(loopCnt,"1");
       c=add(c,a);
    }
    return c;
}
