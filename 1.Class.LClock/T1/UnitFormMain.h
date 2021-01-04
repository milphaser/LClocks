//---------------------------------------------------------------------------

#ifndef UnitFormMainH
#define UnitFormMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
#include "LClock.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TformMain : public TForm
{
__published:	// IDE-managed Components
	TMemo *memoProtocol;
	TMemo *Memo1;
	TGroupBox *gbMessageSent;
	TLabel *Label3;
	TLabel *Label1;
	TLabeledEdit *leditPIdSent;
	TLabeledEdit *leditLCSent;
	TButton *buttonSend;
	TGroupBox *gbMessageReceived;
	TLabel *Label2;
	TLabel *Label4;
	TLabeledEdit *leditPIdReceived;
	TLabeledEdit *leditLCReceived;
	TButton *buttonReceive;
	TGroupBox *gbInternalEvent;
	TLabel *labelIsLessThan;
	TLabeledEdit *leditPId;
	TLabeledEdit *leditLC;
	TButton *buttonInternalEvent;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall buttonInternalEventClick(TObject *Sender);
	void __fastcall buttonSendClick(TObject *Sender);
	void __fastcall buttonReceiveClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

private:	// User declarations
	LClock<int, String>* lcClock;

public:		// User declarations
	__fastcall TformMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformMain *formMain;
//---------------------------------------------------------------------------
#endif
