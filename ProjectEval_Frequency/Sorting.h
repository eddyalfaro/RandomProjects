#ifndef Sorting_h
#define Sorting_h

namespace std{

    class Sorting{

        public:
            template<typename T>
            static void mergeSort(T* array, int from, int to, int (comparator)(T, T));

        private:
            template <typename T>
            static void merge(T* array, int from, int to, int (comparator)(T, T));
    };

    template <typename T>
    void Sorting::mergeSort(T* array, int from, int to, int (comparator)(T, T)){

        int highVal, lowVal, midVal; //array identifiers for locations to sort and midpoit
        int rangeSize; //identifies how many values are within the range

        highVal = to;
        lowVal = from;
        midVal = (to + from)/2;

        rangeSize = (to - from) + 1;

        if (rangeSize == 1){// CASE 1: only one value to be sorted
            //cout << "only one value left, index [" << midVal << "] with element member <" << array[midVal] << ">" << endl;
            return;
        } else { // Recurring case. splits the array in two until reaches case one then returns and sorts the upper and lower halfs
            mergeSort(array, lowVal, midVal, comparator);//sorts upper half
            mergeSort(array, midVal + 1, highVal, comparator);//sorts lower half
            merge(array, lowVal, highVal, comparator);//merges the sorted lower and upper halfs
        }

    }

    template <typename T>
    void Sorting::merge(T* array, int from, int to, int (comparator)(T, T)){
        int upperLow, upperHigh;
        int lowerLow, lowerHigh;
        int numOfElements;

        upperLow = from;
        upperHigh = (from + to)/2;

        lowerLow = upperHigh + 1;
        lowerHigh = to;

        numOfElements = (to - from) + 1;

        T* temp = new T[numOfElements];

        int k = 0;//counter for total elements added;
        int i = upperLow;//counter for elements in the upper half
        int j = lowerLow;//counter for elements in the lower half

        while ((i <= upperHigh) && (j <= lowerHigh)){//merging arrays: when both counters are within their ranges

                if (comparator(array[i], array[j]) > 0){//checks for the smallest value between the upper and loweer half
                    //cout << " Merging <" << (array[i]) << "> at index position " << i << endl;
                    temp[k++] = (array[j]); //add the value in the upper section
                    j++;
                } else {//checks for the smallest value between the upper and lower half
                    //cout << " Merging <" << (array[j]) << "> at index position " << j << endl;
                    temp[k++] = (array[i]);//add the value in the lower section
                    i++;
                }
        }

        while(i <= upperHigh){//if values in the lower secition have already been depleated
            temp[k++] = (array[i]); //add the value in the uppwe section
            i++;
        }

        while(j <= lowerHigh){//if the values in the upper section have already been depleated
            temp[k++] = (array[j]); //add the values in the lower section
            j++;
        }

        //cout << "MERGE METHOD - Merged Elements: " << numOfElements << endl;
        for (int i = from; i < (to + 1); i++){
            array[i] = temp[i - from];
           // cout << "{index = " << (i) << ", element = " << array[i] << '}' << '\t';
        }
        //cout << endl << endl;

        delete [] temp;
    }

}



#endif