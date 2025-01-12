/***************************************************************
 * Name:      projekttestMain.h
 * Purpose:   Defines Application Frame
 * Author:    Wojciech Ziółkowski ()
 * Created:   2025-01-08
 * Copyright: Wojciech Ziółkowski ()
 * License:
 **************************************************************/

#ifndef PROJEKTTESTMAIN_H
#define PROJEKTTESTMAIN_H

#include "MultiPlayerUI.h"
#include "SoloPlayerUI.h"
#include "Game.h"
#include <wx/button.h>

#undef _
#define _(s) wxString::FromUTF8(s)

//(*Headers(projekttestDialog)
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/filedlg.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/tglbtn.h>
//*)

class projekttestDialog: public wxDialog
{
    public:
        projekttestDialog(wxWindow* parent,wxWindowID id = -1);
        void createGame();
        virtual ~projekttestDialog();

    private:
        MultiPlayerUI* multiPlayerDialog;
        SoloPlayerUI* singlePlayerDialog;
        Game* game;

        //(*Handlers(projekttestDialog)
        void OnPlayButtonClick(wxCommandEvent& event);
        void OnSinglePlayerCheck(wxCommandEvent& event);
        void OnMultiPlayerCheck(wxCommandEvent& event);
        void OnLevelChoiceChange(wxCommandEvent& event);
        //*)

        //(*Identifiers(projekttestDialog)
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT1;
        static const long ID_LEVEL_CHOICE;
        static const long ID_RANKING_BUTTON;
        static const long ID_STATICTEXT4;
        static const long ID_SINGLE_PLAYER_CHECKBOX;
        static const long ID_MULTI_PLAYER_CHECKBOX;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT7;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_PLAY_BUTTON;
        //*)

        //(*Declarations(projekttestDialog)
        wxButton* PlayButton;
        wxButton* RankingButton;
        wxCheckBox* MultiPlayerCheckbox;
        wxCheckBox* SinglePlayerCheckbox;
        wxChoice* LevelChoice;
        wxFileDialog* FileDialog1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText6;
        wxStaticText* StaticText7;
        wxTextCtrl* Player1TextField;
        wxTextCtrl* Player2TextField;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // PROJEKTTESTMAIN_H
