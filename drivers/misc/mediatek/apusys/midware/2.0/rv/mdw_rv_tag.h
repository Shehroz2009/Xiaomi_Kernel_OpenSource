/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2020 MediaTek Inc.
 */

#ifndef __MTK_APU_MDW_APTAG_H__
#define __MTK_APU_MDW_APTAG_H__

#include "mdw_rv.h"
#define MDW_TAGS_CNT (3000)

enum mdw_cmd_status {
	MDW_CMD_ENQUE,
	MDW_CMD_START,
	MDW_CMD_DONE,
};

struct mdw_rv_tag {
	int type;

	union mdw_tag_data {
		struct mdw_tag_cmd {
			uint32_t status;
			pid_t pid;
			pid_t tgid;
			uint64_t uid;
			uint64_t kid;
			uint64_t rvid;
			uint32_t num_subcmds;
			uint32_t num_cmdbufs;
			uint32_t priority;
			uint32_t softlimit;
			uint32_t pwr_dtime;
			uint64_t sc_rets;
		} cmd;
	} d;
};

int mdw_rv_tag_init(void);
void mdw_rv_tag_deinit(void);
void mdw_rv_tag_show(struct seq_file *s);
void mdw_cmd_trace(struct mdw_cmd *c, uint32_t status);

#endif
