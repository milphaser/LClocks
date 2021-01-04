//---------------------------------------------------------------------------

#ifndef UnitFormMainH
#define UnitFormMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
#include "VClock.h"
//---------------------------------------------------------------------------
class TformMain : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TGroupBox *gboxVb;
	TLabeledEdit *leditVb0;
	TLabeledEdit *leditVb1;
	TLabeledEdit *leditVb2;
	TButton *buttonIncrementB0;
	TButton *buttonIncrementB1;
	TButton *buttonIncrementB2;
	TGroupBox *gboxVa;
	TLabeledEdit *leditVa0;
	TLabeledEdit *leditVa1;
	TLabeledEdit *leditVa2;
	TButton *buttonIncrementA0;
	TButton *buttonIncrementA1;
	TButton *buttonIncrementA2;
	TGroupBox *gbHP;
	TLabel *labelHB;
	TLabel *labelLex;
	void __fastcall buttonIncrementA0Click(TObject *Sender);
	void __fastcall leditVa0Change(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);

private:	// User declarations

public:		// User declarations
	__fastcall TformMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformMain *formMain;
//---------------------------------------------------------------------------
#endif
