/*
 * Copyright © 2017 Google.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#ifndef RADV_DEBUG_H
#define RADV_DEBUG_H

#include "radv_private.h"

/* Please keep docs/envvars.rst up-to-date when you add/remove options. */
enum {
	RADV_DEBUG_NO_FAST_CLEARS    = 1 << 0,
	RADV_DEBUG_NO_DCC            = 1 << 1,
	RADV_DEBUG_DUMP_SHADERS      = 1 << 2,
	RADV_DEBUG_NO_CACHE          = 1 << 3,
	RADV_DEBUG_DUMP_SHADER_STATS = 1 << 4,
	RADV_DEBUG_NO_HIZ            = 1 << 5,
	RADV_DEBUG_NO_COMPUTE_QUEUE  = 1 << 6,
	RADV_DEBUG_ALL_BOS           = 1 << 7,
	RADV_DEBUG_NO_IBS            = 1 << 8,
	RADV_DEBUG_DUMP_SPIRV        = 1 << 9,
	RADV_DEBUG_VM_FAULTS         = 1 << 10,
	RADV_DEBUG_ZERO_VRAM         = 1 << 11,
	RADV_DEBUG_SYNC_SHADERS      = 1 << 12,
	RADV_DEBUG_PREOPTIR          = 1 << 13,
	RADV_DEBUG_NO_DYNAMIC_BOUNDS = 1 << 14,
	RADV_DEBUG_NO_OUT_OF_ORDER   = 1 << 15,
	RADV_DEBUG_INFO              = 1 << 16,
	RADV_DEBUG_ERRORS            = 1 << 17,
	RADV_DEBUG_STARTUP           = 1 << 18,
	RADV_DEBUG_CHECKIR           = 1 << 19,
	RADV_DEBUG_NOTHREADLLVM      = 1 << 20,
	RADV_DEBUG_NOBINNING         = 1 << 21,
	RADV_DEBUG_NO_NGG            = 1 << 22,
	RADV_DEBUG_ALL_ENTRYPOINTS   = 1 << 23,
	RADV_DEBUG_DUMP_META_SHADERS = 1 << 24,
	RADV_DEBUG_NO_MEMORY_CACHE   = 1 << 25,
	RADV_DEBUG_DISCARD_TO_DEMOTE = 1 << 26,
	RADV_DEBUG_LLVM              = 1 << 27,
};

enum {
	RADV_PERFTEST_LOCAL_BOS       = 1 << 0,
	RADV_PERFTEST_DCC_MSAA        = 1 << 1,
	RADV_PERFTEST_BO_LIST         = 1 << 2,
	RADV_PERFTEST_TC_COMPAT_CMASK = 1 << 3,
	RADV_PERFTEST_CS_WAVE_32      = 1 << 4,
	RADV_PERFTEST_PS_WAVE_32      = 1 << 5,
	RADV_PERFTEST_GE_WAVE_32      = 1 << 6,
	RADV_PERFTEST_DFSM            = 1 << 7,
};

bool
radv_init_trace(struct radv_device *device);

void
radv_check_gpu_hangs(struct radv_queue *queue, struct radeon_cmdbuf *cs);

void
radv_print_spirv(const char *data, uint32_t size, FILE *fp);

void
radv_dump_enabled_options(struct radv_device *device, FILE *f);

#endif
