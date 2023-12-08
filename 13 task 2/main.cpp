#include "header.hpp"

int main(void)
{
    List FAT;
    Table<Table_Element> table;
    int command, number, number1, id = 1, size_off;
    std :: string namef1, namef2, letter, Cyberpunk;
    std :: fstream save("save.txt", std::ios_base::in);

    while (std :: getline(save, Cyberpunk)) 
    {
        FAT.push_back(Cyberpunk);
        table.push_back(Table_Element(id, Cyberpunk, FAT[id - 1]));
        id ++;
    }

    save.close();

    std :: cout << "List of commands: \n1. Create new file \n2. Delete file \n3. Copy file \n4. List of files\n5. Len of file \n6. Write in file a certain number of bytes at a specified offset from the beginning of the file \n7. Rename file \n8. Read file a certain number of bytes at a specified offset from the beginning of the file \n9. List of commands \n0. Exit" << std :: endl;

    std :: cout << "Enter the number of commands: ";
    std :: cin >> command;

    while (command != 0)
    {
        if (command == 1)
        {
            std :: string name;
            std :: cout << "Enter the name of file: ";
            std :: cin >> name;
            FAT.push_back(name);
            table.push_back(Table_Element(id, name, FAT[id - 1]));
            id ++;
        }
        else if (command == 2)
        {
            std :: cout << "Enter the number of the file to be deleted: ";
            std :: cin >> namef1;

            if (table.find_file(namef1) == -1)
            {
                std :: cout << "There is no such file" << std :: endl;
            }
            else
            {
                number = table.find_file(namef1);

                table.deleted_file(FAT, number);

                id --;
            }
        }
        else if (command == 3)
        {
            std :: cout << "Enter the number of file where copy and to copy: ";
            std :: cin >> namef1;
            std :: cin >> namef2;

            number = table.find_file(namef1);

            if (number == -1)
            {
                std :: cout << "There is no such file1" << std :: endl;
            }
            else
            {
                number1 = table.find_file(namef2);
                if (number1 == -1)
                {
                    std :: cout << "There is no such file2" << std :: endl;
                }
                else
                {
                    table.copy_file(number, number1);
                }
            }
        }
        else if (command == 4)
        {
            std :: cout << std :: setw(2) << "ID" << std :: setw(20) << "File name" << std :: setw(60) << "Create time" << std :: setw(60) << "Last change" << std :: endl;
            std :: cout << table;
        }
        else if (command == 5)
        {
            std :: cout << "Enter the number of file: ";
            std :: cin >> namef1;

            number = table.find_file(namef1);

            if (number == -1)
            {
                std :: cout << "There is no such file1" << std :: endl;
            }
            else
            {
                std :: cout << "The size of file is " << table.len_of_file(number) << std :: endl;
            }
        }
        else if (command == 6)
        {
            std :: cout << "Enter the number of file: ";
            std :: cin >> namef1;

            number = table.find_file(namef1);

            if (number == -1)
            {
                std :: cout << "There is no such file1" << std :: endl;
            }
            else
            {
                std :: cout << "Enter the letter: ";
                std :: cin >> letter;
                std :: cout << "Enter the size offsets: ";
                std :: cin >> size_off;
                table.write_letter_in_file(number, letter, size_off);
            }
        }
        else if (command == 7)
        {
            std :: cout << "Enter the number of the file to be renamed: ";
            std :: cin >> namef1;

            number = table.find_file(namef1);

            if (number == -1)
            {
                std :: cout << "There is no such file1" << std :: endl;
            }
            else
            {
                std :: cout << "Enter new name file: ";
                std :: cin >> namef1;
                table.rename_file(number, namef1);
            }
        }
        else if (command == 8)
        {
            std :: cout << "Enter the number of the file to be read: ";
            std :: cin >> namef1;

            number = table.find_file(namef1);

            if (number == -1)
            {
                std :: cout << "There is no such file1" << std :: endl;
            }
            else
            {
                std :: cout << "Enter len read letter: ";
                std :: cin >> number1;
                std :: cout << "Enter the size offsets: ";
                std :: cin >> size_off;
                table.read_part_of_file(number, number1, size_off);
            }
        }
        else if (command == 9)
        {
            std :: cout << "List of commands: \n1. Create new file \n2. Delete file \n3.Copy file \n4. List of files\n 5. Len of file \n 6. Write in file a certain number of bytes at a specified offset from the beginning of the file \n7. Rename file \n8. Read file a certain number of bytes at a specified offset from the beginning of the file \n9. List of commands \n0. Exit\n" << std :: endl;
        }

        std :: cout << "Enter the number of commands: ";
        std :: cin >> command;
    }

    table.save_table();

    for (int i = 0; i < id; i ++)
    {
        FAT.remove_first();
    }

    return 0;
}
