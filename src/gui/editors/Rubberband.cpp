/*
 * Rubberband.cpp - rubberband - either own implementation for Qt3 or wrapper
 *                               for Qt4
 *
 * Copyright (c) 2006-2011 Tobias Doerffel <tobydox/at/users.sourceforge.net>
 *
 * This file is part of LMMS - https://lmms.io
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 */


#include "Rubberband.h"

namespace lmms::gui
{


RubberBand::RubberBand( QWidget * _parent ) :
	QRubberBand( Rectangle, _parent )
{
}




QVector<selectableObject *> RubberBand::selectedObjects() const
{
	QVector<selectableObject *> so = selectableObjects();
	for( QVector<selectableObject *>::iterator it = so.begin();
							it != so.end(); )
	{
		if( ( *it )->isSelected() == false )
		{
			it = so.erase( it );
		}
		else
		{
			++it;
		}
	}
	return( so );
}




void RubberBand::resizeEvent( QResizeEvent * _re )
{
	QRubberBand::resizeEvent( _re );
}




QVector<selectableObject *> RubberBand::selectableObjects() const
{
	QVector<selectableObject *> so;
	if( parentWidget() == nullptr )
	{
		return( so );
	}

	QList<selectableObject *> l =
			parentWidget()->findChildren<selectableObject *>();
	for( QList<selectableObject *>::iterator it = l.begin(); it != l.end();
									++it )
	{
		so.push_back( *it );
	}
	return( so );
}


} // namespace lmms::gui
