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

#include <stdlib.h>
#include <glib.h>
#include <quvi.h>

extern quvi_media_t qm;
extern quvi_t q;

extern void cleanup();

void exit_if_error()
{
  QuviError rc = QUVI_OK;

  if (quvi_ok(q) == QUVI_TRUE)
    return;

  g_printerr("[%s] error: %s\n", __func__, quvi_errmsg(q));
  quvi_get(q, QUVI_INFO_ERROR_CODE, &rc);

  cleanup();
  exit(rc);
}

/* vim: set ts=2 sw=2 tw=72 expandtab: */
