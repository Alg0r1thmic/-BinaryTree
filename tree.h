/*//////////////////////////////////////////////////////
///  *@file Node.h                                   ///
///   * @version 1.0                                 ///
///    * @date 15/06/2017                            ///
///     * @author Raul Edgar Quispe Totocayo         ///
///                                                  ///
///       * @brief this program using the libntl     ///
//////////////////////////////////////////////////////*/

#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <node.h>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <type_traits>
#include <linkedlist.h>
using namespace std;
template<typename T>

class Tree
{
public:
    Tree()
        :rootPtr(nullptr){}
    void insertNode(T val)
    {
        insertNodeHelper(&rootPtr,val);
    }
    //recorridos del arble
    void preOrderTraversal()
    {
        preOrderHelper(rootPtr);
    }
    void inOrderTraversal()
    {
        inOrderHelper(rootPtr);
    }
    void postOrderTraversal()
    {
        postOrderHelper(rootPtr);
    }
    void printNivelByNivel()
    {
        printHelper(rootPtr);
    }
    bool getVal(T & val)
    {
        getValHelper(&rootPtr,val);
    }

    friend std::ostream& operator <<(std::ostream &out,Tree<T> *tre)
    {
        Node<T> *temPtr=tre->rootPtr;
        out << temPtr->getReightPtr()->getData();

        return out;
    }
private:
    Node<T> *rootPtr;
    void insertNodeHelper(Node<T> **,T &);
    void preOrderHelper(Node<T> *);
    void inOrderHelper(Node<T> *);
    void postOrderHelper(Node<T> *);
    bool getValHelper(Node<T> **,T &);
    void printHelper(Node<T>*);

};

#endif // TREE_H
