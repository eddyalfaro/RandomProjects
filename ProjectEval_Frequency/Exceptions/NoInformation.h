/*
*NoInformation.h
*
*Created on: Jun 23, 2021
*     Autor: Eddy Alfaro
*   contact: eddy.cordoba@scientificdrilling.com
*   version: 0.1.1
*/
#ifndef NoInformation_h
#define NoInformation_h
#include <iostream>
#include "Exception.h"

namespace std{

   class NoInformation : Exception{
    public:
        NoInformation();
        NoInformation(string msg);
        ~NoInformation();

        const string def = "lacking information";
    };

    NoInformation::NoInformation():Exception(def){}

    NoInformation::NoInformation(string msg):Exception(msg){}

    NoInformation::~NoInformation(){
        message = "";
    }

} /* namespace std */

#endif /* NoInformation_h */