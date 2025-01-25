#ifndef RANKINGDIALOG_H
#define RANKINGDIALOG_H

#include <vector>
#include "PlayerStats.h"

//(*Headers(RankingDialog)
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/grid.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
//*)

class RankingDialog: public wxDialog
{
	public:

		RankingDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize, const std::vector<PlayerStats>& playersStats = std::vector<PlayerStats>());
		virtual ~RankingDialog();

		//(*Declarations(RankingDialog)
		wxChoice* LevelChoice;
		wxChoice* OptionsChoice;
		wxGrid* Grid1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		//*)

	protected:

		//(*Identifiers(RankingDialog)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_CHOICE1;
		static const long ID_CHOICE2;
		static const long ID_GRID1;
		//*)

	private:
	    wxGrid* statsGrid;
        std::vector<PlayerStats> playersStats;
        void recalculateGridData();
		//(*Handlers(RankingDialog)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
