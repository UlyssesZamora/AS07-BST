#include <iostream>
#include <sstream>
#include "binarySearch.h"

/*  
    Isaias Zamora
    izamora@pengo.cabrillo.edu
    Preffered email: Leezam01@gmail.com
    as07.cpp
    assingment name: Binary Search Tree, assignment number: 7
    
    The purpose of this program is to implement the binary search tree data
    structure to work with ints and handle various i/o
    
    Code status: working/tested
*/

bool isNum(const std::string &input, int &output)
{
    try
    {
        output = std::stoi(input);
        return true;
    }
    catch (...)
    {
        return false;
    }
}

int main()
{
    BinarySearch bst;
    std::string str;
    while (std::getline(std::cin, str))
    {
        std::stringstream ss(str);
        std::string keyWord, key;
        int value;
        ss >> keyWord >> key;
        if (isNum(key, value))
        {
            if (keyWord == "insert")
            {
                bst.insert(value);
            }
            else if (keyWord == "search")
            {
                bst.search(value);
            }
            else if (keyWord == "delete")
            {
                bst.remove(value);
            }
            else if (keyWord == "predecessor")
            {
                bst.predecessor(value);
            }
            else if (keyWord == "successor")
            {
                bst.successor(value);
            }
        }
        else if (keyWord == "max")
        {
            bst.max();
        }
        else if (keyWord == "min")
        {
            bst.min();
        }
        else if (keyWord == "postorder")
        {
            std::cout << "postorder traversal: \n";
            bst.postorder();
            std::cout << std::endl;
        }
        else if (keyWord == "preorder")
        {
            std::cout << "preorder traversal: \n";
            bst.preorder();
            std::cout << std::endl;
        }
        else if (keyWord == "inorder")
        {
            std::cout << "inorder traversal: \n";
            bst.inorder();
            std::cout << std::endl;
        }
    }
    return 0;
}