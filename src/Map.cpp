//
//  Map.cpp
//  CISP400 FInal
//
//  Created by Admin on 6/23/22.
//  Copyright © 2022 Admin. All rights reserved.
//

#include "Map.hpp"
#include "NumGen.hpp"

Map::Map() {
    NumGen numObj;
    const int SIZE{100};
    const int MAX_BATTERIES{40};
    int space{0};
    int counter{0};
    
    // Create Battery Array
    for (int i{0}; i < SIZE; i++)
        m_batteryArray[i] = 'o';
    
    // Place 40 batteries randomly
    do{
        numObj.setRandNum(0, 99);
        space = numObj.getRandNum();
        
        if (m_batteryArray[space] == 'o'){
            m_batteryArray[space] = 'b';
            counter++;
        }
        
    } while (counter < MAX_BATTERIES);
}