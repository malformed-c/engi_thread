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
	pthread_attr_t attr;
	pthread_mutex_t mutex;
	pthread_mutexattr_t mutex_attr;
	pthread_cond_t cond;
	pthread_condattr_t cond_attr;
	void *retval;
	engi_task_t task;
} engi_thread_t;

int engi_thread_init(engi_thread_t *self);

int engi_thread_create(engi_thread_t *self);

int engi_thread_join(engi_thread_t *self);

void engi_thread_exit(void *retptr) __attribute__ ((noreturn));

int engi_task_init(engi_task_t *task, void * func(void *), void *args);

int engi_mutex_lock(engi_thread_t *self);

int engi_mutex_unlock(engi_thread_t *self);

int engi_cond_signal(engi_thread_t *self);

int engi_cond_broadcast(engi_thread_t *self);

int engi_cond_wait(engi_thread_t *self);
