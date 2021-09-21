/*Look at some of the other programs in user/ (e.g., user/echo.c, user/grep.c, and user/rm.c) 
to see how you can obtain the command-line arguments passed to a program.*/
//If the user forgets to pass an argument, sleep should print an error message.
//The command-line argument is passed as a string; you can convert it to an integer using atoi (see user/ulib.c).
//Use the system call sleep.直接调用sleep系统调用即可
/*See kernel/sysproc.c for the xv6 kernel code that implements the sleep system call (look for sys_sleep), 
user/user.h for the C definition of sleep callable from a user program, 
and user/usys.S for the assembler code that jumps from user code into the kernel for sleep.*/
//Make sure main calls exit() in order to exit your program.
/*Add your sleep program to UPROGS in Makefile; once you've done that,
make qemu will compile your program and you'll be able to run it from the xv6 shell.*/
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"//fprintf，exit,sleep的定义都在这里
int main(int argc, char *argv[])/*热知识：main的第一个参数是参数个数，第二个参数是参数字符串的数组，
第0个参数一般是程序的绝对名称(路径＋文件名)*/
{
    if (argc != 2)
    {
        fprintf(2,"Usage:sleep seconds\n");
        exit(1);//这里一定不要忘记调用exit系统调用，表明异常退出
    }
    int time = atoi(argv[1]);
    sleep(time);
    exit(0);//千万不要用return 0代替
}
