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

#include "config.h"

#include <curl/curl.h>
#include <glib.h>

#include "quvi.h"
/* -- */
#include "_quvi_s.h"
#include "_quvi_media_s.h"
#include "_quvi_net_s.h"
#include "_quvi_net_opt_s.h"
/* -- */
#include "net/def.h"
#include "curl/temp.h"

static void _set_opts(_quvi_net_t n, _c_temp_t t, CURL *c)
{
  typedef curl_write_callback cwc;

  curl_easy_setopt(c, CURLOPT_WRITEFUNCTION, (cwc) c_temp_wrcb);
  curl_easy_setopt(c, CURLOPT_URL, n->url.addr->str);
  curl_easy_setopt(c, CURLOPT_WRITEDATA, t);
  curl_easy_setopt(c, CURLOPT_NOBODY, 1L); /* GET -> HEAD */
}

static QuviError _verify(_quvi_net_t n, CURL *c)
{
  CURLcode curlcode = curl_easy_perform(c);
  QuviError rc = QUVI_OK;

  curl_easy_setopt(c, CURLOPT_HTTPGET, 1L); /* HEAD -> GET */
  curl_easy_getinfo(c, CURLINFO_RESPONSE_CODE, &n->status.resp_code);

  if (curlcode == CURLE_OK)
    {
      if (n->status.resp_code == 200 || n->status.resp_code == 206)
        {
          gdouble *l = &n->verify.content_length;
          gchar *s = NULL;

          curl_easy_getinfo(c, CURLINFO_CONTENT_TYPE, &s);
          curl_easy_getinfo(c, CURLINFO_CONTENT_LENGTH_DOWNLOAD, l);

          g_string_assign(n->verify.content_type, s);
        }
      else
        {
          g_string_printf(n->status.errmsg, "server returned HTTP/%03ld",
                          n->status.resp_code);
          rc = QUVI_ERROR_CALLBACK;
        }
    }
  else
    {
      const gchar *s = curl_easy_strerror(curlcode);
      const gint r = n->status.resp_code;
      const gint c = curlcode;
#define _ENO "%s (HTTP/%03d, cURL=0x%03x)"
      g_string_printf(n->status.errmsg, _ENO, s, r, c);
#undef _ENO
      rc = QUVI_ERROR_CALLBACK;
    }
  return (rc);
}

QuviError c_verify(_quvi_t q, _quvi_net_t n)
{
  CURL *c = q->handle.curl;
  _c_temp_t t = c_temp_new();
  QuviError rc = QUVI_OK;

  _set_opts(n, t, c);
  rc = _verify(n, c);

  c_temp_free(t);
  t = NULL;

  return (rc);
}

/* vim: set ts=2 sw=2 tw=72 expandtab: */
