/*
*FileNotFound.h
*
*Created on: Jun 15, 2021
*     Autor: Eddy Alfaro
*   contact: eddy.cordoba@scientificdrilling.com
*   version: 0.1.1
*/
#ifndef FileNotFound_h
#define FileNotFound_h

#include <iostream>
#include "Exception.h"

namespace std{

    class FileNotFound : Exception{
        public:
            FileNotFound();
            FileNotFound(string msg);
            ~FileNotFound();

            const string _msg = "File Not Found";
    };

    FileNotFound::FileNotFound():Exception(_msg){}

    FileNotFound::FileNotFound(string msg):Exception(msg){}

    FileNotFound::~FileNotFound(){
        message = "";
    }
} /* namespace std */

#endif /* FileNotFound_h */