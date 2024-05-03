#include <iostream>
class Point{
    public:
        Point(double, double, double);
        Point(const Point&);
        Point &operator=(const Point&);
        int getX() const;
        int getY() const;
        int getZ() const;
        void setX(int);
        void setY(int);
        void setZ(int);

    private:
        double x;
        double y;
        double z;
};