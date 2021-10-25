/*
*NullPointer.h
*
*Created on: Jun 18, 2021
*     Autor: Eddy Alfaro
*   contact: eddy.cordoba@scientificdrilling.com
*   version: 0.1.0
*/
#ifndef NullPointer_h
#define NullPointer_h

#include <iostream>
#include "Exception.h"

namespace std{

    class NullPointer : Exception{
        public:
            NullPointer();
            NullPointer(string msg);
            ~NullPointer();

            const string _msg = "null pointer";
    };

    NullPointer::NullPointer():Exception(_msg){}

    NullPointer::NullPointer(string msg):Exception(msg){}

    NullPointer::~NullPointer(){
        message = "";
    }
} /* namespace std */

#endif /* NullPointer_h */