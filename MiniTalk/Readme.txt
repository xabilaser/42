write     write(fichero, string, strlen(string));
ft_printf [y cualquier equivalente que TÚ hayas programado]
signal    https://man7.org/linux/man-pages/man7/signal.7.html
    sigemptyset
    sigaddset
    sigaction                                                     
    kill
sigaction                                                       **bonus (estructura para tratar las. señales)
            struct sigaction {
                void    (*sa_handler)(int);    //addr of signal handler, or SIG_IGN, or SIG_DFL 
                sigset_t    sa_mask;           //additional signals to block 
                int    sa_flags;               //signal options
               };
                
getpid     pid_t getpid(void);                        unistd.h   getpid() returns the process ID (PID) of the calling process.
                                                                 (This is often used by routines that generate unique temporary
                                                                 filenames.)

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
No usadas:                                                                 returned to the parent 
STDOUT_FILENO
STDIN_FILENO
malloc
free
