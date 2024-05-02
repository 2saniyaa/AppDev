#include "minmax.h"
#include <stdlib.h>
#include <time.h>

struct min_max maxmin(void) {
	struct min_max r;
	srand(time(NULL));
	r.min = rand() % 16 - 10;//random range -10 to 5
	r.max = rand() % 31 + 15; //rndom range 15-35
	return r;

}