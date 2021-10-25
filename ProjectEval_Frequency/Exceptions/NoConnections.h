/*
*NoConnections.h
*
*Created on: Jul 16, 2021
*     Autor: Eddy Alfaro
*   contact: eddy.cordoba@scientificdrilling.com
*   version: 0.1.1
*/
#ifndef NoConnections_h
#define NoConnections_h
#include <iostream>
#include "Exception.h"

namespace std{

   class NoConnections : Exception{
    public:
        NoConnections();
        NoConnections(string msg);
        ~NoConnections();

        const string def = "lacking information";
    };

    NoConnections::NoConnections():Exception(def){}

    NoConnections::NoConnections(string msg):Exception(msg){}

    NoConnections::~NoConnections(){
        message = "";
    }

} /* namespace std */

#endif /* NoConnections_h */