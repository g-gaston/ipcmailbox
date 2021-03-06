#ifndef _MBOX_H_
#define _MBOX_H_
/* Includes */
#include "pm.h"
#include <stdlib.h>
#include <signal.h>
#include <string.h>

/* Defines */
#define MAX_LEN_MSG 256
#define MAX_N_REC 16
#define MAX_N_MSG 16
#define MAX_N_REQ 16
#define MAX_NUM_MESSAGES 16
#define MAX_NUM_MAILBOXES 16
#define MAX_LEN_NAME 10

#define MB_OK 0
#define MB_ERROR 1
#define MB_FULLMB_ERROR 2
#define MB_MAXMB_ERROR 3
#define MB_MSGTOOLONG_ERROR 4
#define MB_BUFFERTOOSMALL_ERROR 5
#define MB_EMPTYMB_ERROR 6
#define MB_FULNOTIFYLIST_ERROR 7
#define MB_NOMSG_ERROR 8
#define MB_NAME_ERROR 9
#define MB_CLOSE_ERROR 10
#define MB_ALLOC_MEM_ERROR 11

// Añadir n maximo de mailboxes y no sé si algo más

typedef struct mb_message_t {
	char *text;
	int *receivers_pid;
	int num_rec;
	struct mb_message_t *next;
} mb_message_t;

typedef struct mb_req_t {
	int pid;
	int signum;
	struct mb_req_t *next;
} mb_req_t;

typedef struct mb_mailbox_t {
	char* name;
	int id;
	mb_message_t *first_msg;
	int num_msg;
	mb_req_t *first_req;
	int num_req;
	int conn_process;
	struct mb_mailbox_t *next;
} mb_mailbox_t;

typedef struct mb_mbs_ts{
	struct mb_mailbox_t *first_mb;
	int num_mbs;
	int id_master;
} mb_mbs_t;

#endif /* _MBOX_H_ */
