//
//  Map.cpp
//  CISP400 Final
//
//  Created by Ian Wallace on 6/23/22.
//  Copyright © 2022 Ian Wallace. All rights reserved.
//

#include "Map.hpp"
#include "NumGen.hpp"

/**
 *  Function: Map()
 *  Parameters: none
 *  Notes: No-arg Constructor for 10 x 10 map grid generation.
 *         Uses an int array of batteries (either empty = 'o' or full = 'b')
 *         for the robots to traverse. Exactly 40 batteries will be randomly
 *         placed in each array. 
 */
Map::Map() 
{
    const int SIZE{100};
    const int MAX_BATTERIES{40};
    int space{0};
    int counter{0};
    
    // Create Battery Array
    for (int i{ 0 }; i < SIZE; i++)
    {
        m_batteryArray[i] = 'o';
    }

    // Place 40 batteries randomly
    do 
    {
        NumGen numObj(0, 99);
        space = numObj.getRandNum();
        
        if (m_batteryArray[space] == 'o') 
        {
            m_batteryArray[space] = 'b';
            counter++;
        }
        
    } while (counter < MAX_BATTERIES);
}
