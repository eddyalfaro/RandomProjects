/*
*Exception.h
*
*Created on: Jun 15, 2021
*     Autor: Eddy Alfaro
*   contact: eddy.cordoba@scientificdrilling.com
*   version: 0.1.1
*/
#ifndef Exception_h
#define Exception_h
#include <iostream>

namespace std{
    class Exception : exception{
        public:
            Exception();
            Exception(string msg);
            ~Exception();

            string getMsg();

            string message;
    };

    string Exception::getMsg(){
        return message;
    }

     Exception::Exception(){
        message = "Error";
    }

    Exception::Exception(string msg){
        message = msg;
    }

    Exception::~Exception(){
        message = "";
    }
    
} /* namespace std */

#endif /* EXCEPTION_H */