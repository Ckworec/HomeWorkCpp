#include "poligon.h"

int main(void)
{
    PolygonalArea area1;
    Point point;
    int length1, length2, command, number, cur, number2;

    srand(time(NULL));

    std :: cout << "Enter the number of areas: ";
    std :: cin >> length1;

    std :: cout << "Enter the number of point in area: ";
    std :: cin >> length2;

    PolygonalArea area(length2);

    ArrayPolygonalArea arr(area, length1);

    std :: cout << "List of commands: \n0. Exit \n1. Add a new area \n2. Delete an area \n3. Add a new point in an area \n4. Delete a point in an area \n5. Change the coordinates of points in the area \n6. Position the point \n7. Number of areas \n8. Merge of two areas \n9. Intersection of two areas \n10. List of commands" << std :: endl;

    std :: cout << "Enter the command: ";
    std :: cin >> command;

    while (command != 0)
    {
        if (command == 1)
        {
            std :: cout << "Enter the number of points: ";
            std :: cin >> length2;
            PolygonalArea area(length2);
            arr.add_area(area);
        }

        else if (command == 2)
        {
            std :: cout << "Enter the number of area: ";
            std :: cin >> number;
            arr.delete_area(number);
        }

        else if (command == 3)
        {
            std :: cout << "Enter the number of area: ";
            std :: cin >> number;
            std :: cout << "Enter coordinates x and y: ";
            std :: cin >> point.x >> point.y;
            std :: cout << "Enter position of point in area: ";
            std :: cin >> cur;
            area = arr.field[number];
            area.add_point(cur, point);
        }

        else if (command == 4)
        {
            std :: cout << "Enter the number of area: ";
            std :: cin >> number;
            std :: cout << "Enter number of point: ";
            std :: cin >> cur;
            area = arr.field[number];
            area.delete_point(cur);
        }

        else if (command == 5)
        {
            std :: cout << "Enter the number of area: ";
            std :: cin >> number;
            std :: cout << "Enter coordinates x and y: ";
            std :: cin >> point.x >> point.y;
            std :: cout << "Enter position of point in area: ";
            std :: cin >> cur;

            area = arr.field[number];
            area.coordinate_change(cur, point);
        }

        else if (command == 6)
        {
            std :: cout << "Enter the number of area: ";
            std :: cin >> number;
            std :: cout << "Enter coordinates x and y: ";
            std :: cin >> point.x >> point.y;

            area = arr.field[number];
            cur = area.position(point);

            if (cur == -1)
            {
                std :: cout << "The point lies outside the region" << std :: endl;
            }
            else if (cur == 0)
            {
                std :: cout << "The point lies on the boundary of the region" << std :: endl;
            }
            else
            {
                std :: cout << "The point lies in the region" << std :: endl;
            }
        }

        else if (command == 7)
        {
            arr.number_of_components();
        }

        else if (command == 8)
        {
            std :: cout << "Enter the number of area: ";
            std :: cin >> number;
            std :: cout << "Enter the number of area: ";
            std :: cin >> number2;
            area = arr.field[number];
            area1 = arr.field[number2];

            arr.field[std :: min(number, number2)] = area + area1;
        }

        else if (command == 9)
        {
            std :: cout << "Enter the number of area: ";
            std :: cin >> number;
            std :: cout << "Enter the number of area: ";
            std :: cin >> number2;
            area = arr.field[number];
            area1 = arr.field[number2];

            arr.field[std :: min(number, number2)] = area * area1;
        }

        else if (command == 10)
        {
            std :: cout << "List of commands: \n0. Exit \n1. Add a new area \n2. Delete an area \n3. Add a new point in an area \n4. Delete a point in an area \n5. Change the coordinates of points in the area \n6. Position the point \n7. Number of areas \n8. Merge of two areas \n9. Intersection of two areas \n10. List of commands" << std :: endl;
        }
    }

    return 0;
}
