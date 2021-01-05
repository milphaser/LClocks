//---------------------------------------------------------------------------

#include <vcl.h>
#include <IniFiles.hpp>
#pragma hdrstop

#include "UnitFormMain.h"
#include "UnitFormChannels.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TformMain *formMain;
//---------------------------------------------------------------------------
__fastcall TformMain::TformMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformMain::FormShow(TObject *Sender)
{
	// On Init >>>
	meType = ME_RELEASED;
	panelReleased->Color = clLime;
	panelWanted->Color = clBtnFace;
	panelHeld->Color = clBtnFace;

	buttonRequest->Enabled = true;
	buttonRelease->Enabled = false;

	stringIniFileName = Application->ExeName;
	stringIniFileName = stringIniFileName.SubString(1, stringIniFileName.Length() - 3) + "ini";
	TIniFile* iniFile = new TIniFile(stringIniFileName);

	formChannels->ssInChannel->Port = iniFile->ReadInteger(L"InChannels", L"InPort", 0);
	stringPId = iniFile->ReadString("InChannels", "IPAddress", "");

	listPIds = new list<String>;
	queueHeld = new queue<TCustomWinSocket*>;
	lcClock = new LClock<int, String>(stringPId);
	lcT1 = new LClock<int, String>(stringPId);

	formChannels->csOutChannel1->Port = iniFile->ReadInteger(L"OutChannels", L"OutPort", 0);
	formChannels->csOutChannel1->Address = iniFile->ReadString(L"OutChannels", L"IPAddress1", "");
	listPIds->push_front(formChannels->csOutChannel1->Address);
	clbOutChannels->Items->Add(formChannels->csOutChannel1->Address);

	formChannels->csOutChannel2->Port = iniFile->ReadInteger(L"OutChannels", L"OutPort", 0);
	formChannels->csOutChannel2->Address = iniFile->ReadString(L"OutChannels", L"IPAddress2", "");
	listPIds->push_front(formChannels->csOutChannel2->Address);
	clbOutChannels->Items->Add(formChannels->csOutChannel2->Address);

	formChannels->csOutChannel3->Port = iniFile->ReadInteger(L"OutChannels", L"OutPort", 0);
	formChannels->csOutChannel3->Address = iniFile->ReadString(L"OutChannels", L"IPAddress3", "");
	listPIds->push_front(formChannels->csOutChannel3->Address);
	clbOutChannels->Items->Add(formChannels->csOutChannel3->Address);

	formChannels->csOutChannel4->Port = iniFile->ReadInteger(L"OutChannels", L"OutPort", 0);
	formChannels->csOutChannel4->Address = iniFile->ReadString(L"OutChannels", L"IPAddress4", "");
	listPIds->push_front(formChannels->csOutChannel4->Address);
	clbOutChannels->Items->Add(formChannels->csOutChannel4->Address);

	formChannels->csOutChannel5->Port = iniFile->ReadInteger(L"OutChannels", L"OutPort", 0);
	formChannels->csOutChannel5->Address = iniFile->ReadString(L"OutChannels", L"IPAddress5", "");
	listPIds->push_front(formChannels->csOutChannel5->Address);
	clbOutChannels->Items->Add(formChannels->csOutChannel5->Address);

	formChannels->csOutChannel6->Port = iniFile->ReadInteger(L"OutChannels", L"OutPort", 0);
	formChannels->csOutChannel6->Address = iniFile->ReadString(L"OutChannels", L"IPAddress6", "");
	listPIds->push_front(formChannels->csOutChannel6->Address);
	clbOutChannels->Items->Add(formChannels->csOutChannel6->Address);

	formChannels->csOutChannel7->Port = iniFile->ReadInteger(L"OutChannels", L"OutPort", 0);
	formChannels->csOutChannel7->Address = iniFile->ReadString(L"OutChannels", L"IPAddress7", "");
	listPIds->push_front(formChannels->csOutChannel7->Address);
	clbOutChannels->Items->Add(formChannels->csOutChannel7->Address);

	formChannels->csOutChannel8->Port = iniFile->ReadInteger(L"OutChannels", L"OutPort", 0);
	formChannels->csOutChannel8->Address = iniFile->ReadString(L"OutChannels", L"IPAddress8", "");
	listPIds->push_front(formChannels->csOutChannel8->Address);
	clbOutChannels->Items->Add(formChannels->csOutChannel8->Address);

	delete iniFile;

	formChannels->ssInChannel->Active = true;
}
//---------------------------------------------------------------------------
void __fastcall TformMain::FormClose(TObject *Sender, TCloseAction &Action)
{
	formChannels->ssInChannel->Active = false;

	delete listPIds;
	delete queueHeld;
	delete lcClock;
	delete lcT1;
}
//---------------------------------------------------------------------------
void __fastcall TformMain::buttonOpenClick(TObject *Sender)
{
	if(formChannels->ssInChannel->Active == false)
		formChannels->ssInChannel->Active = true;

	if(formChannels->csOutChannel1->Address != "")
		if(formChannels->csOutChannel1->Active == false)
			formChannels->csOutChannel1->Active = true;

	if(formChannels->csOutChannel2->Address != "")
		if(formChannels->csOutChannel2->Active == false)
			formChannels->csOutChannel2->Active = true;

	if(formChannels->csOutChannel3->Address != "")
		if(formChannels->csOutChannel3->Active == false)
			formChannels->csOutChannel3->Active = true;

	if(formChannels->csOutChannel4->Address != "")
		if(formChannels->csOutChannel4->Active == false)
			formChannels->csOutChannel4->Active = true;

	if(formChannels->csOutChannel5->Address != "")
		if(formChannels->csOutChannel5->Active == false)
			formChannels->csOutChannel5->Active = true;

	if(formChannels->csOutChannel6->Address != "")
		if(formChannels->csOutChannel6->Active == false)
			formChannels->csOutChannel6->Active = true;

	if(formChannels->csOutChannel7->Address != "")
		if(formChannels->csOutChannel7->Active == false)
			formChannels->csOutChannel7->Active = true;

	if(formChannels->csOutChannel8->Address != "")
		if(formChannels->csOutChannel8->Active == false)
			formChannels->csOutChannel8->Active = true;
}
//---------------------------------------------------------------------------
void __fastcall TformMain::buttonCloseClick(TObject *Sender)
{
	formChannels->csOutChannel1->Active = false;
	formChannels->csOutChannel2->Active = false;
	formChannels->csOutChannel3->Active = false;
	formChannels->csOutChannel4->Active = false;
	formChannels->csOutChannel5->Active = false;
	formChannels->csOutChannel6->Active = false;
	formChannels->csOutChannel7->Active = false;
	formChannels->csOutChannel8->Active = false;
}
//---------------------------------------------------------------------------
void __fastcall TformMain::leditDelayChange(TObject *Sender)
{
	try
	{
		int delay = leditDelay->Text.ToInt();
		intDelay = delay;
	}
	catch(const EConvertError&)
	{
		MessageDlg("Грешка при конвертиране на <Delay>",
				   mtError, TMsgDlgButtons() << mbOK, 0);
	}
}
//---------------------------------------------------------------------------
TClientSocket* TformMain::GetOutChannel(int num)
{
	switch(num)
	{
		case 1:
			return formChannels->csOutChannel1;
		case 2:
			return formChannels->csOutChannel2;
		case 3:
			return formChannels->csOutChannel3;
		case 4:
			return formChannels->csOutChannel4;
		case 5:
			return formChannels->csOutChannel5;
		case 6:
			return formChannels->csOutChannel6;
		case 7:
			return formChannels->csOutChannel7;
		case 8:
			return formChannels->csOutChannel8;
		default:
			return nullptr;
	}
}
//---------------------------------------------------------------------------
void __fastcall TformMain::pmiClearClick(TObject *Sender)
{
	int ExitCode = Application->MessageBox(L"Сигурни ли сте?", L"Протоколът ще бъде изтрит",
					MB_YESNO|MB_ICONWARNING);
	if(ExitCode == IDNO)
		return;

	memoProtocol->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TformMain::pmiSaveClick(TObject *Sender)
{
	if(savedialogProtocol->Execute())
		memoProtocol->Lines->SaveToFile(savedialogProtocol->FileName);
}
//---------------------------------------------------------------------------
void __fastcall TformMain::AddToProtocol(String source)
{
	String str = "[" + Date().DateString() + " " + Time().TimeString() + "] " +
				 source;
	memoProtocol->Lines->Add(str);
}
//---------------------------------------------------------------------------
void __fastcall TformMain::buttonRequestClick(TObject *Sender)
{
	// On Enter >>>
	// TO BE CODDED
	if(meType != ME_RELEASED)
		return;

	formChannels->intRequestCount = 0;
	formChannels->intReplyCount = 0;

	// LC1
	lcClock->Update();
	leditLClock->Text = lcClock->Get();
	*lcT1 = *lcClock;

	String stringMsgOut = MSG_REQUEST + " " + stringPId + " " + lcClock->Get();

	for(int i = 0; i < clbOutChannels->Count; i++)
	{
		if(clbOutChannels->Checked[i])
		{
			TClientSocket* csPtr = GetOutChannel(i + 1);
			if(csPtr != nullptr)
			{
				csPtr->Socket->SendText(stringMsgOut);
				AddToProtocol(stringMsgOut + ":" + csPtr->Socket->RemoteAddress);
				formChannels->intRequestCount++;
			}
			else
				AddToProtocol(stringMsgOut + ":" + "nullptr");
		}
	}

	if(formChannels->intRequestCount > 0)
	{
		if(cbRandom->Checked)
			Sleep(random(intDelay));
		else
			Sleep(intDelay);

		meType = ME_WANTED;
		panelReleased->Color = clBtnFace;
		panelWanted->Color = clYellow;
		panelHeld->Color = clBtnFace;

		buttonRequest->Enabled = false;
		buttonRelease->Enabled = true;
	}
	else
		AddToProtocol("НЯМА ОТВОРЕНИ КАНАЛИ");
}
//---------------------------------------------------------------------------
void __fastcall TformMain::buttonReleaseClick(TObject *Sender)
{
	// On Exit >>>
	// TO BE CODDED
	if(meType != ME_HELD)
		return;

	meType = ME_RELEASED;
	panelReleased->Color = clLime;
	panelWanted->Color = clBtnFace;
	panelHeld->Color = clBtnFace;

	buttonRequest->Enabled = true;
	buttonRelease->Enabled = false;

	String stringMsgOut = MSG_REPLY + " " + stringPId;

	while(!queueHeld->empty())
	{
		TCustomWinSocket* cwsPtr = queueHeld->front();
		queueHeld->pop();

		cwsPtr->SendText(stringMsgOut);
		AddToProtocol(stringMsgOut + ":" + cwsPtr->RemoteAddress);
	}
}
//---------------------------------------------------------------------------

