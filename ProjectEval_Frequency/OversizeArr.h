#include "Exceptions\InvalidArgument.h"
#include "Exceptions\EmptyArray.h"
#include "Exceptions\FullArray.h"
#include "Exceptions\OutOfBounds.h"
#include "Sorting.h"

#ifndef OversizeArr_h
#define OversizeArr_h

namespace std {

    template<class V>
    struct OverArray{
        private:
            V* index;

            static int MIN_SIZE;

        public:
            int size;
            int lenght;

            //constructors
            OverArray();//default
            OverArray(OverArray<V> &c); //copy
            OverArray(OverArray<V> *c); //copy
            OverArray(V* _array, int _lenght, int _size);//boxing
            OverArray(int _size);//initial
            //destructor
            ~OverArray();

            //returns the element in the array at index i
            V get(int i);
            //returns the last element contained within the array
            V getLast();
            //adds an element to the array
            void add(V value);
            //sets an element in the array at a specific location
            void set(V value, int at);
            //removes the element at the given index from the array, shifting the elements in front of it upwards
            void remove(int index);
            //sorts the array using the specific sorting mechanism
            void organize(int (comparator)(V _lhs, V _rhs));
            
            template<class U>
            friend ostream& operator<< (ostream& os, const OverArray<U>& arr);

            template<class U>
            friend ostream& operator<< (ostream& os, const OverArray<U>* arr);

            //returns the number of bytes that the array is using in memory
            int getBytes();
            //finds the given value within the array by checking from top to bottom
            int find(V _val);
            //returns wether the array is empty or not
            bool isEmpty();

        protected:
            //increments the size of the array when it has reached full capacity
            V* incrementSize();
    };

    template<class V>
    int OverArray<V>::MIN_SIZE = 2;
    
    template<class V>
    int OverArray<V>::getBytes(){
        return size*sizeof(V) + sizeof(size) + sizeof(lenght);
    }

    template<class V>
    void OverArray<V>::remove(int val){
        if (val > lenght) throw OutOfBounds();//checks if the given value is greater than the number of elements
        if (val < 0) throw InvalidArgument();//checks for a negative value
        if (val == lenght - 1) {lenght--; return;}//if the value to remove is the last simply reduce the leght

        for (int i = val + 1; i < lenght; i++) index[i - 1] = index[i];//shift all the values proceding the removed to the left/up
        lenght--;//reduce the value of lenght
    }

    template<class V>
    OverArray<V>::OverArray(int _size){
        size = _size;
        lenght = 0;
        index = new V[size];
    }

    template<class V>
    OverArray<V>::OverArray() : OverArray(MIN_SIZE){
    }

    
    template<class V>
    OverArray<V>::OverArray(V* _array, int _lenght, int _size) {
        lenght = _lenght;
        size = _size;
        index = new V[size];
        for (int i = 0; i < lenght; i++) index[i] = _array[i];
    }

    template<class V>
    OverArray<V>::~OverArray(){
        if (index != NULL) delete [] index;
        size = 0;
        lenght = 0;
        index = NULL;
    }

    template<class V>
    OverArray<V>::OverArray(OverArray<V> &c){
        size = c.size;
        lenght = c.lenght;

        index = new V[size];
        for (int i = 0; i <lenght; i++) {
            index[i] = c.index[i];
        }
    }

    template<class V>
    OverArray<V>::OverArray(OverArray<V>* c) : OverArray(*c){
    }

    template<class V>
    bool OverArray<V>::isEmpty(){
        return lenght == 0;
    }

    template<class V>
    int OverArray<V>::find(V val){
        for (int i = 0; i < lenght; i++){
            if (val == index[i]) return i;
        }

        return -1;
    }

    template<class V>
    void OverArray<V>::add(V value){
        if (lenght == size) index = incrementSize();//if array has reached capacity increment the size of the array
        index[lenght++] = value; // adds the value within the array
    }

    template<class V>
    void OverArray<V>::organize(int (comparator)(V _lhs, V _rhs)){
        Sorting::mergeSort(index, 0, lenght, comparator);
        remove(0);
    }

    template<class V>
    V OverArray<V>::get(int i){
        if (lenght == 0) throw EmptyArray();
        if (i > lenght) throw OutOfBounds();
        return index[i];
    }

    template<class V>
    V OverArray<V>::getLast(){
        if (lenght == 0) throw EmptyArray();
        return index[lenght - 1];
    }

    template<class V>
    void OverArray<V>::set(V value, int at){
        if (at > lenght) throw OutOfBounds();
        if (at < 0) throw InvalidArgument();//checks for a negative value
        index[at] = value;
    }

    template<class V>
    V* OverArray<V>::incrementSize(){
        int temp = 2 * size;
        if (size == 0) temp = 2;
        V* temp_Val = new V[temp];

        for (int i = 0; i < size; i++){
            temp_Val[i] = index[i];
        }

        size = temp;
        delete [] index;
        return temp_Val;
    }

    template<class V>
    ostream& operator<< (ostream& os, const OverArray<V>& arr){
        os << "[" ;

        for (int i = 0; i < arr.lenght - 1; i++){
            os << (arr.index[i]) << ", ";
        }
        
        if (arr.lenght > 0) os << arr.index[arr.lenght - 1] <<  "]" << endl;
        else os << "]" << endl;

        return os;
    }

    template<class V>
    ostream& operator<< (ostream& os, const OverArray<V>* arr){
        os << "[" ;

        for (int i = 0; i < arr->lenght - 1; i++){
            os << (arr->index[i]) << ", ";
        }

        if (arr->lenght > 0) os << arr->index[arr->lenght - 1] <<  "]" << endl;
        else os << "]" << endl;


        return os;
    }

}

#endif
