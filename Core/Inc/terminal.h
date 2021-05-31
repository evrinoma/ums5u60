#ifndef INC_TERMINAL_H_
#define INC_TERMINAL_H_

#include <string.h>
#include <stdio.h>
#include "utils.h"
#include "fsm.h"

#define BS '\b'
#define CR '\r'
#define LF '\n'
#define CRLF "\r\n"

#define LEXEM_LENGTH 5
#define COMMAND_MAX_LENGTH 16

#define INFO_MAX_LENGTH 128
#define RESULT_MAX_LENGTH 512

typedef struct {
	uint8_t state;
	uint8_t result[RESULT_MAX_LENGTH];
} tstatus;

typedef struct taction {
	void (*operations)(tstatus *terminal, struct taction *action);
	uint8_t cmd[COMMAND_MAX_LENGTH];
	uint8_t cmd_length;
	uint8_t info[INFO_MAX_LENGTH];
	uint8_t info_length;
} taction;

tstatus command_parse(uint8_t *buff);


#endif  /* INC_TERMINAL_H_ */
