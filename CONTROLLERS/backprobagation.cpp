//
// Created by stefan on 16/09/15.
//

#include "backprobagation.h"

Backprobagation::Backprobagation(){

}

void Backprobagation::compute_genotype_length() {
    /*Input and hiddenlayer each have a BIAS node therefor + 1 */
    genotype_length = (((num_input+1) * hiddenlayersize) + ((hiddenlayersize + 1) * num_output));
}

void Backprobagation::init(const vector<chromosome_type> &genes) {
    inputlayer.assign(num_input+1, 0.0);
    hiddenlayer.assign(hiddenlayersize+1, 0.0);
    outputlayer.assign(num_output, 0.0);

    /*initialise the input-to-hiddenlayer weights*/
    for(int i = 0;i < num_input+1;i++){
        for(int j = 0;j < hiddenlayersize;j++){
            weights1[i][j] = calc_random();
        }
    }
    /*initialise the hidden-to-outputlayer weights*/
    for(int m = 0;m < hiddenlayersize+1;m++){
        for(int n = 0;n < num_output;n++){
            weights2[m][n] = calc_random();
        }
    }
}

void Backprobagation::step(const vector<double> &input_array, vector<double> &output_array) {

    /*get inputs*/
    for(int i = 0;0 < input_array.size();i++){
        inputlayer[i] = get_value(input_array, i);
    }

    /*Set bias*/
    inputlayer[num_input] = 1.0;

    /*reset outputlayer*/
    for(int i = 0;i < outputlayer.size();i++){
        outputlayer[i] = 0.0;
    }

    /*add weights for the hiddenlayer*/
    for(int i = 0;i < hiddenlayersize;i++){
        for(int j = 0;j < num_input+1;j++){
            hiddenlayer[i] += (inputlayer[j] * (weights1[j][i]));
        }
    }

    /*calculate hiddenlayer sigmoid*/
    for(int i = 0;i < hiddenlayer.size();i++){
        hiddenlayer[i] = f_sigmoid(hiddenlayer[i]);
    }

    /*add outputlayer bias*/
    hiddenlayer[hiddenlayersize] = 1.0;

    /*add weights from hidden to output layer*/
    for(int i = 0;i < outputlayer.size();i++){
        for(int j = 0;j < hiddenlayersize+1;j++){
            outputlayer[i] += (hiddenlayer[i] * (weights2[j][i]));
        }
    }

    for(int i = 0;i < outputlayer.size();i++){
        outputlayer[i] = f_sigmoid(hiddenlayer[i]);
    }
}

void Backprobagation::reset() {

}
void Backprobagation::read_from_file(void) {
}
int Backprobagation::get_num_input ( void ){
    return num_input;
}
int Backprobagation::get_num_output ( void ){
    return num_output;
}

/*Stackoverflow. Accessed 16th september 2015
 * http://stackoverflow.com/questions/4310277/producing-random-float-from-negative-to-positive-range
 * */

double Backprobagation::calc_random() {
    return ((float(rand()) / float(RAND_MAX)) * (high_bound - low_bound)) + low_bound;
}