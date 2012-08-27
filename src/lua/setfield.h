/* libquvi
 * Copyright (C) 2012  Toni Gundogdu <legatvs@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301  USA
 */

#ifndef l_setfield_h
#define l_setfield_h

void l_setfield_s(lua_State*, const gchar*, const gchar*);
void l_setfield_n(lua_State*, const gchar*, const glong);
void l_setfield_b(lua_State*, const gchar*, const gint);
void l_set_reg_userdata(lua_State*, const gchar*, gpointer);
#ifdef _1 /* Unused */
void l_set_luserdata(lua_State*, const gchar*, gpointer);
#endif

#endif /* l_setfield_h */

/* vim: set ts=2 sw=2 tw=72 expandtab: */
