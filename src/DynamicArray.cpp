//
//  DynamicArray.cpp
//  CISP400 FInal
//
//  Created by Admin on 6/23/22.
//  Copyright © 2022 Admin. All rights reserved.
//

#include "DynamicArray.hpp"

// Free Memory functions
template <class T>
void DynamicArray::SAFE_DELETE(T* ptr){
    
    delete [] ptr;
    ptr = nullptr;
}

// Dynamic Array Template
template <class T>
void DynamicArray::DYN_ARRAY(T*& arrayPtr, T* dataObj, int size){
    
    if (size == 1){
        arrayPtr[0] = *dataObj;
    }
    
    else{
        T* tempArray = new T[size];
        
        for (int i{0}; i < (size - 1); i++){
            tempArray[i] = arrayPtr[i];
        }
        
        tempArray[(size - 1)] = *dataObj;
        
        SAFE_DELETE(arrayPtr);
        
        arrayPtr = tempArray;
    }
}
