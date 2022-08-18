//
//  RobotData.cpp
//  CISP400 Final
//
//  Created by Ian Wallace on 6/23/22.
//  Copyright © 2022 Ian Wallace. All rights reserved.
//

#include <iostream>
#include "RobotData.hpp"
#include "GlobalDefs.h"

void RobotData::setFitnessScore()       { m_fitnessScore.push_back(m_accumulator); }
void RobotData::resetAccumulator()      { m_accumulator = 0; }
void RobotData::setAccumulator(int a)   { m_accumulator += a; }
int  RobotData::getRobotFitness(int i) const { return m_fitnessScore[i]; }

// Print data function
void RobotData::outputData() const {
    double average{0.0}, fitness{0.0};
    
    std::cout << "Printing Results...\n";
    std::cout << "Generation: Average Fitness Score\n";
    
    for (int i{0}; i < c_maxSimulations; i++) {
        fitness = getRobotFitness(i);
        average = fitness / c_maxRobots;
        
        if (i < 9)
            printf("0%d: %.2f\t", i + 1, average);
        
        else
            printf("%d: %.2f\t", i + 1, average);
        
        if ((i + 1) % 5 == 0) std::cout << '\n';
    }
    
    std::cout << '\n';
    
}
