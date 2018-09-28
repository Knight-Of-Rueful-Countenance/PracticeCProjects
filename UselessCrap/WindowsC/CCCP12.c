#include <stdio.h>
#include <string.h>
union u{
      char s[4];
      int i;
}x;

int main(int argc,char* argv[])
{
	x.i=7303014;
	printf("x.i=%d, x.s[0]='%c', x.s[1]='%c',x.s[2]='%c',x.s[3]='%c',x.s=\"%s\"\n",
			x.i,x.s[0],x.s[1],x.s[2],x.s);
	printf("x.s[0]=0%o,x.s[1]=0%o,x.s[2]=0%o,x.s[3]=0%o\n",
	                x.s[0],x.s[1],x.s[2]);
	strcpy(x.s,"foo");
	printf("x.i=%d, x.s[0]='%c', x.s[1]='%c',x.s[2]='%c',x.s[3]='%c',x.s=\"%s\"\n",
	        x.i,x.s[0],x.s[1],x.s[2],x.s);
	printf("x.s[0]=0%o,x.s[1]=0%o,x.s[2]=0%o,x.s[3]=0%o\n",
	        x.s[0],x.s[1],x.s[2]);
}

//Why didn't I do this earlier?


/*

Unions, unlike structs, only store one variable in them. However, they have the capacity to store any of the types specified.
When a union is created, space equal to its largest member is allocated.


To access the union, simply store data in it like you would a struct. e.g. "UnionA.charData = 'b'".
If the union is already occupied, the previous value will be overwritten.


USES: 
Say you don't want to be repeatedly allocating new variables within a small scope due to memory constraints, and that
you only need each variable breifly, one at a time. By using unions, one can save space by saving all values in the same
memory location, rather than having to use the variable heap instead with malloc.
*/