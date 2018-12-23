#include<stdio.h>
#include <string.h>
#include<stdlib.h>

int main (int argc, char *argv[]) {
	


	if (argc != 4) {
		printf("Error: This program");
		printf(" only accepts exactly 3");
		printf(" command line-arguments\n");
		exit(-1);
	} 
	
	float a = atof(argv[2]);
  	float b = atof(argv[3]);
	if (a == 0.0 || b== 0.0 ) {
	printf("bad float arg\n");
	exit(-1);
	}

	char *word_list[100];

	FILE* csv_file = fopen(argv[1], "r");

	if (csv_file == NULL) {
		printf("Error: bad file %s.\n", argv[1]);
		exit(-1); 
	}
	
	
	char line_buffer[1000];

	while(fgets(line_buffer, 1000, csv_file)) {
	
    	char* line_ptr = line_buffer;

	char *checkOne = strstr(line_ptr, "#A#");
        char *checkTwo = strstr(line_ptr, "#B#");
      
	if(checkOne == NULL && checkTwo == NULL){
        fprintf(stdout, "%s",line_ptr);
      }

      if(checkOne != NULL){
        char *temp = line_ptr;
        while(temp != checkOne){
          printf("%c", *temp);
          temp++;
        }
        printf("%.6f", a);
        temp = temp + 3;
        printf("%s",temp );

      }


      if(checkTwo != NULL){
        char *temp = line_ptr;
        while(temp != checkTwo){
          printf("%c", *temp);
          temp++;
        }
        printf("%.6f", b);
        temp = temp + 3;
        printf("%s",temp );
      }

     
  }
return 0;
}
