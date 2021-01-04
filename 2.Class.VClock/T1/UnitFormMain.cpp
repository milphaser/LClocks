//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TformMain *formMain;

VClock<int> vcA(3);	// Показание за събитието A
VClock<int> vcB(3);	// Показание за събитието B
//---------------------------------------------------------------------------
__fastcall TformMain::TformMain(TComponent* Owner)
	: TForm(Owner)
{
	// get the current style flags
	LONG const dwStyleA0 = GetWindowLong(leditVa0->Handle, GWL_STYLE);
	LONG const dwStyleA1 = GetWindowLong(leditVa1->Handle, GWL_STYLE);
	LONG const dwStyleA2 = GetWindowLong(leditVa2->Handle, GWL_STYLE);
	LONG const dwStyleB0 = GetWindowLong(leditVb0->Handle, GWL_STYLE);
	LONG const dwStyleB1 = GetWindowLong(leditVb1->Handle, GWL_STYLE);
	LONG const dwStyleB2 = GetWindowLong(leditVb2->Handle, GWL_STYLE);

	// add ES_NUMBER to the current style flags
	SetWindowLong(leditVa0->Handle, GWL_STYLE, dwStyleA0 | ES_NUMBER | ES_RIGHT);
	SetWindowLong(leditVa1->Handle, GWL_STYLE, dwStyleA1 | ES_NUMBER | ES_RIGHT);
	SetWindowLong(leditVa2->Handle, GWL_STYLE, dwStyleA2 | ES_NUMBER | ES_RIGHT);
	SetWindowLong(leditVb0->Handle, GWL_STYLE, dwStyleB0 | ES_NUMBER | ES_RIGHT);
	SetWindowLong(leditVb1->Handle, GWL_STYLE, dwStyleB1 | ES_NUMBER | ES_RIGHT);
	SetWindowLong(leditVb2->Handle, GWL_STYLE, dwStyleB2 | ES_NUMBER | ES_RIGHT);
}
//---------------------------------------------------------------------------
void __fastcall TformMain::FormShow(TObject *Sender)
{
	// VC1 Rule
	for(unsigned int i = 0; i < vcA.Size(); i++)
	{
		leditVa0->Text = vcA[0];
		leditVa1->Text = vcA[1];
		leditVa2->Text = vcA[2];

		leditVb0->Text = vcB[0];
		leditVb1->Text = vcB[1];
		leditVb2->Text = vcB[2];
	}
}
//---------------------------------------------------------------------------
void __fastcall TformMain::buttonIncrementA0Click(TObject *Sender)
{
	if(Sender == buttonIncrementA0)
	{
		vcA.Update(0);
		leditVa0->Text = vcA[0];
	}
	else if(Sender == buttonIncrementA1)
	{
		vcA.Update(1);
		leditVa1->Text = vcA[1];
	}
	else if(Sender == buttonIncrementA2)
	{
		vcA.Update(2);
		leditVa2->Text = vcA[2];
	}
	else if(Sender == buttonIncrementB0)
	{
		vcB.Update(0);
		leditVb0->Text = vcB[0];
	}
	else if(Sender == buttonIncrementB1)
	{
		vcB.Update(1);
		leditVb1->Text = vcB[1];
	}
	else if(Sender == buttonIncrementB2)
	{
		vcB.Update(2);
		leditVb2->Text = vcB[2];
	}
}
//---------------------------------------------------------------------------
void __fastcall TformMain::leditVa0Change(TObject *Sender)
{
	int intHB = 0;

	// А. Определяне на релацията HB (предшестване)
	// чрез сравнение на двата векторни часовника,
	// съгласно правилата за тяхното сравнение
	if(vcA < vcB)
	{
		intHB = 0;
		labelHB->Caption = "a -> b {a предшества b}";
	}
	else if(vcB < vcA)
	{
		intHB = 1;
		labelHB->Caption = "b -> a {b предшества a}";
	}
	else if(vcA == vcB)
	{
		intHB = 2;
		labelHB->Caption = "{събитията са едновременни}";
	}
	else
	{
		intHB = 3;
		labelHB->Caption = "a || b {събитията са конкурентни}";
	}

	// Б. Лексикографическо сравнение на двата векторни часовника
	// Б.1 Извличане на векторите от двата часовника
	vector<int> v1, v2;
	for(unsigned int i = 0; i < vcA.Size(); i++)
	{
		v1.push_back(vcA[i]);
		v2.push_back(vcB[i]);
	}
	// Б.2 Използване на вграденото (лексигографическо) сравнение на вектори
	String str;
	if(v1 < v2)
	{
		str = "лексикографически: {a предшества b}";
		if(intHB != 0)
			str += "?!";
	}
	else if(v2 < v1)
	{
		str = "лексикографически: {b предшества a}";
		if(intHB != 1)
			str += "?!";
	}
	else if(v1 == v2)
	{
		str = "лексикографически: {събитията са едновременни}";
		if(intHB != 2)
			str += "?!";
	}
	else
	{
		str = "лексикографически: {събитията са конкурентни}";
		if(intHB != 3)
			str += "?!";
	}
	labelLex->Caption = str;
}
//---------------------------------------------------------------------------

