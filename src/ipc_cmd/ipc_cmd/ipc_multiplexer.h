#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <mqueue.h>

#define IPC_QUEUE_NAME          "/ipc_dispatch"
#define IPC_MESSAGE_MAX_SIZE    512

#define IPC_MOTION_START        "\x01\x00\x00\x00\x02\x00\x00\x00\x7c\x00\x7c\x00"
#define IPC_MOTION_STOP         "\x01\x00\x00\x00\x02\x00\x00\x00\x7d\x00\x7d\x00"
#define IPC_BABY_CRYING         "\x04\x00\x00\x00\x02\x00\x00\x00\x04\x60\x04\x60\x00\x00\x00\x00"


int ipc_init();
void ipc_stop();
int open_queue(int n_queue);
int parse_message(char *msg, ssize_t len);
