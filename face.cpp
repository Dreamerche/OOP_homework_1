#include <iostream>
#include <vector>
#include <face.hpp>
using namespace std;

    Face::Face(const vector<int> vIndexes){
        setFaceVertexes(vIndexes);
    };
    //da ima oop friendli kod
    Face::Face(const Face& other){
        for (size_t i = 0; i < other.getFaceVertexes().size(); i++)
        {
            setFaceVertexes(other.getFaceVertexes());
        }
    };
    Face &Face::operator=(const Face& other){
        if(this!=&other){
            setFaceVertexes(other.getFaceVertexes());
        }
        return *this;
    };
    vector<int> Face::getFaceVertexes() const{
        return this->faceVertexes;
    };
    void Face::setFaceVertexes(const vector<int> otherIndexes){
        this->faceVertexes.resize(otherIndexes.size());
        this->faceVertexes=otherIndexes;
    }
