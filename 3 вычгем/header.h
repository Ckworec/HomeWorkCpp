#include <iostream>
#include <ostream>
#include <ctime>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <stack>
#include <cmath>
#define eps 1.e-14

typedef struct Point
{
    double x, y;

    Point()
    {
        x = y = 0;
    }

    Point(double x_, double y_)
    {
        x = x_;
        y = y_;
    }

    int operator!=(const Point &point)
    {
        if (fabs(x - point.x) < eps && fabs(y - point.y) < eps)
            return 1;
        else
            return 0;
    }
}Point;

class PolygonalArea
{
    private:
        int len;
        std :: vector<Point> component;
        
    public:
        PolygonalArea();
        PolygonalArea(int len);
        PolygonalArea(const PolygonalArea &area);
        
        ~PolygonalArea();

        //int position(const Point &point);//позиция
        int position1(const Point &point);
        friend std :: ostream& operator<<(std :: ostream &out, const PolygonalArea& area);
};

class Vector
{
    private:
        double coords[3];
    
    public:
        Vector();
        
        Vector(int x, int y, int z);
        double operator[](int i);
        
        Vector operator()(Vector a,Vector b);
        
        double operator*(Vector obj);
};

double distance(const Point &point1, const Point &point2);
