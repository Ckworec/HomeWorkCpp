#include <iostream>
#include <ostream>
#include <ctime>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>

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
}Point;

class PolygonalArea
{
    private:
        int len;
        std :: vector<Point> component;
        
    public:
        PolygonalArea();
        PolygonalArea(int len);
        
        ~PolygonalArea();
        
        PolygonalArea operator+(PolygonalArea &area);//объединение
        PolygonalArea operator*(PolygonalArea &area);//пересечение
        PolygonalArea operator=(const PolygonalArea &area);//сравнение
        PolygonalArea operator=(PolygonalArea &&area);
        Point operator[](int i);//итератор
        Point intersection_point(const PolygonalArea &area, int k1, int k2);//поиск точки пересечения для объединения
        PolygonalArea coordinate_change(int i, Point point);//изменение координаты
        PolygonalArea add_point(int k, Point point);//добавление точки
        PolygonalArea delete_point(int i);//удаление точки
        int position(const Point &point);//позиция
        friend class ArrayPolygonalArea;
        int point_on_a_line(const Point &point);
};

class ArrayPolygonalArea
{
    public:
        int len;
        std :: vector<PolygonalArea> field;
    
        ArrayPolygonalArea();
        ArrayPolygonalArea(PolygonalArea &area, int len);

        ~ArrayPolygonalArea();

        ArrayPolygonalArea add_area(PolygonalArea &area);
        ArrayPolygonalArea delete_area(int i);

        void number_of_components();//количество областей
        friend class PolygonalArea;
};

int distance(Point k1, Point k2);//дистанция