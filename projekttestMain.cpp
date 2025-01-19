/***************************************************************
 * Name:      projekttestMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Wojciech Ziółkowski ()
 * Created:   2025-01-08
 * Copyright: Wojciech Ziółkowski ()
 * License:
 **************************************************************/

#include "projekttestMain.h"
#include <wx/msgdlg.h>
#include <wx/wx.h>

//(*InternalHeaders(projekttestDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(projekttestDialog)
const long projekttestDialog::ID_STATICTEXT2 = wxNewId();
const long projekttestDialog::ID_STATICTEXT1 = wxNewId();
const long projekttestDialog::ID_LEVEL_CHOICE = wxNewId();
const long projekttestDialog::ID_RANKING_BUTTON = wxNewId();
const long projekttestDialog::ID_STATICTEXT4 = wxNewId();
const long projekttestDialog::ID_SINGLE_PLAYER_CHECKBOX = wxNewId();
const long projekttestDialog::ID_MULTI_PLAYER_CHECKBOX = wxNewId();
const long projekttestDialog::ID_STATICTEXT5 = wxNewId();
const long projekttestDialog::ID_STATICTEXT6 = wxNewId();
const long projekttestDialog::ID_STATICTEXT7 = wxNewId();
const long projekttestDialog::ID_TEXTCTRL1 = wxNewId();
const long projekttestDialog::ID_TEXTCTRL2 = wxNewId();
const long projekttestDialog::ID_PLAY_BUTTON = wxNewId();
//*)

BEGIN_EVENT_TABLE(projekttestDialog,wxDialog)
    //(*EventTable(projekttestDialog)
    //*)
END_EVENT_TABLE()

projekttestDialog::projekttestDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(projekttestDialog)
    wxBoxSizer* BoxSizer1;
    wxFlexGridSizer* FlexGridSizer1;
    wxGridSizer* GridSizer1;
    wxGridSizer* GridSizer2;

    Create(parent, id, _("Znajdź liczbę"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    FlexGridSizer1 = new wxFlexGridSizer(7, 1, 0, 0);
    GridSizer1 = new wxGridSizer(2, 2, 0, 0);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Poziom trudności"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    GridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Ranking wszystkich graczy"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    GridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    LevelChoice = new wxChoice(this, ID_LEVEL_CHOICE, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_LEVEL_CHOICE"));
    LevelChoice->Append(_("Łatwy"));
    LevelChoice->SetSelection( LevelChoice->Append(_("Średni")) );
    LevelChoice->Append(_("Trudny"));
    GridSizer1->Add(LevelChoice, 1, wxALL|wxEXPAND, 5);
    RankingButton = new wxButton(this, ID_RANKING_BUTTON, _("Ranking"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RANKING_BUTTON"));
    GridSizer1->Add(RankingButton, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer1->Add(GridSizer1, 1, wxALL|wxEXPAND, 5);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Wybierz tryb rozgrywki"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    SinglePlayerCheckbox = new wxCheckBox(this, ID_SINGLE_PLAYER_CHECKBOX, _("Tryb jednoosobowy"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SINGLE_PLAYER_CHECKBOX"));
    SinglePlayerCheckbox->SetValue(true);
    BoxSizer1->Add(SinglePlayerCheckbox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    MultiPlayerCheckbox = new wxCheckBox(this, ID_MULTI_PLAYER_CHECKBOX, _("Tryb dwuosobowy"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_MULTI_PLAYER_CHECKBOX"));
    MultiPlayerCheckbox->SetValue(false);
    BoxSizer1->Add(MultiPlayerCheckbox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer1, 1, wxALL|wxEXPAND, 5);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Gracz/e:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer1->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer2 = new wxGridSizer(2, 2, 0, 0);
    StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Gracz1"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    GridSizer2->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Gracz2"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    GridSizer2->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Player1TextField = new wxTextCtrl(this, ID_TEXTCTRL1, _("Nick1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    Player1TextField->SetHelpText(_("Nick gracza 1"));
    GridSizer2->Add(Player1TextField, 1, wxALL|wxEXPAND, 5);
    Player2TextField = new wxTextCtrl(this, ID_TEXTCTRL2, _("Nick2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    Player2TextField->SetHelpText(_("Nick gracza 2"));
    GridSizer2->Add(Player2TextField, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer1->Add(GridSizer2, 1, wxALL|wxEXPAND, 5);
    PlayButton = new wxButton(this, ID_PLAY_BUTTON, _("Graj"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_PLAY_BUTTON"));
    FlexGridSizer1->Add(PlayButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);
    //*)

    PlayButton->Bind(wxEVT_BUTTON, &projekttestDialog::OnPlayButtonClick, this);
    SinglePlayerCheckbox->Bind(wxEVT_CHECKBOX, &projekttestDialog::OnSinglePlayerCheck, this);
    MultiPlayerCheckbox->Bind(wxEVT_CHECKBOX, &projekttestDialog::OnMultiPlayerCheck, this);

    multiPlayerDialog = new MultiPlayerUI(parent, 1, wxDefaultPosition, wxDefaultSize);
    singlePlayerDialog = new SoloPlayerUI(parent, 2, wxDefaultPosition, wxDefaultSize);
}

void projekttestDialog::OnPlayButtonClick(wxCommandEvent& event)
{
    this->createGame();
    singlePlayerDialog->createGameBoard(this->game);
    if(SinglePlayerCheckbox->IsChecked()){
        singlePlayerDialog->ShowModal();
    } else {
        multiPlayerDialog->ShowModal();
    }
}

void projekttestDialog::OnSinglePlayerCheck(wxCommandEvent& event){
    if(MultiPlayerCheckbox->IsChecked()){
        MultiPlayerCheckbox->SetValue(false);
    }
    if(!SinglePlayerCheckbox->IsChecked()){
        SinglePlayerCheckbox->SetValue(true);
    }
}

void projekttestDialog::OnMultiPlayerCheck(wxCommandEvent& event){
    if(SinglePlayerCheckbox->IsChecked()){
        SinglePlayerCheckbox->SetValue(false);
    }
    if(!MultiPlayerCheckbox->IsChecked()){
        MultiPlayerCheckbox->SetValue(true);
    }
}

void projekttestDialog::createGame() {
    Level* level = new Level(LevelChoice->GetStringSelection().ToUTF8().data());

    std::string gameType = SinglePlayerCheckbox->IsChecked() ? "single" : "multi";
    Player* player1 = new Player(Player1TextField->GetValue().ToStdString());
    if(gameType == "single") {
        this->game = new Game(level, gameType, player1);
    } else {
        Player* player2 = new Player(Player2TextField->GetValue().ToStdString());
        this->game = new Game(level, gameType, player1, player2);
    }

    std::vector<std::string> randomNumber = level->generateRandomNumber();
    this->game->setSolution(randomNumber);
}

projekttestDialog::~projekttestDialog()
{
    //(*Destroy(projekttestDialog)
    //*)
}
