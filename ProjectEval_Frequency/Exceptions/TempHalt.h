/*
*TempHalt.h
*
*Created on: Jul 02, 2021
*     Autor: Eddy Alfaro
*   contact: eddy.cordoba@scientificdrilling.com
*   version: 0.1.0
*/
#ifndef TempHalt_h
#define TempHalt_h

#include <iostream>
#include "Exception.h"

namespace std{

    class TempHalt : Exception{
        public:
            TempHalt();
            TempHalt(string msg);
            ~TempHalt();

            const string _msg = "Invalid input";
    };

    TempHalt::TempHalt():Exception(_msg){}

    TempHalt::TempHalt(string msg):Exception(msg){}

    TempHalt::~TempHalt(){
        message = "";
    }
} /* namespace std */

#endif /* FileNotFound_h */