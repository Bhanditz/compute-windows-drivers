//////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2007  Qumranet All Rights Reserved
//
// Module Name:
// osdep.h
//
// Abstract:
// Windows OS dependent definitions of data types
//
// Author:
// Yan Vugenfirer  - February 2007.
//
//////////////////////////////////////////////////////////////////////////////////////////

#if defined(IGNORE_VIRTIO_OSDEP_H)
// to make simulation environment easy
#include "external_os_dep.h"
#else

#ifndef __OS_DEP_H
#define __OS_DEP_H

#include <ntddk.h>

#define ktime_t ULONGLONG
#define ktime_get() KeQueryPerformanceCounter(NULL).QuadPart

#define likely(x) x
#define unlikely(x) x

#define ENOSPC 1
#define BUG_ON(a)
#define WARN_ON(a)

#ifndef __cplusplus
#define bool int
#define false FALSE
#define true TRUE
#ifndef INLINE_DEFINED
#define inline __forceinline
#endif
#endif

#ifdef DBG
#define DEBUG
#endif

#define mb()   KeMemoryBarrier()
#define rmb()  KeMemoryBarrier()
#define wmb()  KeMemoryBarrier()
#define smp_wmb() KeMemoryBarrier()

#ifndef min
#define min(_a, _b) (((_a) < (_b)) ? (_a) : (_b))
#endif

#ifndef max
#define max(_a, _b) (((_a) > (_b)) ? (_a) : (_b))
#endif

#endif
#endif
