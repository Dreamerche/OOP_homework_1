#include <iostream>
#include <point.hpp>
#include <point.cpp>
#include <face.hpp>
#include <face.cpp>
using namespace std;
class Object3d{
    public:
        Object3d(const char*);
        void setObject(const char*);
        int getNumber(char n);
        //не разбрах втория конструктор
        int getVertexCount() const;
        int getFaceCount() const;
        void save(const string& file);
        void print(ostream &);
        Object3d cut(function<bool>(float x, float y, float z) f);
        void flip();
        void createCube(double);
        void createSphere(double);


    private:
        vector<Point> vertexes;
        vector<Face> faces;
};