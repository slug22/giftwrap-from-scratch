#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define INIT_LEN 20
#define MAX_COORD 100

float crossp(float pointAx, float pointAy, float pointBx, float pointBy, float xRef, float yRef) {
    return ((pointAx - xRef) * (pointBy - yRef) - (pointAy - yRef) * (pointBx - xRef));
}

int iter_all_but_current_pt(int reference_idx, int dots[INIT_LEN][2]) {
    int old_ref = reference_idx;
    int A_ref;
    int best_idx;
    float currBest = -100000.0;
    if (reference_idx == 0) {
        A_ref = 1;
    } else {
        A_ref = 0;
    }
    
    
    for (int i=0;i<INIT_LEN;i++) {
        if (i == reference_idx) {
            continue;
        }
        float crosspy = crossp(dots[A_ref][0], dots[A_ref][1], dots[i][0], dots[i][1], dots[old_ref][0],dots[old_ref][1]);
        //printf("\ncrosspy: %f", crosspy);        
        if (fabs(crosspy) < 1e-6) {
            continue;
        }
        if (crosspy > currBest) {
            currBest = crosspy;
            best_idx = i;
        } else {
            continue;
        }

        
    }
    return best_idx;
}
void iter_over_hull_points(int reference_idx, int dots[INIT_LEN][2], int hullpts[INIT_LEN][2], int count) {
   if (count > 1 && 
    hullpts[0][0] == dots[reference_idx][0] && 
    hullpts[0][1] == dots[reference_idx][1]) {
    return;


    } else {
        
        int new_ref_idx = iter_all_but_current_pt(reference_idx, dots);
        hullpts[count][0] = dots[new_ref_idx][0];
        hullpts[count][1] = dots[new_ref_idx][1];
        printf("\nNew Hull Points: %d, %d", hullpts[count][1], hullpts[count][0]);
        count++;
        printf("\nHull Point Count: %d", count);
        iter_over_hull_points(new_ref_idx, dots, hullpts, count);
    }
}
int main() {
    int dots[INIT_LEN][2];
    int hullpts[INIT_LEN][2];
    
    srand(time(0));
    for (int i=0; i<INIT_LEN; i++) {
        dots[i][0] = (1 + rand() % (100 - 1 + 1));
        dots[i][1] = (1 + rand() % (100 - 1 + 1));


    }
    int minVal = 10000;
    int leftmost[23];
    
    for (int i=0;i<INIT_LEN;i++) {
        if (dots[i][0] <= minVal) {
            minVal = dots[i][0];
            leftmost[0] = dots[i][0];
           
            leftmost[1] = dots[i][1];
            
            leftmost[2] = i;
        }
        
    }
    printf("Jarvis March (the shittiest one)");
    //initialize first hullpts
    hullpts[0][0] = leftmost[0];
    hullpts[0][1] = leftmost[1];
    printf("\nOG Hull Points (and lowest x val): %d, %d", hullpts[0][0], hullpts[0][1]);
    printf("\neye <3 sea");
   

    iter_over_hull_points(leftmost[2], dots, hullpts, 1);
}