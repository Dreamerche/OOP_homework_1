#include <iostream>
#include <vector>
using namespace std;

class Face{
    public:
        Face(const vector<int>);
        Face(const Face&);
        Face &operator=(const Face&);
        vector<int> getFaceVertexes() const;
        void setFaceVertexes(vector<int>);

    private:
        vector<int> faceVertexes;
};