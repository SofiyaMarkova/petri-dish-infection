/* DO NOT MODIFY - NE MODIFIEZ PAS */

#ifndef PETRI_H_
#define PETRI_H_

#include <stdbool.h>

#define EDGE_LENGTH 9

bool are_adjacent_infected(int dish[][EDGE_LENGTH], int row, int col);
void spread_infection(int dish[][EDGE_LENGTH]);
void print_petri_dish(int dish[][EDGE_LENGTH]);

#endif /* PETRI_H_ */
