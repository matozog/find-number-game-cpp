#include "SoloPlayerUI.h"
#include <wx/wx.h>

//(*InternalHeaders(SoloPlayerUI)
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/statline.h>
//*)

#undef _
#define _(s) wxString::FromUTF8(s)

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

wxColour customGreen(0, 204, 102); // RGB for Forest Green
wxColour customBlack(38, 38, 38);     // Pure black
wxColour evenRow(204, 255, 230);
wxFont currentAttemptInputFont(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
wxFont inputFont(14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
wxFont labelFont(11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

SoloPlayerUI::SoloPlayerUI(wxWindow* parent,wxWindowID id, const wxPoint& pos,const wxSize& size)
{
    //wxBitmap questionTagBitMap("assets/question-tag.png", wxBITMAP_TYPE_PNG);

	//(*Initialize(SoloPlayerUI)
	wxFlexGridSizer* BoxSizer1;
	wxBoxSizer* GridSizer1;

	Create(parent, wxID_ANY, _("Tryb jednoosobowy"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SinglePlayerContentFlexbox = new wxFlexGridSizer(7, 1, 0, 0);
	GridSizer1 = new wxBoxSizer(wxHORIZONTAL);

    this->SetBackgroundColour(customGreen);

	// Player nickname
	wxGridSizer* PlayerNicknameBox = new wxGridSizer(2, 1, 0, 0);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Gracz"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText2->SetFont(labelFont);
	PlayerNicknameBox->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    PlayerNicknameTextField = new wxTextCtrl(this, ID_PLAYER_NICKNAME_TEXT_FIELD, _("Text"), wxDefaultPosition, wxSize(100, 32), wxTE_READONLY|wxTE_CENTER, wxDefaultValidator, _T("ID_PLAYER_NICKNAME_TEXT_FIELD"));
    PlayerNicknameTextField->SetFont(inputFont);
	PlayerNicknameBox->Add(PlayerNicknameTextField, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	GridSizer1->Add(PlayerNicknameBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

	//Level
    wxGridSizer* LevelBox = new wxGridSizer(2, 1, 0, 0);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Poziom trudności"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText3->SetFont(labelFont);
	LevelBox->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("Text"), wxDefaultPosition, wxSize(100, 32), wxTE_READONLY|wxTE_CENTER, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl2->SetFont(inputFont);
	LevelBox->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer1->Add(LevelBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

	// Info
    GameInfoBox = new wxGridSizer(2, 1, 0, 0);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Szukana liczba"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText4->SetFont(labelFont);
	GameInfoBox->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	//TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, _("Text"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	//GameInfoBox->Add(TextCtrl3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    //wxStaticBitmap* questionIcon = new wxStaticBitmap(this, wxID_ANY, questionTagBitMap, wxPoint(25, 25));
    //GameInfoBox->Add(questionIcon, 0, wxALL, 5);
    GridSizer1->Add(GameInfoBox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

    SinglePlayerContentFlexbox->Add(GridSizer1, 1, wxALL|wxEXPAND, 5);
    wxStaticLine* line1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	SinglePlayerContentFlexbox->Add(line1, 0, wxALL|wxEXPAND, 5);

    // Game board
    GameBoard = new wxFlexGridSizer(2, 1, 0, 0);
	SinglePlayerContentFlexbox->Add(GameBoard, 1, wxALL, 5);

	BoxSizer1 = new wxFlexGridSizer(1, 3, 0, 0);
	BoxSizer1->AddGrowableCol(1);

	// Amount of attempts
	wxBoxSizer* AmountOfAttemptsBox = new wxBoxSizer(wxHORIZONTAL);
    StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Ilość prób:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    StaticText6->SetFont(labelFont);
	AmountOfAttemptsBox->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	AttemptsTextField = new wxTextCtrl(this, ID_ATTEMPTS_TEXT_FIELD, _("0"), wxDefaultPosition, wxSize(60, 30), wxTE_READONLY|wxTE_CENTER, wxDefaultValidator, _T("ID_ATTEMPTS_TEXT_FIELD"));
	AttemptsTextField->SetFont(inputFont);
	AmountOfAttemptsBox->Add(AttemptsTextField, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);

    BoxSizer1->Add(AmountOfAttemptsBox, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);

	//BoxSizer1->AddStretchSpacer(); // Add stretchable space
	BoxSizer1->AddSpacer(1);

	// Timer
	wxBoxSizer* TimerBox = new wxBoxSizer(wxHORIZONTAL);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Czas:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	StaticText5->SetFont(labelFont);
	TimerBox->Add(StaticText5, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	TimerTextField = new wxTextCtrl(this, ID_TIMER_TEXT_FIELD, _("0"), wxDefaultPosition, wxSize(100, 30), wxTE_READONLY|wxTE_CENTER, wxDefaultValidator, _T("ID_TIMER_TEXT_FIELD"));
	TimerTextField->SetFont(inputFont);
	TimerBox->Add(TimerTextField, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	Timer1.SetOwner(this);

    BoxSizer1->Add(TimerBox, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);

    wxStaticLine* line2 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
    SinglePlayerContentFlexbox->Add(line2, 0, wxALL|wxEXPAND, 5);

	SinglePlayerContentFlexbox->Add(BoxSizer1, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 10);
	SetSizer(SinglePlayerContentFlexbox);
	Timer1.SetOwner(this, ID_TIMER1);
	SinglePlayerContentFlexbox->Fit(this);
	SinglePlayerContentFlexbox->SetSizeHints(this);
	//*)

    scrolledWindow = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL);
    scrolledWindow->SetScrollRate(0, 10);

    PlayerAttemptsGridBox = new wxGridSizer(1, 0, 0, 0);
    GameBoard->Add(scrolledWindow, 1, wxALL, 5);

    CurrentAttemptGridBox = new wxBoxSizer(wxHORIZONTAL);
    GameBoard->Add(CurrentAttemptGridBox, 1, wxALL, 10);
    AcceptAttemptButton = new wxButton(this, wxNewId(), _("Zatwierdź"), wxDefaultPosition, wxSize(120, 35), 0, wxDefaultValidator, _T("ID_SINGLE_PLAYER_ACCEPT_ATTEMPT_BUTTON"));
    AcceptAttemptButton->SetFont(labelFont);
    AcceptAttemptButton->SetBackgroundColour(customBlack);
    AcceptAttemptButton->SetForegroundColour(wxColour(255, 255, 255));

    AcceptAttemptButton->Bind(wxEVT_ENTER_WINDOW, &SoloPlayerUI::OnMouseEnterAcceptButton, this);

    scrolledWindow->SetSizer(PlayerAttemptsGridBox);
    PlayerAttemptsGridBox->SetSizeHints(scrolledWindow);

    SinglePlayerContentFlexbox->Layout();
    SinglePlayerContentFlexbox->Fit(this);

    AcceptAttemptButton->Bind(wxEVT_BUTTON, &SoloPlayerUI::OnAcceptAttemptClick, this);

    this->Bind(wxEVT_CLOSE_WINDOW, &SoloPlayerUI::OnCloseGame, this);
    // Bind timer event
    this->Bind(wxEVT_TIMER, &SoloPlayerUI::OnTimerTick, this);

    // Timer
    Timer1.Start(100);

    // Bind the paint event to draw the gradient
    //this->Bind(wxEVT_PAINT, &SoloPlayerUI::OnPaint, this);
}

void SoloPlayerUI::OnMouseEnterAcceptButton(wxMouseEvent& event){
    wxButton* button = dynamic_cast<wxButton*>(event.GetEventObject());
    if (button) {
        button->SetBackgroundColour(customBlack);  // Light blue on hover
        button->Refresh();
    }
    event.Skip();
}

std::string joinStrings(const std::vector<std::string>& strings, const std::string& delimiter) {
    std::string result;
    for (size_t i = 0; i < strings.size(); ++i) {
        result += "?";
        //result += strings[i];
        /*if (i < strings.size() - 1) {
            result += delimiter; // Add the delimiter except after the last element
        }*/
    }
    return result;
}

void SoloPlayerUI::createGameBoard(Game* game){
    int gameBoardWidth = 550;
    int amountOfVisibleAttempts = 8;
    if(game->getLevel()->getLevelType() == LevelType::MEDIUM) {
        gameBoardWidth = 650;
    } else if (game->getLevel()->getLevelType() == LevelType::HARD){
        gameBoardWidth = 780;
    }
    this->game = game;
    PlayerAttemptsGridBox->SetCols(2);
    scrolledWindow->SetMaxSize(wxSize(gameBoardWidth, 600)); // -1 for width means no limit, 200px max height
    scrolledWindow->SetMinSize(wxSize(gameBoardWidth, 0));
    PlayerNicknameTextField->SetValue(game->getPlayer1()->getNickname());
    TextCtrl2->SetValue(_(game->getLevel()->getLevelTypeText()));
    //TextCtrl3->SetValue(joinStrings(game->getSolution(), ""));
    this->generateNumberInfo(game->getLevel()->getAmountOfDigits());
    this->generateCurrentAttempt();
    SinglePlayerContentFlexbox->Layout();
    //wxMessageBox(std::to_string(CurrentAttemptGridBox->GetSize().GetWidth()), _("Sukces"), wxOK | wxICON_INFORMATION);
}

void SoloPlayerUI::generateNumberInfo(int amountOfDigits) {
    wxBitmap questionTagBitMap("assets/question-tag.png", wxBITMAP_TYPE_PNG);
    wxBoxSizer* boxSizer = new wxBoxSizer(wxHORIZONTAL);

    if (!questionTagBitMap.IsOk()) {
        wxLogError("Failed to load image: assets/question-tag.png");
        return;
    }

    for(int i = 0; i < amountOfDigits; i++){
        wxStaticBitmap* questionIcon = new wxStaticBitmap(this, wxID_ANY, questionTagBitMap, wxPoint(30, 30));
        boxSizer->Add(questionIcon, 0, wxALL, 0);
    }
    GameInfoBox->Add(boxSizer, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

}

void SoloPlayerUI::generateAttempt(Attempt attempt) {
    Player* player1 = game->getPlayer1();
    int amountOfAttempts = player1->getAttempts().size();
    PlayerAttemptsGridBox->SetRows(amountOfAttempts);

    AttemptsTextField->SetValue(std::to_string(amountOfAttempts));

    wxBoxSizer* AttemptTextFieldsBox = new wxBoxSizer(wxHORIZONTAL);

    // Create a wxFont with a larger size
    wxFont font(15, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);

    for(int j=0; j<attempt.getDigits().size(); j++){
        wxString id = wxString::Format("ID_SINGLE_PLAYER_ATTEMPT_%d", j);
        wxTextCtrl* attemptCell = new wxTextCtrl(scrolledWindow, wxNewId(), _(attempt.getDigits().at(j)), wxDefaultPosition, wxSize(45, 35), wxTE_READONLY|wxTE_CENTER, wxDefaultValidator, id);
        attemptCell->SetFont(font);
        AttemptTextFieldsBox->Add(attemptCell, 0, wxRIGHT, 25);
    }

    wxBoxSizer* AttemptResultBoxSizer = new wxBoxSizer(wxHORIZONTAL);

    // Load an image file
    wxBitmap circleBitMap("assets/circle.png", wxBITMAP_TYPE_PNG);
    // Load an image file
    wxBitmap checkMarkBitMap("assets/check-mark.png", wxBITMAP_TYPE_PNG);
    //wxMessageBox(std::to_string(attempt.getCorrectDigits()), _("Sukces"), wxOK | wxICON_INFORMATION);
    for(int i = 0; i<attempt.getCorrectDigits(); i++) {
        // Display the image in the panel
        wxStaticBitmap* checkMarkIcon = new wxStaticBitmap(scrolledWindow, wxID_ANY, checkMarkBitMap, wxPoint(30, 30));
        AttemptResultBoxSizer->Add(checkMarkIcon, 0, wxRIGHT, 20);
    }

    //wxMessageBox(std::to_string(attempt.getCorrectDigitsMisplaced()), _("Sukces"), wxOK | wxICON_INFORMATION);
    for(int i = 0; i<attempt.getCorrectDigitsMisplaced(); i++) {
        // Display the image in the panel
        wxStaticBitmap* circleIcon = new wxStaticBitmap(scrolledWindow, wxID_ANY, circleBitMap, wxPoint(30, 30));
        AttemptResultBoxSizer->Add(circleIcon, 0, wxRIGHT, 20);
    }

    AttemptTextFieldsBox->AddSpacer(15);

    //if(amountOfAttempts%2 == 0){
    //    AttemptResultBoxSizer->SetBackgroundColour(evenRow);
    //    AttemptTextFieldsBox->SetBackgroundColour(evenRow);
    //}

    //wxButton* ButtonTmp = new wxButton(scrolledWindow, wxNewId(), _("Tmp"), wxDefaultPosition, wxSize(100, 30), 0, wxDefaultValidator, _T("ID_SINGLE_PLAYER_ACCEPT_ATTEMPT_BUTTON-tmp"));
    PlayerAttemptsGridBox->Add(AttemptTextFieldsBox, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    PlayerAttemptsGridBox->Add(AttemptResultBoxSizer, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    PlayerAttemptsGridBox->Layout();

    if(amountOfAttempts < 8) {
        scrolledWindow->SetMinSize(wxSize(-1, amountOfAttempts*50));
    }
    scrolledWindow->SetSizer(PlayerAttemptsGridBox);
    scrolledWindow->Layout();
    scrolledWindow->FitInside();
    scrolledWindow->Scroll(0, 600);

    SinglePlayerContentFlexbox->Layout();
    SinglePlayerContentFlexbox->Fit(this);
}

void SoloPlayerUI::generateCurrentAttempt() {
    Level* level = game->getLevel();
    CurrentAttemptGridBox->Clear(true);
    currentAttemptCtrls.clear();

    for(int i=0; i<level->getAmountOfDigits(); i++){
        std::string cellId = "ID_SINGLE_PLAYER_CURRENT_ATTEMPT_" + i;
        wxTextCtrl* currentAttemptCell = new wxTextCtrl(this, wxNewId(), "", wxDefaultPosition, wxSize(45, 35), wxTE_CENTER, wxDefaultValidator, cellId);
        currentAttemptCell->SetFont(currentAttemptInputFont);
        //currentAttemptCell->Bind(wxEVT_TEXT, &SoloPlayerUI::OnTextChange, this);
         currentAttemptCell->Bind(wxEVT_TEXT, [this, currentAttemptCell](wxCommandEvent& event) {
            wxString value = currentAttemptCell->GetValue();

            // Allow only one digit (0-9)
            if (value.length() > 1 || !value.IsEmpty() && !wxIsdigit(value[0])) {
                currentAttemptCell->SetValue(value.substr(0, 1));
                currentAttemptCell->SetInsertionPointEnd(); // Maintain cursor position
            }

            this->UpdateAcceptButtonState();

            event.Skip(); // Let the event propagate
        });

        currentAttemptCtrls.push_back(currentAttemptCell);
        CurrentAttemptGridBox->Add(currentAttemptCell, 0, wxRIGHT, 25);
    }
    CurrentAttemptGridBox->Add(AcceptAttemptButton, 0, wxLEFT, 20);
    this->UpdateAcceptButtonState();

    CurrentAttemptGridBox->Layout();
    SinglePlayerContentFlexbox->Fit(this);
}

void SoloPlayerUI::UpdateAcceptButtonState() {
    for (wxTextCtrl* textCtrl : currentAttemptCtrls) {
        if (textCtrl->GetValue().IsEmpty()) {
            AcceptAttemptButton->Disable();
            return;
        }
    }
    AcceptAttemptButton->Enable();
}

void SoloPlayerUI::OnAcceptAttemptClick(wxCommandEvent& evt) {
    std::vector<std::string> digits;

    for (wxTextCtrl* textCtrl : this->currentAttemptCtrls) {
        std::string value = textCtrl->GetValue().ToStdString();
        digits.push_back(value);
    }

    if(digits.size() > 0) {
        Attempt attempt(digits, this->game->getSolution());
        this->game->getPlayer1()->addAttempt(attempt);
        this->generateAttempt(attempt);

        scrolledWindow->FitInside();
        scrolledWindow->Layout();
    }

    if (game->checkGuess(digits)) {
        Timer1.Stop();
        this->game->getPlayer1()->setChallengeTime(elapsedTime);
        this->game->savePlayerStats();
        wxMessageBox(_("Brawo " + this->game->getPlayer1()->getNickname() + "! Zgadłeś liczbę! Potrzebowałeś "
                       + std::to_string(this->game->getPlayer1()->getAttempts().size()) + " prób. Czas wyzwania wynosi: "
                       + wxString::Format("%.1f s", elapsedTime)), _("Sukces"), wxOK | wxICON_INFORMATION);
    }
}

void SoloPlayerUI::OnTextChange(wxCommandEvent& evt){
        wxString value = evt.GetString();

        // Allow only one digit (0-9)
        if (value.length() > 1 || !value.IsEmpty() && !wxIsdigit(value[0])) {
            //singleDigitCtrl->SetValue(value.substr(0, 1));
            //singleDigitCtrl->SetInsertionPointEnd(); // Maintain cursor position
        }

        //event.Skip();

        // Print or use the new value
        //wxLogMessage("Text changed: %s", newValue);
}

void SoloPlayerUI::OnCloseGame(wxCloseEvent& event) {
    delete this->game;
    this->currentAttemptCtrls.clear();
    this->EndModal(wxID_OK);
}

void SoloPlayerUI::OnTimerTick(wxTimerEvent& event){
     this->elapsedTime += 0.1;
     TimerTextField->SetValue(wxString::Format("%.1f s", elapsedTime));
}

SoloPlayerUI::~SoloPlayerUI()
{    delete this->game;
	//(*Destroy(SoloPlayerUI)
	//*)
}

