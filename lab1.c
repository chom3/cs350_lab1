#include <stdio.h>
#include "time_functions.h"
#include <stdlib.h>

/**
 * Lab 1:
 * 0.080 seconds for a 30000 line file (2492910 bytes).
 * A file size of 12227904 bytes leads to a 0.390 result time.
*/

int main(int argc, const char* argv[])
{
	
	//initialize input/output file to be opened
	FILE *iFP, *oFP;
	//we use output/input [256] to take in the max size for an input in scanf
	char input[256];
	char output[256];
	
	printf("Name of an input file? \n");
	scanf("%s", input);
	
	//need to open the input file so that we can read it later
	iFP = fopen(input, "r");
	
	//iPath and oPath are used to print out the full path names as per instruction
	char *iPath = realpath(input, NULL);
	if (iPath == NULL){
		printf("%s not found\n", input);
	}
	else{
		printf("The name of the file is: %s\n", input);
		printf("The path is %s\n", iPath);
		free(iPath);
	}
	
	printf("Name of an output file? \n");
	scanf("%s", output);
	//need to open the output file, if the name doesn't exist a file will be created. 
	oFP = fopen(output, "w");
	
	char *oPath = realpath(output, NULL);
	if (oPath == NULL){
		printf("%s not found\n", output);
	}
	else{
		printf("The name of the file is: %s\n", output);
		printf("The path is: %s\n", oPath);
		free(oPath);
	}
	

	//allocate a buffer and fread the bytes in "byte by byte" and write it to file.
	unsigned char buffer[256];
	size_t bytes = 0;
	
	printf("%s", "start_timing begins now.\n");
	//initialize CPU timer so that we can record the result for the total time the cpu clock takes to calculate
	start_timing();
	
	//use fread to read byte by byte, size of an unsigned char is a byte
	//at the same time fwrite will use what is in the buffer to copy byte by byte. 
	while ((bytes = fread(buffer, sizeof(unsigned char), sizeof(buffer[0]), iFP))){
    		fwrite(buffer, sizeof(unsigned char), sizeof(buffer[0]), oFP);
	}
	stop_timing();
	printf("%s", "stop_timing is now called.\n");
	//to find the total time elapsed we subtract start from end/print the CPU time used, which is in the function get_CPU_time_diff()
	printf("the time from 'CPU time' for byte copying is %10.3f seconds\n",get_CPU_time_diff());  
	
	fclose(iFP);
	fclose(oFP);
	
	return 0;	
}
