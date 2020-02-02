// title: global_variables.h
// date: 4/5/19
// by: Abhay Gupta
// 
// description: place all variables

// declare beads and obstacles
// x_y_z coordinates, x_y_z rotated position, x_y_z rotation rate
const int vec_len = 9;
float beads[][vec_len] = { //red
                {3,3,3,   1,2,3,  0.01,0,0}, 
                {5,3,5,   1,2,3,  0.5,0,0} 
                };

float obs[][vec_len] =   { //blue
                {1.5,5,3,   1,2,3,  0.01,0,0}, 
                {4,3,5,    1,2,3,  0.3,0,0} 
                };

