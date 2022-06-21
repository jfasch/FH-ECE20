#ifndef CXX_SCHOOL_POINT_H
#define CXX_SCHOOL_POINT_H

class point
{
public:
    point(int x, int y) : _x(x), _y(y) {}

    bool operator==(point other) const
    {
        return _x == other._x && _y == other._y;
    }

    bool operator!=(point other) const
    {
        return !operator==(other);
    }

    point operator+(point other) const
    {
        int x = _x + other._x;
        int y = _y + other._y;

        return point{x,y};
    }

    point& operator+=(point vec)
    {
        _x += vec._x;
        _y += vec._y;

        return *this;
    }

    int x() const { return _x; }
    int y() const { return _y; }

    void move(int x, int y)
    {
        _x += x;
        _y += y;
    }

    void move(point vec)
    {
        _x += vec._x;
        _y += vec._y;
    }

private:
    int _x;
    int _y;
};

#endif
