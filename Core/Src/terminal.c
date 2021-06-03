#include "terminal.h"
#include "action.h"

void action_help(tstatus *terminal, taction *action) {
	uint16_t amount_info_length = 0;
	uint8_t i = 0;
	terminal->state = feedback();

   for (i = 0; i < count_actions; i++) {
	   if ((amount_info_length+actions[i].cmd_length)>=RESULT_MAX_LENGTH)
			break;
		memcpy(terminal->result + amount_info_length, &actions[i].cmd, actions[i].cmd_length + 1);
		amount_info_length+=actions[i].cmd_length;
	   if ((amount_info_length+1)>=RESULT_MAX_LENGTH)
			break;
		memcpy(terminal->result + amount_info_length, "-", 2);
		amount_info_length+=1;
		if ((amount_info_length+actions[i].info_length)>=RESULT_MAX_LENGTH)
			break;
		memcpy(terminal->result + amount_info_length, &actions[i].info, actions[i].info_length + 1);
		amount_info_length+=actions[i].info_length;

	}
}

void action_on_pc13(tstatus *terminal, taction *action) {
	set_on_pc13();
	terminal->state = feedback();
	sprintf(terminal->result, action->info);
}

void action_off_pc13(tstatus *terminal, taction *action) {
	set_off_pc13();
	terminal->state = feedback();
	sprintf(terminal->result, action->info);
}

void action_on_pc15(tstatus *terminal, taction *action) {
	set_on_pc15();
	terminal->state = feedback();
	sprintf(terminal->result, action->info);
}

void action_off_pc15(tstatus *terminal, taction *action) {
	set_off_pc15();
	terminal->state = feedback();
	sprintf(terminal->result, action->info);
}

void action_on_blink(tstatus *terminal, taction *action) {
	set_on_blink();
	terminal->state = feedback();
	sprintf(terminal->result, action->info);
}

void action_off_blink(tstatus *terminal, taction *action) {
	set_off_blink();
	terminal->state = feedback();
	sprintf(terminal->result, action->info);
}

void action_cdc_feedback(tstatus *terminal, taction *action) {
	set_cdc_feedback();
	terminal->state = feedback();
	sprintf(terminal->result, action->info);
}

void action_off_feedback(tstatus *terminal, taction *action) {
	set_off_feedback();
	terminal->state = feedback();
	sprintf(terminal->result, action->info);
}

void action_on_adc(tstatus *terminal, taction *action) {
	set_on_adc();
	terminal->state = feedback();
	sprintf(terminal->result, action->info);
}

void action_off_adc(tstatus *terminal, taction *action) {
	set_off_adc();
	terminal->state = feedback();
	sprintf(terminal->result, action->info);
}

void action_adc(tstatus *terminal, taction *action) {
	float value = 0;
	value = get_sense_12V_normalized();
	terminal->state = feedback();
	sprintf(terminal->result, "%.2fv\r\n", value);
}

void action_status(tstatus *terminal, taction *action) {
	terminal->state = feedback();
	sprintf(terminal->result, action->info);
}

void action_write(tstatus *terminal, taction *action)
{
	write_config();
	terminal->state = feedback();
	sprintf(terminal->result, action->info);
}

void action_read(tstatus *terminal, taction *action)
{
	terminal->state = feedback();
	sprintf(terminal->result, action->info);
}

void action_dev(tstatus *terminal, taction *action)
{
	terminal->state = feedback();
	sprintf(terminal->result, "REVID: %u DEVID: %u\r\n",  HAL_GetREVID(), HAL_GetDEVID());
}

tstatus command_parse(uint8_t *buff) {
	tstatus terminal = { CMD_ERASE, { 0 } };
	uint8_t *list_lexems[LEXEM_LENGTH] = { 0 };
	uint8_t i = 0;
	uint8_t *lexem;

	for (lexem = strtok(buff, " \r"); lexem != NULL;
			lexem = strtok(NULL, " \r")) {
		list_lexems[i] = lexem;
		i++;
	}

	for (i = 0; i < count_actions; i++) {
		if (!strncmp(list_lexems[0], actions[i].cmd, actions[i].cmd_length)) {
			actions[i].operations(&terminal, &actions[i]);
			break;
		}
	}

	return terminal;
}
