/* Author:  your-name-here  */

#include <stdio.h>
#include <stdlib.h>
#include "petri.h"

int main(void) {
	printf("Petri...\n");
	//1.declaring array
        int dish[EDGE_LENGTH][EDGE_LENGTH] = {{1,1,0,1,1,1,0,1,1},
                                              {1,1,0,1,1,1,0,1,1},
                                               {0,0,1,1,1,0,0,0,0},
                                               {1,1,1,1,1,0,0,0,0},
                                              {1,1,1,1,1,0,0,1,1},
                                               {1,1,0,0,0,0,0,1,1},
                                               {0,0,0,1,1,1,0,1,1},
                                               {1,1,0,1,1,1,0,1,1},
                                               {1,1,0,1,1,1,0,1,1},

        };
//2. print initial
   print_petri_dish(dish);

//3. advance simulation by 1
    spread_infection(dish);

//4. print new state of dish
    print_petri_dish(dish);


}


