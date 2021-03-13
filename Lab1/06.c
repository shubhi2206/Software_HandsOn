//Program to read input from Standard Input and display on Standard Output

#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char *argv[]){
	char input[200];
	// Reading from Standard Input
	int l = read(0, input, sizeof(input));
	
	
	// Writing to Standard Output
	write(1, input, l);
	return 0;
}
