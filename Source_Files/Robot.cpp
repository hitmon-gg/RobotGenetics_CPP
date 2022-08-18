//
//  Robot.cpp
//  CISP400 Final
//
//  Created by Ian Wallace on 6/23/22.
//  Copyright © 2022 Ian Wallace. All rights reserved.
//

#include "Robot.hpp"
#include "DNA.hpp"
#include "NumGen.hpp"
#include "GlobalDefs.h"

// No-Arg Constructor
Robot::Robot() {
    NumGen numObj(0, 99);
    
    m_position = numObj.getRandNum();
    m_battery  = 5;
    m_turns    = 0;
    
    for (int i{0}; i < c_numOfGenes; i++)
        m_genes[i] = DNA();
}


// Constructor for baby robots
Robot::Robot(Robot* parent1, Robot* parent2, int counter) {
    NumGen numObj(0, 99);
    
    m_position = numObj.getRandNum();
    m_battery  = 5;
    m_turns    = 0;
    
    // Else combine genes from 2 robots into two new robots
    // Child 1
    if (counter % 2 == 0) {
        for (int i{0}; i < (c_numOfGenes / 2); i++)
            m_genes[i] = parent1 -> m_genes[i];
        
        for (int i{c_numOfGenes / 2}; i < c_numOfGenes; i++)
            m_genes[i] = parent2 -> m_genes[i];
    }
    
    //Child 2
    else {
        for (int i{0}; i < (c_numOfGenes / 2); i++)
            m_genes[i] = parent2 -> m_genes[i];
        
        for (int i{c_numOfGenes / 2}; i < c_numOfGenes; i++)
            m_genes[i] = parent1 -> m_genes[i];
    }
    
    // If mutation, swap genes around by 1;
    if (numObj.getRandNum() < 5) {
        DNA tempGene;
        tempGene = m_genes[0];
        
        for (int i{0}; i < 14; i++)
            m_genes[i] = m_genes[i + 1];
        
        m_genes[15] = tempGene;
    }
}

// Robot map traversing sensors
void Robot::senseArea(Map* const mapPtr) {
    
    // calibrate sensor
    for (int i{0}; i < 4; i++)
        m_sensor[i] = 0;
    
    // check for walls true = 1, batteries true = 2, else 0 = empty
    // North
    if (m_position - 10 < 0) // N
        m_sensor[0] = 1;
    
    else if (mapPtr -> m_batteryArray[m_position - 10] == 'b')
        m_sensor[0] = 2;
    
    // South
    if (m_position + 10 > 99)
        m_sensor[1] = 1;
    
    else if (mapPtr -> m_batteryArray[m_position + 10] == 'b')
        m_sensor[1] = 2;
    
    // East
    if ((m_position + 1) % 10 == 0 || m_position == 9)
        m_sensor[2] = 1;
    
    else if (mapPtr -> m_batteryArray[m_position + 1] == 'b')
        m_sensor[2] = 2;
    
    // West
    if (m_position % 10 == 0 || m_position == 0)
        m_sensor[3] = 1;
    
    else if (mapPtr -> m_batteryArray[m_position - 1] == 'b')
        m_sensor[3] = 2;
}

// Robot move logic
void Robot::move(Map* const mapPtr) {
    int geneMatch{0};
    int newPosition{m_position};
    int direction{0};
    
    m_turns++;
    senseArea(mapPtr);
    
    // check genes
    for (int i{0}; i < c_numOfGenes; i++) {
        geneMatch = 0;
        
        for (int j{0}; j < (c_numOfProteins - 1); j++) {
            if (m_genes[i].m_proteins[j] == m_sensor[j] || m_genes[i].m_proteins[j] == 3) // 3 don't care
                geneMatch++;
        }
        
        if (geneMatch == 4) {
            direction = m_genes[i].m_proteins[4];
            break;
        }
        
        if (i == 15)
            direction = m_genes[i].m_proteins[4];
    }
    
    if (direction == 4) {
        NumGen numObj(0, 3);
        direction = numObj.getRandNum();
    }
    
    // move position
    // N = - 10,
    else if (direction == 0) {
        if (m_sensor[0] != 1)
            newPosition = m_position - 10;
    }
    
    //S = + 10
    else if (direction == 1) {
        if (m_sensor[1] != 1)
            newPosition = m_position + 10;
    }
    
    //E = + 1
    else if (direction == 2) {
        if (m_sensor[2] != 1)
            newPosition = m_position + 1;
    }
    
    //W = - 1
    else if (direction == 3) {
        if (m_sensor[3] != 1)
            newPosition = m_position - 1;
    }
    
    m_position = newPosition;
    
    if (mapPtr -> m_batteryArray[m_position] != 'b')
        m_battery--;
    
    else {
        mapPtr -> m_batteryArray[m_position] = 'o';
        addPower();
    }
}

Robot& Robot::operator=(const Robot &right) {
    
    if (this != &right) {
        m_position = right.getPosition();
        m_battery = right.getBattery();
        m_turns = right.getTurns();
        
        for (int i{0}; i < c_numOfGenes; i++) {
            for (int j{0}; j < c_numOfProteins; j++) {
                m_genes[i].m_proteins[j] = right.getProteins(i, j);
            }
        }
    }
    
    return *this;
}

// Setters
void Robot::addPower()         { m_battery += 5; }
void Robot::resetBattery()     { m_battery = 5; }
void Robot::resetTurns()       { m_turns = 0; }
void Robot::setPosition(int p) { m_position = p; } 

// Getters
int Robot::getBattery()  const { return m_battery; }
int Robot::getTurns()    const { return m_turns; }
int Robot::getPosition() const { return m_position; }
int Robot::getProteins(int i, int j) const { return m_genes[i].m_proteins[j]; }


