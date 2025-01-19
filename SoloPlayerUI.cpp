#include "SoloPlayerUI.h"
#include <wx/wx.h>

//(*InternalHeaders(SoloPlayerUI)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(SoloPlayerUI)
const long SoloPlayerUI::ID_STATICTEXT2 = wxNewId();
const long SoloPlayerUI::ID_STATICTEXT3 = wxNewId();
const long SoloPlayerUI::ID_STATICTEXT4 = wxNewId();
const long SoloPlayerUI::ID_PLAYER_NICKNAME_TEXT_FIELD = wxNewId();
const long SoloPlayerUI::ID_TEXTCTRL2 = wxNewId();
const long SoloPlayerUI::ID_TEXTCTRL3 = wxNewId();
const long SoloPlayerUI::ID_STATICTEXT5 = wxNewId();
const long SoloPlayerUI::ID_TIMER_TEXT_FIELD = wxNewId();
const long SoloPlayerUI::ID_STATICTEXT6 = wxNewId();
const long SoloPlayerUI::ID_ATTEMPTS_TEXT_FIELD = wxNewId();
const long SoloPlayerUI::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(SoloPlayerUI,wxDialog)
	//(*EventTable(SoloPlayerUI)
	//*)
END_EVENT_TABLE()

SoloPlayerUI::SoloPlayerUI(wxWindow* parent,wxWindowID id, const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(SoloPlayerUI)
	wxBoxSizer* BoxSizer1;
	wxGridSizer* GridSizer1;

	Create(parent, wxID_ANY, _("Tryb jednoosobowy"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SinglePlayerContentFlexbox = new wxFlexGridSizer(5, 1, 0, 0);
	GridSizer1 = new wxGridSizer(2, 3, 0, 0);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Gracz"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	GridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Zbiór"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	GridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Ilość cryfr w liczbie"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	GridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	PlayerNicknameTextField = new wxTextCtrl(this, ID_PLAYER_NICKNAME_TEXT_FIELD, _("Text"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_PLAYER_NICKNAME_TEXT_FIELD"));
	GridSizer1->Add(PlayerNicknameTextField, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("Text"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	GridSizer1->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, _("Text"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	GridSizer1->Add(TextCtrl3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SinglePlayerContentFlexbox->Add(GridSizer1, 1, wxALL|wxEXPAND, 5);
    GameBoard = new wxFlexGridSizer(2, 1, 0, 0);
	SinglePlayerContentFlexbox->Add(GameBoard, 1, wxALL|wxEXPAND, 5);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Czas:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	BoxSizer1->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TimerTextField = new wxTextCtrl(this, ID_TIMER_TEXT_FIELD, _("Text"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TIMER_TEXT_FIELD"));
	BoxSizer1->Add(TimerTextField, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Ilość prób:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	BoxSizer1->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	AttemptsTextField = new wxTextCtrl(this, ID_ATTEMPTS_TEXT_FIELD, _("Text"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_ATTEMPTS_TEXT_FIELD"));
	BoxSizer1->Add(AttemptsTextField, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SinglePlayerContentFlexbox->Add(BoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(SinglePlayerContentFlexbox);
	Timer1.SetOwner(this, ID_TIMER1);
	SinglePlayerContentFlexbox->Fit(this);
	SinglePlayerContentFlexbox->SetSizeHints(this);
	//*)

    scrolledWindow = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL);
    scrolledWindow->SetScrollRate(0, 10);
    scrolledWindow->SetMaxSize(wxSize(-1, 600)); // -1 for width means no limit, 200px max height

    PlayerAttemptsGridBox = new wxGridSizer(1, 0, 0, 0);
    GameBoard->Add(scrolledWindow, 1, wxALL|wxEXPAND, 5);

    CurrentAttemptGridBox = new wxGridSizer(1, 0, 0, 0);
    GameBoard->Add(CurrentAttemptGridBox, 1, wxALL|wxEXPAND, 5);
    AcceptAttemptButton = new wxButton(this, wxNewId(), _("Zatwierdź"), wxDefaultPosition, wxSize(100, 30), 0, wxDefaultValidator, _T("ID_SINGLE_PLAYER_ACCEPT_ATTEMPT_BUTTON"));

    scrolledWindow->SetSizer(PlayerAttemptsGridBox);
    PlayerAttemptsGridBox->SetSizeHints(scrolledWindow);

    SinglePlayerContentFlexbox->Layout();
    SinglePlayerContentFlexbox->Fit(this);

    AcceptAttemptButton->Bind(wxEVT_BUTTON, &SoloPlayerUI::OnAcceptAttemptClick, this);
}

void SoloPlayerUI::createGameBoard(Game* game){
    this->game = game;
    PlayerAttemptsGridBox->SetCols(game->getLevel()->getAmountOfDigits() + 1);
    this->generateCurrentAttempt();
    SinglePlayerContentFlexbox->Layout();
}

void SoloPlayerUI::generateAttempts(Attempt attempt) {
    Player* player1 = game->getPlayer1();
    int amountOfAttempts = player1->getAttempts().size();
    PlayerAttemptsGridBox->SetRows(amountOfAttempts);

    for(int j=0; j<attempt.getDigits().size(); j++){
        wxString id = wxString::Format("ID_SINGLE_PLAYER_ATTEMPT_%d", j);
        wxTextCtrl* attemptCell = new wxTextCtrl(scrolledWindow, wxNewId(), _(attempt.getDigits().at(j)), wxDefaultPosition, wxSize(40, 30), wxTE_READONLY, wxDefaultValidator, id);
        PlayerAttemptsGridBox->Add(attemptCell, 1, wxALL, 5);
    }

    wxButton* ButtonTmp = new wxButton(scrolledWindow, wxNewId(), _("Tmp"), wxDefaultPosition, wxSize(100, 30), 0, wxDefaultValidator, _T("ID_SINGLE_PLAYER_ACCEPT_ATTEMPT_BUTTON-tmp"));
    PlayerAttemptsGridBox->Add(ButtonTmp, 0, wxALL, 5);
    PlayerAttemptsGridBox->Layout();

    if(amountOfAttempts < 8) {
        scrolledWindow->SetMinSize(wxSize(-1, amountOfAttempts*40));
    }
    scrolledWindow->SetSizer(PlayerAttemptsGridBox);
    scrolledWindow->Layout();
    scrolledWindow->FitInside();

    SinglePlayerContentFlexbox->Layout();
    SinglePlayerContentFlexbox->Fit(this);
}

void SoloPlayerUI::generateCurrentAttempt() {
    Level* level = game->getLevel();
    CurrentAttemptGridBox->Clear(true);
    CurrentAttemptGridBox->SetCols(level->getAmountOfDigits() + 1);
    currentAttemptCtrls.clear();
    for(int i=0; i<level->getAmountOfDigits(); i++){
        std::string cellId = "ID_SINGLE_PLAYER_CURRENT_ATTEMPT_" + i;
        wxTextCtrl* currentAttemptCell = new wxTextCtrl(this, wxNewId(), _(std::to_string(i + 1)), wxDefaultPosition, wxSize(40, 30), wxTE_READONLY, wxDefaultValidator, cellId);
        currentAttemptCtrls.push_back(currentAttemptCell);
        CurrentAttemptGridBox->Add(currentAttemptCell, 1, wxALL, 5);
    }
    CurrentAttemptGridBox->Add(AcceptAttemptButton, 0, wxALL, 5);

    CurrentAttemptGridBox->Layout();
    SinglePlayerContentFlexbox->Fit(this);
}

void SoloPlayerUI::OnAcceptAttemptClick(wxCommandEvent& evt) {
    std::vector<std::string> digits;

    for (wxTextCtrl* textCtrl : this->currentAttemptCtrls) {
        std::string value = textCtrl->GetValue().ToStdString();
        digits.push_back(value);
    }

    if(digits.size() > 0) {
        Attempt attempt(digits);
        this->game->getPlayer1()->addAttempt(attempt);
        this->generateAttempts(attempt);

        scrolledWindow->FitInside();
        scrolledWindow->Layout();
    }

}

SoloPlayerUI::~SoloPlayerUI()
{
    delete this->game;
	//(*Destroy(SoloPlayerUI)
	//*)
}

