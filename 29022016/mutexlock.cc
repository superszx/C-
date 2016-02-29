 ///
 /// @file    mutexlock.cc
 /// @author  苏志贤(529203156@qq.com)
 /// @date    2016-02-29 18:59:54
 ///

 //封装一个互斥锁的类，
 //完成多线程进行 1 ~ 10，000，000*线程数 的加法操作
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#define MAXNUM 10000000
class Mutex
{
	public:
		Mutex();
		~Mutex();
		void lock();
		void unlock();
	private:
		pthread_mutex_t _mutex;
};
struct factory{
	Mutex mutex;
	int num;
};

Mutex::Mutex()
{
	int ret;
	ret = pthread_mutex_init(&_mutex,NULL);
	if(-1 == ret)
	{
		perror("pthread_mutex_t");
		exit(-1);
		}
}

Mutex::~Mutex()
{
	int ret;
	ret = pthread_mutex_destroy(&_mutex);
	if(EBUSY == ret)
	{
		pthread_mutex_unlock(&_mutex);
		pthread_mutex_destroy(&_mutex);
	}
}

void Mutex::lock()
{
	pthread_mutex_lock(&_mutex);
}

void Mutex::unlock()
{
	pthread_mutex_unlock(&_mutex);
}

void * PthreadHandle(void *p)
{
	struct factory *pfac = (struct factory *)p;
	int i;
	for(i=0;i<MAXNUM;++i)
	{
		pfac->mutex.lock();
		++ pfac->num;
		pfac->mutex.unlock();
	}
	pthread_exit(0);
}

using std::cout;
using std::endl;
int main()
{
	struct factory fac;
	fac.num = 0;
	pthread_t tid[3];
	int i;
	int ret;
	for(i=0;i<3;++i)
	{
		ret = pthread_create(&tid[i],NULL,PthreadHandle,(void *)&fac);
		if(-1 == ret)
		{
			perror("pthread_create");
			exit(-1);
		}
	}
	for(i=0;i<3;++i)
		pthread_join(tid[i],NULL);
	cout << "the total num = " << fac.num << endl;
	return 0;
}


