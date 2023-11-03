#include "header.h"

int PolygonalArea :: position1(const Point &point)
{
    double sum_angle = 0, phi1;

    for (int i = 0; i < len; i ++)
    {
        if (this -> chek_point_line_segment(i, point) == 1)
        {
            std :: cout << "The point lies on the boundary of the region" << std :: endl;
            return 0;
        }
    }

    for (int i = 0; i < len; i ++)
    {
        if (i < len - 1)
        {
            Vector vector3, vector1(component[i].x - point.x, component[i].y - point.y, 0), vector2(component[i + 1].x - point.x, component[i + 1].y - point.y, 0);

            phi1 = acos((vector1 * vector2) / (sqrt(vector1 * vector1) * sqrt(vector2 * vector2)));

            vector3(vector1, vector2);

            if (vector3[2] < 0)
                sum_angle += phi1;
            else
            {
                sum_angle -= phi1;
            }
        }
        else
        {
            Vector vector3, vector1(component[i].x - point.x, component[i].y - point.y, 0), vector2(component[0].x - point.x, component[0].y - point.y, 0);

            phi1 = acos((vector1 * vector2) / (sqrt(vector1 * vector1) * sqrt(vector2 * vector2)));

            vector3(vector1, vector2);

            if (vector3[2] < 0)
                sum_angle += phi1;
            else
            {
                sum_angle -= phi1;
            }
        }
    }

    if (fabs(sum_angle) < eps)
    {
        std :: cout << "The point lies outside the region" << std :: endl;
        return -1;
    }
    else
    {
        std :: cout << "The point lies in the region" << std :: endl;
        return 1;
    }
}

double distance(const Point &point1, const Point &point2)
{
    double lenght;

    lenght = sqrt((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y));

    return lenght;
}

PolygonalArea :: PolygonalArea()
{
    len = 0;
}

PolygonalArea :: PolygonalArea(int length)
{
    double x, y;
    len = length;
    FILE *f;

    /*for (int i = 0; i < len; i ++)
    {
        component.push_back(Point(rand() % 50, rand() % 50));
    }*/

    f = fopen("data.txt", "r");
    while (fscanf(f, "%lf%lf", &x, &y) == 2)
    {
        component.push_back(Point(x, y));
    }
}

PolygonalArea :: ~PolygonalArea()
{

}

PolygonalArea :: PolygonalArea(const PolygonalArea &area) : PolygonalArea(area.len)
{
    for (int k = 0; k < len; ++k)
    {
        component[k].x = area.component[k].x;
        component[k].y = area.component[k].y;
    }
    //std::cout << "Copy constructor" << *this << std::endl;
}

std :: ostream& operator<<(std :: ostream &out, const PolygonalArea& area)
{
    for (int i = 0; i < area.len; i ++)
    {
	    out << "(" << area.component[i].x << ", " << area.component[i].y << ") ";
    }

	return out;
}

Vector :: Vector() {Vector(0, 0, 0);}

Vector :: Vector(double x, double y, double z)
{
    coords[0] = x;
    coords[1] = y;
    coords[2] = z;
}

double Vector :: operator[](int i)
{
    int k = i % 3;
    return coords[k];
}

Vector Vector :: operator()(Vector a,Vector b)
{
    for(int i = 0; i < 3; i ++)
        coords[i]=a[i+1]*b[i+2]-a[i+2]*b[i+1];

    return *this;
}

double Vector :: operator*(Vector obj)
{
    double res=0;

    for(int i=0; i < 3; i++)
        res+=coords[i]*obj[i];

    return res;
}

int PolygonalArea :: chek_point_line_segment(int k, const Point &point)
{
    double AB, AP, BP;

    if (k < len - 1)
    {
        AB = sqrt((component[k].x - component[k + 1].x) * (component[k].x - component[k + 1].x) + (component[k].y - component[k + 1].y) * (component[k].y - component[k + 1].y));
        AP = sqrt((component[k].x - point.x) * (component[k].x - point.x) + (component[k].y - point.y) * (component[k].y - point.y));
        BP = sqrt((point.x - component[k + 1].x) * (point.x - component[k + 1].x) + (point.y - component[k + 1].y) * (point.y - component[k + 1].y));
    }
    else
    {
        AB = sqrt((component[0].x - component[k].x) * (component[0].x - component[k].x) + (component[0].y - component[k].y) * (component[0].y - component[k].y));
        AP = sqrt((component[0].x - point.x) * (component[0].x - point.x) + (component[0].y - point.y) * (component[0].y - point.y));
        BP = sqrt((point.x - component[k].x) * (point.x - component[k].x) + (point.y - component[k].y) * (point.y - component[k].y));
}

    if (fabs(AB - AP - BP) < eps)
        return 1;
    else
        return 0;
}
