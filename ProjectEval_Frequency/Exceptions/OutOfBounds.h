/*
*OutOfBounds.h
*
*Created on: Jun 15, 2021
*     Autor: Eddy Alfaro
*   contact: eddy.cordoba@scientificdrilling.com
*   version: 0.1.1
*/
#ifndef OutOfBounds_h
#define OutOfBounds_h
#include <iostream>
#include "Exception.h"

namespace std{

   class OutOfBounds : Exception{
    public:
        OutOfBounds();
        OutOfBounds(string msg);
        ~OutOfBounds();

        const string def = "index out of bounds";
    };

    OutOfBounds::OutOfBounds():Exception(def){}

    OutOfBounds::OutOfBounds(string msg):Exception(msg){}

    OutOfBounds::~OutOfBounds(){
        message = "";
    }

} /* namespace std */

#endif /* OutOfBounds_h */