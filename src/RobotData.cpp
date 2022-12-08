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

void RobotData::setFitnessScore()     { m_fitnessScoreVector.push_back(m_accumulator); }
void RobotData::resetAccumulator()    { m_accumulator = 0; }
void RobotData::setAccumulator(int a) { m_accumulator += a; }
int  RobotData::getRobotFitness(int i) const { return m_fitnessScoreVector[i]; }

/**
 *  Name: outputData
 *  Parameters: none
 *  Notes: Takes each fitness score in m_fitnessScoreVector and
 *         outputs the average by dividing the fitness against the
 *         max amount of robots. 
 */
void RobotData::outputData()
{
    double average{0.0};
    double fitnessDouble{0.0};
    int generation = 1;
    std::cout << "Printing Results...\n";
    std::cout << "Generation: Average Fitness Score\n";
    
    for (const auto& fitnessInt : m_fitnessScoreVector)
    {
        fitnessDouble = static_cast<double>(fitnessInt);
        
        //fitness = getRobotFitness(i);
        average = fitnessDouble / c_maxRobots;
        
        if (generation <= 9)
        {
            printf("0%d: %.2f\t", generation, average);
            
        } else if (generation == 100) {
            
            printf("%d:%.2f\t", generation, average);

        } else {
            
            printf("%d: %.2f\t", generation, average);
        }
        
        if ((generation) % 5 == 0) std::cout << '\n';
        generation++;
    }
    
    std::cout << '\n';
    
}
