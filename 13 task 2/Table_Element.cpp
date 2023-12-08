#include "header.hpp"

Table_Element :: Table_Element()
{
    ID = 0;
    file_name = "";
}

Table_Element :: Table_Element(int id, std :: string name, Node *f)
{
    auto now = std::chrono::system_clock::now();
    ID = id;
    file_name = name;
    file = f;
    time_create = std :: chrono :: system_clock :: to_time_t(now);
    time_last_change = std :: chrono :: system_clock :: to_time_t(now);
}

Table_Element :: ~Table_Element()
{

}

int Table_Element :: len_of_file()
{
    int i;
//    std :: fstream &file1 = file -> val;

    file -> val.seekg(0, std :: ios :: end);

    i = file -> val.tellg();

    file -> val.seekg(0, std :: ios :: beg);

    return i;
}

void Table_Element :: read_part_of_file(int len, int size_offsets)
{
//    std :: fstream &file1 = file -> val;
    char var;
    int i = 0;

    file -> val.seekg(size_offsets, std :: ios_base :: beg);

    while (file -> val >> var && i < len)
    {
        std :: cout << var;
        i ++;
    }

    std :: cout << std :: endl;
    file->val.close();
    file->val.open(file_name, std::ios_base::in | std::ios_base::out);
    (file -> val).seekp(0, std :: ios_base :: beg);
}

void Table_Element :: write_letter_in_file(std :: string letter, int size_offsets)
{
//    file -> val << "hfghg";

//    std :: cout << "--2--\n" << std::endl;
    auto now = std::chrono::system_clock::now();

    (file -> val).seekp(size_offsets, std :: ios_base :: beg);

    file -> val << letter;

    time_last_change = std :: chrono :: system_clock :: to_time_t(now);

    file->val.close();
    file->val.open(file_name, std::ios_base::in | std::ios_base::out);
    (file -> val).seekp(0, std :: ios_base :: beg);
}

void Table_Element :: copy_file(Table_Element &cell)
{
    auto now = std::chrono::system_clock::now();
    std :: string str;

    while (std :: getline(file -> val,str))
    {
        cell.file -> val << str << '\n';
    }

    cell.time_last_change = std :: chrono :: system_clock :: to_time_t(now);

    file->val.close();
    file->val.open(file_name, std::ios_base::in | std::ios_base::out);
    file -> val.seekp(0, std :: ios :: beg);
    cell.file->val.close();
    cell.file->val.open(cell.file_name, std::ios_base::in | std::ios_base::out);
    cell.file -> val.seekp(0, std :: ios :: beg);
}

void Table_Element :: rename_file(std :: string new_name)
{
    auto now = std::chrono::system_clock::now();

    rename(this -> file_name.c_str(), new_name.c_str());
    this -> file_name = new_name;
    time_last_change = std :: chrono :: system_clock :: to_time_t(now);
}

void Table_Element :: deleted_file(List list)
{
    remove(this -> file_name.c_str());
    list.remove(ID - 1);
}
