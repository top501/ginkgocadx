/*
 *  Ginkgo CADx Project
 *
 * Copyright (c) 2015-2016 Gert Wollny
 * Copyright (c) 2008-2014 MetaEmotion S.L. All rights reserved.
 *
 * Ginkgo CADx is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser Public License
 * along with Ginkgo CADx; if not, see <http://www.gnu.org/licenses/>.
 *
 */


#pragma once
#include <vector>

#include <export/tools/itoolslider.h>
#include <api/iwidgets.h>
#include <api/math/geometry3d.h>



namespace GNC
{
namespace GCS
{
namespace Widgets
{
//---------------------------------------------------------------------
class WZoomBuilder : public GNC::GCS::Widgets::IWidgetBuilder
{
public:

        typedef GNC::GCS::Vector TVector;
        typedef GNC::GCS::Events::EventoRaton   TEventoRaton;
        typedef GNC::GCS::Events::EventoTeclado TEventoTeclado;
        typedef GNC::GCS::IWidgetsManager        TWidgetsManager;
        typedef GNC::GCS::Widgets::IWidget       TWidget;
        WZoomBuilder(TWidgetsManager* pManager, const GNC::GCS::TriggerButton& buttonMask, long gid);

        ~WZoomBuilder();

        virtual void OnMouseEvents(TEventoRaton& event);
        virtual void OnKeyEvents(TEventoTeclado& event);

        virtual void Render(GNC::GCS::Contexto3D* c);

        virtual GNC::GCS::Widgets::TipoCursor GetCursor();

        //region "Helpers"

        bool         m_Changed;
        bool         m_Dentro;
        //endregion


protected:
        TVector  m_NodoMoviendose;  // Cursor

        double  m_Start;           // Displacement origin in screen pixels
        double  m_Stop;            // Displacement destination in screen pixels

        bool     m_MouseDown;
        Estado   m_Estado;
};
}
}
}
