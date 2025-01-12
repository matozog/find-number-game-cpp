#ifndef MULTIPLAYERUI_H
#define MULTIPLAYERUI_H

//(*Headers(MultiPlayerUI)
#include <wx/dialog.h>
#include <wx/grid.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/timer.h>
//*)

#undef _
#define _(s) wxString::FromUTF8(s)

class MultiPlayerUI: public wxDialog
{
	public:

		MultiPlayerUI(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~MultiPlayerUI();

		//(*Declarations(MultiPlayerUI)
		wxGrid* Grid1;
		wxGrid* Grid2;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxStaticText* StaticText7;
		wxStaticText* StaticText8;
		wxStaticText* StaticText9;
		wxTextCtrl* TextCtrl10;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl3;
		wxTextCtrl* TextCtrl4;
		wxTextCtrl* TextCtrl5;
		wxTextCtrl* TextCtrl6;
		wxTextCtrl* TextCtrl7;
		wxTextCtrl* TextCtrl8;
		wxTextCtrl* TextCtrl9;
		wxTimer Timer1;
		wxTimer Timer2;
		//*)

	protected:

		//(*Identifiers(MultiPlayerUI)
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL1;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_TEXTCTRL4;
		static const long ID_TEXTCTRL5;
		static const long ID_TEXTCTRL6;
		static const long ID_STATICTEXT6;
		static const long ID_TEXTCTRL7;
		static const long ID_STATICTEXT7;
		static const long ID_TEXTCTRL8;
		static const long ID_STATICTEXT8;
		static const long ID_TEXTCTRL9;
		static const long ID_STATICTEXT9;
		static const long ID_TEXTCTRL10;
		static const long ID_GRID1;
		static const long ID_GRID2;
		static const long ID_TIMER1;
		static const long ID_TIMER2;
		//*)

	private:

		//(*Handlers(MultiPlayerUI)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
