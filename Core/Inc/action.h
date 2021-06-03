#ifndef INC_ACTION_H_
#define INC_ACTION_H_

#define STATUS "status"
#define STATUS_INFO "control status\r\n"

#define HELP "help"
#define HELP_INFO "Display all commands\r\n"

#define ON_PC13 "on_pc13"
#define ON_PC13_INFO "Turn on pin pc13\r\n"

#define OFF_PC13 "off_pc13"
#define OFF_PC13_INFO "Turn off pin pc13\r\n"

#define ON_PC15 "on_pc15"
#define ON_PC15_INFO "Turn on pin pc15\r\n"

#define OFF_PC15 "off_pc15"
#define OFF_PC15_INFO "Turn off pin pc15\r\n"

#define ON_BLINK "on_blink"
#define ON_BLINK_INFO "Blinking on\r\n"

#define OFF_BLINK "off_blink"
#define OFF_BLINK_INFO "Blinking off\r\n"

#define CDC_FB "cdc_fb"
#define CDC_FB_INFO "Feedback via USB cdc\r\n"

#define OFF_FB "off_fb"
#define OFF_FB_INFO "Feedback off\r\n"

#define ON_ADC "on_adc"
#define ON_ADC_INFO "ADC on\r\n"

#define OFF_ADC "off_adc"
#define OFF_ADC_INFO "ADC off\r\n"

#define ADC "adc"
#define ADC_INFO "ADC value\r\n"

#define WRITE "wri"
#define WRITE_INFO "save config\r\n"

#define READ "read"
#define READ_INFO "read config\r\n"

#define DEV "dev"
#define DEV_INFO "read config\r\n"

void action_help(tstatus *terminal, taction *action);
void action_on_pc13(tstatus *terminal, taction *action);
void action_off_pc13(tstatus *terminal, taction *action);
void action_on_pc15(tstatus *terminal, taction *action);
void action_off_pc15(tstatus *terminal, taction *action);
void action_on_blink(tstatus *terminal, taction *action);
void action_off_blink(tstatus *terminal, taction *action);
void action_cdc_feedback(tstatus *terminal, taction *action);
void action_off_feedback(tstatus *terminal, taction *action);
void action_on_adc(tstatus *terminal, taction *action);
void action_off_adc(tstatus *terminal, taction *action);
void action_adc(tstatus *terminal, taction *action);
void action_status(tstatus *terminal, taction *action);
void action_write(tstatus *terminal, taction *action);
void action_read(tstatus *terminal, taction *action);
void action_dev(tstatus *terminal, taction *action);

taction actions[] = {
		{ action_help, HELP, strlen(HELP), HELP_INFO,  strlen(HELP_INFO)},
		{ action_on_pc13, ON_PC13,strlen(ON_PC13), ON_PC13_INFO,  strlen(ON_PC13_INFO) },
		{ action_off_pc13, OFF_PC13, strlen(OFF_PC13), OFF_PC13_INFO,  strlen(OFF_PC13_INFO) },
		{ action_on_pc15, ON_PC15,strlen(ON_PC15), ON_PC15_INFO,  strlen(ON_PC15_INFO) },
		{ action_off_pc15, OFF_PC15, strlen(OFF_PC15), OFF_PC15_INFO,  strlen(OFF_PC15_INFO) },
		{ action_on_blink, ON_BLINK, strlen(ON_BLINK), ON_BLINK_INFO,  strlen(ON_BLINK_INFO) },
		{ action_off_blink, OFF_BLINK, strlen(OFF_BLINK), OFF_BLINK_INFO,  strlen(OFF_BLINK_INFO) },
		{ action_cdc_feedback, CDC_FB, strlen(CDC_FB), CDC_FB_INFO,  strlen(CDC_FB_INFO) },
		{ action_off_feedback, OFF_FB, strlen(OFF_FB), OFF_FB_INFO,  strlen(OFF_FB_INFO) },
		{ action_on_adc, ON_ADC, strlen(ON_ADC), ON_ADC_INFO,  strlen(ON_ADC_INFO) },
		{ action_off_adc, OFF_ADC, strlen(OFF_ADC), OFF_ADC_INFO,  strlen(OFF_ADC_INFO) },
		{ action_adc, ADC, strlen(ADC), ADC_INFO,  strlen(ADC_INFO) },
		{ action_write, WRITE, strlen(WRITE), WRITE_INFO,  strlen(WRITE_INFO) },
		{ action_read, READ, strlen(READ), READ_INFO,  strlen(READ_INFO) },
		{ action_status, STATUS, strlen(STATUS), STATUS_INFO,  strlen(STATUS_INFO) },
		{ action_dev, DEV, strlen(DEV), DEV_INFO,  strlen(DEV_INFO) }
};

uint8_t count_actions = sizeof(actions) / sizeof(actions[0]);

#endif /* INC_ACTION_H_ */
