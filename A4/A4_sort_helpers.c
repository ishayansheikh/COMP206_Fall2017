#include "A4_sort_helpers.h"
#include <semaphore.h>


// Function: read_all() 
// Provided to read an entire file, line by line.
// No need to change this one.

void read_all( char *filename ){
    
    FILE *fp = fopen( filename, "r" );
    int curr_line = 0;
	
    while( curr_line < MAX_NUMBER_LINES && 
           fgets( text_array[curr_line], MAX_LINE_LENGTH, fp ) )
    {
        curr_line++;
    }
	
    text_array[curr_line][0] = '\0';
    fclose(fp);
}

// Function: read_all() 
// Provided to read only the lines of a file staring with first_letter.
// No need to change this one.
void read_by_letter( char *filename, char first_letter ){

    FILE *fp = fopen( filename, "r" );
    int curr_line = 0;
    text_array[curr_line][0] = '\0';
	
    while( fgets( text_array[curr_line], MAX_LINE_LENGTH, fp ) ){
        if( text_array[curr_line][0] == first_letter ){
            curr_line++;
        }

        if( curr_line == MAX_NUMBER_LINES ){
            sprintf( buf, "ERROR: Attempted to read too many lines from file.\n" );
            write( 1, buf, strlen(buf) );
            break;
        }
    }
	
    text_array[curr_line][0] = '\0';
    fclose(fp);
}

// YOU COMPLETE THIS ENTIRE FUNCTION FOR Q1.
void sort_words( ){
	char temp[MAX_LINE_LENGTH] = "";
	//int n =(sizeof(text_array))/sizeof(text_array[0]);

	int n = 0;
	int i = 0;
    	while(i<MAX_NUMBER_LINES) {
        if(text_array[i][0] == '\0') {
            n = i;
            break;
        }
	i++;
    }
	
	for (int i = 0; i< n-1; i++) {
		for (int j = i + 1; j< n; j++) {
			  
                	if (strcmp(text_array[i], text_array[j]) > 0) {
                    	strcpy(temp, text_array[i]);
                    	strcpy(text_array[i], text_array[j]);
                    	strcpy(text_array[j], temp);
               		}
        	}
    	}	



	/*for (int pos=0; pos < n;pos++) {
		char curr[MAX_LINE_LENGTH]="";
 		strcpy(curr,text_array[pos]);
		int min_pos = -1;
		char* min_val = "";

		for(int other_pos = pos; other_pos <n; other_pos++) {
			if ( strcmp(text_array[other_pos],min_val) < 0) {		
				min_pos = other_pos;
				strcpy(min_val,text_array[other_pos]);
			}

		}
		strcpy(text_array[min_pos], curr);
		strcpy(text_array[pos], min_val);
	}*/
}
// YOU COMPLETE THIS ENTIRE FUNCTION FOR Q2.
sem_t* semaphore_array[27];
int initialize( ){
    
    sprintf(buf, "Initializing.\n"  );
  
	
	int i = 0;
	char mySemaphoreName[200]; 	
	
  	while (	i<27) {
	
	sprintf(mySemaphoreName, "mySem_%d", i); 
	int num = (i == 1? 1 : 0);
 	semaphore_array[i] = sem_open(mySemaphoreName, O_CREAT, 0644 , num);
 	sem_unlink(mySemaphoreName);
	i++;         
	}
	FILE* fp = fopen("my_file.txt", "w"); 
	fclose(fp);  

    
    return 0;
}

// YOU MUST COMPLETE THIS FUNCTION FOR Q2 and Q3.   
int process_by_letter( char* input_filename, char first_letter ){
    
    	int var1 = first_letter - 'a' + 1; 
	int check = 5;
	int check2 = 10;
	sem_wait(semaphore_array[var1]); 

	sprintf( buf, "This process will sort the letter %c.\n", first_letter ); 

	read_by_letter(input_filename, first_letter); 
	
	sort_words(); 


	FILE * fp = fopen("my_file.txt", "a"); 
	
	int i = 0;
	while (i<MAX_NUMBER_LINES) {	
 		if(text_array[i][0] == '\0') {
		break;
	}
	
		fprintf(fp, "%s", text_array[i]); 
		i++;	
	}
 	fclose(fp); 
	int finalResult = sem_post(semaphore_array[(var1+1)%27]);
 	if(finalResult < 0) 
	fprintf(stderr, "there was an error with sem_post\n");


  

    return 0;
}

// YOU COMPLETE THIS ENTIRE FUNCTION FOR Q2 and Q3.
int finalize( ){
    
    sem_wait(semaphore_array[0]);

    char myLine[MAX_LINE_LENGTH];
    

 	
    FILE * fp = fopen("my_file.txt", "r");

    while(fgets(myLine, MAX_LINE_LENGTH, fp) != NULL) {
        printf("%s", myLine);
    }

    fclose(fp);
    printf("Sorting complete!\n");
    
    return 0;
}

