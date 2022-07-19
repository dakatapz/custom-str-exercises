#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sum;

void calc_sum(void *i)
{
  int a, b, sum1;
  printf("Starting my thread with calc_sum\n");
  printf("enter number1:\n");
  scanf("%d", &a);
  printf("enter number2:\n");
  scanf("%d", &b);
  sum = a + b;
  printf("Sum insinde calc_sum thread: %d\n", sum);
  pthread_exit(&sum);
}

void main()
{
  pthread_t id;
  printf("Before entering calc_sum thread\n");
  pthread_create(&id, NULL, calc_sum, NULL);
  pthread_join(id, NULL);
  printf("Sum after calling calc_sum thread: %d\n", sum);
}
