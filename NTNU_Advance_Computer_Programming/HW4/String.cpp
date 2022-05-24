#include<iostream>
#include<cstring>
#include "String.h"
String::String():size_(0), capacity_(1),str_(new char[1]){
    str_[0]='\0';
};
String::String(const char *rhs):size_(strlen(rhs)), capacity_(size_+1), str_(new char[capacity_]){
    strncpy(str_,rhs,size_+1);
};
String::String(const String &s):size_(s.size_), capacity_(s.capacity_),str_(new char[s.capacity_]){
    strncpy(str_,s.str_,s.size_+1);
};
String::~String(){
    delete[] str_;
}
size_t String::size(){
    return size_;
}
const char* String::c_str(){
    return str_;
}
char& String::operator [] (size_t s){
    return str_[s];
}
const char& String::operator [] (size_t s) const{
    return str_[s];
}
String& String::operator += (const char* s){
    size_+=strlen(s);
    char *buff = new char[size_+1];
    strcpy(buff, str_);
    strcat(buff, s);
    delete[] str_;
    str_=buff;
    return *this;
}
String& String::operator += (const String& rhs){
    return operator += (rhs.str_);
}
String& String::operator += (const char ch){
    char *tmp = new char[2];
    tmp[0]=ch; tmp[1]='\0';
    return operator += (tmp);
}
void String::clear(){
    size_=0;
    str_[0]='\0';
}
String& String::operator = (const char* s){
    size_ = strlen(s);
    capacity_ = size_+1;
    delete[] str_;
    str_ = new char[capacity_];
    strncpy(str_, s, size_);
    str_[size_]='\0';
    return *this;
}
String& String::operator = (const String& rhs){
    return operator = (rhs.str_);
}
String& String::operator = (const char ch){
    char *tmp = new char[2];
    tmp[0]=ch; tmp[1]='\0';
    return operator += (tmp);
}
void String::swap(String &rhs){
    capacity_ ^= rhs.capacity_;
    rhs.capacity_ ^= capacity_;
    capacity_ ^= rhs.capacity_;
    size_ ^= rhs.size_;
    rhs.size_ ^= size_;
    size_ ^= rhs.size_;
    char *tmp=str_;
    str_ = rhs.str_;
    rhs.str_ = tmp;
}
std::ostream & operator << (std::ostream& o, const String& s){
    return o << s.str_;
}
std::istream & operator >> (std::istream& i, String& s){
    String tmp;
    char next;
    s.clear();
    while(i.get(next) && (int)next!=i.eof() && !std::isspace(next)){
        s += next;
    }
    return i;
}
bool operator == (const char*   lhs, const String& rhs){
    return (strcmp(lhs, rhs.str_) == 0);
}
bool operator == (const String& lhs, const String& rhs){
    return operator == (lhs.str_, rhs);
}
bool operator == (const String& lhs, const char*   rhs){
    return operator == (rhs, lhs);
}
bool operator != (const String& lhs, const String& rhs){
    return !(operator == (lhs.str_, rhs));
}
bool operator != (const char*   lhs, const String& rhs){
    return !(operator == (lhs, rhs));
}
bool operator != (const String& lhs, const char*   rhs){
    return !(operator == (rhs, lhs));
}
bool operator < (const String& lhs, const String& rhs){
    return (strcmp(lhs.str_, rhs.str_) < 0);
}
bool operator < (const char*   lhs, const String& rhs){
    return (strcmp(lhs, rhs.str_) < 0);
}
bool operator < (const String& lhs, const char*   rhs){
    return (strcmp(lhs.str_, rhs) < 0);
}
bool operator > (const String& lhs, const String& rhs){
    return (strcmp(lhs.str_, rhs.str_) > 0);
}
bool operator > (const char*   lhs, const String& rhs){
    return (strcmp(lhs, rhs.str_) > 0);
}
bool operator > (const String& lhs, const char*   rhs){
    return (strcmp(lhs.str_, rhs) > 0);
}
bool operator <= (const String& lhs, const String& rhs){
    return !(operator > (lhs, rhs));
}
bool operator <= (const char*   lhs, const String& rhs){
    return !(operator > (lhs, rhs));
}
bool operator <= (const String& lhs, const char*   rhs){
    return !(operator > (lhs, rhs));
}
bool operator >= (const String& lhs, const String& rhs){
    return !(operator < (lhs, rhs));
}
bool operator >= (const char*   lhs, const String& rhs){
    return !(operator < (lhs, rhs));
}
bool operator >= (const String& lhs, const char*   rhs){
    return !(operator < (lhs, rhs));
}
String operator + (const String& lhs, const char* rhs){
    size_t Size = lhs.size_ + strlen(rhs);
    char * buff = new char[Size + 1];
    strcpy(buff, lhs.str_);
    strcat(buff, rhs);
    buff[Size] = '\0';
    String tmp(buff);
    delete[] buff;
    return tmp;
}
String operator + (const String& lhs, const String& rhs){
    return operator + (lhs,rhs.str_);
}
String operator + (const char* lhs, const String& rhs){
    return operator + (rhs,lhs);
}
String operator + (const char lhs, const String& rhs){
    char *tmp = new char[2];
    tmp[0]=lhs; tmp[1]='\0';
    return operator + (rhs,tmp);
}
String operator + (const String& lhs, const char rhs){
    char *tmp = new char[2];
    tmp[0]=rhs; tmp[1]='\0';
    return operator + (lhs,tmp);
}