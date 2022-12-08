//
//  Robot.hpp
//  CISP400 Final
//
//  Created by Ian Wallace on 6/23/22.
//  Copyright © 2022 Ian Wallace. All rights reserved.
//

#ifndef Robot_hpp
#define Robot_hpp

#include <stdio.h>
#include "Map.hpp"
#include "DNA.hpp"
#include "GlobalDefs.h"

class Robot 
{
    int m_position;
    int m_battery;
    int m_turns;
    int m_sensor[4]; // Element 0 N, 1 S, 2 E, 3 W... 0 = empty, 1 = wall, 2 = battery
    DNA m_genes[c_numOfGenes];
    
    void addPower(); // adds additional battery power per battery eaten
    
public:
    // Constructors
    Robot(); // Initialization
    Robot(const Robot&, const Robot&, const int); // Baby Robot Constructor
    
    void senseArea(const Map);
    void move(Map&);
    Robot& operator=(const Robot &right);
    
    // Setters
    void resetBattery();
    void resetTurns();
    void setPosition(int);
    
    // Getters
    [[nodiscard]] int getBattery() const;
    [[nodiscard]] int getTurns() const;
    [[nodiscard]] int getPosition() const;
    [[nodiscard]] int getProteins(int i, int j) const;
};

#endif /* Robot_hpp */
