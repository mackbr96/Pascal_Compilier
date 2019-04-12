#ifndef TYPES_H
#define TYPES_H

#include <stdio.h>
#include <stdlib.h>
#include "externs.h"

typedef struct types types;


struct types{
	int type;

	struct types* next;
}; 

types* mkType(int);
types* addType(types*, int);
types* linkTypes(types* t, types* p);

#endif