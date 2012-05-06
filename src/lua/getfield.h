/* libquvi
 * Copyright (C) 2012  Toni Gundogdu <legatvs@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#ifndef l_getfield_h
#define l_getfield_h

const gchar *l_getfield_s(lua_State*, const gchar*,
                          const gchar*, const gchar*);

const gdouble l_getfield_n(lua_State*, const gchar*,
                           const gchar*, const gchar*);

const gboolean l_getfield_b(lua_State*, const gchar*,
                            const gchar*, const gchar*);

const gpointer l_get_reg_userdata(lua_State*, const gchar*);

typedef gint (*l_callback_getfield_table_iter_s) (gpointer, const gchar*);

QuviError l_getfield_table_iter_s(lua_State*, const gpointer, const gchar*,
                                  const gchar*, const gchar*,
                                  l_callback_getfield_table_iter_s);

#endif /* l_getfield_h */

/* vim: set ts=2 sw=2 tw=72 expandtab: */
