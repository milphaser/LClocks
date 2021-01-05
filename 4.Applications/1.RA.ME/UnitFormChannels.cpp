//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitFormChannels.h"
#include "UnitFormMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TformChannels *formChannels;
//---------------------------------------------------------------------------
__fastcall TformChannels::TformChannels(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TformChannels::ssInChannelClientConnect(TObject *Sender, TCustomWinSocket *Socket)
{
	formMain->AddToProtocol(Socket->RemoteHost + " [" + Socket->RemoteAddress + "] InChannel CONNECTED");
}
//---------------------------------------------------------------------------
void __fastcall TformChannels::ssInChannelClientDisconnect(TObject *Sender, TCustomWinSocket *Socket)
{
	formMain->AddToProtocol(Socket->RemoteHost + " [" + Socket->RemoteAddress + "] InChannel DISCONNECTED");
}
//---------------------------------------------------------------------------
void __fastcall TformChannels::ssInChannelClientError(TObject *Sender, TCustomWinSocket *Socket,
		  TErrorEvent ErrorEvent, int &ErrorCode)
{
	formMain->AddToProtocol(Socket->RemoteHost + " [" + Socket->RemoteAddress + "] InChannel ERROR");

	// Обработка на грешката

	ErrorCode = 0;
}
//---------------------------------------------------------------------------
void __fastcall TformChannels::csOutChannel1Connect(TObject *Sender, TCustomWinSocket *Socket)
{
	formMain->AddToProtocol(Socket->RemoteHost + " [" + Socket->RemoteAddress + "] OutChannel CONNECTED");

	if(Sender == csOutChannel1)
		formMain->clbOutChannels->Checked[0] = true;
	else if(Sender == csOutChannel2)
		formMain->clbOutChannels->Checked[1] = true;
	else if(Sender == csOutChannel3)
		formMain->clbOutChannels->Checked[2] = true;
	else if(Sender == csOutChannel4)
		formMain->clbOutChannels->Checked[3] = true;
	else if(Sender == csOutChannel5)
		formMain->clbOutChannels->Checked[4] = true;
	else if(Sender == csOutChannel6)
		formMain->clbOutChannels->Checked[5] = true;
	else if(Sender == csOutChannel7)
		formMain->clbOutChannels->Checked[6] = true;
	else if(Sender == csOutChannel8)
		formMain->clbOutChannels->Checked[7] = true;
}
//---------------------------------------------------------------------------
void __fastcall TformChannels::csOutChannel1Disconnect(TObject *Sender, TCustomWinSocket *Socket)
{
	formMain->AddToProtocol(Socket->RemoteHost + " [" + Socket->RemoteAddress + "] OutChannel DISCONNECTED");

	if(Sender == csOutChannel1)
		formMain->clbOutChannels->Checked[0] = false;
	else if(Sender == csOutChannel2)
		formMain->clbOutChannels->Checked[1] = false;
	else if(Sender == csOutChannel3)
		formMain->clbOutChannels->Checked[2] = false;
	else if(Sender == csOutChannel4)
		formMain->clbOutChannels->Checked[3] = false;
	else if(Sender == csOutChannel5)
		formMain->clbOutChannels->Checked[4] = false;
	else if(Sender == csOutChannel6)
		formMain->clbOutChannels->Checked[5] = false;
	else if(Sender == csOutChannel7)
		formMain->clbOutChannels->Checked[6] = false;
	else if(Sender == csOutChannel8)
		formMain->clbOutChannels->Checked[7] = false;
}
//---------------------------------------------------------------------------
void __fastcall TformChannels::csOutChannel1Error(TObject *Sender, TCustomWinSocket *Socket,
		  TErrorEvent ErrorEvent, int &ErrorCode)
{
	formMain->AddToProtocol(Socket->RemoteHost + " [" + Socket->RemoteAddress + "] OutChannel ERROR");

	if(Sender == csOutChannel1)
		formMain->clbOutChannels->Checked[0] = false;
	else if(Sender == csOutChannel2)
		formMain->clbOutChannels->Checked[1] = false;
	else if(Sender == csOutChannel3)
		formMain->clbOutChannels->Checked[2] = false;
	else if(Sender == csOutChannel4)
		formMain->clbOutChannels->Checked[3] = false;
	else if(Sender == csOutChannel5)
		formMain->clbOutChannels->Checked[4] = false;
	else if(Sender == csOutChannel6)
		formMain->clbOutChannels->Checked[5] = false;
	else if(Sender == csOutChannel7)
		formMain->clbOutChannels->Checked[6] = false;
	else if(Sender == csOutChannel8)
		formMain->clbOutChannels->Checked[7] = false;

	// Обработка на грешките

	ErrorCode = 0;
}
//---------------------------------------------------------------------------
void __fastcall TformChannels::csOutChannel1Read(TObject *Sender, TCustomWinSocket *Socket)
{
	// On Receipt of Reply >>>
	// TO BE CODDED
	String stringMsg = Socket->ReceiveText();
	formMain->AddToProtocol(Socket->RemoteAddress + ":" + stringMsg);

	if(stringMsg.Pos(MSG_REPLY) == 1)
	{
		intReplyCount++;
		if(intReplyCount == intRequestCount)
		{
			formMain->meType = formMain->ME_HELD;
			formMain->panelReleased->Color = clBtnFace;
			formMain->panelWanted->Color = clBtnFace;
			formMain->panelHeld->Color = clRed;

			formMain->buttonRequest->Enabled = false;
			formMain->buttonRelease->Enabled = true;

			// access()
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TformChannels::ssInChannelClientRead(TObject *Sender, TCustomWinSocket *Socket)
{
	String stringMsgIn = Socket->ReceiveText();     // Receive Message
	String stringMsg;

	for(int intInx = 1; intInx > 0; stringMsgIn = stringMsgIn.c_str() +
									MSG_LEADER.Length() + intInx - 1)
	{
		String stringBuf = stringMsgIn.c_str() + MSG_LEADER.Length();
		intInx = stringBuf.Pos(MSG_LEADER);

		if(intInx > 0)
			stringMsg = stringBuf.SubString(1, intInx - 1);
		else
			stringMsg = stringBuf;

		OnReceiptOfMsg(MSG_LEADER + stringMsg, Socket);
	}
}
//---------------------------------------------------------------------------
void __fastcall TformChannels::OnReceiptOfMsg(String stringMsg,
	TCustomWinSocket *Socket)
{
	Sleep(formMain->intDelay);

	// On Receipt of Request >>>
	// TO BE CODDED
	formMain->AddToProtocol(Socket->RemoteAddress + ":" + stringMsg);

	if(stringMsg.Pos(MSG_REQUEST) == 1)
	{
		stringMsg = stringMsg.c_str() + MSG_REQUEST.Length() + 1;
		int intInx = stringMsg.Pos(" ");
		String stringPId2 = stringMsg.SubString(1, intInx - 1);
		String stringT2 = stringMsg.c_str() + intInx;
		int intT2 = 0;

		try
		{
			intT2 = stringT2.ToInt();
		}
		catch(Exception& e)
		{
			intT2 = 0;
			formMain->AddToProtocol(e.Message);
		}

		// LC3
		formMain->lcClock->Update(intT2);
		formMain->leditLClock->Text = formMain->lcClock->Get();

		LClock<int, String> lcT2(intT2, stringPId2);

		if((formMain->meType == formMain->ME_HELD) ||
		  ((formMain->meType == formMain->ME_WANTED) && (*formMain->lcT1 < lcT2)))
		{
			formMain->queueHeld->push(Socket);
			formMain->AddToProtocol("QUEUE REQUEST " + Socket->RemoteAddress);
		}
		else
		{
			String stringMsgOut = MSG_REPLY + " " + formMain->GetPId();
			Socket->SendText(stringMsgOut);
			formMain->AddToProtocol(stringMsgOut + ":" + Socket->RemoteAddress);
		}
	}
}
//---------------------------------------------------------------------------

