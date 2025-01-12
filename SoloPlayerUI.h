#ifndef SOLOPLAYERUI_H
#define SOLOPLAYERUI_H

#include "Game.h"

//(*Headers(SoloPlayerUI)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/timer.h>
//*)

#undef _
#define _(s) wxString::FromUTF8(s)

class SoloPlayerUI: public wxDialog
{
	public:
		SoloPlayerUI(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		void createGameBoard(Game* game);
		void generateAttempts();
		void generateCurrentAttempt();
		virtual ~SoloPlayerUI();

        wxGridSizer* GameBoard;
        wxFlexGridSizer* SinglePlayerContentFlexbox;

		//(*Declarations(SoloPlayerUI)
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxTextCtrl* AttemptsTextField;
		wxTextCtrl* PlayerNicknameTextField;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl3;
		wxTextCtrl* TimerTextField;
		wxTimer Timer1;
		//*)

	protected:

		//(*Identifiers(SoloPlayerUI)
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_PLAYER_NICKNAME_TEXT_FIELD;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT5;
		static const long ID_TIMER_TEXT_FIELD;
		static const long ID_STATICTEXT6;
		static const long ID_ATTEMPTS_TEXT_FIELD;
		static const long ID_TIMER1;
		//*)

	private:
        Game* game;
		//(*Handlers(SoloPlayerUI)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
