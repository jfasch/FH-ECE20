#ifndef MY_STRING_H
#define MY_STRING_H

class MyString
{
public:
    MyString()
    {
        _str = new char[1];
        *_str = 0;
    }

    MyString(const char* str)
    {
        _str = new char[strlen(str)+1];
        strcpy(_str, str);
    }

    MyString(const MyString& other)
    {
        _str = new char[strlen(other._str)+1];
        strcpy(_str, other._str);
    }

    MyString& operator=(const MyString& other)
    {
        if (this != &other) {
            delete[] _str;

            _str = new char[strlen(other._str)+1];
            strcpy(_str, other._str);
        }
        return *this;
    }

    ~MyString()
    {
        delete[] _str;
    }

    const char* c_str() const { return _str; }

    size_t size() const
    {
        return strlen(_str);
    }
    
private:
    char* _str;
};

#endif
