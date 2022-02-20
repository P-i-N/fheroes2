/***************************************************************************
 *   Free Heroes of Might and Magic II: https://github.com/ihhub/fheroes2  *
 *   Copyright (C) 2019 - 2022                                             *
 *                                                                         *
 *   Free Heroes2 Engine: http://sourceforge.net/projects/fheroes2         *
 *   Copyright (C) 2009 by Andrey Afletdinov <fheroes2@gmail.com>          *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef H2INTERFACE_BORDER_H
#define H2INTERFACE_BORDER_H

#include "dialog.h"

namespace Interface
{
    void GameBorderRedraw( const bool viewWorldMode );

    class BorderWindow
    {
    public:
        explicit BorderWindow( const fheroes2::Rect & );
        virtual ~BorderWindow() = default;

        virtual void SetPos( int32_t, int32_t ) = 0;
        virtual void SavePosition( void ) = 0;

        void Redraw() const;
        bool QueueEventProcessing( void );

        const fheroes2::Rect & GetRect( void ) const;
        const fheroes2::Rect & GetArea( void ) const
        {
            return area;
        }

    protected:
        void SetPosition( int32_t, int32_t, uint32_t, uint32_t );
        void SetPosition( int32_t, int32_t );

        fheroes2::Rect area;
        Dialog::FrameBorder border;
    };
}

#endif
