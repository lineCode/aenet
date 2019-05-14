#include <stdio.h>
#include <stdlib.h>
#include "ae.h"

#define UNUSED(V) ((void) V)

void beforeSleep(struct aeEventLoop *eventLoop);
void afterSleep(struct aeEventLoop *eventLoop);
int serverCron(struct aeEventLoop *eventLoop, long long id, void *clientData);

int main(void)
{
    aeEventLoop* el = aeCreateEventLoop(10);
    aeSetBeforeSleepProc(el, beforeSleep);
    aeSetAfterSleepProc(el, afterSleep);
    aeCreateTimeEvent(el, 1000, serverCron, NULL, NULL);
    aeMain(el);
    aeDeleteEventLoop(el);
    return 0;
}

void beforeSleep(struct aeEventLoop *eventLoop)
{
    UNUSED(eventLoop);
    printf("beforeSleep\n");
}

void afterSleep(struct aeEventLoop *eventLoop)
{
    UNUSED(eventLoop);
    printf("afterSleep\n");
}

int serverCron(struct aeEventLoop *eventLoop, long long id, void *clientData)
{
    UNUSED(eventLoop);
    UNUSED(id);
    UNUSED(clientData);
    printf("hello, world!\n");
    return -1;
}