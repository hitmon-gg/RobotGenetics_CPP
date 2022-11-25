//
//  main.cpp
//  CISP400 Final
//
//  Created by Ian Wallace on 6/23/22.
//  Copyright © 2022 Ian Wallace. All rights reserved.
//

#include <iostream>
#include <memory>

#include "../include/RobotData.hpp"
#include "../include/Robot.hpp"
#include "../include/NumGen.hpp"
#include "../include/Map.hpp"
#include "../include/GlobalDefs.h"
#include "../include/MergeSort.hpp"

// Prototypes
void robotTesting(Robot[], RobotData&);
void cullAndCreate(Robot[]);
void resetRobots(Robot[]);

int main() 
{
    
    // Initialize and create array of Robots
    Robot robotArray[c_maxRobots];
    
    // Holds and processes robot fitness score data
    RobotData dataObj;
    
    // Perform Simulation
    std::cout << "Start Simulation.\n";
    std::cout << "Robots: " << c_maxRobots << '\n';
    std::cout << "Simulations: " << c_maxSimulations << '\n';

    // Simulation loop
    for (int i{0}; i < c_maxSimulations; i++) 
    {
        
        // Test Robots by running each one through a random maze
        robotTesting(robotArray, dataObj);
        
        // Add fitness Score to robot data object
        dataObj.setFitnessScore();
        
        // Segment off worst performing robots and combine best
        // performing robots to pass genes to lower half robot population
        cullAndCreate(robotArray);
        
        // Reset parent robots turns and battery states
        resetRobots(robotArray);
    }
    
    std::cout << "\nSimulation Complete!\n";
    
    // Store and output results
    dataObj.outputData();

    std::cout << "Press any key to exit.\n";
    std::cin.get();
    
    return 0;
}

void robotTesting(Robot robotArray[], RobotData& dataObj) 
{
    dataObj.resetAccumulator();
    
    // create a new map and use it to test robot, loop c_maxSimulation times for c_maxRobots robots
    for (int i{0}; i < c_maxRobots; i++) 
    {
        Map mapObj;
        
        do
        {
            robotArray[i].move(mapObj);
            
        } while (robotArray[i].getBattery() > 0);
        
        dataObj.setAccumulator(robotArray[i].getTurns() - 5);
    }
}

void cullAndCreate(Robot robotArray[]) 
{
    Robot tmp[c_maxRobots]; // Temp array for sorting algorithm

    // Merge Sort Array based on turns taken to compelete test
    msort(0, (c_maxRobots - 1), robotArray, tmp);
    
    // Cull and create new robots in bottom half of array
    for (int i{0}; i < c_halfMaxRobots; i += 2) 
    {
        if (i == 0) 
        {
            Robot newRobot1(robotArray[c_maxRobots - 1],
                            robotArray[c_maxRobots - 2], i);
            
            Robot newRobot2(robotArray[c_maxRobots - 1],
                            robotArray[c_maxRobots - 2], (i + 1));
            
            robotArray[0] = newRobot1;
            robotArray[1] = newRobot2;

        } else  {
            
            Robot newRobot1(robotArray[c_maxRobots - (i + 1)],
                            robotArray[c_maxRobots - (i + 2)], i);
            
            Robot newRobot2(robotArray[c_maxRobots - (i + 1)],
                            robotArray[c_maxRobots - (i + 2)], (i + 1));
            
            robotArray[i]     = newRobot1;
            robotArray[i + 1] = newRobot2;
        }
    }
}

void resetRobots(Robot robotArray[]) 
{

    for (int i{c_halfMaxRobots - 1}; i < c_maxRobots; i++)
    {
        NumGen numObj(0, 99);
        
        robotArray[i].resetBattery();
        robotArray[i].resetTurns();
        robotArray[i].setPosition(numObj.getRandNum());
    }
}
