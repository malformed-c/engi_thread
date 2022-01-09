#include <stdlib.h>
#include <pthread.h>

#include "engi_thread.h"

int engi_thread_init(engi_thread_t *self)
{
	self->attr = NULL;

	return 0;
}

int engi_thread_create(engi_thread_t *self, engi_task_t *task)
{
	int res = 0;

	res = pthread_create(&self->thread, self->attr, task->func, task->args);

	return res;
}

int engi_thread_join(engi_thread_t *self)
{
	int res = 0;

	res = pthread_join(self->thread, &self->retval);

	return res;
}

engi_task_t * engi_task_init(engi_task_t *task, void * func(void *), void *args)
{
	task->func = func;
	task->args = args;
	return task;
}




