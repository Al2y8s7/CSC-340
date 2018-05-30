#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;


/**
 * The following signatures below do not contain any logic
 */

//Vector ADT class & its member function

class vector{
private:
    double* array;
    int capacity;
    int size;
public:
    //default constructor
    vector();
    //custom constructor
    vector(double data);
    //copy constructor
    vector(const vector& rhs);
    //destructor
    ~vector();
    deleteArray();
    //class behavior
    int getCapacity();
    bool empty();
    void insert(int index, double data);
    void popBack();
    void pushBack(double data);
    int getSize();
    void resize(int newCapacity);
    void shrink_to_fit();
    void printVector() const; 
    friend ostream& operator <<(ostream& out,const vector& rhs); 
};
   //operator over loader
   
   void mainMenu();
#endif /* VECTOR_H */

