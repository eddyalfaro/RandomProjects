/*
*EmptyArray.h
*
*Created on: Jun 30, 2021
*     Autor: Eddy Alfaro
*   contact: eddy.cordoba@scientificdrilling.com
*   version: 0.1.1
*/
#ifndef EmptyArray_h
#define EmptyArray_h

#include <iostream>
#include "Exception.h"

namespace std{

    class EmptyArray : Exception{
        public:
            EmptyArray();
            EmptyArray(string msg);
            ~EmptyArray();

            const string _msg = "Array empty";
    };

    EmptyArray::EmptyArray():Exception(_msg){}

    EmptyArray::EmptyArray(string msg):Exception(msg){}

    EmptyArray::~EmptyArray(){
        message = "";
    }
} /* namespace std */

#endif /* FileNotFound_h */