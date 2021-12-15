write     write(fichero, string, strlen(string));
ft_printf [y cualquier equivalente que TÚ hayas programado]
signal    https://man7.org/linux/man-pages/man7/signal.7.html
    sigemptyset
    sigaddset
    sigaction                                                     **bonus (estructura para tratar las. señales)
    kill
getpid     pid_t getpid(void);                        unistd.h   getpid() returns the process ID (PID) of the calling process.
                                                                 (This is often used by routines that generate unique temporary
                                                                 filenames.)
malloc     void *malloc(size_t size);                stdlib.h    The malloc() function allocates size bytes and returns a pointer
                                                                 to the allocated memory.
free       void free(*string);                       stdlib.h    free displays the total amount of free and used physical and swap
                                                                 memory in the system, as well as the buffers and caches used by
                                                                 the kernel.
pause      int pause(void);                          unistd.h    pause() causes the calling process (or thread) to sleep until a
                                                                 signal is delivered that either terminates the process or causes
                                                                 the invocation of a signal-catching function.
sleep     unsigned int sleep(unsigned int seconds);  unistd.h    sleep() causes the calling thread to sleep either until the
                                                                 number of real-time seconds specified in seconds have elapsed or
                                                                 until a signal arrives which is not ignored.
                                                  
usleep    int usleep(useconds_t usec);               unistd.h    The usleep() function suspends execution of the calling thread
                                                                 for (at least) usec microseconds.  The sleep may be lengthened
                                                                 slightly by any system activity or by the time spent processing
                                                                 the call or by the granularity of system timers.
exit      noreturn void exit(int status);            unistd.h    The exit() function causes normal process termination and the
                                                                 least significant byte of status (i.e., status & 0xFF) is
                                                                 returned to the parent 
STDOUT_FILENO
STDIN_FILENO
