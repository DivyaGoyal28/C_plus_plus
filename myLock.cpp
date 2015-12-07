#include <pthread.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define msleep(a) usleep(a*1000)
#define MUTEX_LOCK(a) while(a);a=1;
#define MUTEX_UNLOCK(a) (a=0)
int shared_var;
struct context
{
  int mutex_id;
  int m_exit;

} context;
void *
read_fun (void *args)
{
  struct context *c = (struct context *) args;

  while (!c->m_exit)
    {
      msleep (1000);
      printf ("%s\n", __FUNCTION__);
      MUTEX_LOCK (c->mutex_id);
      printf ("shared_var=%d\n", shared_var);
      MUTEX_UNLOCK (c->mutex_id);
    }

}

void *
write_fun1 (void *args)
{
  struct context *c = (struct context *) args;
  while (!c->m_exit)
    {
      msleep (1000);
      printf ("%s\n", __FUNCTION__);
      MUTEX_LOCK (c->mutex_id);
      shared_var++;
      MUTEX_UNLOCK (c->mutex_id);
    }
}

void *
write_fun2 (void *args)
{
  struct context *c = (struct context *) args;

  int fd = open ("my_file.txt", O_CREAT);
  if (fd > 0)
    {
      while (!c->m_exit)
	{
	  msleep (1000);
	  printf ("%s\n", __FUNCTION__);
	  MUTEX_LOCK (c->mutex_id);
	  printf ("write returns %d", write (fd, "hello", 6));
	  printf ("errno %s", strerror(errno));
	  MUTEX_UNLOCK (c->mutex_id);
	}
    }
}

int
main ()
{
  pthread_t reader;
  pthread_t writer1, writer2;
  context.m_exit = 0;
  printf ("%s\n", __FUNCTION__);
  pthread_create (&reader, NULL, read_fun, &context);	//(id,attribute,
  pthread_create (&writer1, NULL, write_fun1, &context);
  pthread_create (&writer2, NULL, write_fun2, &context);
  pthread_join (reader, NULL);
  pthread_join (writer1, NULL);
  pthread_join (writer2, NULL);
  return 0;
}
