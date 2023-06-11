#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

int main() {
    int choice;
    std::cout << "Welcome to C++ menu choice\n";
    std::cout << "1) Task 1 \n";
    std::cout << "2) Task 2\n";
    std::cout << "3) Task 3\n";
    std::cout << "4) Task 4\n";
    std::cout << "5) Task 5\n";
    std::cout << "6) Exit to menu\n";
    std::cin >> choice;

    switch (choice) {
        case 1:
            float x1;
            float x2;
            float x3;
            float x4;
            //-------
            float y1;
            float y2;
            float y3;
            float y4;
            std::cout << "hello! put coordinates it's task1!\n";
            std::cout << "\nput coordinate 1 - for example (0, 0):\n";
            std::cin >> x1 >> y1;
            std::cout << "Your coordinate 1 is:\t";
            std::cout << "(" << x1 << ", " << y1 << ")";
            std::cout << "\nput coordinate 2:\n";
            std::cin >> x2 >> y2;
            std::cout << "Your coordinate 2 is:\t";
            std::cout << "(" << x2 << ", " << y2 << ")";
            std::cout << "\nput coordinate 3:\n";
            std::cin >> x3 >> y3;
            std::cout << "Your coordinate 3 is:\t";
            std::cout << "(" << x3 << ", " << y3 << ")" "\n";
            x4 = x1 + x3 - x2;
            y4 = y1 + y3 - y2;
            std::cout << "Your answer:\t" << x4 << ", " << y4 << "\n";
            return main();
            break;

        case 2:

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
            std::cin >> x11 >> y11;
            std::cout << "Your coordinate 1 is:\t";
            std::cout << "(" << x11 << "," << y11 << ")\n";
            std::cin >> x22 >> y22;
            std::cout << "Your coordinate 2 is:\t";
            std::cout << "(" << x22 << "," << y22 << ")\n";
            std::cin >> x33 >> y33;
            std::cout << "Your coordinate 3 is:\t";
            std::cout << "(" << x33 << "," << y33 << ")\n";
            std::cin >> x44 >> y44;
            std::cout << "Your coordinate 4 is:\t";
            std::cout << "(" << x44 << "," << y44 << ")\n";


            double formulaX = (x11 + x22 + x33 + x44) / 4;
            double formulaY = (y11 + y22 + y33 + y44) / 4;

            std::cout << "Your answer is:" << "(" << formulaX << "," << formulaY << ")" << "\n";
            return main();
            break;
    }


            if(choice == 3) {

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
                std::cout << "Put coordinates of point A:\n";
                std::cin >> x333 >> y333;
                std::cout << "Your coordinate 1 is:\t";
                std::cout << "(" << x333 << "," << y333 << ")\n";
                std::cout << "Put coordinates of point B:\n";
                std::cin >> x444 >> y444;
                std::cout << "Your coordinate 2 is:\t";
                std::cout << "(" << x444 << "," << y444 << ")\n";

                double midx = (x111 + x222) / 2;
                double midy = (y111 + y222) / 2;

                double foundx = (x111 + 2 * y222) / 3;
                double foundy = (y111 + 2 * x111) / 3;

                //find lenght
                double lengthx = x222 - x111;
                double lengthy = y222 - y222;

                double llc = sqrt(pow(x222 - x111, 2) + pow(y222 - y111, 2));
                double llai = sqrt(pow(x111 - x444, 2) + pow(y111 - y444, 2));
                double sump = (llc + llai) * 2;
                double lla = midx * (2 / sqrt(3));
                double S = abs((x222 - x111) * (y444 - y111) - (y222 - y111) * (x444 - x111));
           //   std::cout << sump << "\n"  << S << "\n";
                std::cout << round(sump * 1000) / 1000 << std::endl;
                std::cout << round(S * 1000) / 1000 << std::endl;


                double acx = lengthy * llc * (sqrt(3) / 3);
                double acy = -lengthx * llc * (sqrt(3) / 3);

                double xx = midx + acx;
                double xxy = midy + acy;
                std::cout << "coordinate of point C: (" << xx << ", " << xxy << ")" << "\n";
                return main();
            }

if(choice == 4){

            double xd1;
            double xd2;
            //---------
            double yd1;
            double yd2;
            double height;


            std::cout << "Put coordinate A\n";
            std::cin >> xd1 >> yd1;
            std::cout << "You put A: \t" << "(" << xd1 << "," << yd1 << ")\n";
            std::cout << "Put coordinate B:\n";
            std::cin >> xd2 >> yd2;
            std::cout << "You put B: \t" << "(" << xd2 << "," << yd2 << ")\n";
            std::cout << "Put Height\n";
            std::cin >> height;
            std::cout << "You put height\t" << height;

            double Mx = (xd1 + xd2) / 2;
            double My = (yd2 + yd2) / 2;


            // Находим боковую сторону той фигуры и угол!
            double formulaC = sqrt(pow(height, 2) + pow((xd2 - xd1) / 2, 2));
            double k = acos((formulaC / 2) / height);

            //--------Координаты Вершин!
            double xd3 = Mx + (height / tan(k)) * ((yd2 - yd1) / 2, 2);
            double yd3 = My + (height / tan(k)) * ((xd2 - xd1) / 2, 2);

            std::cout << "answer?" << "C:" << "(" << xd3 << "," << yd3 << ")" << "\n";
            return main();

    }

if(choice == 5){
double xe;
double ye;
double xe2;
double ye2;
double xe3;
double ye3;

std::cout << "Put coordinates!\n";
std::cin >> xe >> ye;
std::cout << "You put: \t" <<  "(" << xe << "," << ye << ")\n";
    std::cin >> xe2 >> ye2;
    std::cout << "You put: \t" <<  "(" << xe2 << "," << ye2 << ")\n";
    std::cin >> xe3 >> ye3;
    std::cout << "You put: \t" <<  "(" << xe3 << "," << ye3 << ")\n";

    double side = (sqrt(pow(xe2 - xe, 2) + pow(ye2 - ye, 2)));
    double side2 = (sqrt(pow(xe3 - xe2, 2) + pow(ye3 - ye2, 2)));
    double side3 = (sqrt(pow(xe - xe3, 2) + pow(ye - ye3, 2)));

    if(side + side2 <= side3 || side + side3 <= side2 || side2+side3 <= side  ){
        std::cout << "does not exist\n";
        return 0;
    }


    // вычисляет угол между двумя сторонами 180/π, чтобы получить значения угла в градусах

    double aw = acos((side2 * side2 + side3 * side3 - side * side)/2*side2*side3) * 180/M_PI;
    double yw = acos((side * side + side3 * side3 - side2 * side2)/2*side*side3) * 180/M_PI;
    double t = 180 - aw - yw;

    if( side == side2 && side == side3 )
    {
        std::cout << "This is equilateral!\n";
    }
    else
        if( side == side2 || side == side3 || side3 == side2)
        {
            std::cout << "It's triangle is isosceles!\n";
        }
        else
        {
            std::cout << "This is a scalene triangle!\n";
        }


        if(aw < 90 && yw < 90 && t < 90){
        std::cout << "it's Sharp - angled\n";
            } else if (aw == 90 || yw == 90 || t == 90){
        std::cout << "It's Rectangular\n";
    }   else {
        std::cout << "It;s Obtuse angle\n";
    }
    return main();
}

if(choice == 6){
    return 0;
}

}
