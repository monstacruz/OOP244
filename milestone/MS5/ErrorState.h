//
//  ErrorState.hpp
//  ms2
//
//  Created by mon sta cruz on 2018-07-18.
//  Copyright © 2018 mon. All rights reserved.
//

#ifndef ErrorState_hpp
#define ErrorState_hpp
#include <iostream>
using namespace std;

namespace AMA {
    
    class ErrorState{
        char * msg;
        
    public:
        
        explicit ErrorState(const char * ErrorMessage = nullptr);
        
        ErrorState(const ErrorState&) = delete;
        ErrorState& operator=(const ErrorState&) = delete;
        
        virtual ~ErrorState();
        
        //void set(const char *);
        void clear();
        bool isClear() const;
        void message(const char *);
        const char* message() const;
        friend ostream& operator<<(ostream&, const ErrorState&);
    };
}

#endif /* ErrorState_hpp */
