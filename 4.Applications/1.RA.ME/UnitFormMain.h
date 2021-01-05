//---------------------------------------------------------------------------

#ifndef UnitFormMainH
#define UnitFormMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
#include <Vcl.CheckLst.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <System.Win.ScktComp.hpp>
//---------------------------------------------------------------------------
#include "LClock.h"
//---------------------------------------------------------------------------
#include <list>
#include <queue>
using namespace std;
//---------------------------------------------------------------------------
class TformMain : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *gbProtocol;
	TMemo *memoProtocol;
	TStatusBar *sbarStatus;
	TSaveDialog *savedialogProtocol;
	TPopupMenu *popupProtocol;
	TMenuItem *pmiClear;
	TMenuItem *pmiSave;
	TPanel *panelControl;
	TGroupBox *gbOutChannels;
	TCheckListBox *clbOutChannels;
	TButton *buttonOpen;
	TButton *buttonClose;
	TLabeledEdit *leditLClock;
	TButton *buttonRequest;
	TButton *buttonRelease;
	TGroupBox *gbState;
	TPanel *panelReleased;
	TPanel *panelWanted;
	TPanel *panelHeld;
	TUpDown *updownDelay;
	TLabeledEdit *leditDelay;
	TCheckBox *cbRandom;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall buttonOpenClick(TObject *Sender);
	void __fastcall buttonCloseClick(TObject *Sender);
	void __fastcall leditDelayChange(TObject *Sender);
	void __fastcall pmiClearClick(TObject *Sender);
	void __fastcall pmiSaveClick(TObject *Sender);
	void __fastcall buttonRequestClick(TObject *Sender);
	void __fastcall buttonReleaseClick(TObject *Sender);
private:	// User declarations
	String stringIniFileName;
	String stringPId;

public:		// User declarations
	enum METype
	{
	  ME_RELEASED,
	  ME_WANTED,
	  ME_HELD
	} meType;

	int intDelay;

	LClock<int, String>* lcClock;			// Текущо логическо време
	LClock<int, String>* lcT1;				// Показание в момента на заявката

	list <String> *listPIds;				// СПИСЪК НА ПРОЦЕСИТЕ
	queue <TCustomWinSocket*> *queueHeld;	// ОПАШКА НА ЗАЯВКИТЕ

	__fastcall TformMain(TComponent* Owner);

	void __fastcall AddToProtocol(String source);
	TClientSocket* GetOutChannel(int num);

	String& __fastcall GetPId(void) {return stringPId;}
};
//---------------------------------------------------------------------------
extern PACKAGE TformMain *formMain;
//---------------------------------------------------------------------------
#endif
