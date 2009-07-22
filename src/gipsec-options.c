/*
 * gipsec-options.c
 * This file is part of gipsec, parse the options.
 * 
 * Copyright (C) 2005 Novell, Inc
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
 * Foundation, Inc., 59 Temple Place, Suite 330, 
 * Boston, MA 02111-1307, USA.
 *
 * Authors: Bin Li <libin.charles@gmail.com>
 *
 * See ChangeLog to get more details.
 * $Id$
 */
#include <glib.h>

static int debug = 0;

void
options_parse (int argc, char *argv[])
{
	GOptionContext *opt_ctx = NULL;
	GError *error = NULL;
	GOptionEntry entries[] = {
		{ "client", 0, 0, G_OPTION_ARG_NONE, &debug, "Run in VPN client mode", NULL },
		{ "server", 0, 0, G_OPTION_ARG_NONE, &debug, "Run in VPN server mode", NULL },
		{ "monitor", 0, 0, G_OPTION_ARG_NONE, &debug, "Run with the monitor window", NULL },
		{ "debug", 0, 0, G_OPTION_ARG_NONE, &debug, "Output to console rather than syslog", NULL },
		{ NULL }
	};

	opt_ctx = g_option_context_new (NULL);
	g_option_context_set_summary (opt_ctx, "ipsec-tools configure and monitor GUI.");
	g_option_context_add_main_entries (opt_ctx, entries, NULL);

	if (!g_option_context_parse (opt_ctx, &argc, &argv, &error)) {
		g_warning ("%s\n", error->message);
		g_error_free (error);
		exit (1);
	}

	g_option_context_free (opt_ctx);
}
