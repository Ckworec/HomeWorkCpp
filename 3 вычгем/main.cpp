#include "header.h"

int main(void)
{
    int length, test;
    double x, y;

    srand(time(NULL));
    std :: cout << "Enter the number of points: ";
    std :: cin >> length;
    PolygonalArea area(length);
    std :: cout << area << std :: endl;

    std :: cout << "Enter the number of tests: ";
    std :: cin >> test;
    
    for (int i = 0; i < test; i ++)
    {
        std :: cout << "Enter coordinates x and y: ";
        std :: cin >> x >> y;
        Point point(x, y);
        
        area.position1(point);
    }

    return 0;
}
