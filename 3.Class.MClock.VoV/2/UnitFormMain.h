//---------------------------------------------------------------------------

#ifndef UnitFormMainH
#define UnitFormMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
#include "MClock.h"
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.CategoryButtons.hpp>
#include <Vcl.ButtonGroup.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *btnEventP0;
	TStringGrid *sgMatrix0;
	TStringGrid *sgMatrix1;
	TStringGrid *sgMatrix2;
	TGroupBox *gb0;
	TStaticText *sTxt0;
	TButton *btnP0toP1;
	TButton *btnP0toP2;
	TGroupBox *gb1;
	TStaticText *sTxt1;
	TButton *btnP1toP0;
	TButton *btnP1toP2;
	TGroupBox *gb2;
	TStaticText *stxt2;
	TButton *btnP2toP0;
	TButton *btnP2toP1;
	TButton *btnEventP1;
	TButton *btnEventP2;
	TLabel *labelM1;
	TLabel *labelM0;
	TLabel *labelM2;
	TStatusBar *sbMsgReceived;
	TGroupBox *gb01;
	TButton *btnReset0;
	TButton *btnReset1;
	TButton *btnReset2;
	TLabel *resultTxt0;
	TButton *MC0andMC1;
	TButton *MC0andMC2;
	TLabel *Label1;
	TLabel *result0;
	TGroupBox *gb11;
	TGroupBox *gb21;
	TButton *MC1andMC0;
	TButton *MC1andMC2;
	TButton *MC2andMC0;
	TButton *MC2andMC1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *result1;
	TLabel *result2;
	TLabel *resultTxt1;
	TLabel *resultTxt2;
	void __fastcall btnEventP0Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btnP0toP1Click(TObject *Sender);
	void __fastcall btnP0toP2Click(TObject *Sender);
	void __fastcall btnP1toP0Click(TObject *Sender);
	void __fastcall btnP1toP2Click(TObject *Sender);
	void __fastcall btnP2toP0Click(TObject *Sender);
	void __fastcall btnP2toP1Click(TObject *Sender);
	void __fastcall MC0andMC1Click(TObject *Sender);
	void __fastcall MC0andMC2Click(TObject *Sender);
	void __fastcall MC1andMC0Click(TObject *Sender);
	void __fastcall MC1andMC2Click(TObject *Sender);
	void __fastcall MC2andMC0Click(TObject *Sender);
	void __fastcall MC2andMC1Click(TObject *Sender);
	void __fastcall btnReset0Click(TObject *Sender);
	void __fastcall btnReset1Click(TObject *Sender);
	void __fastcall btnReset2Click(TObject *Sender);

private:	// User declarations

	void __fastcall ResetMClocks();
public:		// User declarations
	int intItemSelected;
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
