#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void timeout(int sig) {
    if (sig == SIGALRM) {
        puts("time out! ");
    }
    alarm(2);
}

int main(int argc, char const *argv[]) {
    int i;
    struct sigaction act;
    act.sa_handler = timeout;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGALRM, &act, 0);  // 效果类似于signal

    alarm(2);
    for (i = 0; i < 5; ++i)
    {
        puts("waits...");
        sleep(100);
    }
    return 0;
}