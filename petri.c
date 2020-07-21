/* Author: your-name-here  */

#include <stdio.h>
#include <stdlib.h>

#include "petri.h"

void print_petri_dish(int dish[][EDGE_LENGTH]) {
	//yours... a vous
	for(int i = 0; i < EDGE_LENGTH; i++){
	    for(int j = 0; j < EDGE_LENGTH; j++){
	        printf(" %d ",dish[i][j]);
	    }
	    printf("\n");
	}
}

bool are_adjacent_infected(int dish[][EDGE_LENGTH], int row, int col) {
	// yours... a vous
	bool infected = false;

	//yes cant access memory outside dish but either way that memory location will never have a 1 which would make it equal infected (should be redone though, in the odd chance there was a 1 saved nearby)
	if(dish[row+1][col] == 1 || dish[row-1][col] == 1 || dish[row][col+1] == 1 || dish[row][col-1] == 1 || dish[row+1][col+1] == 1 || dish[row-1][col+1] == 1 || dish[row+1][col-1] == 1 || dish[row-1][col-1] == 1){
        infected = true;
	}
	return infected;
}

void spread_infection(int dish[][EDGE_LENGTH]) {
	// yours... a vous
	//traverese array an infect all
	for(int i = 0; i < EDGE_LENGTH; i++){
	    for(int j = 0; j < EDGE_LENGTH; j++){
	        if(dish[i][j] == 1){ //if sees a 1 at the location, so can infect others
	            //like looping through a small 2D array around the infected 1. so make 1 around the 3 by 3 around
//has to be <= so not miss the edge too
	            for(int m = i - 1; m <= (i + 1); m++){
	                for(int n = j - 1; n <= (j + 1); n++){
	                    if(m >= 0 && m < EDGE_LENGTH && n >= 0 && n < EDGE_LENGTH) { //chcek so that not try access that outside the allocated, declared dish
//if sees a 0 there in the area that needs to infect, it turns it to 3 (later will change all the newly infected to 1, need do this way so no overlap happen)
	                        switch(dish[m][n]){
	                            case 0:
                                    dish[m][n]=3;
	                                break;
	                            case 1: //if 1 it stay 1 still (so later remember that square can infect more)
                                    dish[m][n]=1;
	                                break;
	                            case 3: //if 3 already the infected got, keep it as got infected
                                    dish[m][n]=3;
	                                break;
	                        }
                        }
	                }
	            }
	        }
	    }
	}

	// a print to check the in between to show how infection progressed
    printf("\n");

    for(int i = 0; i < EDGE_LENGTH; i++){
        for(int j = 0; j < EDGE_LENGTH; j++){
            printf(" %d ",dish[i][j]);
        }
        printf("\n");
    }
    
	//now after all infected got accounted, switch back all 3 to be 1 (so if run again it will register the 1 as the ones capable of infecting)
    for(int i = 0; i < EDGE_LENGTH; i++){
        for(int j = 0; j < EDGE_LENGTH; j++){
            if(dish[i][j]==3){
                dish[i][j]=1;
            }
        }
    }

    printf("\n");

}

