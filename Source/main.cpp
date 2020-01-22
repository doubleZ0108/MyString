#include <iostream>
#include "../Header/mystring.h"
using namespace std;

void testBasicFunction(){
    MyString mystr;
    MyString mystr2("a_string");
    MyString mystr3(mystr2);

    cout << mystr.size() << endl;
    cout << mystr2.size() << endl;

    cout << mystr3 << endl;

    mystr3[1] = ' ';
    cout << mystr3 << endl;

    mystr3[2] = 'b';
    cout << mystr3 << endl;
    cout << mystr2[1] << endl;

    mystr.append("foobar");
    cout << mystr.size() << endl;

    mystr2.append("_boxboz");
    cout << mystr2 << endl;

}

int main() {
    testBasicFunction();

    return 0;
}
