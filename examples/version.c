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

#include <glib.h>
#include <quvi.h>

gint main(gint argc, gchar **argv)
{
  g_print("libquvi %s\n", quvi_version(QUVI_VERSION));
  g_print("  build for %s\n", quvi_version(QUVI_VERSION_BUILD));
  g_print("libquvi-scripts %s\n", quvi_version(QUVI_VERSION_SCRIPTS));
  return (0);
}

/* vim: set ts=2 sw=2 tw=72 expandtab: */
