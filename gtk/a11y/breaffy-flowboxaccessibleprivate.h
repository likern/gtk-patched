/*
 * Copyright (C) 2013 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __BREAFFY_FLOW_BOX_ACCESSIBLE_PRIVATE_H__
#define __BREAFFY_FLOW_BOX_ACCESSIBLE_PRIVATE_H__

#include <gtk/a11y/breaffy-flowboxaccessible.h>

G_BEGIN_DECLS

void _breaffy_flow_box_accessible_selection_changed (GtkWidget *box);
void _breaffy_flow_box_accessible_update_cursor     (GtkWidget *box,
                                                 GtkWidget *child);
G_END_DECLS

#endif /* __BREAFFY_FLOW_BOX_ACCESSIBLE_PRIVATE_H__ */