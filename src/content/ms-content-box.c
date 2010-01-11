/*
 * Copyright (C) 2010 Igalia S.L.
 *
 * Contact: Iago Toral Quiroga <itoral@igalia.com>
 *
 * Authors: Juan A. Suarez Romero <jasuarez@igalia.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 */

/*
 * A container for multiple medias.
 *
 * This high level class represents a container for multiple medias.
 *
 */

#include "ms-content-box.h"

#define MIME_BOX "x-ms/box"

static void ms_content_box_dispose (GObject *object);
static void ms_content_box_finalize (GObject *object);

G_DEFINE_TYPE (MsContentBox, ms_content_box, MS_TYPE_CONTENT_MEDIA);

static void
ms_content_box_class_init (MsContentBoxClass *klass)
{
    GObjectClass *gobject_class = (GObjectClass *)klass;

    gobject_class->dispose = ms_content_box_dispose;
    gobject_class->finalize = ms_content_box_finalize;
}

static void
ms_content_box_init (MsContentBox *self)
{
  ms_content_box_set_childcount (self, MS_METADATA_KEY_CHILDCOUNT_UNKNOWN);
  ms_content_media_set_mime (MS_CONTENT_MEDIA (self), MIME_BOX);
}

static void
ms_content_box_dispose (GObject *object)
{
    G_OBJECT_CLASS (ms_content_box_parent_class)->dispose (object);
}

static void
ms_content_box_finalize (GObject *object)
{
    g_signal_handlers_destroy (object);
    G_OBJECT_CLASS (ms_content_box_parent_class)->finalize (object);
}

/**
 * ms_content_box_new:
 *
 * Creates a new content box object.
 *
 * Returns: a newly-allocated content box.
 **/
MsContentBox *
ms_content_box_new (void)
{
  return g_object_new (MS_TYPE_CONTENT_BOX,
		       NULL);
}