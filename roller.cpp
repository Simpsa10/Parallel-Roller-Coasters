/* This program will use parallel programming techniques to simulate roller coasters running in unison. 
   Only one roller coster is allowed to run at one time */

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
using namespace std;

void *load(void *);
void *go(void *);

sem_t e, s;
int ride = 1;
int n = 0;
int c = 0;

int main(int argc, char**argv)
	{
	n = atoi(argv[1]);
	c = atoi(argv[2]);

	sem_init(&e, 0, 1);
	sem_init(&s, 0, 0);

	pthread_t t1,t2;
	
	pthread_create(&t1,NULL,load,NULL);
	pthread_create(&t2,NULL,go,NULL);
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	
	sem_destroy(&e);
	sem_destroy(&s);
	}	

void *load(void *arg)
{
	while(n != 0 && c <= n)
		{	
		sem_wait(&e);
		n = n-c;
		int rng = 1 + rand()% 1000000;
		usleep(rng);
	cout << c << " passengers have been loaded\n";
		sem_post(&s);
		}
}
		


void *go( void *arg)
{
	while(n != 0 && c <= n)
		{ 
		sem_wait(&s);
		cout << "Ride #" << ride << " has started\n";
		int rng = 1 + rand()% 1000000;
		usleep(rng);
		cout << "Car has returned\n";
		sem_post(&e);
		ride++;
		}
}
	
