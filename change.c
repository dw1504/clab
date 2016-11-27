#include <stdio.h>

int main (int argc, char **argv){
        char **s;
        char foo[] = "Hello World";
  
        *s = foo;
        printf("s is %s\n", s);
       
        s[0] = foo;
	printf("s[0] is %s\n", s[0]);
	return 0;
}
