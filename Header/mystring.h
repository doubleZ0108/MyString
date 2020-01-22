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

    /* Destructor */
    ~MyString(){
        if(str){
            free(this->str);
            this->str = NULL;
        }
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

#endif //MYSTRING_MYSTRING_H
