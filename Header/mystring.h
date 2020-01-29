//
//  mystring.h
//  MyString
//  
//  Created by double Z on 2020/01/22 .
//  Copyright © 2019 double Z. All rights reserved.
//

#ifndef MYSTRING_MYSTRING_H
#define MYSTRING_MYSTRING_H

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class MyString;
int mystrcmp(const MyString& mystr1, const MyString& mystr2);

class MyString{

    friend ostream& operator<<(ostream& os, const MyString& mystr);

private:
    char* str = NULL;
    int length = 0;

public:
    /* Constructor */
    MyString() = default;

    MyString(const char* source_str){
        this->length = strlen(source_str);
        int temp_size = sizeof(char) * this->length;
        this->str = (char *)malloc(temp_size);
        memcpy(this->str, source_str, temp_size);
    }

    MyString(const MyString& source_mystr){
        this->length = source_mystr.size();
        int temp_size = sizeof(char) * this->length;
        this->str = (char *)malloc(temp_size);
        memcpy(this->str, source_mystr.getStr(), temp_size);
    }

    MyString(char source_ch){
        this->length = 1;
        int temp_size = sizeof(char) * this->length;
        this->str = (char *)malloc(temp_size);
        *this->str = source_ch;
    }

    /* Destructor */
    ~MyString(){
        if(str){
            free(this->str);
            this->str = NULL;
        }
    }

    /* Assign Operator*/
    MyString& operator=(const MyString& source_mystr){
        if(this == &source_mystr){
            return *this;
        }else if(this->str){
            free(this->str);
            this->str = NULL;
        }
        this->length = source_mystr.size();
        int temp_size = sizeof(char) * this->length;
        this->str = (char *)malloc(temp_size);
        memcpy(this->str, source_mystr.getStr(), temp_size);
        return *this;
    }

    MyString& operator=(const char* source_str){
        if(this->str){
            free(this->str);
            this->str = NULL;
        }
        this->length = strlen(source_str);
        int temp_size = sizeof(char) * this->length;
        this->str = (char *)malloc(temp_size);
        memcpy(this->str, source_str, temp_size);
        return *this;
    }

    MyString& operator=(char source_ch){
        if(this->str){
            free(this->str);
            this->str = NULL;
        }
        this->length = 1;
        int temp_size = sizeof(char) * this->length;
        this->str = (char *)malloc(temp_size);
        *this->str = source_ch;
        return *this;
    }

    /* Getter */
    char* getStr() const{
        return this->str;
    }

    int size() const{
        return this->length;
    }

    /* Operator */
    char& operator[](int index){
        return *(str + index);
    }

    const char operator[](int index) const{
        return *(str + index);
    }

    bool operator==(const MyString& rhv){
        return (mystrcmp(*this, rhv) == 0);
    }

    bool operator!=(const MyString& rhv){
        return !(*this==rhv);
    }

    bool operator<(const MyString& rhv){
        return (mystrcmp(*this, rhv) < 0);
    }

    bool operator>(const MyString& rhv){
        return (mystrcmp(*this, rhv) > 0);
    }

    bool operator<=(const MyString& rhv){
        return (*this<rhv || *this==rhv);
    }

    bool operator>=(const MyString& rhv){
        return (*this>rhv || *this==rhv);
    }

    /* Append */
    void append(const char* appendix_str){
        if(this->str){
            char* buf_str = (char *)malloc(sizeof(char)*this->length);
            memcpy(buf_str, this->str, sizeof(char)*this->length);

            int origin_len = this->length;
            int fresh_len = strlen(appendix_str);
            this->length += fresh_len;

            free(this->str);
            this->str = NULL;
            this->str = (char *)malloc(sizeof(char)*this->length);
            memcpy(this->str, buf_str, sizeof(char)*origin_len);
            memcpy(this->str+origin_len, appendix_str, sizeof(char)*fresh_len);

            free(buf_str);
        } else{
            this->length = strlen(appendix_str);
            int temp_size = sizeof(char) * this->length;
            this->str = (char *)malloc(temp_size);
            this->str = (char *)memcpy(this->str, appendix_str, temp_size);
        }
    }

    void append(const MyString& appendix_mystr){
        if(this->str){
            char* buf_str = (char *)malloc(sizeof(char)*this->length);
            memcpy(buf_str, this->str, sizeof(char)*this->length);

            int origin_len = this->length;
            int fresh_len = appendix_mystr.size();
            this->length += fresh_len;

            free(this->str);
            this->str = NULL;
            this->str = (char *)malloc(sizeof(char)*this->length);
            memcpy(this->str, buf_str, sizeof(char)*origin_len);
            memcpy(this->str+origin_len, appendix_mystr.getStr(), sizeof(char)*fresh_len);

            free(buf_str);
        } else{
            this->length = appendix_mystr.size();
            int temp_size = sizeof(char) * this->length;
            this->str = (char *)malloc(temp_size);
            memcpy(this->str, appendix_mystr.getStr(), temp_size);
        }
    }
};

ostream& operator<<(ostream& os, const MyString& mystr){
    int length = mystr.size();
    for(int i=0;i<length;++i){
        os << mystr[i];
    }
    return os;
}

int mystrcmp(const MyString& mystr1, const MyString& mystr2){
    for(int i=0;i<mystr1.size() && i<mystr2.size();++i){
        if(mystr1[i]<mystr2[i]){
            return -1;
        }else if(mystr1[i]>mystr2[i]){
            return 1;
        }
    }
    if(mystr1.size() < mystr2.size()){
        return -1;
    }else if(mystr1.size() > mystr2.size()){
        return 1;
    }

    return 0;
}

#endif //MYSTRING_MYSTRING_H
