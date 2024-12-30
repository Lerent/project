#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"


int main(int argc, char *argv[]) {
	int choose;
	
	do {
		Menu();
		scanf("%d", &choose);
		
		switch (choose) {
			case 1: {
				newUser();
				break;
			}
			case 2: {
				show();
				break;
			}
			case 3: {
				showUser();
				break;
			}
			case 4: {
				
				break;
			}
			case 5: {
				
				break;
			}
			case 6: {
				
				break;
			}
			case 7: {
				
				break;
			}
			case 8: {
				break;
			}
		}
	} while (choose != 8);
	
	return 0;
}
