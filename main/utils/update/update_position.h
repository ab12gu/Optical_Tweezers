
//--------------------------------  idleFunc  ----------------------------------
// runs in background... allows changes per frame 

void update_func(float (&my_array)[2][9]){
    // add the rotation change to the previous rotation position

    int elems = sizeof my_array / sizeof my_array[0];

    for (int elem = 0; elem < elems; elem++) {
        for (int coord =0; coord < 3; coord++) {
                my_array[elem][3+coord] += my_array[elem][6+coord];
        }
    }
}

void idleFunc (void)
{
    update_func(obs);
    update_func(beads);

    glutPostRedisplay(); // just update here…
}