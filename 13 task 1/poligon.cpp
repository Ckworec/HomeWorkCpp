#include "poligon.h"

PolygonalArea :: PolygonalArea()
{
    len = 0;

    component[0].x = 0;
    component[0].y = 0;
}

PolygonalArea :: PolygonalArea(int len)
{
    for (int i = 0; i < len; i ++)
    {
        component[i].x = rand();
        component[i].y = rand();
    }
}
        
PolygonalArea :: ~PolygonalArea()
{

}

ArrayPolygonalArea :: ArrayPolygonalArea()
{
    field[0].len = 0;
    field[0].component[0].x = 0;
    field[0].component[0].y = 0;
}

ArrayPolygonalArea :: ArrayPolygonalArea(PolygonalArea &area, int length)
{
    len = length;
    field.push_back(area);
}

ArrayPolygonalArea :: ~ArrayPolygonalArea()
{

}

ArrayPolygonalArea ArrayPolygonalArea :: add_area(PolygonalArea &area)
{
    field.push_back(area);

    return *this;
}

ArrayPolygonalArea ArrayPolygonalArea :: delete_area(int i)
{
    len --;

    for (int j = i; j < len; j ++)
    {
        field[j] = field[j + 1];
    }

    field.pop_back();

    return *this;
}

PolygonalArea& PolygonalArea :: operator=(const PolygonalArea &area)
{
    len = area.len;

    for (int i = 0; i < len; i ++)
    {
        component[i].x = area.component[i].x;
        component[i].y = area.component[i].y;
    }

    return *this;
}

PolygonalArea& PolygonalArea :: operator=(PolygonalArea &&area)
{
    len = area.len;

    component = std :: move(area.component);

    return *this;
}

PolygonalArea& PolygonalArea :: operator+(PolygonalArea &area)//объединение
{
    int flag = 0, cur, min;
    Point point, intersection;

    for (int i = 0; i < component.size(); i ++)
    {
        if (flag == 0 && area.position(component[i]) == 1)
        {
            for (int j = 0; j < area.len; j ++)
            {
                if (j == 0)
                {
                    intersection = point = intersection_point(area, i, j);
                    min = distance(component[i], point);
                    cur = j;
                }
                else
                { 
                    point = intersection_point(area, i, j);
                    if (min > distance(component[i], point))
                    {
                        min = distance(component[i], point);
                        intersection = point;
                        cur = j;
                    }
                }
            }

            this -> add_point(i, intersection);
            this -> delete_point(i + 1);
            flag = 1;
            i = cur;
        }
        else if (flag == 1 && this->position(area.component[i]) == 1)
        {
            for (int j = 0; j < len; j ++)
            {
                if (j == 0)
                {
                    intersection = point = intersection_point(*this, i, j);
                    min = distance(area.component[i], point);
                    cur = j;
                }
                else
                { 
                    point = intersection_point(*this, i, j);
                    if (min > distance(area.component[i], point))
                    {
                        min = distance(area.component[i], point);
                        intersection = point;
                        cur = j;
                    }
                }
            }

            this -> add_point(i, intersection);
            this -> delete_point(i + 1);
            flag = 0;
            i = cur;
        }
        else if (flag == 1 && this -> position(area.component[i]) == -1)
        {
            this -> add_point(i, area.component[i]);
        }
        else if (flag == 1 && this -> position(area.component[i]) == 0)
        {
            flag = 0;
            this -> add_point(point_on_a_line(area.component[i]), area.component[i]);
        }
        else if (flag == 0 && area.position(component[i]) == 0)
        {
            flag = 1;
        }
    }

    //удалить area как сделать???
    //надо как-то сделать чтобы area не было в массиве областей

    return *this;
}

PolygonalArea& PolygonalArea :: operator*(PolygonalArea &area)//пересечение
{
    PolygonalArea tmp;
    Point point, intersection;
    int counter = 0, min, cur, flag = 0;

    for (int i = 0; i < len; i ++)
    {
        if (flag == 0)
        {
            if (area.position(component[i]) == 1)
            {
                for (int j = 0; j < area.len; j ++)
                {
                    if (j == 0)
                    {
                        intersection = point = intersection_point(area, i, j);
                        min = distance(component[i], point);
                        cur = j;
                    }
                    else
                    {    
                        point = intersection_point(area, i, j);
                        if (min > distance(component[i], point))
                        {
                            min = distance(component[i], point);
                            intersection = point;
                            cur = j;
                        }
                    }
                }
            }

            tmp.add_point(counter, intersection);
            counter ++;
            tmp.add_point(counter, component[i]);
            counter ++;
            flag = 1;
        }
        else if (flag == 1)
        {
            if (area.position(component[i]) == -1)
            {
                for (int j = 0; j < area.len; j ++)
                {
                    if (j == 0)
                    {
                        intersection = point = intersection_point(area, i, j);
                        min = distance(component[i], point);
                        cur = j;
                    }
                    else
                    {    
                        point = intersection_point(area, i, j);
                        if (min > distance(component[i], point))
                        {
                            min = distance(component[i], point);
                            intersection = point;
                            cur = j;
                        }
                    }
                }
                tmp.add_point(counter, intersection);
                counter ++;
                flag = 2;
                i = cur;
            }

            if (flag == 1)
            {
                tmp.add_point(counter, component[i]);
                counter ++;
            }
        }
        else if (flag == 2)
        {
            while (this -> position(area.component[cur]) == -1)
            {
                tmp.add_point(counter, area.component[cur]);
                counter ++;
                cur ++;
            }
            break;
        }
    }

    component.clear();
    component.shrink_to_fit();

    *this = tmp;

    return *this;
}

