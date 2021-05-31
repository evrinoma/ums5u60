#ifndef INC_FSM_H_
#define INC_FSM_H_

#define IDLE               0x01U
#define INIT               (IDLE+1)
#define INIT_GPIO          (INIT+1)
#define ENABLE_3V3         (INIT_GPIO+1)
#define ENABLE_VCORE_GTH   (ENABLE_3V3+1)
#define ENABLE_1V8         (ENABLE_VCORE_GTH+1)
#define ENABLE_BR          (ENABLE_1V8+1)
#define INIT_SI5341        (ENABLE_BR+1)
#define TPS_CFG            (INIT_SI5341+1)
#define INIT_USB           (TPS_CFG+1)
#define CMD	               (INIT_USB+1)
#define CMD_PARSE          (CMD+1)
#define CMD_ERASE          (CMD_PARSE+1)
#define CMD_BS             (CMD_ERASE+1)
#define FEEDBACK_DISABLED  (CMD_BS+1)
#define FEEDBACK_CDC       (FEEDBACK_DISABLED+1)

#endif /* INC_FSM_H_ */
