#include <iostream>
#include "../Header/mystring.h"
using namespace std;

void testConstructor(){
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

    mystr2.append(mystr3);
    cout << mystr2 << endl;

    cout << mystr3 << endl;
}

void testAssignOperator(){
    MyString mystr;
    mystr = "hello";

    MyString mystr2;
    mystr2 = mystr;

    MyString mystr3;
    mystr3 = 'c';

    mystr = mystr;      //自我赋值

    mystr = mystr2 = mystr3 = "world";  //连续赋值
}


void testRelationOperator(){
    cout << (MyString("abc") == MyString("abc")) << endl;
    cout << (MyString("abc") <= MyString("abc")) << endl;
    cout << (MyString("abd") == MyString("abc")) << endl;
    cout << (MyString("abc") != MyString("abc")) << endl;
    cout << (MyString("abd") != MyString("abc")) << endl;
    cout << (MyString("ab0") < MyString("ab1")) << endl;
    cout << (MyString("ab0") > MyString("ab1")) << endl;
    cout << (MyString("ab0") >= MyString("ab1")) << endl;
    cout << (MyString("15") < MyString("3")) << endl;
}

void testConstant(){
    const MyString cstr("a constant string");
    cout << cstr.size() << endl;
    cout << cstr[2] << endl;
    cout << cstr << endl;
}

void testNullCharacter(){
    MyString mystr("abc123");
    cout << mystr.size() << endl;

    mystr[2] = '\0';
    cout << mystr.size() << endl;

    MyString mystr2(mystr);
    cout << mystr2.size() << endl;

    MyString mystr3("foo");
    mystr3.append(mystr);
    cout << mystr3.size() << endl;

    cout << mystr3 << endl;
}

int main() {
//    testConstant();
    testAssignOperator();
//    testRelationOperator();
//    testConstant();
//    testNullCharacter();

    return 0;
}
