#include "MultiPlayerUI.h"

//(*InternalHeaders(MultiPlayerUI)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(MultiPlayerUI)
const long MultiPlayerUI::ID_STATICTEXT2 = wxNewId();
const long MultiPlayerUI::ID_STATICTEXT3 = wxNewId();
const long MultiPlayerUI::ID_STATICTEXT4 = wxNewId();
const long MultiPlayerUI::ID_STATICTEXT5 = wxNewId();
const long MultiPlayerUI::ID_TEXTCTRL1 = wxNewId();
const long MultiPlayerUI::ID_TEXTCTRL2 = wxNewId();
const long MultiPlayerUI::ID_TEXTCTRL3 = wxNewId();
const long MultiPlayerUI::ID_TEXTCTRL4 = wxNewId();
const long MultiPlayerUI::ID_TEXTCTRL5 = wxNewId();
const long MultiPlayerUI::ID_TEXTCTRL6 = wxNewId();
const long MultiPlayerUI::ID_STATICTEXT6 = wxNewId();
const long MultiPlayerUI::ID_TEXTCTRL7 = wxNewId();
const long MultiPlayerUI::ID_STATICTEXT7 = wxNewId();
const long MultiPlayerUI::ID_TEXTCTRL8 = wxNewId();
const long MultiPlayerUI::ID_STATICTEXT8 = wxNewId();
const long MultiPlayerUI::ID_TEXTCTRL9 = wxNewId();
const long MultiPlayerUI::ID_STATICTEXT9 = wxNewId();
const long MultiPlayerUI::ID_TEXTCTRL10 = wxNewId();
const long MultiPlayerUI::ID_GRID1 = wxNewId();
const long MultiPlayerUI::ID_GRID2 = wxNewId();
const long MultiPlayerUI::ID_TIMER1 = wxNewId();
const long MultiPlayerUI::ID_TIMER2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(MultiPlayerUI,wxDialog)
	//(*EventTable(MultiPlayerUI)
	//*)
END_EVENT_TABLE()

MultiPlayerUI::MultiPlayerUI(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(MultiPlayerUI)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxFlexGridSizer* FlexGridSizer1;
	wxGridSizer* GridSizer1;
	wxGridSizer* GridSizer2;

	Create(parent, id, _("Tryb dwuosobowy"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(1000,280));
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(4, 1, 0, 0);
	GridSizer1 = new wxGridSizer(2, 4, 0, 0);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Gracz1"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	GridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Gracz2"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	GridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Zbiór"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	GridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Ilość cyfr w liczbie"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	GridSizer1->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Text"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	GridSizer1->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("Text"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	GridSizer1->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, _("Text"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	GridSizer1->Add(TextCtrl3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, _("Text"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	GridSizer1->Add(TextCtrl4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(GridSizer1, 1, wxALL|wxEXPAND, 5);
	GridSizer2 = new wxGridSizer(3, 2, 0, 0);
	TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, _("nick1"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	GridSizer2->Add(TextCtrl5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl6 = new wxTextCtrl(this, ID_TEXTCTRL6, _("nick2"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	GridSizer2->Add(TextCtrl6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Czas:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	BoxSizer1->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl7 = new wxTextCtrl(this, ID_TEXTCTRL7, _("timer"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	BoxSizer1->Add(TextCtrl7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Próby:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	BoxSizer1->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl8 = new wxTextCtrl(this, ID_TEXTCTRL8, _("il prób"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL8"));
	BoxSizer1->Add(TextCtrl8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	GridSizer2->Add(BoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("Czas:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	BoxSizer2->Add(StaticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl9 = new wxTextCtrl(this, ID_TEXTCTRL9, _("timer"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL9"));
	BoxSizer2->Add(TextCtrl9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("Próby:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	BoxSizer2->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrl10 = new wxTextCtrl(this, ID_TEXTCTRL10, _("il prób"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL10"));
	BoxSizer2->Add(TextCtrl10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	GridSizer2->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Grid1 = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID1"));
	GridSizer2->Add(Grid1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Grid2 = new wxGrid(this, ID_GRID2, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID2"));
	GridSizer2->Add(Grid2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(GridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	Timer1.SetOwner(this, ID_TIMER1);
	Timer2.SetOwner(this, ID_TIMER2);
	SetSizer(FlexGridSizer1);
	Layout();
	//*)
}

MultiPlayerUI::~MultiPlayerUI()
{
	//(*Destroy(MultiPlayerUI)
	//*)
}

