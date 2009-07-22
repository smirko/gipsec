/*
 * main.c
 * This file is part of gipsec, the main function.
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
#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdlib.h>
#include <glib.h>
#include <libintl.h>
#include <gtk/gtk.h>
#include "gipsec.h"


int main (int argc, char *argv[])
{
	GMainLoop *loop = NULL;
	GIPSec *gipsec = NULL;

	// set directory containing message catalogs
	bindtextdomain (GETTEXT_PACKAGE, GIPSEC_LOCALEDIR);
	// set encoding of message translations
	bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");

	gtk_init (&argc, &argv);

	textdomain (GETTEXT_PACKAGE);

	loop = g_main_loop_new (NULL, FALSE);

	gipsec = gipsec_new ();
	if (gipsec == NULL)
		exit (1);

	g_main_loop_run (loop);

	exit (0);
}
