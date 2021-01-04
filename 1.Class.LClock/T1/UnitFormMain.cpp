//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TformMain *formMain;
//---------------------------------------------------------------------------
__fastcall TformMain::TformMain(TComponent* Owner)
	: TForm(Owner)
{
	// get the current style flags
	LONG const dwStyle01 = GetWindowLong(leditPId->Handle, GWL_STYLE);
	LONG const dwStyle02 = GetWindowLong(leditLC->Handle, GWL_STYLE);
	LONG const dwStyle11 = GetWindowLong(leditPIdSent->Handle, GWL_STYLE);
	LONG const dwStyle12 = GetWindowLong(leditLCSent->Handle, GWL_STYLE);
	LONG const dwStyle21 = GetWindowLong(leditPIdReceived->Handle, GWL_STYLE);
	LONG const dwStyle22 = GetWindowLong(leditLCReceived->Handle, GWL_STYLE);

	// add ES_NUMBER to the current style flags
	SetWindowLong(leditPId->Handle, GWL_STYLE, 		dwStyle01 | ES_NUMBER | ES_RIGHT);
	SetWindowLong(leditLC->Handle, GWL_STYLE, 		dwStyle02 | ES_NUMBER | ES_RIGHT);
	SetWindowLong(leditPIdSent->Handle, GWL_STYLE, 	dwStyle11 | ES_NUMBER | ES_RIGHT);
	SetWindowLong(leditLCSent->Handle, GWL_STYLE,    	dwStyle12 | ES_NUMBER | ES_RIGHT);
	SetWindowLong(leditPIdReceived->Handle, GWL_STYLE, 	dwStyle21 | ES_NUMBER | ES_RIGHT);
	SetWindowLong(leditLCReceived->Handle, GWL_STYLE,	dwStyle22 | ES_NUMBER | ES_RIGHT);

	// Set PId
	leditPId->Text = "1000";
}
//---------------------------------------------------------------------------
void __fastcall TformMain::FormShow(TObject *Sender)
{
	// LC0 Rule
	lcClock = new LClock<int, String>(leditPId->Text);
	leditLC->Text = lcClock->Get();
}
//---------------------------------------------------------------------------
void __fastcall TformMain::buttonInternalEventClick(TObject *Sender)
{
	labelIsLessThan->Hide();

	// LC1 Rule
	lcClock->Update();
	leditLC->Text = lcClock->Get();
}
//---------------------------------------------------------------------------
void __fastcall TformMain::buttonSendClick(TObject *Sender)
{
	labelIsLessThan->Hide();

	// LC2 Rule
	buttonInternalEventClick(Sender);
	leditPIdSent->Text = leditPId->Text;
	leditLCSent->Text = lcClock->Get();
}
//---------------------------------------------------------------------------
void __fastcall TformMain::buttonReceiveClick(TObject *Sender)
{
	labelIsLessThan->Hide();
	if(leditPIdReceived->Text.IsEmpty() || leditLCReceived->Text.IsEmpty())
	{
		ShowMessage("Invalid MSG - empty fields");
		return;
	}

	// LC3 Rule
	LClock<int, String> lcClockOther(leditLCReceived->Text.ToInt(), leditPIdReceived->Text);
	if(*lcClock < lcClockOther)
		labelIsLessThan->Show();

	lcClock->Update(leditLCReceived->Text.ToInt());
	leditLC->Text = lcClock->Get();
}
//---------------------------------------------------------------------------
void __fastcall TformMain::FormClose(TObject *Sender, TCloseAction &Action)
{
  delete lcClock;
}
//---------------------------------------------------------------------------

