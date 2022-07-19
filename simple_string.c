#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void main()
{ 
  uint8_t a = 0xAF;
  char tmp, tmp1;
  char ret;

  //actual conversion;
  tmp = ((a & 0xF0) >> 4) & 0xF;
  if ((tmp >= 0) && (tmp <= 9)) {
      ret = tmp + '0';
      printf("First character is: %c\n", ret);
  } else if ((tmp >= 'a') && (tmp <= 'f')) {
      ret = tmp - ('a' + 10);
      printf("First character is: %c\n", ret);
  } else if ((tmp >= 'A') && (tmp <= 'F')) {
      ret = tmp - ('A' + 10);
      printf("First character is: %c\n", ret);
  }

  tmp1 = (a & 0xF);
  if ((tmp1 >= 0) && (tmp1 <= 9)) {
      ret = tmp1 - '0';
      printf("Second character is: %c\n", ret);
  } else if ((tmp1 >= 'a') && (tmp1 <= 'f')) {
      ret = tmp1 - ('a' + 10);
      printf("Second character is: %c\n", ret);
  } else if ((tmp1 >= 'A') && (tmp1 <= 'F')) {
      ret = tmp1 - ('A' + 10);
      printf("Second character is: %c\n", ret);
  }
}
