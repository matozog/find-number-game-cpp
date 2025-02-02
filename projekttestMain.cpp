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
#include <iostream>
#include <fstream>
#include <sstream>

//(*InternalHeaders(projekttestDialog)
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/statline.h>
#include <wx/dcclient.h>
#include <wx/utils.h>
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
const long projekttestDialog::ID_GAME_INFO_BUTTON = wxNewId();
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
    wxColour customGreen(0, 204, 102); // RGB for Forest Green
    wxFont inputFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    wxFont buttonFont(13, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    wxFont labelFont(11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

    //(*Initialize(projekttestDialog)
    //wxBoxSizer* BoxSizer1;
    wxFlexGridSizer* FlexGridSizer1;
    wxGridSizer* GridSizer1;
    //wxBoxSizer* GridSizer2;

    Create(parent, id, _("Znajdź liczbę"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));

    this->SetBackgroundColour(customGreen);

    FlexGridSizer1 = new wxFlexGridSizer(7, 1, 0, 0);
    GridSizer1 = new wxGridSizer(2, 2, 0, 20);

    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Informacje o grze"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    GridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Ranking graczy"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    GridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

    wxButton* InfoButton = new wxButton(this, ID_GAME_INFO_BUTTON, _("Instrukcja"), wxDefaultPosition, wxSize(100, 30), 0, wxDefaultValidator, _T("ID_GAME_INFO_BUTTON"));
    GridSizer1->Add(InfoButton, 1, wxRIGHT|wxBOTTOM|wxTOP|wxEXPAND, 5);

    RankingButton = new wxButton(this, ID_RANKING_BUTTON, _("Ranking"), wxDefaultPosition, wxSize(100, 30), 0, wxDefaultValidator, _T("ID_RANKING_BUTTON"));
    RankingButton->SetBackgroundColour(wxColour(38, 38, 38));
    RankingButton->SetForegroundColour(wxColour(255, 255, 255));
    GridSizer1->Add(RankingButton, 1, wxLEFT|wxTOP|wxBOTTOM|wxEXPAND, 5);

    FlexGridSizer1->Add(GridSizer1, 1, wxALL|wxEXPAND, 15);

    wxStaticLine* line1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
    FlexGridSizer1->Add(line1, 1, wxLEFT|wxRIGHT|wxBOTTOM|wxEXPAND, 10);

    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Ustawienia gry"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

    wxGridSizer* GameSettingsSizer = new wxGridSizer(2, 2, 5, 10);

    //wxBoxSizer* LevelBox = new wxBoxSizer(wxHORIZONTAL);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Poziom trudności"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    GameSettingsSizer->Add(StaticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    LevelChoice = new wxChoice(this, ID_LEVEL_CHOICE, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_LEVEL_CHOICE"));
    LevelChoice->Append(_("Łatwy"));
    LevelChoice->SetSelection( LevelChoice->Append(_("Średni")) );
    LevelChoice->Append(_("Trudny"));
    GameSettingsSizer->Add(LevelChoice, 0, wxALL|wxEXPAND, 5);
    //FlexGridSizer1->Add(GameSettingsSizer, 0, wxALL|wxEXPAND, 10);

    //GridSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Nick gracza"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    GameSettingsSizer->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);

    Player1TextField = new wxTextCtrl(this, ID_TEXTCTRL1, _("Nick1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    Player1TextField->SetHelpText(_("Nick gracza 1"));
    GameSettingsSizer->Add(Player1TextField, 1, wxALL|wxEXPAND, 5);

    FlexGridSizer1->Add(GameSettingsSizer, 1, wxALL|wxEXPAND, 10);

    wxStaticLine* line2 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
    FlexGridSizer1->Add(line2, 1, wxLEFT|wxRIGHT|wxEXPAND, 10);

    PlayButton = new wxButton(this, ID_PLAY_BUTTON, _("Graj"), wxDefaultPosition, wxSize(120, 30), 0, wxDefaultValidator, _T("ID_PLAY_BUTTON"));
    FlexGridSizer1->Add(PlayButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 18);

    SetSizer(FlexGridSizer1);
    FileDialog1 = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);
    //*)

    StaticText2->SetFont(labelFont);
    StaticText4->SetFont(labelFont);
    StaticText6->SetFont(labelFont);
    StaticText5->SetFont(labelFont);
    StaticText1->SetFont(labelFont);

    InfoButton->SetFont(buttonFont);
    RankingButton->SetFont(buttonFont);
    PlayButton->SetFont(buttonFont);

    InfoButton->SetBackgroundColour(wxColour(38, 38, 38));
    InfoButton->SetForegroundColour(wxColour(255, 255, 255));

    PlayButton->SetBackgroundColour(wxColour(38, 38, 38));
    PlayButton->SetForegroundColour(wxColour(255, 255, 255));

    Player1TextField->SetFont(buttonFont);
    LevelChoice->SetFont(buttonFont);

    this->loadPlayersRanking();

    PlayButton->Bind(wxEVT_BUTTON, &projekttestDialog::OnPlayButtonClick, this);
    RankingButton->Bind(wxEVT_BUTTON, &projekttestDialog::OnShowRanking, this);
    InfoButton->Bind(wxEVT_BUTTON, &projekttestDialog::OnInfoClick, this);

    rankingDialog = new RankingDialog(parent, 3, wxDefaultPosition, wxDefaultSize, this->playersStats);
}

void projekttestDialog::OnInfoClick(wxCommandEvent& event){
    // Specify the path to the PDF file
    wxString pdfPath = wxT("./assets/game-info.pdf");

    // Launch the default application for opening PDFs
    if (!wxLaunchDefaultApplication("/game-info.pdf"))
    {
        wxMessageBox(_("Nie można otworzyć pliku instrukcji gry."), _("Bląd wczytywania"), wxOK | wxICON_ERROR);
    }
}

void projekttestDialog::OnPlayButtonClick(wxCommandEvent& event)
{
    this->createGame();
    singlePlayerDialog = new SoloPlayerUI(this, 2, wxDefaultPosition, wxDefaultSize);
    singlePlayerDialog->createGameBoard(this->game);
    singlePlayerDialog->ShowModal();
}

/*void projekttestDialog::OnSinglePlayerCheck(wxCommandEvent& event){
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
*/
void projekttestDialog::createGame() {
    Level* level = new Level(LevelChoice->GetStringSelection().ToUTF8().data());

    //std::string gameType = SinglePlayerCheckbox->IsChecked() ? "single" : "multi";
    Player* player1 = new Player(Player1TextField->GetValue().ToStdString());
    this->game = new Game(level, "single", player1);

    std::vector<std::string> randomNumber = level->generateRandomNumber();
    this->game->setSolution(randomNumber);
}

void projekttestDialog::loadPlayersRanking() {
    std::ifstream file("ranking.csv"); // Open the file
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << "ranking.csv" << "\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) { // Read each line
        std::stringstream ss(line);
        std::string nick, level, attemptsStr, timeStr;

        // Parse the CSV line (comma-separated values)
        if (std::getline(ss, nick, ',') &&
            std::getline(ss, level, ',') &&
            std::getline(ss, attemptsStr, ',') &&
            std::getline(ss, timeStr, ',')) {

            // Convert attempts and time to the correct types
            int attempts = std::stoi(attemptsStr);
            double time = std::stod(timeStr);

            // Create a PlayerStats object and add it to the vector
            this->playersStats.emplace_back(nick, level, attempts, time);
        }
    }

    file.close(); // Close the file
}

void projekttestDialog::OnShowRanking(wxCommandEvent& event){
    this->rankingDialog->ShowModal();
}

projekttestDialog::~projekttestDialog()
{
    //(*Destroy(projekttestDialog)
    //*)
}
