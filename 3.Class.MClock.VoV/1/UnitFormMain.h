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
	TImage *imgExample;
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
	TRadioGroup *rgImageExamples;
	TButton *btnReset;
	void __fastcall btnEventP0Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btnP0toP1Click(TObject *Sender);
	void __fastcall btnP0toP2Click(TObject *Sender);
	void __fastcall btnP1toP0Click(TObject *Sender);
	void __fastcall btnP1toP2Click(TObject *Sender);
	void __fastcall btnP2toP0Click(TObject *Sender);
	void __fastcall btnP2toP1Click(TObject *Sender);
	void __fastcall btnResetClick(TObject *Sender);
	//void __fastcall rbExample1Click(TObject *Sender);
	void __fastcall rgImageExamplesClick(TObject *Sender);

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
