object formMain: TformMain
  Left = 0
  Top = 0
  Caption = #1051#1086#1075#1080#1095#1077#1089#1082#1080' '#1095#1072#1089#1086#1074#1085#1080#1094#1080' - '#1090#1077#1089#1090#1086#1074#1086' '#1087#1088#1080#1083#1086#1078#1077#1085#1080#1077
  ClientHeight = 521
  ClientWidth = 859
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object memoProtocol: TMemo
    Left = 0
    Top = 311
    Width = 859
    Height = 210
    Align = alBottom
    ReadOnly = True
    TabOrder = 0
  end
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 859
    Height = 66
    Align = alTop
    Alignment = taCenter
    Ctl3D = False
    Lines.Strings = (
      ''
      #1062#1077#1083' '#1085#1072' '#1087#1088#1080#1084#1077#1088#1072': '#1058#1077#1089#1090#1074#1072#1085#1077' '#1085#1072' '#1082#1083#1072#1089#1072' LClock')
    ParentCtl3D = False
    ReadOnly = True
    TabOrder = 1
  end
  object gbMessageSent: TGroupBox
    Left = 0
    Top = 153
    Width = 428
    Height = 158
    Align = alLeft
    Caption = ' Message Sent '
    TabOrder = 2
    object Label3: TLabel
      Left = 418
      Top = 31
      Width = 7
      Height = 25
      Caption = ')'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label1: TLabel
      Left = 65
      Top = 32
      Width = 53
      Height = 25
      Caption = 'MSG('
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object leditPIdSent: TLabeledEdit
      Left = 118
      Top = 32
      Width = 149
      Height = 24
      EditLabel.Width = 48
      EditLabel.Height = 16
      EditLabel.Caption = 'PId Sent'
      ReadOnly = True
      TabOrder = 0
    end
    object leditLCSent: TLabeledEdit
      Left = 270
      Top = 32
      Width = 148
      Height = 24
      EditLabel.Width = 44
      EditLabel.Height = 16
      EditLabel.Caption = 'LC Sent'
      ReadOnly = True
      TabOrder = 1
    end
    object buttonSend: TButton
      Left = 118
      Top = 59
      Width = 300
      Height = 20
      Caption = 'send'
      TabOrder = 2
      OnClick = buttonSendClick
    end
  end
  object gbMessageReceived: TGroupBox
    Left = 431
    Top = 153
    Width = 428
    Height = 158
    Align = alRight
    Caption = ' MessageReceived '
    TabOrder = 3
    object Label2: TLabel
      Left = 65
      Top = 32
      Width = 53
      Height = 25
      Caption = 'MSG('
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 418
      Top = 31
      Width = 7
      Height = 25
      Caption = ')'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -20
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object leditPIdReceived: TLabeledEdit
      Left = 118
      Top = 32
      Width = 149
      Height = 24
      EditLabel.Width = 73
      EditLabel.Height = 16
      EditLabel.Caption = 'PId Received'
      TabOrder = 0
    end
    object leditLCReceived: TLabeledEdit
      Left = 270
      Top = 32
      Width = 148
      Height = 24
      EditLabel.Width = 69
      EditLabel.Height = 16
      EditLabel.Caption = 'LC Received'
      TabOrder = 1
    end
    object buttonReceive: TButton
      Left = 118
      Top = 59
      Width = 300
      Height = 20
      Caption = 'receive'
      TabOrder = 2
      OnClick = buttonReceiveClick
    end
  end
  object gbInternalEvent: TGroupBox
    Left = 0
    Top = 66
    Width = 859
    Height = 87
    Align = alTop
    Caption = ' Internal Event '
    TabOrder = 4
    object labelIsLessThan: TLabel
      Left = 668
      Top = 37
      Width = 83
      Height = 16
      Caption = 'Is Less Than'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsItalic]
      ParentFont = False
      Visible = False
    end
    object leditPId: TLabeledEdit
      Left = 276
      Top = 32
      Width = 149
      Height = 24
      EditLabel.Width = 18
      EditLabel.Height = 16
      EditLabel.Caption = 'PId'
      ReadOnly = True
      TabOrder = 0
    end
    object leditLC: TLabeledEdit
      Left = 427
      Top = 32
      Width = 149
      Height = 24
      EditLabel.Width = 14
      EditLabel.Height = 16
      EditLabel.Caption = 'LC'
      ReadOnly = True
      TabOrder = 1
    end
    object buttonInternalEvent: TButton
      Left = 274
      Top = 59
      Width = 301
      Height = 20
      Caption = 'internal event'
      TabOrder = 2
      OnClick = buttonInternalEventClick
    end
  end
end
