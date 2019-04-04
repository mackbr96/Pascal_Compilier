#include <stdio.h>
#include <stdlib.h>
#include "node.c"





int main() {
	scope *top;
	node *tmp;
	int choice;
	char name[32];

	top = mkscope();

	while(1) {
		fprintf(stderr, "0 push, 1 pop 2 search 3 insert 4 searchall\n");
		scanf("%d", &choice);
		switch(choice) {
			case 0: //push
				top = push_scope(top);
				break;
			case 1: //pop
				top = pop_scope(top);
				break;
			case 4: //search all
		
			case(2): //search
				fprintf(stderr, "Enter name\n");
				scanf("%s", name);
				tmp = searchNode(top, name);
				if (tmp != NULL) {
					fprintf(stderr, "Found[%s]\n", tmp->name);
				}
				else {
					fprintf(stderr, "Not found%s\n", name);
				}
			
				break;
			case 3: //insert
				fprintf(stderr, "enter name\n");
				scanf("%s", name);
				top = insertNode(top, name);
				break;

		}
	}

}
