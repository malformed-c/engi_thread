#include <stdlib.h>
#include <pthread.h>

#include "engi_thread.h"

int engi_thread_init(engi_thread_t *self)
{
	pthread_attr_init(&self->attr);

	pthread_mutexattr_init(&self->mutex_attr);
	pthread_mutexattr_settype(&self->mutex_attr, PTHREAD_MUTEX_ERRORCHECK);
	pthread_mutexattr_setrobust(&self->mutex_attr, PTHREAD_MUTEX_ROBUST);

	pthread_mutex_init(&self->mutex, &self->mutex_attr);

	pthread_condattr_init(&self->cond_attr);
	pthread_cond_init(&self->cond, &self->cond_attr);

	return 0;
}

int engi_thread_create(engi_thread_t *self)
{
	int ret = 0;

	engi_task_t *task = &self->task;

	ret = pthread_create(&self->thread, &self->attr, task->func, task->args);

	return ret;
}

int engi_thread_join(engi_thread_t *self)
{
	int ret = 0;

	ret = pthread_join(self->thread, &self->retval);

	return ret;
}

void engi_thread_exit(void *retptr)
{
	pthread_exit(retptr);
}

int engi_task_init(engi_task_t *task, void * func(void *), void *args)
{
	task->func = func;
	task->args = args;
	
	return 0;
}

int engi_mutex_lock(engi_thread_t *self)
{
	int ret = 0;

	ret = pthread_mutex_lock(&self->mutex);

	return ret;
}

int engi_mutex_unlock(engi_thread_t *self)
{
	int ret = 0;

	ret = pthread_mutex_unlock(&self->mutex);

	return ret;
}

int engi_cond_signal(engi_thread_t *self)
{
	int ret = 0;

	ret = pthread_cond_signal(&self->cond);

	return ret;
}

int engi_cond_broadcast(engi_thread_t *self)
{
	int ret = 0;

	ret = pthread_cond_broadcast(&self->cond);

	return ret;
}

int engi_cond_wait(engi_thread_t *self)
{
	int ret = 0;

	ret = pthread_cond_wait(&self->cond, &self->mutex);

	return ret;
}