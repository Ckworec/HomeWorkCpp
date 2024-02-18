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
#include <fstream>
#include <exception>
#include <filesystem>
#include <cstring>
#include <ios>
#include <iomanip>
#include <chrono>
#define eps 1.e-15

typedef struct Node 
{
    std :: fstream val;
    Node* next;

    Node(std :: string name) : next(nullptr)
    {
        val.open(name, std::ios_base::app);
        val.close();
        val.open(name, std::ios_base::in | std::ios_base::out);
    }
}Node;

typedef struct List
{
    Node* first;
    Node* last;

    List() : first(nullptr), last(nullptr) {}

    bool is_empty() 
    {
        return first == nullptr;
    }

    void push_back(std :: string _val)
    {
        Node* p = new Node(_val);

        if (is_empty()) {
            first = p;
            last = p;
            return;
        }

        last -> next = p;
        last = p;
    }

    void remove_first() 
    {
        if (is_empty()) return;
        Node* p = first;
        first = p -> next;
        delete p;
    }

    void remove_last() 
    {
        if (is_empty()) 
            return;

        if (first == last) 
        {
            remove_first();
            return;
        }

        Node* p = first;

        while (p -> next != last)
            p = p -> next;
        p -> next = nullptr;
        delete last;
        last = p;
    }

    void remove(int i)
    {
        int index = 0;

        if (is_empty()) 
            return;

        if (i == 0)
        {
            remove_first();
            return;
        }

        Node* slow = first;
        Node* fast = first -> next;

        while (fast && i != index)
        {
            fast = fast -> next;
            slow = slow -> next;
            index ++;
        }

        if (!fast) 
        {
            std :: cout << "This element does not exist" << std :: endl;
            return;
        }

        slow -> next = fast -> next;
        delete fast;
    }

    Node* operator[] (const int index) 
    {
        if (is_empty()) 
            return nullptr;

        Node* p = first;

        for (int i = 0; i < index; i ++) 
        {
            p = p -> next;
            if (!p) 
                return nullptr;
        }

        return p;
    }
}List;


template <typename Type>
class Table
{
    private:
        std :: vector<Type> element_table;
    public:
        Table()
        {

        }
        Table(Type element)
        {
            element_table.push_back(element);
        }

        ~Table()
        {

        }

        int find_file(std :: string number)
        {
            for (int i = 0; i < static_cast<int>(element_table.size()); i ++) 
            {
                if (number == element_table[i].file_name)
                {
                    return i;
                }
            }

            return -1;
        }

        void push_back(Type element)
        {
            element_table.push_back(element);
        }

        void write_letter_in_file(int i, std::string letter, int size_offsets)
        {
            element_table[i].write_letter_in_file(letter, size_offsets);
        }

        int len_of_file(int i)
        {
            return element_table[i].len_of_file();
        }

        void read_part_of_file(int i, int len, int size_offsets)
        {
            element_table[i].read_part_of_file(len, size_offsets);
        }

        void copy_file(int i, int j)
        {
            element_table[i].copy_file(element_table[j]);
        }

        void rename_file(int i, std :: string new_name)
        {
            element_table[i].rename_file(new_name);
        }

        void deleted_file(List list, int j)
        {
            element_table[j].deleted_file(list);

            element_table.erase(element_table.begin() + j);
            for (int i = 0; i < static_cast<int>(element_table.size()); i ++)
            {
                element_table[i].ID = i + 1;
            }
        }

        void save_table()
        {
            std :: fstream save_file("save.txt", std::ios_base::out);

            save_file.seekg(0, std::ios::beg);

            for (int i = 0; i < static_cast<int>(element_table.size()); i ++)
            {
                save_file << element_table[i].file_name << "\n";
            }
        }

        friend std :: ostream& operator<<(std :: ostream &out, const Table& table)
        {
            for (int i = 0; i < static_cast<int>(table.element_table.size()); i ++)
            {
                out << table.element_table[i];
            }

            return out;
        }

        friend class Table_Element;
};

class Table_Element
{
    private:
        int ID;
        std :: string file_name;
        Node *file;
        std :: time_t time_create;
        std :: time_t time_last_change;

    public:
        Table_Element();
        Table_Element(int id, std :: string name, Node *f);

        ~Table_Element();

        void write_letter_in_file(std :: string letter, int size_offsets);
        int len_of_file();
        void read_part_of_file(int len, int size_offsets);
        void copy_file(Table_Element &cell);
        void rename_file(std :: string new_name);
        friend std :: ostream& operator<<(std :: ostream &out, const Table_Element& cell)
        {
            std :: cout << std :: setw(2) << cell.ID << std :: setw(20) << cell.file_name << std :: setw(60) << std::put_time(std::localtime(&cell.time_create), "%c %Z") <<  std :: setw(60) << std::put_time(std::localtime(&cell.time_last_change), "%c %Z") << std :: endl;
            return out;
        }

        void deleted_file(List list);
        friend class Table<Table_Element>;
};
