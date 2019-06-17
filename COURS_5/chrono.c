#include <sys/time.h>

static struct timeval t0;

void start(){
    gettimeofday(&t0, 0);
}

float timedifference_msec(struct timeval t0, struct timeval t1){
  return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

float stop(){
  struct timeval t1;
  gettimeofday(&t1, 0);
  return timedifference_msec(t0, t1);
}
