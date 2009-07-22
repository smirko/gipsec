/*
 * gipsec.c
 * This file is part of gipsec, implement gipsec instance.
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
#include "gipsec.h"

G_DEFINE_TYPE(GIPSec, gipsec, G_TYPE_OBJECT)

static void
gipsec_init (GIPSec *gipsec)
{
}

static void
finalize (GObject *object)
{
}

static void
gipsec_class_init (GIPSecClass *gipsec_class)
{
}

GIPSec *
gipsec_new ()
{
	return g_object_new (GIPSEC_TYPE, NULL);
}
