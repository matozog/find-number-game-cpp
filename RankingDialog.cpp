#include "RankingDialog.h"

//(*InternalHeaders(RankingDialog)
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/msgdlg.h>
//*)

#undef _
#define _(s) wxString::FromUTF8(s)

//(*IdInit(RankingDialog)
const long RankingDialog::ID_STATICTEXT1 = wxNewId();
const long RankingDialog::ID_STATICTEXT2 = wxNewId();
const long RankingDialog::ID_CHOICE1 = wxNewId();
const long RankingDialog::ID_CHOICE2 = wxNewId();
const long RankingDialog::ID_GRID1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(RankingDialog,wxDialog)
	//(*EventTable(RankingDialog)
	//*)
END_EVENT_TABLE()


RankingDialog::RankingDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size, const std::vector<PlayerStats>& stats)
{
    this->playersStats = stats;
    int totalHeight = 35 + this->playersStats.size() * 25;
    if(this->playersStats.size() > 8) {
        totalHeight = 35  + 25 * 8;
    }
    wxColour customGreen(0, 204, 102); // RGB for Forest Green
    wxFont inputFont(13, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    wxFont labelFont(11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    wxFont gridFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);

	//(*Initialize(RankingDialog)
	wxGridSizer* GridSizer1;

	Create(parent, id, _("Ranking graczy"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));

    this->SetBackgroundColour(customGreen);

	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
	GridSizer1 = new wxGridSizer(2, 2, 0, 15);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Poziom trudności"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	GridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Kryterium"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	GridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LevelChoice = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    LevelChoice->Append(_("Łatwy"));
    LevelChoice->SetSelection( LevelChoice->Append(_("Średni")) );
    LevelChoice->Append(_("Trudny"));
	GridSizer1->Add(LevelChoice, 1, wxALL|wxEXPAND, 5);
	OptionsChoice = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    OptionsChoice->SetSelection( OptionsChoice->Append(_("Ilość prób")) );
    OptionsChoice->Append(_("Czas"));
	GridSizer1->Add(OptionsChoice, 1, wxALL|wxEXPAND, 5);
	FlexGridSizer1->Add(GridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);

    // Create a wxGrid with no rows and columns initially
    statsGrid = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxSize(400, totalHeight), 0, _T("ID_GRID1"));
    statsGrid->CreateGrid(0, 4); // Create grid with 4 columns (no rows initially)
    statsGrid->EnableEditing(false);
    statsGrid->EnableScrolling(true, true);  // Enable horizontal and vertical scrolling
    statsGrid->SetScrollRate(10, 20);

    // Set column labels
    statsGrid->SetColLabelValue(0, "Nick gracza");
    statsGrid->SetColLabelValue(1, "Poziom");
    statsGrid->SetColLabelValue(2, _("Ilość prób"));
    statsGrid->SetColLabelValue(3, "Czas (s)");
    statsGrid->SetDefaultCellFont(gridFont);
    statsGrid->SetLabelFont(inputFont);
    statsGrid->SetColLabelSize(35);

    FlexGridSizer1->Add(statsGrid, 1, wxALL|wxEXPAND, 15);
    //scrolledWindow->SetSizer(FlexGridSizer1);

	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);
	//*)

	StaticText1->SetFont(labelFont);
	StaticText2->SetFont(labelFont);
	LevelChoice->SetFont(inputFont);
	OptionsChoice->SetFont(inputFont);

    this->FilterGridDataByLevel();
	this->recalculateGridData();

    LevelChoice->Bind(wxEVT_CHOICE, &RankingDialog::OnChangeLevel, this);
    OptionsChoice->Bind(wxEVT_CHOICE, &RankingDialog::OnChangeOption, this);

}

void RankingDialog::recalculateGridData() {
    if(_(OptionsChoice->GetStringSelection().ToUTF8().data()) == "Czas"){
        this->SortStatsByTIme();
    } else {
        this->SortStatsByAttempts();
    }
    statsGrid->ClearGrid(); // Clear any existing grid data

    // Add rows for the number of players
    if (statsGrid->GetNumberRows() < static_cast<int>(this->filteredStats.size())) {
        statsGrid->AppendRows(this->filteredStats.size() - statsGrid->GetNumberRows());
    }

    // Populate grid with player data
    for (size_t i = 0; i < this->filteredStats.size(); ++i) {
        statsGrid->SetCellValue(i, 0, this->filteredStats[i].getNick());
        statsGrid->SetCellValue(i, 1, _(this->filteredStats[i].getLevel()));
        statsGrid->SetCellValue(i, 2, wxString::Format("%d", this->filteredStats[i].getAttempts()));
        statsGrid->SetCellValue(i, 3, wxString::Format("%.2f", this->filteredStats[i].getTime()));
    }

    statsGrid->AutoSizeColumns(); // Adjust column sizes to fit content
    statsGrid->AutoSizeRows();

    FlexGridSizer1->FitInside(this);
}

void RankingDialog::OnChangeLevel(wxCommandEvent& event) {
    FilterGridDataByLevel();

    this->recalculateGridData();
}

void RankingDialog::FilterGridDataByLevel(){
    wxString selectedLevel = LevelChoice->GetStringSelection().ToUTF8().data();

    // Filter players by the selected level
    this->filteredStats.clear();
    std::copy_if(this->playersStats.begin(), this->playersStats.end(), std::back_inserter(filteredStats),
             [&selectedLevel](const PlayerStats& player) {
                 return _(player.getLevel()) == _(selectedLevel);
             });
}

void RankingDialog::OnChangeOption(wxCommandEvent& event) {
    this->recalculateGridData();
}

void RankingDialog::SortStatsByAttempts(){
    std::sort(this->filteredStats.begin(), this->filteredStats.end(), [](const PlayerStats& a, const PlayerStats& b) {
        return a.getAttempts() < b.getAttempts();
    });
}

void RankingDialog::SortStatsByTIme() {
    std::sort(this->filteredStats.begin(), this->filteredStats.end(), [](const PlayerStats& a, const PlayerStats& b) {
        return a.getTime() < b.getTime();
    });
}

RankingDialog::~RankingDialog()
{
	//(*Destroy(RankingDialog)
	//*)
}

