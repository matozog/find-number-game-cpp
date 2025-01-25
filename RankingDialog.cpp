#include "RankingDialog.h"

//(*InternalHeaders(RankingDialog)
#include <wx/intl.h>
#include <wx/string.h>
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
    int totalHeight = 30 * this->playersStats.size();

	//(*Initialize(RankingDialog)
	wxFlexGridSizer* FlexGridSizer1;
	wxGridSizer* GridSizer1;

	Create(parent, id, _("Ranking graczy"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
	GridSizer1 = new wxGridSizer(2, 2, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Poziom trudności:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	GridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Kryterium:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
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
    statsGrid = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxSize(325, totalHeight), 0, _T("ID_GRID1"));
    statsGrid->CreateGrid(0, 4); // Create grid with 4 columns (no rows initially)
    statsGrid->EnableEditing(false);

    // Set column labels
    statsGrid->SetColLabelValue(0, "Nick gracza");
    statsGrid->SetColLabelValue(1, "Poziom");
    statsGrid->SetColLabelValue(2, _("Ilość prób"));
    statsGrid->SetColLabelValue(3, "Czas (s)");

    FlexGridSizer1->Add(statsGrid, 1, wxALL|wxEXPAND, 15);

	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);
	//*)

	this->recalculateGridData();
}

void RankingDialog::recalculateGridData() {
    // To function
    statsGrid->ClearGrid(); // Clear any existing grid data

    // Add rows for the number of players
    if (statsGrid->GetNumberRows() < static_cast<int>(this->playersStats.size())) {
        statsGrid->AppendRows(this->playersStats.size() - statsGrid->GetNumberRows());
    }

    // Populate grid with player data
    for (size_t i = 0; i < this->playersStats.size(); ++i) {
        statsGrid->SetCellValue(i, 0, this->playersStats[i].getNick());
        statsGrid->SetCellValue(i, 1, _(this->playersStats[i].getLevel()));
        statsGrid->SetCellValue(i, 2, wxString::Format("%d", this->playersStats[i].getAttempts()));
        statsGrid->SetCellValue(i, 3, wxString::Format("%.2f", this->playersStats[i].getTime()));
    }

    statsGrid->AutoSizeColumns(); // Adjust column sizes to fit content
}

RankingDialog::~RankingDialog()
{
	//(*Destroy(RankingDialog)
	//*)
}

