
/**
 * Uses radians. 
 */

#include <iostream>
#include <math.h>
#include <iomanip>

int main(int argc, char **argv) {
    int M_slices;
    int N_rings;
    double R;
    int a_x;
    int a_y;
    int b_x;
    int b_y;

    std::cin >> M_slices >> N_rings >> R;
    std::cin >> a_x >> a_y >> b_x >> b_y;

    double distance = 0.0;
    double temp_dist = 0.0;
    if (a_y > b_y) {
        distance += (a_y - b_y) * R / N_rings;  // traverse to the inside
        distance += M_PI / M_slices * abs(a_x - b_x) * R / N_rings * b_y;  // travel around canal arc
        temp_dist += (R / N_rings * a_y) + (R / N_rings * b_y); 
        if (temp_dist < distance) {
            distance = temp_dist;
        }
    } 
    else if (b_y > a_y) {
        // traverse arc before going to the outside
        distance += (b_y - a_y) * R / N_rings;
        distance += M_PI / M_slices * abs(a_x - b_x) * R / N_rings * a_y;
        temp_dist += (R / N_rings * a_y) + (R / N_rings * b_y); 
        if (temp_dist < distance) {
            distance = temp_dist;
        }
    } 
    else {
        // if endpoint is on the same canal only need to tranverse the arc
        // OR go to centre (all the way inside to 'origin') and travel via streets only
        distance += abs(a_x - b_x) * M_PI / M_slices * R / N_rings * b_y; 
        temp_dist += R / N_rings * b_y * 2;
        if (temp_dist < distance) {
            distance = temp_dist;
        }
    }

    std::cout << std::fixed << std::setprecision(14);
    std::cout << distance << std::endl;
    
    return 0;
}