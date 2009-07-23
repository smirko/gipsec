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
#include <stdlib.h>
#include <glib.h>

static gboolean debug = FALSE;
static gboolean no_main_window = FALSE;
static gchar* run_mode = NULL;

void
options_parse (int argc, char *argv[])
{
	GOptionContext *opt_ctx = NULL;
	GError *error = NULL;
	GOptionEntry entries[] = {
		{ "mode", 'm', 0,
		   	G_OPTION_ARG_STRING,
		   	&run_mode,
		   	"Run in VPN client or server mode",
		   	NULL },
		{ "dialog", 'd', 0,
		   	G_OPTION_ARG_NONE,
		   	&no_main_window,
		   	"Run in Dialog without the monitor window",
		   	NULL },
		{ "debug", 'v', 0,
		   	G_OPTION_ARG_NONE,
		   	&debug,
		   	"Output to console rather than syslog",
		   	NULL },
		{ NULL }
	};

	opt_ctx = g_option_context_new (NULL);
	g_option_context_set_summary (opt_ctx, "The ipsec-tools' GUI to use VPN easily.");
	g_option_context_add_main_entries (opt_ctx, entries, NULL);

	if (!g_option_context_parse (opt_ctx, &argc, &argv, &error)) {
		g_warning ("%s\n", error->message);
		g_error_free (error);
		exit (1);
	}

	g_option_context_free (opt_ctx);
}

gboolean
is_server_mode ()
{
	if (strncmp (run_mode, "server", 6) == 0)
		return TRUE;
	else if (strncmp (run_mode, "client", 6) == 0)
		return FALSE;
	else
		g_warning ("Plese set the correct run mode, client or server.");

	// The default mode is client
	return FALSE;
}

gboolean
is_dialog_window ()
{
	return no_main_window;
}
