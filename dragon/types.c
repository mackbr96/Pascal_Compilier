
#include <assert.h>
#include "externs.h"
#include "types.h"

types* mkType(int type) {
	types *p = (types *)malloc(sizeof(types));
    assert(p != NULL);

    p -> type = type;
    p -> next = NULL;

    return p;

}
types* addType(types* t, int type) {
	types *p = mkType(type);
    p -> next = t;
 	t = p;

    return t;


}

types* linkTypes(types* t, types* p) {
    if(p == NULL) {
        fprintf(stderr, "LINK TYPE NULL\n");
        exit(0);
    }
    t -> next = p;

    return t;
}

