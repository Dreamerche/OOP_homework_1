#include <iostream>
#include <point.hpp>

Point::Point(double x, double y, double z){
    setX(x);
    setY(y);
    setZ(z);
}
//shte vidia ima li smisul ot tozi, ama nali da e OOP-friendli
Point::Point(const Point& other){
    setX(other.getX());
    setY(other.getY());
    setZ(other.getZ());
}
//oop friendli, ama mai niama smisul za tazi chast ot zadachata
Point &Point::operator=(const Point& other) {
    if(this!=&other){
        setX(other.getX());
        setY(other.getY());
        setZ(other.getZ());
    }
  return *this;
}

int Point::getX() const{
    return this->x;
}
int Point::getY() const{
    return this->y;
}
int Point::getZ() const{
    return this->z;
}
void Point::setX(int x){
    this->x=x;
}
void Point::setY(int y){
    this->y=y;
}
void Point::setZ(int z){
    this->z=z;
}