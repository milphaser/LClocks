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
	   for(unsigned int j = 0; j < mClock0[i].Size(); j++)
	   {
			sgMatrix0->Cells[j][i] = IntToStr(mClock0[i][j]);
			sgMatrix1->Cells[j][i] = IntToStr(mClock1[i][j]);
			sgMatrix2->Cells[j][i] = IntToStr(mClock2[i][j]);
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
	   for(unsigned int j = 0; j < mClock1[i].Size(); j++)
			sgMatrix1->Cells[j][i] = IntToStr(mClock1[i][j]);

	//show new sender's MC
	for(unsigned int i = 0; i < mClock0.Size(); i++)
	   for(unsigned int j = 0; j < mClock0[i].Size(); j++)
			sgMatrix0->Cells[j][i] = IntToStr(mClock0[i][j]);
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
	   for(unsigned int j = 0; j < mClock2[i].Size(); j++)
			sgMatrix2->Cells[j][i] = IntToStr(mClock2[i][j]);

	//show new sender's MC
	for(unsigned int i = 0; i < mClock0.Size(); i++)
	   for(unsigned int j = 0; j < mClock0[i].Size(); j++)
			sgMatrix0->Cells[j][i] = IntToStr(mClock0[i][j]);
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
		for(unsigned int j = 0; j < mClock0[i].Size(); j++)
			sgMatrix0->Cells[j][i] = IntToStr(mClock0[i][j]);

	//show new sender's MC
	for(unsigned int i = 0; i < mClock1.Size(); i++)
	   for(unsigned int j = 0; j < mClock1[i].Size(); j++)
			sgMatrix1->Cells[j][i] = IntToStr(mClock1[i][j]);
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
	   for(unsigned int j = 0; j < mClock2[i].Size(); j++)
			sgMatrix2->Cells[j][i] = IntToStr(mClock2[i][j]);

	//show new sender's MC
	for(unsigned int i = 0; i < mClock1.Size(); i++)
	   for(unsigned int j = 0; j < mClock1[i].Size(); j++)
			sgMatrix1->Cells[j][i] = IntToStr(mClock1[i][j]);
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
	   for(unsigned int j = 0; j < mClock0[i].Size(); j++)
			sgMatrix0->Cells[j][i] = IntToStr(mClock0[i][j]);

	//show new sender's MC
	for(unsigned int i = 0; i < mClock2.Size(); i++)
	   for(unsigned int j = 0; j < mClock2[i].Size(); j++)
			sgMatrix2->Cells[j][i] = IntToStr(mClock2[i][j]);
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
	   for(unsigned int j = 0; j < mClock1[i].Size(); j++)
			sgMatrix1->Cells[j][i] = IntToStr(mClock1[i][j]);

	//show new sender's MC
	for(unsigned int i = 0; i < mClock2.Size(); i++)
	   for(unsigned int j = 0; j < mClock2[i].Size(); j++)
			sgMatrix2->Cells[j][i] = IntToStr(mClock2[i][j]);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnResetClick(TObject *Sender)
{  //Reset  all matrices
	int ExitCode = Application->MessageBox(L"Are you sure you want to RESET all matrix clocks?", L"Warning", MB_YESNO | MB_ICONQUESTION);
	if(ExitCode == IDYES)
		ResetMClocks();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ResetMClocks()
{
	for(unsigned int i = 0; i < mClock0.Size(); i++)
		for(unsigned int j = 0; j < mClock0[i].Size(); j++)
		{
			mClock0[i][j] =0;
			sgMatrix0->Cells[j][i] = IntToStr(mClock0[i][j]);

			mClock1[i][j] =0;
			sgMatrix1->Cells[j][i] = IntToStr(mClock1[i][j]);

			mClock2[i][j] =0;
			sgMatrix2->Cells[j][i] = IntToStr(mClock2[i][j]);
		}

	for(int i = 0; i < 3; i++)
		sbMsgReceived->Panels->Items[i]->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::rgImageExamplesClick(TObject *Sender)
{
	if(rgImageExamples->ItemIndex != intItemSelected)
	{
		int ExitCode = Application->MessageBox(L"Are you sure you want to change the example?", L"Warning", MB_YESNO | MB_ICONQUESTION);
		if(ExitCode == IDYES)
		{
			switch(rgImageExamples->ItemIndex)
			{
				case 0 :
					imgExample->Picture->LoadFromFile("Example1.JPG");
					intItemSelected = rgImageExamples->ItemIndex;
					break;
				case 1 :
					imgExample->Picture->LoadFromFile("Example2.JPG");
					intItemSelected = rgImageExamples->ItemIndex;
					break;
				case 2 :
					imgExample->Picture->LoadFromFile("Example3.JPG");
					intItemSelected = rgImageExamples->ItemIndex;
					break;
				case 3 :
					imgExample->Picture->LoadFromFile("Example4.JPG");
					intItemSelected = rgImageExamples->ItemIndex;
					break;
			}

			ResetMClocks();
		}
		else
			rgImageExamples->ItemIndex = intItemSelected;
	}
}
//---------------------------------------------------------------------------

