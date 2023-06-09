#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

//class Coordinates {
//public:
//    float x1;
//    float x2;
//    float x3;
//    float x4;
//
//    float y1;
//    float y2;
//    float y3;
//    float y4;


//    float x1o;
//    float x2o;
//    float x3o;
//    float x4o;
//
//    float y1o;
//    float y2o;
//    float y3o;
//    float y4o;
//};





int main() {
    float x1;
    float x2;
    float x3;
    float x4;
//-----------
    float y1;
    float y2;
    float y3;
    float y4;

//    std::cout <<  "Welcome to C++ menu choice\n";
//    std::cout << "1) Task 1 \n";
//    std::cout << "2) Task 2\n";
//    std::cout << "3) Task 3\n";
//    std::cout << "4) Task 4\n";
//    std::cout << "5) Task 5\n";


//    std::cout << "hello! put coordinates it's task1!\n";
//    std::cout << "\nput coordinate 1 - for example (0, 0):\n";
//    std::cin >> x1 >> y1;
//    std::cout << "Your coordinate 1 is:\t" ;
//    std::cout << "(" << x1 << ", "<< y1 << ")";
//    std::cout << "\nput coordinate 2:\n";
//    std::cin >> x2 >> y2;
//    std::cout << "Your coordinate 2 is:\t";
//    std::cout << "(" << x2 << ", "<< y2 << ")";
//    std::cout << "\nput coordinate 3:\n";
//    std::cin >>  x3 >> y3;
//    std::cout << "Your coordinate 3 is:\t";
//    std::cout << "(" << x3 << ", "<< y3 << ")" "\n";
//    x4 = x1 + x3 - x2;
//    y4 = y1 + y3 - y2;
//    std::cout << "Your answer:\t" << x4 << ", " << y4;




    return 0;
}



int mai(){
    double x11;
    double x22;
    double x33;
    double x44;
    //---------
    double y11;
    double y22;
    double y33;
    double y44;

    std::cout << "Task 2!\n";
    std::cout << "put coordinate:\n";
    std::cin >>  x11 >> y11;
    std::cout << "Your coordinate 1 is:\t";
    std::cout << "(" << x11 << "," << y11 << ")\n";
    std::cin >>  x22 >> y22;
    std::cout << "Your coordinate 2 is:\t";
    std::cout << "(" << x22 << "," << y22 << ")\n";
    std::cin >>  x33 >> y33;
    std::cout << "Your coordinate 3 is:\t";
    std::cout << "(" << x33 << "," << y33 << ")\n";
    std::cin  >> x44 >> y44;
    std::cout << "Your coordinate 4 is:\t";
    std::cout << "(" << x44 << "," << y44 << ")\n";

    double formulaX = (x11 + x22 + x33 + x44) / 4;
    double formulaY = (y11 + y22 + y33 + y44) / 4;
    std::cout << "Your answer is:" << "(" << formulaX << "," << formulaY << ")" << std::endl;
}


int ma() {
    double x111;
    double x222;
    double x333;
    double x444;
    //---------
    double y111;
    double y222;
    double y333;
    double y444;
    std::cout << "Put coordinates of point A:\n";
    std::cin >> x111 >> y111;
    std::cout << "Your coordinate 1 is:\t";
    std::cout << "(" << x111 << "," << y111 << ")\n";
    std::cout << "Put coordinates of point B:\n";
    std::cin >> x222 >> y222;
    std::cout << "Your coordinate 2 is:\t";
    std::cout << "(" << x222 << "," << y222 << ")\n";

    double midx = (x111 + x222) / 2;
    double midy = (y111 + y222) / 2;

    //find lenght
    double llc = sqrt(pow());

    //vextor
    double foundx = (x111 + 2 * y222) / 3;
    double foundy = (y111 + 2 * x111) / 3;

    double lengthx = x333 - x111;
    double lengthy = y333 - y333;

    double acx =
}