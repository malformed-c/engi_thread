#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <signal.h>

#include "engi_thread.h"

void * work_test()
{
	static int c = 0;
	printf("test %d\n", c++);
	return NULL;
}

int main()
{
	engi_thread_t th;

	engi_thread_init(&th);

	th.task.func = work_test;
	th.task.args = NULL;

	engi_thread_create(&th);

	engi_thread_join(&th);

	return 0;
}