PolygonalArea& PolygonalArea :: coordinate_change(int i, Point point)
{
    component[i] = point;

    return *this;
}

PolygonalArea& PolygonalArea :: add_point(int k, Point point)
{
    double x, y;
    Point tmp;

    len ++;
    component.push_back(point);

    for (int i = len; i > k; i --)
    {
        tmp = component[i - 1];
        component[i - 1] = component[i];
        component[i] = tmp;
    }

    return *this;
}

PolygonalArea& PolygonalArea :: delete_point(int i)
{
    len --;

    for (int j = i; j < len; j ++)
    {
        component[j] = component[j + 1];
    }

    component.pop_back();

    return *this;
}

int PolygonalArea :: position(const Point &point)// https://ru.stackoverflow.com/questions/464787/%D0%A2%D0%BE%D1%87%D0%BA%D0%B0-%D0%B2%D0%BD%D1%83%D1%82%D1%80%D0%B8-%D0%BC%D0%BD%D0%BE%D0%B3%D0%BE%D1%83%D0%B3%D0%BE%D0%BB%D1%8C%D0%BD%D0%B8%D0%BA%D0%B0
{
    bool result = false;
    int j = len - 1;
    for (int i = 0; i < len; i++)
    {
        if ((component[i].y < point.y && component[j].y >= point.y || component[j].y < point.y && component[i].y >= point.y) &&
             (component[i].x + (point.y - component[i].y) / (component[j].y - component[i].y) * (component[j].x - component[i].x) < point.x))
            result = !result;
        j = i;
    }

    if (result == false)
    {
        //std :: cout << "The point lies outside the region" << std :: endl;
        return -1;
    }
    else
    {
        for (int i = 0; i < len - 1; i ++)
        {
            j = i + 1;

            if ((point.x - component[i].x) * (component[j].y - component[i].y) == (component[j].x - component[i].x) * (point.y - component[i].y))
            {
                if (std :: min(component[i].y, component[j].y) <= point.y && std :: max(component[i].y, component[j].y) >= point.y &&
                 std :: min(component[i].x, component[j].x) <= point.x && std :: max(component[i].x, component[j].x) >= point.x)
                {
                    //std :: cout << "The point lies on the boundary of the region" << std :: endl;
                    return 0;
                }
            }

            //std :: cout << "The point lies in the region" << std :: endl;
        }
    }

    return 1;
}

Point PolygonalArea :: intersection_point(const PolygonalArea &area, int k1, int k2)//проверить формулы
{
    double a1, a2, b1, b2, x, y;

    a1 = (component[k1 - 1].y - component[k1].y) / (component[k1 - 1].x - component[k1].x);
    b1 = component[k1].y - component[k1].x * a1;

    a2 = (area.component[k2].y - area.component[k2 - 1].y) / (area.component[k2].x - area.component[k2 - 1].x);
    b2 = area.component[k2 - 1].y - area.component[k2 - 1].x * a1;

    x = (b2 - b1) / (a1 - a2);
    y = a1 * x + b1;

    return Point(x, y);
}

void ArrayPolygonalArea :: number_of_components()
{
    std :: cout << "Number of components: " << field.size() << std :: endl;   
}

int distance(Point k1, Point k2)
{
    double lenght;

    lenght = sqrt((k1.x - k2.x) * (k1.x - k2.x) + (k1.y - k2.y) * (k1.y - k2.y));

    return lenght;
}

int PolygonalArea :: point_on_a_line(const Point &point)
{
    for (int i = 0; i < len; i ++)
    {
        bool colinear = ((component[i].x - component[i + 1].x) * (point.y - component[i + 1].y) == (component[i].y - component[i + 1].y) * 
        (point.x - component[i + 1].x));

        if(colinear)
        {
            return i;
        }
    }
}