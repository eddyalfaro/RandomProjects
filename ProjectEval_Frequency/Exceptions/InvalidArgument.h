/*
*InvalidArgument.h
*
*Created on: Jun 25, 2021
*     Autor: Eddy Alfaro
*   contact: eddy.cordoba@scientificdrilling.com
*   version: 0.1.0
*/
#ifndef InvalidArgument_h
#define InvalidArgument_h

#include <iostream>
#include "Exception.h"

namespace std{

    class InvalidArgument : Exception{
        public:
            InvalidArgument();
            InvalidArgument(string msg);
            ~InvalidArgument();

            const string _msg = "Invalid input";
    };

    InvalidArgument::InvalidArgument():Exception(_msg){}

    InvalidArgument::InvalidArgument(string msg):Exception(msg){}

    InvalidArgument::~InvalidArgument(){
        message = "";
    }
} /* namespace std */

#endif /* FileNotFound_h */