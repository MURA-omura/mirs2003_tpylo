/**
 * @file request.h
 * @brief Arduinoへのリクエストモジュール
 * @author 岡部
 * @date 2020/11/11
 */

#ifndef __REQUEST__
#define __REQUEST__

typedef enum{
	STP = 0,
	STR,
	ROT,
	CRV
} run_state_t;

extern void request_set_runmode(run_state_t state, int speed, int dist);
extern int  request_get_runmode(run_state_t *state, int *speed, int *dist);
extern int  request_get_dist(int *dist_l, int *dist_r);
extern int  request_get_batt(double *volt);
extern void request_set_spray();
extern int  request_get_arcohol(int *pressure);

#endif
