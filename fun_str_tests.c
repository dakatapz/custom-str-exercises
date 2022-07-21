#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strcat1(char *s, char *t, char *q) {
  int i;
  int p = strlen(t) + strlen(q);
  for (i=0; i < p; i++) {
   if (*t != '\0') {
     *s = *t;
     t++;
     s++;
   } else if ((*t == '\0') && (*q != '\0')) {
     *s = *q;
     q++;
     s++;
   }
  }
  *s = '\0';
}

int strend1(char *s, char *t) {
  int a = strlen(s) - strlen(t);
  int i = strlen(t);
  for (i = 0; i < strlen(t) +1; i++) {
    if( *(s + a + i) == *(t + i))
      return 1;
    else
      return 0;
  }
}

int strncmp1 (char *s, char *t, int n){
  int i, k;
  k = strlen(s);
  for (i = 0; i < n; i++) {
   while (*s != '\0') {
      if (*(s+i) == *(t + i)) {
         printf("%s\n", t+i);
         return 1;
      }
      s++;
   }
  }
  return 0;
}

int strncpy1 (char *s, char *t, int n)
{
  int i, k;
  k = strlen(t) - n;
  for ( i = 0; i < n; i++)
    *(s + i) = *(t+k+i);
  if (*s != '\0')
    return 1;
  return 0;
}

void main (void) {
 char *str1 = "my test";
 char *str2 = "pk";
 char *my_strcat, *test_strncpy1;
 my_strcat = malloc(strlen(str1) + 1); 
 int len1 = 0, len2 = 0, len = 0, i, k, l, p=4;
 len1 = strlen(str1);
 len2 = strlen(str2);

 test_strncpy1 = malloc(p);

 len = len1 + len2;
 printf("first string is: %s\n",  str1);
 printf("second string is: %s\n", str2);

 strcat1(my_strcat, str1, str2);
 printf("%s\n", my_strcat);
 free (my_strcat);

 if (i = strend1(str1, str2))
    printf("Str2 is present at the end of str1\n");
 else
    printf("No match!\n");

 if (k = strncmp1(str1, str2, 1))
    printf("first n characters of str2 are found in str1\n");
 else
    printf("none of the N characters match\n");

 if (l = strncpy1(test_strncpy1, str1, p))
    printf("%s\n", test_strncpy1);
 else
    printf("ERROR!\n");
 free(test_strncpy1);
}
