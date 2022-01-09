#pragma once

#include "common.h"

typedef struct engi_task_s
{
	void * (*func)(void *);
	void *args;
} engi_task_t;

typedef struct engi_thread_s
{
	pthread_t thread;
	pthread_attr_t *attr;
	void *retval;
	engi_task_t task;
} engi_thread_t;

engi_task_t * engi_task_init(engi_task_t *task, void * func(void *), void *args);

int engi_thread_init(engi_thread_t *self);

int engi_thread_create(engi_thread_t *self, engi_task_t *task);

int engi_thread_join(engi_thread_t *self);

