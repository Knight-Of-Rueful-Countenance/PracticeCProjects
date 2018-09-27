#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void allocateMemory();
int main(int argc,char* argv[])
{
	char inputfromFile[127];
	FILE* filedir;
	filedir = fopen(argv[1],"r");//Open file
	if(filedir==NULL){printf("ERR: Failed to Read File\n"); return 1;}
	fgets(inputfromFile,126,filedir);//Load data
	printf("%s\n",inputfromFile); //Print First Line (up to 127 char)

	rewind(filedir);//Go back to beginning of string
	while(1)
	{
		fscanf(filedir,"%s",inputfromFile);
		printf("%s",inputfromFile);
		if(feof(filedir)){break;}
	}
	fclose(filedir);
	//Special Keywords:
	register int x =5; //Stores the value in a specific register - may increase speed if register cannot be better used
	static float y = 5.9; //Remembered through function calls after instantiated
	volatile char p = 5; //This is reloaded from memory every time that it is accessed - e.g. if a variable is being edited by an external source, this will mean it updates within the program as well.
	//Now for some basic string manipulation:
	char* stringA = "The cat sat back on the back of the chair and yawned, amusedly";
	char* stringB = "The Big Backed Bear Bent his Back and Began to Brew his Beverage";
	printf("stringA Numerically:\n%d\n",atoi(stringA));
	printf("stringA as a float:\n%f\n",atof(stringA));
	printf("%s\n%s\n",stringA,stringB);
	printf("A= %d, B= %d\n",strlen(stringA),strlen(stringB));
	strncpy(stringA,"bananas on toast",strlen("bananas on toast"));
	printf("%s",stringA);
	if(strncmp(stringA,stringB,4)==0)
	{
		char* temp;
		strncpy(temp,stringA,5);
		temp[5] = 0;
		printf("Both strings start with %s",temp);
	}

	return 0; 
}

/*STRINGS:

Strings are ended with a terminator  to show where the actual text ends. This is represented in c by '\0'.

POINTERS: 
As the stack may cause a crash if it causes a stack (system stack is smol)overflow, malloc() may be used to create a variable in the system heap (mbs big) instead. free() will remove it. An example can be found below:
*/

void allocateMemory()
{
	char *p; //Empty pointer is assigned the address of the allocated memory in the system heap after casting
	p = (char*)malloc(183764);
	strcpy(p,"hello");
	free(p);//the memory can be freed up when not needed.
	//Often, you will want a specific number of chars, etc., so this can be used:
	p = (char*)malloc(sizeof(1000*char);
	free(p);
}

//Why use referencing?: With large values, it will take a while and a lot of memory space to duplicate.
//By just passing the address, you avoid the need to copy everything, saving time and space.
