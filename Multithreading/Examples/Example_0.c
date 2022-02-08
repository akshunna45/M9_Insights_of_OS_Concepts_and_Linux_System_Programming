#include "stdio.h"
#include "pthread.h"
#include "stdlib.h"
int array[100] ;

void fill_array(int* arr, int size)
{
for (size_t i = 0; i < size; i++)
{
arr[i] = i;
}
}
long sequential_sum(int* arr, int size)
{
long sum = 0;
for (size_t i = 0; i < size; i++)
{
sum += arr[i];
}
return sum;
}
void* thread_sum(void* param)
{
long sum = 0;
for (size_t i = 0; i < 100; i++)
{
sum += ((int*)param)[i];
}
//return sum;
pthread_exit((void *)sum);
}

int main()
{
pthread_t tid;
int sum = 0;

fill_array(array, 100);
printf("Sequential Sum = %ld\n", sequential_sum(array, 100));

pthread_create(&tid, NULL, thread_sum, (void*)array);

void* temp= malloc(sizeof(long));

pthread_join(tid, &temp);
printf("Thread Sum = %ld\n", ((long int*)temp));

return 0;
}
