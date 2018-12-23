#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) {
	if (argc != 3) {
		printf("Error: This program only accepts exactly 2 command line-arguments\n");
		exit(-1);
	} 	

	int daySize = atoi(argv[1]);
	int firstDay = atoi(argv[2]);

	if (daySize <2) {
	printf("ERROR: Cannot print days smaller than size 2. \n");
	exit(-1);
	}
	if (firstDay < 1 || firstDay > 7) {
	printf("ERROR: The first day of the week must be between 1 and 7. \n"); 
	exit(-1);
	}

	int numSymbols = (daySize+3)*7+1;

	char *month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	char *nameOfWeek[1000];
	if (daySize == 2) {
	char *nameOfWeek[] = {NULL, "Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"};
	}
	if (daySize == 3) {
	char *nameOfWeek[] = {NULL, "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	}
	if (daySize == 4) {
	char *nameOfWeek[] = {NULL, "Sund", "Mond", "Tues", "Wedn", "Thur", "Frid", "Satu"};
	}
	if (daySize == 5) {
	char *nameOfWeek[] = {NULL, "Sunda", "Monda", "Tuesd", "Wedne", "Thurs", "Frida", "Satur"};
	}
	if (daySize == 6) {
	char *nameOfWeek[] = {NULL, "Sunday", "Monday", "Tuesda", "Wednes", "Thursd", "Friday", "Saturd"};
	}
	if (daySize == 7) {
	char *nameOfWeek[] = {NULL, "Sunday ", "Monday ", "Tuesday", "Wednesd", "Thursda", "Friday ", "Saturda"};
	} 
	if (daySize == 8) {
	char *nameOfWeek[] = {NULL, "Sunday  ", "Monday  ", "Tuesday ", "Wednesda", "Thursday", "Friday  ", "Saturday"};
	}
	if (daySize == 9) {
	char *nameOfWeek[] = {NULL, "Sunday   ", "Monday   ", "Tuesday  ", "Wednesday", "Thursday ", "Friday   ", "Saturday "};
	} 
	if (daySize == 10) {
	char *nameOfWeek[] = {NULL, "Sunday    ", "Monday    ", "Tuesday   ", "Wednesday ", "Thursday  ", "Friday    ", "Saturday  "};
	} 
	if (daySize == 11) {
	char *nameOfWeek[] = {NULL, "Sunday     ", "Monday     ", "Tuesday    ", "Wednesday  ", "Thursday   ", "Friday     ", "Saturday   "};
	}
	if (daySize == 12) {
	char *nameOfWeek[] = {NULL, "Sunday      ", "Monday      ", "Tuesday     ", "Wednesday   ", "Thursday    ", "Friday      ", "Saturday    "};
	}		
	if (daySize == 13) {
	char *nameOfWeek[] = {NULL, "Sunday       ", "Monday       ", "Tuesday      ", "Wednesday    ", "Thursday     ", "Friday       ", "Saturday     "};
	}		
	if (daySize == 14) {
	char *nameOfWeek[] = {NULL, "Sunday        ", "Monday        ", "Tuesday       ", "Wednesday     ", "Thursday      ", "Friday        ", "Saturday      "};
	}
	if (daySize == 15) {
	char *nameOfWeek[] = {NULL, "Sunday         ", "Monday         ", "Tuesday        ", "Wednesday      ", "Thursday       ", "Friday         ", "Saturday       "};
	}
	if (daySize == 16) {
	char *nameOfWeek[] = {NULL, "Sunday          ", "Monday          ", "Tuesday         ", "Wednesday       ", "Thursday        ", "Friday          ", "Saturday        "};
	}
	if (daySize == 17) {
	char *nameOfWeek[] = {NULL, "Sunday           ", "Monday           ", "Tuesday          ", "Wednesday        ", "Thursday         ", "Friday           ", "Saturday         "};
	}		
	if (daySize == 18) {
	char *nameOfWeek[] = {NULL, "Sunday            ", "Monday            ", "Tuesday           ", "Wednesday         ", "Thursday          ", "Friday            ", "Saturday          "};
	}
		if (daySize == 19) {
	char *nameOfWeek[] = {NULL, "Sunday             ", "Monday             ", "Tuesday            ", "Wednesday          ", "Thursday           ", "Friday             ", "Saturday           "};
	}
	if (daySize > 19) {
	char *nameOfWeek[] = {NULL, "Sunday              ", "Monday              ", "Tuesday             ", "Wednesday           ", "Thursday            ", "Friday              ", "Saturday            "};
	}

		
	
	

	for (int i = 0; i < 12; i++) {
		int start = (firstDay+(i*2))%7;

		printf("|");
		for (int j = 0; j < numSymbols-2; j++) {
			printf("-");
		}
		printf("|\n");
		
		printf("|");
		int space= (numSymbols)/2;
			
//
	int length = (daySize+3)*7-1;
	int month_length = strlen(month[i]);
	int white_space = length - month_length; 
	int before_after = white_space/2;

	if(white_space%2 == 1)
	{
		

		for(int i = 0; i < (before_after); i++)
		{
			printf(" ");
		}
		
		printf("%s", month[i]);

		for(int i = 0; i < (before_after+1); i++)
		{
			printf(" ");
		}

		printf("|\n");
	}

	else
	{
		

		for(int i = 0; i < before_after; i++)
		{
			printf(" ");
		}
	
		printf("%s", month[i]);

		for(int i = 0; i < before_after; i++)
		{
			printf(" ");
		}

		printf("|\n");
	}
	
		
		printf("|");
		for (int j = 0; j < numSymbols-2; j++) {
			printf("-");
		}
		printf("|\n");
		
		printf("|");
		for (int i = 1; i < 8; i++) {
		printf(" %s |", nameOfWeek[i]);
		}	
		printf("\n");
		
		printf("|");
		for (int j = 0; j < numSymbols-2; j++) {
			printf("-");
		}
		printf("|\n");
		
		
		printf("|");
		for (int i = 1; i < 31; i++) {
			
			
	
			if (start ==1) {
			if (i<10) {
			int space2 = ((numSymbols)/7)-5;
			printf(" %i", i);			
			printf(" %*s |",space2, "");
			} else {
			if (daySize ==2) {
			printf(" %i ", i);			
			printf("|");
			}
			else {
			int space2 = ((numSymbols)/7)-6;
			printf(" %i", i);			
			printf(" %*s |",space2, "");
			}
			}
			if (i%7 == 0) {
			printf("\n|");
			
			}
			if (i ==30) {
			for (int j = 0; j<5; j++) {
			int space2 = ((numSymbols)/7)-3;
			printf(" %*s |", space2, "");
			}		
			}
		}
		
			if (start ==2) {
			
			
			if (i ==1) {
			int space2 = ((numSymbols)/7)-3;
			printf(" %*s |", space2, "");
			}
			
			if (i<10) {
			int space2 = ((numSymbols)/7)-5;
			printf(" %i", i);			
			printf(" %*s |",space2, "");
			} else {
			if (daySize ==2) {
			printf(" %i ", i);			
			printf("|");
			}
			else {
			int space2 = ((numSymbols)/7)-6;
			printf(" %i", i);			
			printf(" %*s |",space2, "");
			}}
			if (i%7 == 6) {
			printf("\n|");
			}
			  
			if (i ==30) {
			
			for (int j = 0; j<4; j++) {
			int space2 = ((numSymbols)/7)-3;
			printf(" %*s |", space2, "");
			}		
			}
					
		}
			if (start ==3) {
			int space2 = ((numSymbols)/7)-3;
			if (i ==1) {
			for (int k = 0; k <2; k++) {
			printf(" %*s |", space2, "");
			}	
	}	
			if (i<10) {
			int space2 = ((numSymbols)/7)-5;
			printf(" %i", i);			
			printf(" %*s |",space2, "");
			} else {
			if (daySize ==2) {
			printf(" %i ", i);			
			printf("|");
			}
			else {
			int space2 = ((numSymbols)/7)-6;
			printf(" %i", i);			
			printf(" %*s |",space2, "");
			}}
			if (i%7 == 5) {
			printf("\n|");
			
			}
			if (i ==30) {
			for (int j = 0; j<3; j++) {
			printf(" %*s |", space2, "");
			}		
			}
		}
			
			if (start ==4) {
			int space2 = ((numSymbols)/7)-3;
			if (i ==1) {			
			for (int k = 0; k <3; k++) {
			printf(" %*s |", space2, "");
			}	

	}
			if (i<10) {
			int space2 = ((numSymbols)/7)-5;
			printf(" %i", i);			
			printf(" %*s |",space2, "");
			} else {
			if (daySize ==2) {
			printf(" %i ", i);			
			printf("|");
			}
			else {
			int space2 = ((numSymbols)/7)-6;
			printf(" %i", i);			
			printf(" %*s |",space2, "");
			}}
			if (i%7 == 4) {
			printf("\n|");
			
			}
			if (i ==30) {
			for (int j = 0; j<2; j++) {
			printf(" %*s |", space2, "");
			}		
			}
					
		}	
			if (start ==5) {
			int space2 = ((numSymbols)/7)-3;
			if (i ==1) {			
			for (int k = 0; k <4; k++) {
			printf(" %*s |", space2, "");
			}	

	}
			if (i<10) {
			int space2 = ((numSymbols)/7)-5;
			printf(" %i", i);			
			printf(" %*s |",space2, "");
			} else {
			if (daySize ==2) {
			printf(" %i ", i);			
			printf("|");
			}
			else {		
			int space2 = ((numSymbols)/7)-6;
			printf(" %i", i);			
			printf(" %*s |",space2, "");
			}}
			if (i%7 == 3) {
			printf("\n|");
			
			}
			if (i ==30) {
			for (int j = 0; j<1; j++) {
			printf(" %*s |", space2, "");
			}		
			}
					
		}
			if (start ==6) {
			int space2 = ((numSymbols)/7)-3;
			if (i ==1) {			
			for (int k = 0; k <5; k++) {
			printf(" %*s |", space2, "");
			}	

	}
			if (i<10) {
			int space2 = ((numSymbols)/7)-5;
			printf(" %i", i);			
			printf(" %*s |",space2, "");
			} else {
			if (daySize ==2) {
			printf(" %i ", i);			
			printf("|");
			}
			else {
			int space2 = ((numSymbols)/7)-6;
			printf(" %i", i);			
			printf(" %*s |",space2, "");
			}}
			if (i%7 == 2 && i!=30) {
			printf("\n|");
			
			}
				
			
			}

			if (start ==0) {
			int space2 = ((numSymbols)/7)-3;
			if (i ==1) {			
			for (int k = 0; k <6; k++) {
			printf(" %*s |", space2, "");
			}	

	}
			if (i<10) {
			int space2 = ((numSymbols)/7)-5;
			printf(" %i", i);			
			printf(" %*s |",space2, "");
			} else {
			if (daySize ==2) {
			printf(" %i ", i);			
			printf("|");
			}
			else {
			int space2 = ((numSymbols)/7)-6;
			printf(" %i", i);			
			printf(" %*s |",space2, "");
			}}
			if (i%7 == 1) {
			printf("\n|");
			}
			if (i ==30) {
			for (int k = 0; k < 6; k++) {
			printf(" %*s |", space2, "");
					
			}
}
					
					
		}
				
		}
		
	
		printf("\n");	
			
}

		printf("|");
		for (int j = 0; j < numSymbols-2; j++) {
			printf("-");
		}
		printf("|\n");
	
}
