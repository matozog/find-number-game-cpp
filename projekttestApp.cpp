/***************************************************************
 * Name:      projekttestApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Wojciech Ziółkowski ()
 * Created:   2025-01-08
 * Copyright: Wojciech Ziółkowski ()
 * License:
 **************************************************************/

#include "projekttestApp.h"

//(*AppHeaders
#include "projekttestMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(projekttestApp);

bool projekttestApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	projekttestDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
