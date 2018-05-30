/**
 * The file contains the logic for the following signatures defined in the header file
 * Author: Alvin Nguyen
 */

#include "vector.h"

//default constructor
vector::vector() {
    array = new double [10];
    capacity = 10;
    size = 0;
}

//custom constructor
vector::vector(double data) {
    array = new double [10];
    array[0] = data;
    capacity = 10;
    size = 1;
}

//copy constructor
vector::vector(const vector& rhs) {
    
}

//destructor
vector::~vector() {
    if(array == NULL){
     return;
     deleteArray();
    }
}

//helper function
vector::deleteArray(){
    if(array != NULL){
        for(int i = 0; i < size; i--){
            array[size - 1] = NULL;
            size--;
        }
    }else{
            capacity = 0;
            size = 0;
        }
}

//Returns the maximum number of doubles that vector can store
int vector::getCapacity() {
    return capacity;
}

//Tests if vector is empty
bool vector::empty() {
    if (size == 0) {
        return true;
    } else {
        return false;
    }
}

//Inserts an element into the vector at a specific position
void vector::insert(int index, double data) {
    if (index > capacity) {
        //expand array
        double* newArray = new double [20];
        //copy old array to new array
        //for(int i = 0; i < array.size; i++){
        //newArray[i] = array[i];
        //   }
        //        //delete old array
        //        delete [] array;
        //        for(int i = 0; i < size; i++){
        //            if(i = index){
        //                newArray[index] = data;
        //                break;
        //            }else{
        //                newArray[i] = array[i];
        //            }         
        //        }
        //        for(int j = index; j < size; j++){
        //            newArray[j + 1] = array[j];
        //            }
        //shift elements in array to right
        for (int j = newArray[size - 1]; j > index; --j) {
            newArray[j] = newArray[j - 1];
        }
        newArray[index] = data;
    }

}

//Deletes element from end of the vector
void vector::popBack() {
    if (size == 0) {
        cout << "Array is empty!" << endl;
    } else {
        array[size - 1] = 0;
        size--;
    }
}

//Add element to end of the vector
void vector::pushBack(double data) {
    //if vector is full, add capacity
    if (size == capacity) {
        double* newArray = new double[20];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        //newArray[data] = newArray[size];
        delete array;
    }
    array[size] = data;
    size++;
}

//Specifies a new size of the vector
void vector::resize(int newCapacity) {
    if (newCapacity < 0) {
        cout << "Invalid input!" << endl;
    }
    if (newCapacity < size) {
        capacity = newCapacity;
        size = newCapacity;
        double* newArray = new double[newCapacity];
        for (int i = 0; i < newCapacity; i++) {
            newArray[i] = array[i];
        }
    } else {
        double* newArray = new double[newCapacity];
        for (int j = 0; j < size; j++) {
            newArray[newCapacity] = array[capacity];
        }
    }
}

int vector::getSize() {
    return size;
}

//Discards excess capacity
void vector::shrink_to_fit() {
    if (capacity > size) {
        resize(size);
    } else {
        cout << "Capacity is equal to size!" << endl;
    }
}
//helper function
void vector::printVector() const {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}

//Prints out all elements in a vector
ostream& operator<<(ostream& out, const vector& rhs) {
    rhs.printVector();
    out << endl;
    return out;
}

//Interface for user
void mainMenu() {
    vector testArray;
    int option;
    cout << "Enter values to add to vector: ";
    int value;
    for (int i = 0; i < 10; i++) {
        cin >> value;
        testArray.pushBack(value);
    }
    //User options
    cout << "Elements in array: " << testArray << endl;
    cout << "Enter option from list below: " << endl;
    cout << "0 - Get capacity of vector: " << endl;
    cout << "1 - Check if vector is empty: " << endl;
    cout << "2 - Insert element to vector" << endl;
    cout << "3 - PopBack from vector" << endl;
    cout << "4 - PushBack at end of vector" << endl;
    cout << "5 - Resize vector" << endl;
    cout << "6 - Shrink to fit: " << endl;
    cout << "7 - Operator overload: " << endl << endl;
    cin >> option;
    switch (option) {
        case 0:
            cout << "0 - Capacity of vector" << endl;
            cout << testArray.getCapacity();
            break;
        case 1:
            cout << "1 - Check if vector is empty" << endl;
            testArray.empty();
            break;
        case 2:
            cout << "2 - Insert element to vector" << endl;
            int index;
            double value;
            cout << "Enter index and value to insert to vector: " << endl;
            cin >> index >> value;
            testArray.insert(index, value);
            cout << "Element was inserted at " << index << " index with value: " << value << endl;
            cout << testArray;
            break;
        case 3:
            cout << "3 - PopBack from vector" << endl;
            testArray.popBack();
            cout << "Deleted last element from vector" << endl;
            break;
        case 4:
            cout << "4 - PushBack at end of vector" << endl;
            double temp;
            cout << "Enter value for double: " << endl;
            cin >> temp;
            testArray.pushBack(temp);
            cout << temp << " was added to end of vector" << endl;
            break;
        case 5:
            cout << "5 - Resize vector" << endl;
            int newSize;
            cout << "Enter new size of vector: " << endl;
            cin >> value;
            testArray.resize(newSize);
            cout << "Vector was resized to " << value << endl;
            break;
        case 6:
            cout << "6 - Shrink to fit: " << endl;
            cout << testArray;
            testArray.shrink_to_fit();
            cout << testArray;
            break;
        case 7:
            cout << "7 - Operator overload: " << endl;
            cout << testArray;
            break;
    }

}
