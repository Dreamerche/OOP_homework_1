#include <iostream>
#include <point.hpp>
#include <point.cpp>
#include <face.hpp>
#include <face.cpp>
#include <object3d.hpp>
#include <fstream>
#include <cmath>

using namespace std;

        Object3d::Object3d(const char* name){
            ifstream file(name);
            if (!file.is_open()) {
                cout << "Error opening file: " << name << std::endl;
            }
            else{
                getObjectInfo(file);
            }
        }
        void setObject(ifstream file){
            while (!file.eof()){
                int BUFF_SIZE=20;
                char buff[BUFF_SIZE];        
                file.getline(buff, BUFF_SIZE);
                int oldCurr=2;  
                int curr=2;
                int nextInterval=2;
                if(buff[0]=='v'){
                    for (size_t i = 0; i < 3; i++)//max 3 coordinates per a point
                    {
                        double num=0.0;
                        for (size_t j = curr; j < BUFF_SIZE; j++)
                        {
                            if(buff[curr]==' ' && curr!=nextInterval){
                                nextInterval=j;
                                j=BUFF_SIZE;//to stop the for
                                oldCurr=curr+1;
                            }
                            curr++;
                        }
                        bool isNegative=false;
                        if(oldCurr=='-'){
                            oldCurr++;
                            isNegative=true;}

                        int multiply=1;
                        while (oldCurr<nextInterval && oldCurr!='.'){
                            num=num*multiply+getNumber(buff[oldCurr]);
                            multiply=10;
                        }
                        oldCurr++;
                        multiply=1;
                        int afterZero=0;
                        int countDigits=0;//after the .
                        while (oldCurr<nextInterval)
                        {
                            int afterZero=afterZero*multiply+getNumber(buff[oldCurr]);
                        }
                        if(countDigits!=0){
                            num+=afterZero*(0.1,countDigits);
                        }
                        if(isNegative){
                            num*=-1;
                        }   
                        }

                    }

                
            }
            if(buff[0]=='f'){

            }
            }   
            file1.close();
            file2.close();
        }

        int Face::getNumber(char n){//kogi ne znam dali sme uchili konventirane, puk i mai ne e razresheno da polzvame tuk
            if (n=='0'){return 0;}
            else if(n=='1'){return 1;}
            else if(n=='2'){return 2;}
            else if(n=='3'){return 3;}
            else if(n=='4'){return 4;}
            else if(n=='5'){return 5;}
            else if(n=='6'){return 6;}
            else if(n=='7'){return 7;}
            else if(n=='8'){return 8;}
            return 9;
        }


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