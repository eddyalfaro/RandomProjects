/*
*FullArray.h
*
*Created on: Jul 7, 2021
*     Autor: Eddy Alfaro
*   contact: eddy.cordoba@scientificdrilling.com
*   version: 0.1.1
*/
#ifndef FullArray_h
#define FullArray_h

#include <iostream>
#include "Exception.h"

namespace std{

    class FullArray : Exception{
        public:
            FullArray();
            FullArray(string msg);
            ~FullArray();

            const string _msg = "File Not Found";
    };

    FullArray::FullArray():Exception(_msg){}

    FullArray::FullArray(string msg):Exception(msg){}

    FullArray::~FullArray(){
        message = "";
    }
} /* namespace std */

#endif /* FullArray_h */