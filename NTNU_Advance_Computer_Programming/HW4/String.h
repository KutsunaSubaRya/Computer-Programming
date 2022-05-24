#ifndef STRING_H
#define STRING_H
class String{
public:
    String();
    String(const char*);
    String(const String &);
    constexpr String(std::nullptr_t) = delete;
    ~String();
    size_t size();
    const char* c_str ();
    char& operator [] (size_t);
    const char& operator [] (size_t) const;
    String& operator += (const char*);
    String& operator += (const String&);
    String& operator += (const char);
    void clear();
    String& operator = (const char*);
    String& operator = (const String&);
    String& operator = (const char);
    constexpr String& operator = (std::nullptr_t) = delete;
    void swap(String&);
    friend std::istream & operator >> (std::istream&, String&);
    friend std::ostream & operator << (std::ostream&, const String&);
    friend bool operator == (const String&, const String&);
    friend bool operator == (const char*, const String&);
    friend bool operator == (const String&, const char*);
    friend bool operator != (const String&, const String&);
    friend bool operator != (const char*, const String&);
    friend bool operator != (const String&, const char*);
    friend bool operator <  (const String&, const String&);
    friend bool operator <  (const char*, const String&);
    friend bool operator <  (const String&, const char*);
    friend bool operator >  (const String&, const String&);
    friend bool operator >  (const char*, const String&);
    friend bool operator >  (const String&, const char*);
    friend bool operator <= (const String&, const String&);
    friend bool operator <= (const char*, const String&);
    friend bool operator <= (const String&, const char*);
    friend bool operator >= (const String&, const String&);
    friend bool operator >= (const char*, const String&);
    friend bool operator >= (const String&, const char*);
    friend String operator + (const String&, const char*);
    friend String operator + (const String&, const String&);
    friend String operator + (const char*, const String&);
    friend String operator + (const char, const String&);
    friend String operator + (const String&, const char);
private:
    size_t size_ = 0, capacity_ = 0;
    char *str_ = nullptr;
};
#endif