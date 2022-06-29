#ifndef COPY_GOOD_H
#define COPY_GOOD_H

#include <string>
#include <vector>

class HasTonsOfCrap
{
public:
    const std::string& str() const { return _str; }
    const std::vector<int>& ints() const { return _ints; }

    void add_something_to_str(const std::string& something)
    {
        _str += something;
    }
    
    void add_one_more_piece_of_crap(int crap)
    {
        _ints.push_back(crap);
    }

private:
    std::string _str;
    std::vector<int> _ints;
};

class HasOverloadedCopy
{
public:
    HasOverloadedCopy() = default;
    HasOverloadedCopy(const std::string& s) : _str(s) {}
    HasOverloadedCopy(const HasOverloadedCopy& other)
    : _str(other._str)
    {
        _str += " (Kopie vom Constructor gemacht)";
    }

    HasOverloadedCopy& operator=(const HasOverloadedCopy& other)
    {
        _str = other._str + " (Kopie vom Assignment Operator gemacht)";
        return *this;
    }

    const std::string& str() const { return _str; }

private:
    std::string _str;
};

#endif
