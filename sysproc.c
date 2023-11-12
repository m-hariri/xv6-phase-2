#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_get_process_lifetime(void)
{
  int pid;
  if(argint(0, &pid) < 0)
    return -1;

  return get_process_lifetime(pid);
}

int
sys_cp(void){
  return 3;
  /*char buf[512];
  int fd, dfd, r, w;
  char *src;
  char *dest;

  if(argc != 3){
    printf(2, "Usage: cp src dest\n");
    exit();
  }

  src = argv[1];
  dest = argv[2];

  if ((fd = open(src, O_RDONLY)) < 0) {
    printf(2, "cp: cannot open source %s\n", src);
    exit();
  }
  if ((dfd = open(dest, O_CREATE|O_WRONLY)) < 0) {
    printf(2, "cp: cannot open destination %s\n", dest);
    exit();
  }
  
  while ((r = read(fd, buf, sizeof(buf))) > 0) {
    w = write(dfd, buf, r);
    if (w != r || w < 0) 
      break;
  }
  if (r < 0 || w < 0)
    printf(2, "cp: error copying %s to %s\n", src, dest);

  close(fd);
  close(dfd);*/

}

int
sys_digitalRoot(void){
  int num;
  if(argint(0,&num)<0){
    return -1;
  }
  if(num<0)
  return -1;
  int temp=num;
  while (num > 9) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    cprintf("digital root of %d is: %d\n", temp,num);
    return num;

}

int
sys_uncleCount(void){
  int pid; 

   if(argint(0,&pid)<0){
    return -1;
  }
  //cprintf("I'm %d ---parent %d input is %d\n", myproc()->pid,myproc()->parent->pid, pid);
  int out= uncleCount_(pid);
  
  cprintf("-process %d 's parent is %d and has %d uncle\n", pid, myproc()->parent->pid,out);
  return out;

}