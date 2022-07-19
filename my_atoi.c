#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//need to revisit return in case of integer not valid
int my_atoi(int result, char *s)
{
  int i, len;
  len = strlen(s);
  result = 0;
  if (s[0] == '-') {
   for (i=1; i < len; i++) {
    if(s[i] >= '0' && s[i] <='9')
      result = (result*10 + s[i] - '0');
    else 
      printf("Not a valid int!\n");
   }
   result = (-1)*result;
  } else {
   for (i = 0; i < len; i++){
       if(s[i] >= '0' && s[i] <= '9')
         result = result*10 + s[i] - '0';
       else
         printf("Not a valid int!\n");
   }
  }
  return result;
}

void main() {
  int actual_result, tmp;
  char *t = "-5647";

  actual_result = my_atoi(tmp, t);
  printf("%d\n", actual_result);
}
