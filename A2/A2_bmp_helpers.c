/* FILE: A2_bmp_helpers.c is where you will code your answers for Assignment 2.
 * 
 * Each of the functions below can be considered a start for you. 
 *
 * You should leave all of the code as is, except for what's surrounded
 * in comments like "REPLACE EVERTHING FROM HERE... TO HERE.
 *
 * The assignment document and the header A2_bmp_headers.h should help
 * to find out how to complete and test the functions. Good luck!
 * Name: Shayan Sheikh
 * ID: 260738247
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

int bmp_open( char* bmp_filename,        unsigned int *width, 
              unsigned int *height,      unsigned int *bits_per_pixel, 
              unsigned int *padding,     unsigned int *data_size, 
              unsigned int *data_offset, unsigned char** img_data ){

              
  // YOUR CODE FOR Q1 SHOULD REPLACE EVERYTHING FROM HERE
  //printf( "BMP_OPEN is not yet implemented. Please help complete this code!\n" );
  
	FILE *bmpfile = fopen( bmp_filename, "rb" );

	char b, m;
	fread (&b,1,1,bmpfile);
	fread (&m,1,1,bmpfile);
	
	if (b!='B' || m!='M') {
	printf("Error: This is not a BMP file.");
	exit(-1);
	}	
	
	unsigned int overallFileSize;
	fread( &overallFileSize, 1, sizeof(unsigned int), bmpfile );
	
	fclose(bmpfile);
	bmpfile = fopen(bmp_filename, "rb" );

	char* imageData = (char*) malloc( sizeof(char) * overallFileSize );
	fread( imageData, 1, overallFileSize, bmpfile );

	unsigned int* wp = (unsigned int*)(imageData+18);
  	*width= *wp;

	unsigned int* hp = (unsigned int*)(imageData+22);
  	*height= *hp;
	
	unsigned int* bpp = (unsigned int*)(imageData+28);
  	*bits_per_pixel= *bpp;
	
	unsigned int paddingNum = 0;
	if (((*width)*(*bits_per_pixel)/8)%4==0){
		paddingNum = 0;
	} 
	if (((*width)*(*bits_per_pixel)/8)%4==1){
		paddingNum = 3;
	}
	if (((*width)*(*bits_per_pixel)/8)%4==2){
		paddingNum = 2;
	}	
	if (((*width)*(*bits_per_pixel)/8)%4==3){
		paddingNum = 1;
	}
	
	 
	
  	*padding= paddingNum;
  	*data_size= overallFileSize ;
	

  	unsigned int* dataOff = (unsigned int*)(imageData+10);
	*data_offset= *dataOff;
 	*img_data=imageData;
  // TO HERE
  
  return 0;  
}

// We've implemented bmp_close for you. No need to modify this function
void bmp_close( unsigned char **img_data ){

  if( *img_data != NULL ){
    free( *img_data );
    *img_data = NULL;
  }
}

int bmp_mask( char* input_bmp_filename, char* output_bmp_filename, 
              unsigned int x_min, unsigned int y_min, unsigned int x_max, unsigned int y_max,
              unsigned char red, unsigned char green, unsigned char blue )
{
  unsigned int img_width;
  unsigned int img_height;
  unsigned int bits_per_pixel;
  unsigned int data_size;
  unsigned int padding;
  unsigned int data_offset;
  unsigned char* img_data    = NULL;
  
  int open_return_code = bmp_open( input_bmp_filename, &img_width, &img_height, &bits_per_pixel, &padding, &data_size, &data_offset, &img_data ); 
  
  if( open_return_code ){ printf( "bmp_open failed. Returning from bmp_mask without attempting changes.\n" ); return -1; }
 
  // YOUR CODE FOR Q2 SHOULD REPLACE EVERYTHING FROM HERE
 	FILE* output_img = fopen(output_bmp_filename, "wb");
	char* output_img_data = (unsigned char*) malloc(sizeof(char)*data_size);
	memcpy(output_img_data, img_data, data_size); 
	
	unsigned char *pixel_data = output_img_data + data_offset;
	unsigned int num_colors = bits_per_pixel/8;	
	for (int tempx = x_min; tempx<= x_max; tempx++) {
		
		for(int tempy = y_min; tempy <= y_max; tempy++) {
		 pixel_data[ tempy*(img_width*num_colors+padding) + tempx*num_colors + 2 ] = red;
		 pixel_data[ tempy*(img_width*num_colors+padding) + tempx*num_colors + 1 ] = green;		
		 pixel_data[ tempy*(img_width*num_colors+padding) + tempx*num_colors + 0 ] = blue;
		}
  	}
	fwrite(output_img_data, 1, data_size, output_img);
	free (output_img_data);
  // TO HERE!
  
  bmp_close( &img_data );
  
  return 0;
}         

int bmp_collage( char* bmp_input1, char* bmp_input2, char* bmp_result, int x_offset, int y_offset ){

  unsigned int img_width1;
  unsigned int img_height1;
  unsigned int bits_per_pixel1;
  unsigned int data_size1;
  unsigned int padding1;
  unsigned int data_offset1;
  unsigned char* img_data1    = NULL;
  
  int open_return_code = bmp_open( bmp_input1, &img_width1, &img_height1, &bits_per_pixel1, &padding1, &data_size1, &data_offset1, &img_data1 ); 
  
  if( open_return_code ){ printf( "bmp_open failed for %s. Returning from bmp_collage without attempting changes.\n", bmp_input1 ); return -1; }
  
  unsigned int img_width2;
  unsigned int img_height2;
  unsigned int bits_per_pixel2;
  unsigned int data_size2;
  unsigned int padding2;
  unsigned int data_offset2;
  unsigned char* img_data2    = NULL;
  
  open_return_code = bmp_open( bmp_input2, &img_width2, &img_height2, &bits_per_pixel2, &padding2, &data_size2, &data_offset2, &img_data2 ); 
  
  if( open_return_code ){ printf( "bmp_open failed for %s. Returning from bmp_collage without attempting changes.\n", bmp_input2 ); return -1; }
  
  // YOUR CODE FOR Q3 SHOULD REPLACE EVERYTHING FROM HERE
	unsigned int new_width = 0;
	unsigned int new_height = 0;
	unsigned int data_size_new = 0;
			
	if (x_offset>=0) {
		if ((img_width2 + x_offset)>img_width1) {
			new_width = img_width2 + x_offset;		
		} else {
			new_width = img_width1;
		} 
	}  

	if (x_offset<0) {
		if ((img_width2<img_width1) || ((img_width2-img_width1) < abs(x_offset))){
			new_width = img_width1+ abs(x_offset);
		} else {
			new_width = img_width2;
		}
	}

	if (y_offset>=0) {
		if ((img_height2 + y_offset)>img_height1) {
			new_height = img_height2 + y_offset;		
		} else {
			new_height= img_height1;
		} 
	}  

	if (y_offset<0) {
		if ((img_height2<img_height1) || ((img_height2-img_height1) < abs(x_offset))){
			new_height = img_height1+ abs(y_offset);
		} else {
			new_height = img_height2;
		}
	}
	
	unsigned int new_padding = 0;
	if (((new_width)*(bits_per_pixel1)/8)%4==0){
		new_padding = 0;
	} 
	if (((new_width)*(bits_per_pixel1)/8)%4==1){
		new_padding = 3;
	}
	if (((new_width)*(bits_per_pixel1)/8)%4==2){
		new_padding = 2;
	}	
	if (((new_width)*(bits_per_pixel1)/8)%4==3){
		new_padding = 1;
	}
	
	
	unsigned int num_colors = bits_per_pixel1/8;		
	data_size_new =  ((new_width*(num_colors) + new_padding) * new_height);
	unsigned int header_size = data_offset1;

	
	FILE* output_img = fopen(bmp_result, "wb");
	char* output_img_data = (unsigned char*) malloc(sizeof(char)*(data_size_new + header_size));
	memcpy(output_img_data, img_data1, header_size);
	
	
	unsigned int* wp = (unsigned int*)(output_img_data+18);
  	*wp = new_width;
	//memcpy((output_img_data+18),&new_width,4); 	
	
	unsigned int* hp = (unsigned int*)(output_img_data+22);
	*hp = new_height;
	//memcpy((output_img_data+22),&new_height,4);
	
	unsigned int size_final = data_size_new+header_size;
	unsigned int* sp = (unsigned int*)(output_img_data+2);
	*sp = data_size_new + header_size;
	//memcpy((output_img_data+2),&(size_final),4);
	

 
		unsigned int img_one_start_col = 0;
		unsigned int img_one_start_row = 0;
		unsigned int img_two_start_col = 0;
		unsigned int img_two_start_row = 0;
		unsigned int img_one_end_row = 0;
		unsigned int img_one_end_col = 0;
		unsigned int img_two_end_row = 0;
		unsigned int img_two_end_col = 0;
	
	if (x_offset >=0) {
		img_one_start_col = 0;
		img_one_end_col = img_width1;
		img_two_start_col = x_offset;
		img_two_end_col = x_offset + img_width2;
	
	}
	
	if (y_offset>=0) {
		img_one_start_row = 0;
		img_one_end_row = img_height1;
		img_two_start_row = y_offset;
		img_two_end_row = y_offset + img_height2;
	}

	if (x_offset<0) {
		img_one_start_col = abs(x_offset);
		img_one_end_col = abs(x_offset) + img_width1;
		
		img_two_start_col = 0;
		img_two_end_col = img_width2;
		
	}

	if (y_offset<0) {
		img_one_start_row = abs(y_offset);
		img_one_end_row = abs(y_offset)+img_height1;
		img_two_start_row = 0;
		img_two_end_row = img_height2;
	}
	
	unsigned char *pixel_data_result = output_img_data + data_offset1;
	unsigned int num_colors_result = bits_per_pixel1/8;

	unsigned char *pixel_data_img2 = img_data2 + data_offset2;
	unsigned int num_colors_img2 = bits_per_pixel2/8;

	unsigned char *pixel_data_img1 = img_data1 + data_offset1;
	unsigned int num_colors_img1 = bits_per_pixel1/8;
	
	for (int vertical = 0; vertical < new_height; vertical++) {

		for (int horizontal = 0; horizontal < new_width; horizontal++) {
			
			if (vertical >= img_two_start_row && vertical < img_two_end_row && horizontal >= img_two_start_col && horizontal < img_two_end_col) {
				pixel_data_result[vertical*(new_width*num_colors+new_padding) + horizontal*num_colors_result+0] = pixel_data_img2[(vertical-img_two_start_row)*(img_width2*num_colors_img2+padding2) + (horizontal-img_two_start_col)*num_colors_img2+0];
				pixel_data_result[vertical*(new_width*num_colors+new_padding) + horizontal*num_colors_result+1] = pixel_data_img2[(vertical-img_two_start_row)*(img_width2*num_colors_img2+padding2) + (horizontal-img_two_start_col)*num_colors_img2+1];
				pixel_data_result[vertical*(new_width*num_colors+new_padding) + horizontal*num_colors_result+2] = pixel_data_img2[(vertical-img_two_start_row)*(img_width2*num_colors_img2+padding2) + (horizontal-img_two_start_col)*num_colors_img2+2];
			
			} else  if(vertical >= img_one_start_row && vertical < img_one_end_row && horizontal >= img_one_start_col && horizontal < img_one_end_col)  {
				pixel_data_result[vertical*(new_width*num_colors+new_padding) +horizontal*num_colors_result+0] = pixel_data_img1[(vertical-img_one_start_row)*		(img_width1*num_colors_img1+padding1) + (horizontal-img_one_start_col)*num_colors_img1+0];
				pixel_data_result[vertical*(new_width*num_colors+new_padding) +horizontal*num_colors_result+1] = pixel_data_img1[(vertical-img_one_start_row)*		(img_width1*num_colors_img1+padding1) + (horizontal-img_one_start_col)*num_colors_img1+1];
				pixel_data_result[vertical*(new_width*num_colors+new_padding) +horizontal*num_colors_result+2] = pixel_data_img1[(vertical-img_one_start_row)*		(img_width1*num_colors_img1+padding1) + (horizontal-img_one_start_col)*num_colors_img1+2];
			}	
		}

	} 
	
	
	fwrite(output_img_data, 1, size_final, output_img);
	free (output_img_data);




  // TO HERE!
      
  bmp_close( &img_data1 );
  bmp_close( &img_data2 );
  
  return 0;
}                  
