//
// Created by stefan on 16/09/15.
//

#ifndef PROJECT_BACKPROBAGATION_H
#define PROJECT_BACKPROBAGATION_H


#include "controller.h"

class Backprobagation: public Controller {

private:
    static const int hiddenlayersize = 3;
    vector<double> inputlayer;
    vector<double> hiddenlayer;
    vector<double> outputlayer;
    double weights1[num_input+1][hiddenlayersize];
    double weights2[hiddenlayersize+1][num_output];

public:
    Backprobagation();
    /* -------------------------------------------------------------------------------------------------- */
    /*                                             VIRTUAL FUNCTIONS                                      */
    /* -------------------------------------------------------------------------------------------------- */
    void init                          ( const vector <chromosome_type> &genes );
    void step                          ( const vector <double> &input_array, vector <double> &output_array);
    void reset                         ( void );
    void compute_genotype_length       ( void );
    void read_from_file                ( void );
    int get_num_input                   (void);
    int get_num_output                  (void);
    /* -------------------------------------------------------------------------------------------------- */
    /* -------------------------------------------------------------------------------------------------- */

};


#endif //PROJECT_BACKPROBAGATION_H
