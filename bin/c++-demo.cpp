#include <math.h>
#include <iostream>

class point
{
public:
    point() : _x{0}, _y{0} {}
    point(int x, int y) : _x{x}, _y{y} {}

    int x() const { return _x; }
    int y() const { return _y; }

    void move(int x, int y)
    {
        _x += x;
        _y += y;
    }

    point& operator+=(const point& by)
    {
        _x += by._x;
        _y += by._y;
        return *this;
    }

    double distance_from_origin() const
    {
        return sqrt(this->_x*this->_x + this->_y*this->_y);
    }


private:
    int _x;
    int _y;
};


point operator+(const point& lhs, const point& rhs)
{
    int x = lhs.x() + rhs.x();
    int y = lhs.y() + rhs.y();
    return point(x, y);
}

int main(void)
{
    point A{1,2}, B(2,4);
    point C, D;

    std::cout << "A(" << A.x() << ',' << A.y() << ')' << std::endl;
    std::cout << "B(" << B.x() << ',' << B.y() << ')' << std::endl;
    std::cout << "C(" << C.x() << ',' << C.y() << ')' << std::endl;
    std::cout << "D(" << D.x() << ',' << D.y() << ')' << std::endl;

    // move_point(&A, 665, 0);
    A.move(665, 0);
    std::cout << "A(" << A.x() << ',' << A.y() << ')' << std::endl;

    point vector{3, 4};
    point X;
    X = A += vector;
    // A.operator+=(vector);
    std::cout << "A(" << A.x() << ',' << A.y() << ')' << std::endl;

    double distance = A.distance_from_origin();
    std::cout << "|A|: " << distance << std::endl;

    point sum = A + B;
    std::cout << "sum(" << sum.x() << ',' << sum.y() << ')' << std::endl;

    return 0;
}
