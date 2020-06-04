/*
 * timer.c : Sample C code to create a timer using signal
 */

#include <stdio.h>
#include <sys/time.h>
#include <signal.h>

/* Signal handler */
typedef void (*sighandler_t)(int);

/*
 * timer_handler : API that is triggered using signal
 */
int timer_handler(void)
{
	printf("\nTimer API triggered");
	return 0;
}

/*
 * Main API
 */
int main()
{
	/* Setting the timer values */
        struct timeval my_value={1,0};
        struct timeval my_interval={5,0};
        struct itimerval my_timer={my_interval,my_value};

	/* Setting the timer behavior */
        setitimer(ITIMER_REAL, &my_timer, 0);

	/* Assigning the signal handler */
        signal(SIGALRM, (sighandler_t)timer_handler);

	/* 
	 * Loop to run the main thread so that we can observe
	 * that the timer is running 
	 */
	while(1);

        return 0;
}

