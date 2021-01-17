#include <stdio.h>

/* count blanks, tabs, and newlines. */
main()
{
	int bc, tc, nc;
	int c;

	bc = tc = nc = 0;
	while ((c = getchar()) != EOF) {
	    if (c == ' ')
  	    	++bc;
	    if (c == '\t')
		++tc;
	    if (c == '\n')
		++nc;
	}
	printf(" blanks   : %d\n tabs     : %d\n newlines : %d\n", bc, tc, nc);
}


