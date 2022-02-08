#include"stdio.h"
#include"pthread.h"
#include "semaphore.h"

int val = 100; 
int NUM = 100;

void *task_body1(void *pv) 
{
  for (int i = 1; i <= NUM; i++) 
  {
    // CS start
    pthread_mutex_lock(&m1);
    val++;
    // CS end
    pthread_mutex_unlock(&m1);
  }
}
void *task_body2(void *pv) 
{
  for (int i = 1; i <= NUM; i++) 
  {
    pthread_mutex_lock(&m1);
    val--;
    pthread_mutex_unlock(&m1);
  }
}
int main() 
{
  pthread_t pt1, pt2;
  pthread_mutex_init(&m1, NULL);
  pthread_create(&pt1, NULL, task_body1, NULL);
  pthread_create(&pt2, NULL, task_body2, NULL);
  pthread_join(pt1, NULL);
  pthread_join(pt2, NULL);
  printf("main--thank you, value=%d\n", val);
  return 0;
}