#include <conio.h>
#include <iostream>

#include "Functions.h"

using namespace std;

void Insert(Tree& tree)
{
    system("cls");
    cout << "Enter a quantity of elements to add: ";

    unsigned int count = 0U;
    cin >> count;

    for (unsigned int i = 0U; i < count; ++i)
    {
        Node* temp = new Node;  

        cout << endl << "Enter an english word " << i + 1 << endl;
        cin >> temp->m_english;

        cout << endl << "Enter a russian word " << i + 1 << endl;
        cin >> temp->m_russian;

        tree.Insert(temp);
    }
}

void Print(const Tree& tree)
{
    system("cls");

    tree.Print(tree.GetRoot());

    _getch();
}

void PrintMenu()
{
    char menu[] = "1. Insert node\n2. Remove node\n3. Print node\n4. Search node\n5. Edit\n6. Save\n7. Exit\n";

    system("cls");

    cout << menu;
}

void Remove(Tree& tree)
{
    system("cls");
    cout << "Enter an english word to remove:" << endl;

    char buffer[15] = {};
    cin >> buffer;

    Node* node = tree.Search(tree.GetRoot(), buffer);

    tree.Remove(node);
}

void Search(const Tree& tree)
{
    system("cls");
    cout << "Enter an english word to search:" << endl;

    char buffer[15] = {};
    cin >> buffer;

    Node* node = tree.Search(tree.GetRoot(), buffer);

    if (node != nullptr)
    {
        wcout << node->GetRussian();
    }
    else
    {
        cout << "Word not found" << endl;
    }

    _getch();
}

void Edit(Tree& tree)
{
    system("cls");
    char buffer[15] = {};
    cout << "Enter an english word to edit:" << endl;
    cin >> buffer;

    Node* node = tree.Search(tree.GetRoot(), buffer);
    if (node != nullptr)
    {
        cout << "Enter a new translation:" << endl;
        cin >> node->m_russian;
    }
    else
    {
        cout << "Word not found" << endl;
    }

    _getch();
}

void STF(std::ofstream& of, const Node* node)
{
    if (node != nullptr)
    {
        STF(of, node->m_left);
        
        of.write(node->m_english.c_str(), strlen(node->m_english.c_str()) + 1);
        of.write("\t", 2);
        of.write(node->m_russian.c_str(), strlen(node->m_russian.c_str()) + 1);
        of.write("\n", 2);

        STF(of, node->m_right);
    }
}


void SaveToFile(const Tree& tree)
{

    system("cls");
    std::ofstream file;

    //std::locale mylocale("");   // get global locale
    //std::cin.imbue(mylocale);
   
    file.open("dictionary.txt");

    if (file.is_open())
    {
        STF(file, tree.GetRoot());
        file.close();

        std::cout << "Saved\n";
    }
    else
    {
        std::cout << "Cannot open the file\n";
    }
       
   
    _getch();
}
