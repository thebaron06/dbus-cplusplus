/*
 *
 *  D-Bus++ - C++ bindings for D-Bus
 *
 *  Copyright (C) 2005-2007  Paolo Durante <shackan@gmail.com>
 *
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef __DBUSXX_DEBUG_H
#define __DBUSXX_DEBUG_H

#include "api.h"

namespace DBus {

typedef void (*LogFunction)(const char *format, ...);

extern DXXAPI LogFunction debug_log;

#ifndef NDEBUG
// see https://gcc.gnu.org/onlinedocs/cpp/Variadic-Macros.html
#define LOG(_LOG_MSG_FMT, ...) do{ \
        debug_log(_LOG_MSG_FMT, ##__VA_ARGS__); \
    } while(0)
#else
#define LOG(...)
#endif

} /* namespace DBus */

#endif
