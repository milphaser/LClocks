//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
MClock<int, 3> mClock0;
MClock<int, 3> mClock1;
MClock<int, 3> mClock2;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
	mClock0.SetPId(0);
	mClock1.SetPId(1);
	mClock2.SetPId(2);

	for(unsigned int i = 0; i < mClock0.Size(); i++)
	{
		for(unsigned int j = 0; j < mClock0[i].Size(); j++)
		{
			sgMatrix0->Cells[j][i] = IntToStr(mClock0[i][j]);
			sgMatrix1->Cells[j][i] = IntToStr(mClock1[i][j]);
			sgMatrix2->Cells[j][i] = IntToStr(mClock2[i][j]);
		}
	}

	sbMsgReceived->Panels->Items[3]->Text = Time().TimeString()+ " "+ Date().DateString();
	intItemSelected = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnEventP0Click(TObject *Sender)
{
	if(Sender == btnEventP0)
	{
		mClock0.Update(0);
		sgMatrix0->Cells[0][0] = IntToStr(mClock0[0][0]);
		sbMsgReceived->Panels->Items[0]->Text ="P0: Internal event occurred";
	}

	if(Sender == btnEventP1)
	{
		mClock1.Update(1);
		sgMatrix1->Cells[1][1] = IntToStr(mClock1[1][1]);
		sbMsgReceived->Panels->Items[1]->Text ="P1: Internal event occurred";
	}

	if(Sender == btnEventP2)
	{
		mClock2.Update(2);
		sgMatrix2->Cells[2][2] = IntToStr(mClock2[2][2]);
		sbMsgReceived->Panels->Items[2]->Text ="P2: Internal event occurred";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnP0toP1Click(TObject *Sender)
{
	//before SEND -> increment the sender
	mClock0.Update(0);

	//receive msg
	sbMsgReceived->Panels->Items[1]->Text ="P1: Message received from P0";

	//process msg MC
	mClock1.Update(mClock0);

	//show new receiver's MC
	for(unsigned int i = 0; i < mClock1.Size(); i++)
	{
		for(unsigned int j = 0; j < mClock1[i].Size(); j++)
		{
			sgMatrix1->Cells[j][i] = IntToStr(mClock1[i][j]);
		}
	}

	//show new sender's MC
	for(unsigned int i = 0; i < mClock0.Size(); i++)
	{
		for(unsigned int j = 0; j < mClock0[i].Size(); j++)
		{
			sgMatrix0->Cells[j][i] = IntToStr(mClock0[i][j]);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnP0toP2Click(TObject *Sender)
{
	//before SEND -> increment the sender
	mClock0.Update(0);

	//receive msg
	sbMsgReceived->Panels->Items[2]->Text ="P2: Message received from P0";

	//process msg MC
	mClock2.Update(mClock0);

	//show new MC
	for(unsigned int i = 0; i < mClock2.Size(); i++)
	{
		for(unsigned int j = 0; j < mClock2[i].Size(); j++)
		{
			sgMatrix2->Cells[j][i] = IntToStr(mClock2[i][j]);
		}
	}

	//show new sender's MC
	for(unsigned int i = 0; i < mClock0.Size(); i++)
	{
		for(unsigned int j = 0; j < mClock0[i].Size(); j++)
		{
			sgMatrix0->Cells[j][i] = IntToStr(mClock0[i][j]);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnP1toP0Click(TObject *Sender)
{
	//before SEND -> increment the sender
	mClock1.Update(1);

	//receive msg
	sbMsgReceived->Panels->Items[0]->Text ="P0: Message received from P1";

	//process msg MC
	mClock0.Update(mClock1);

	//show new MC
	for(unsigned int i = 0; i < mClock0.Size(); i++)
	{
		for(unsigned int j = 0; j < mClock0[i].Size(); j++)
		{
			sgMatrix0->Cells[j][i] = IntToStr(mClock0[i][j]);
		}
	}

	//show new sender's MC
	for(unsigned int i = 0; i < mClock1.Size(); i++)
	{
		for(unsigned int j = 0; j < mClock1[i].Size(); j++)
		{
			sgMatrix1->Cells[j][i] = IntToStr(mClock1[i][j]);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnP1toP2Click(TObject *Sender)
{
	//before SEND -> increment the sender
	mClock1.Update(1);

	//receive msg
	sbMsgReceived->Panels->Items[2]->Text ="P2: Message received from P1";

	//receiver processes the msg's MC
	mClock2.Update(mClock1);

	//show receiver's new MC
	for(unsigned int i = 0; i < mClock2.Size(); i++)
	{
		for(unsigned int j = 0; j < mClock2[i].Size(); j++)
		{
			sgMatrix2->Cells[j][i] = IntToStr(mClock2[i][j]);
		}
	}

	//show new sender's MC
	for(unsigned int i = 0; i < mClock1.Size(); i++)
	{
		for(unsigned int j = 0; j < mClock1[i].Size(); j++)
		{
			sgMatrix1->Cells[j][i] = IntToStr(mClock1[i][j]);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnP2toP0Click(TObject *Sender)
{
	//before SEND -> increment the sender
	mClock2.Update(2);

	//receive msg
	sbMsgReceived->Panels->Items[0]->Text ="P0: Message received from P2";

	//receiver processes the msg's MC
	mClock0.Update(mClock2);

	//show receiver's new MC
	for(unsigned int i = 0; i < mClock0.Size(); i++)
	{
		for(unsigned int j = 0; j < mClock0[i].Size(); j++)
		{
			sgMatrix0->Cells[j][i] = IntToStr(mClock0[i][j]);
		}
	}

	//show new sender's MC
	for(unsigned int i = 0; i < mClock2.Size(); i++)
	{
		for(unsigned int j = 0; j < mClock2[i].Size(); j++)
		{
			sgMatrix2->Cells[j][i] = IntToStr(mClock2[i][j]);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnP2toP1Click(TObject *Sender)
{
	//before SEND -> increment the sender
	mClock2.Update(2);

	//receive msg
	sbMsgReceived->Panels->Items[1]->Text ="P1: Message received from P2";

	//receiver processes the msg's MC
	mClock1.Update(mClock2);

	//show receiver's new MC
	for(unsigned int i = 0; i < mClock1.Size(); i++)
	{
		for(unsigned int j = 0; j < mClock1[i].Size(); j++)
		{
			sgMatrix1->Cells[j][i] = IntToStr(mClock1[i][j]);
		}
	}

	//show new sender's MC
	for(unsigned int i = 0; i < mClock2.Size(); i++)
	{
		for(unsigned int j = 0; j < mClock2[i].Size(); j++)
		{
			sgMatrix2->Cells[j][i] = IntToStr(mClock2[i][j]);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MC0andMC1Click(TObject *Sender)
{
	if(mClock0 == mClock1)
	{
		result0->Caption = "MC0 = MC1";
		resultTxt0->Caption = "MC0 и MC1 са едновременни";
	}
	else if(mClock0 < mClock1)
	{
		result0->Caption = "MC0 < MC1";
		resultTxt0->Caption = "MC0 предшества MC1";
	}
	else if(mClock1 < mClock0)
	{
		result0->Caption = "MC0 > MC1";
		resultTxt0->Caption = "MC0 следва MC1";
	}
	else
	{
		result0->Caption = "MC0 || MC1";
		resultTxt0->Caption = "MC0 и MC1 са конкурентни";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MC0andMC2Click(TObject *Sender)
{
	if(mClock0 == mClock2)
	{
		result0->Caption = "MC0 = MC2";
		resultTxt0->Caption = "MC0 и MC2 са едновременни";
	}
	else if(mClock0 < mClock2)
	{
		result0->Caption = "MC0 < MC2";
		resultTxt0->Caption = "MC0 предшества MC2";
	}
	else if(mClock2 < mClock0)
	{
		result0->Caption = "MC0 > MC2";
		resultTxt0->Caption = "MC0 следва MC2";
	}
	else
	{
		result0->Caption = "MC0 || MC2";
		resultTxt0->Caption = "MC0 и MC2 са конкурентни";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MC1andMC0Click(TObject *Sender)
{
	if(mClock1 == mClock0)
	{
		result1->Caption = "MC1 = MC0";
		resultTxt1->Caption = "MC1 и MC0 са едновременни";
	}
	else if(mClock1 < mClock0)
	{
		result1->Caption = "MC1 < MC0";
		resultTxt1->Caption = "MC1 предшества MC0";
	}
	else if(mClock0 < mClock1)
	{
		result1->Caption = "MC1 > MC0";
		resultTxt1->Caption = "MC1 следва MC0";
	}
	else
	{
		result1->Caption = "MC1 || MC0";
		resultTxt1->Caption = "MC1 и MC0 са конкурентни";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MC1andMC2Click(TObject *Sender)
{
	if(mClock1 == mClock2)
	{
		result1->Caption = "MC1 = MC2";
		resultTxt1->Caption = "MC1 и MC2 са едновременни";
	}
	else if(mClock1 < mClock2)
	{
		result1->Caption = "MC1 < MC2";
		resultTxt1->Caption = "MC1 предшества MC2";
	}
	else if(mClock2 < mClock1)
	{
		result1->Caption = "MC1 > MC2";
		resultTxt1->Caption = "MC1 следва MC2";
	}
	else
	{
		result1->Caption = "MC1 || MC2";
		resultTxt1->Caption = "MC1 и MC2 са конкурентни";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MC2andMC0Click(TObject *Sender)
{
	if(mClock2 == mClock0)
	{
		result2->Caption = "MC2 = MC0";
		resultTxt2->Caption = "MC2 и MC0 са едновременни";
	}
	else if(mClock2 < mClock0)
	{
		result2->Caption = "MC2 < MC0";
		resultTxt2->Caption = "MC2 предшества MC0";
	}
	else if(mClock0 < mClock2)
	{
		result2->Caption = "MC2 > MC0";
		resultTxt2->Caption = "MC2 следва MC0";
	}
	else
	{
		result2->Caption = "MC2 || MC0";
		resultTxt2->Caption = "MC2 и MC0 са конкурентни";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MC2andMC1Click(TObject *Sender)
{
	if(mClock2 == mClock1)
	{
		result2->Caption = "MC2 = MC1";
		resultTxt2->Caption = "MC2 и MC1 са едновременни";
	}
	else if(mClock2 < mClock1)
	{
		result2->Caption = "MC2 < MC1";
		resultTxt2->Caption = "MC2 предшества MC1";
	}
	else if(mClock1 < mClock2)
	{
		result2->Caption = "MC2 > MC1";
		resultTxt2->Caption = "MC2 следва MC1";
	}
	else
	{
		result2->Caption = "MC2 || MC1";
		resultTxt2->Caption = "MC2 и MC1 са конкурентни";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnReset0Click(TObject *Sender)
{
	int ExitCode = Application->MessageBox(L"Are you sure you want to RESET the Matrix clock MC0 ?", L"Warning", MB_YESNO | MB_ICONQUESTION);
	if(ExitCode == IDYES)
	{
		mClock0.Init();
		for(unsigned int i = 0; i < mClock0.Size(); i++)
		{
			for(unsigned int j = 0; j < mClock0[i].Size(); j++)
			{
				sgMatrix0->Cells[j][i] = IntToStr(mClock0[i][j]);
			}
		}

		result0->Caption = "";
		resultTxt0->Caption = "";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnReset1Click(TObject *Sender)
{
	int ExitCode = Application->MessageBox(L"Are you sure you want to RESET the Matrix clock MC1 ?", L"Warning", MB_YESNO | MB_ICONQUESTION);
	if(ExitCode == IDYES)
	{
		mClock1.Init();
		for(unsigned int i = 0; i < mClock1.Size(); i++)
		{
			for(unsigned int j = 0; j < mClock1[i].Size(); j++)
			{
				sgMatrix1->Cells[j][i] = IntToStr(mClock1[i][j]);
			}
		}

		result1->Caption = "";
		resultTxt1->Caption = "";
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnReset2Click(TObject *Sender)
{
	int ExitCode = Application->MessageBox(L"Are you sure you want to RESET the Matrix clock MC2 ?", L"Warning", MB_YESNO | MB_ICONQUESTION);
	if(ExitCode == IDYES)
	{
		mClock2.Init();
		for(unsigned int i = 0; i < mClock2.Size(); i++)
		{
			for(unsigned int j = 0; j < mClock2[i].Size(); j++)
			{
				sgMatrix2->Cells[j][i] = IntToStr(mClock2[i][j]);
			}
		}

		result2->Caption = "";
		resultTxt2->Caption = "";
	}
}
//---------------------------------------------------------------------------

