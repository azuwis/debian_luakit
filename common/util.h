/*
 * util.h - useful functions
 *
 * Copyright (C) 2010 Mason Larobina <mason.larobina@gmail.com>
 * Copyright (C) 2007-2008 Julien Danjou <julien@danjou.info>
 * Copyright (C) 2006 Pierre Habouzit <madcoder@debian.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef LUAKIT_COMMON_UTIL_H
#define LUAKIT_COMMON_UTIL_H

#include <glib/gtypes.h>
#include <string.h>
#include <unistd.h>

/* Useful macros */
#define NONULL(x) (x ? x : "")
#define LENGTH(x) sizeof(x)/sizeof((x)[0])

#define fatal(string, ...) _fatal(__LINE__, __FUNCTION__, string, ##__VA_ARGS__)
void _fatal(int, const gchar *, const gchar *, ...);

#define warn(string, ...) _warn(__LINE__, __FUNCTION__, string, ##__VA_ARGS__)
void _warn(int, const gchar *, const gchar *, ...);

#ifdef DEBUG_MESSAGES

#define debug(string, ...) _debug(__LINE__, __FUNCTION__, string, ##__VA_ARGS__)
void _debug(int, const gchar *, const gchar *, ...);

#else

#define debug(string)

#endif

/* A NULL resistant strlen. Unlike it's libc sibling, l_strlen returns a
 * ssize_t, and supports its argument being NULL. */
static inline ssize_t l_strlen(const gchar *s) {
    return s ? strlen(s) : 0;
}

#define p_clear(p, count)       ((void)memset((p), 0, sizeof(*(p)) * (count)))

gboolean file_exists(const gchar*);

#endif
// vim: ft=c:et:sw=4:ts=8:sts=4:enc=utf-8:tw=80
