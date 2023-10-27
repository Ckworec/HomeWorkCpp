#include "header.h"

int PolygonalArea :: position(const Point &point)// https://ru.stackoverflow.com/questions/464787/%D0%A2%D0%BE%D1%87%D0%BA%D0%B0-%D0%B2%D0%BD%D1%83%D1%82%D1%80%D0%B8-%D0%BC%D0%BD%D0%BE%D0%B3%D0%BE%D1%83%D0%B3%D0%BE%D0%BB%D1%8C%D0%BD%D0%B8%D0%BA%D0%B0
{
    bool result = false;
    int j = len - 1;

    for (int i = 0; i < len; i++)
    {
        if (((component[i].y < point.y && component[j].y >= point.y) || (component[j].y < point.y && component[i].y >= point.y)) &&
             (component[i].x + (point.y - component[i].y) / (component[j].y - component[i].y) * (component[j].x - component[i].x) < point.x))
            result = !result;
        j = i;
    }

    for (int i = 0; i < len - 1; i ++)
    {
        j = i + 1;

        if (fabs((point.x - component[i].x) * (component[j].y - component[i].y) - (component[j].x - component[i].x) * (point.y - component[i].y)) < eps)
        {
            if (std :: min(component[i].y, component[j].y) <= point.y && std :: max(component[i].y, component[j].y) >= point.y &&
             std :: min(component[i].x, component[j].x) <= point.x && std :: max(component[i].x, component[j].x) >= point.x)
            {
                std :: cout << "The point lies on the boundary of the region" << std :: endl;
                return 0;
            }
        }
    }

    if (result == false)
    {
        std :: cout << "The point lies outside the region" << std :: endl;
        return -1;
    }

    std :: cout << "The point lies in the region" << std :: endl;

    return 1;
}

int PolygonalArea :: position1(const Point &point)
{
    double sum_angle = 0, phi1;

    for (int i = 0; i < len; i ++)
    {
        if (i < len - 1)
        {
            Vector vector3, vector1(component[i].x - point.x, component[i].y - point.y, 0), vector2(component[i + 1].x - point.x, component[i + 1].y - point.y, 0);

            phi1 = acos((vector1 * vector2) / (sqrt((component[i].x - point.x) * (component[i].x - point.x) + (component[i].y - point.y) * (component[i].y - point.y)) * sqrt((component[i + 1].x - point.x) * (component[i + 1].x - point.x) + (component[i + 1].y - point.y) * (component[i + 1].y - point.y))));

            if (fabs(cos(phi1)) < eps)
            {
                std :: cout << "The point lies on the boundary of the region" << std :: endl;
                return 0;
            }

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

            phi1 = acos((vector1 * vector2) / (sqrt((component[i].x - point.x) * (component[i].x - point.x) + (component[i].y - point.y) * (component[i].y - point.y)) * sqrt((component[0].x - point.x) * (component[0].x - point.x) + (component[0].y - point.y) * (component[0].y - point.y))));

            if (fabs(cos(phi1)) < eps)
            {
                std :: cout << "The point lies on the boundary of the region" << std :: endl;
                return 0;
            }

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
    len = length;

    for (int i = 0; i < len; i ++)
    {
        component.push_back(Point(rand() % 50, rand() % 50));
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

std :: ostream& operator<<(std :: ostream &out, const PolygonalArea& area) // задаем оператор для вывода
{
    for (int i = 0; i < area.len; i ++)
    {
	    out << "(" << area.component[i].x << ", " << area.component[i].y << ") ";
    }

	return out;
}

Vector :: Vector() {Vector(0, 0, 0);}

Vector :: Vector(int x, int y, int z)
{
            coords[0] = x;
            coords[1] = y;
            coords[2] = z;
        }

        double Vector :: operator[](int i)
        {
            int k=i % 3;
            return coords[k];
        }

        Vector Vector :: operator()(Vector a,Vector b)
        {
            for(int i=0; i < 3; i++)
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
