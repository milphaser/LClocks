//---------------------------------------------------------------------------

#ifndef UnitFormChannelsH
#define UnitFormChannelsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Win.ScktComp.hpp>
//---------------------------------------------------------------------------
const String MSG_LEADER    = "|";
const String MSG_REQUEST   = MSG_LEADER + "REQUEST";
const String MSG_REPLY     = MSG_LEADER + "REPLY";
//---------------------------------------------------------------------------
class TformChannels : public TForm
{
__published:	// IDE-managed Components
	TServerSocket *ssInChannel;
	TClientSocket *csOutChannel8;
	TClientSocket *csOutChannel7;
	TClientSocket *csOutChannel6;
	TClientSocket *csOutChannel5;
	TClientSocket *csOutChannel4;
	TClientSocket *csOutChannel3;
	TClientSocket *csOutChannel2;
	TClientSocket *csOutChannel1;
	void __fastcall ssInChannelClientConnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall ssInChannelClientDisconnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall ssInChannelClientError(TObject *Sender, TCustomWinSocket *Socket,
          TErrorEvent ErrorEvent, int &ErrorCode);
	void __fastcall ssInChannelClientRead(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall csOutChannel1Connect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall csOutChannel1Disconnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall csOutChannel1Error(TObject *Sender, TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
	void __fastcall csOutChannel1Read(TObject *Sender, TCustomWinSocket *Socket);






private:	// User declarations
	void __fastcall OnReceiptOfMsg(String, TCustomWinSocket*);

public:		// User declarations
	__fastcall TformChannels(TComponent* Owner);

	int intRequestCount;
	int intReplyCount;
};
//---------------------------------------------------------------------------
extern PACKAGE TformChannels *formChannels;
//---------------------------------------------------------------------------
#endif
