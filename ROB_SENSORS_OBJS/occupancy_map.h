//
// Created by stefan on 15/08/15.
//

#ifndef PROJECT_OCCUPANCY_MAP_H
#define PROJECT_OCCUPANCY_MAP_H

#include "stdio.h"
#include "iostream"
#include "fstream"
#include "vector"
#include "string"
class Occupancy_Map{


private:

public:
    Occupancy_Map();
    FILE* open_map(const char* filename);
    void update_map(const char* filename, double x_coord, double z_coord);
};


#endif //PROJECT_OCCUPANCY_MAP_H
