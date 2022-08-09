//
//  DynamicArray.hpp
//  CISP400 FInal
//
//  Created by Admin on 6/23/22.
//  Copyright © 2022 Admin. All rights reserved.
//

#ifndef DynamicArray_hpp
#define DynamicArray_hpp

#include <stdio.h>

struct DynamicArray {
    template <class T>
    void SAFE_DELETE(T*);
    
    template <class T>
    void DYN_ARRAY(T*&, T*, int);
};

#endif /* DynamicArray_hpp */
