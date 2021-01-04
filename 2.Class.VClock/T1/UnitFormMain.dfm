object formMain: TformMain
  Left = 0
  Top = 0
  Caption = #1042#1077#1082#1090#1086#1088#1085#1080' '#1095#1072#1089#1086#1074#1085#1080#1094#1080' - '#1090#1077#1089#1090#1074#1072#1085#1077' '#1085#1072' '#1089#1088#1072#1074#1085#1077#1085#1080#1077#1090#1086
  ClientHeight = 331
  ClientWidth = 485
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 485
    Height = 74
    Align = alTop
    Alignment = taCenter
    Ctl3D = False
    Lines.Strings = (
      #1062#1077#1083' '#1085#1072' '#1087#1088#1080#1084#1077#1088#1072': '
      #1044#1072' '#1089#1077' '#1087#1086#1082#1072#1078#1077' '#1088#1072#1079#1083#1080#1082#1072#1090#1072' '#1084#1077#1078#1076#1091' '#1086#1087#1077#1088#1072#1094#1080#1103' '#1089#1088#1072#1074#1085#1077#1085#1080#1077' '
      #1085#1072' '#1074#1077#1082#1090#1086#1088#1085#1080' '#1095#1072#1089#1086#1074#1085#1080#1094#1080' '
      #1080' '#1086#1073#1080#1082#1085#1086#1074#1077#1085#1086#1090#1086' '#1083#1077#1082#1089#1080#1082#1086#1075#1088#1072#1092#1080#1095#1077#1089#1082#1086' '#1089#1088#1072#1074#1085#1077#1085#1080#1077' '#1085#1072' '#1074#1077#1082#1090#1086#1088#1080)
    ParentCtl3D = False
    ReadOnly = True
    TabOrder = 0
  end
  object gboxVb: TGroupBox
    Left = 0
    Top = 161
    Width = 485
    Height = 88
    Align = alTop
    Caption = ' Vb '
    TabOrder = 1
    object leditVb0: TLabeledEdit
      Left = 20
      Top = 39
      Width = 149
      Height = 24
      EditLabel.Width = 32
      EditLabel.Height = 16
      EditLabel.Caption = 'Vb[0]'
      MaxLength = 6
      TabOrder = 0
      OnChange = leditVa0Change
    end
    object leditVb1: TLabeledEdit
      Left = 167
      Top = 39
      Width = 149
      Height = 24
      EditLabel.Width = 32
      EditLabel.Height = 16
      EditLabel.Caption = 'Vb[1]'
      MaxLength = 6
      TabOrder = 1
      OnChange = leditVa0Change
    end
    object leditVb2: TLabeledEdit
      Left = 315
      Top = 39
      Width = 149
      Height = 24
      EditLabel.Width = 32
      EditLabel.Height = 16
      EditLabel.Caption = 'Vb[2]'
      MaxLength = 6
      TabOrder = 2
      OnChange = leditVa0Change
    end
    object buttonIncrementB0: TButton
      Left = 21
      Top = 65
      Width = 146
      Height = 17
      Caption = 'increment'
      TabOrder = 3
      OnClick = buttonIncrementA0Click
    end
    object buttonIncrementB1: TButton
      Left = 170
      Top = 65
      Width = 146
      Height = 17
      Caption = 'increment'
      TabOrder = 4
      OnClick = buttonIncrementA0Click
    end
    object buttonIncrementB2: TButton
      Left = 318
      Top = 65
      Width = 146
      Height = 17
      Caption = 'increment'
      TabOrder = 5
      OnClick = buttonIncrementA0Click
    end
  end
  object gboxVa: TGroupBox
    Left = 0
    Top = 74
    Width = 485
    Height = 87
    Align = alTop
    Caption = ' Va '
    TabOrder = 2
    object leditVa0: TLabeledEdit
      Left = 20
      Top = 39
      Width = 149
      Height = 24
      EditLabel.Width = 32
      EditLabel.Height = 16
      EditLabel.Caption = 'Va[0]'
      MaxLength = 6
      TabOrder = 0
      OnChange = leditVa0Change
    end
    object leditVa1: TLabeledEdit
      Left = 167
      Top = 39
      Width = 149
      Height = 24
      EditLabel.Width = 32
      EditLabel.Height = 16
      EditLabel.Caption = 'Va[1]'
      MaxLength = 6
      TabOrder = 1
      OnChange = leditVa0Change
    end
    object leditVa2: TLabeledEdit
      Left = 315
      Top = 39
      Width = 149
      Height = 24
      EditLabel.Width = 32
      EditLabel.Height = 16
      EditLabel.Caption = 'Va[2]'
      MaxLength = 6
      TabOrder = 2
      OnChange = leditVa0Change
    end
    object buttonIncrementA0: TButton
      Left = 21
      Top = 65
      Width = 146
      Height = 17
      Caption = 'increment'
      TabOrder = 3
      OnClick = buttonIncrementA0Click
    end
    object buttonIncrementA1: TButton
      Left = 170
      Top = 65
      Width = 146
      Height = 17
      Caption = 'increment'
      TabOrder = 4
      OnClick = buttonIncrementA0Click
    end
    object buttonIncrementA2: TButton
      Left = 318
      Top = 65
      Width = 146
      Height = 17
      Caption = 'increment'
      TabOrder = 5
      OnClick = buttonIncrementA0Click
    end
  end
  object gbHP: TGroupBox
    Left = 0
    Top = 249
    Width = 485
    Height = 82
    Align = alTop
    Caption = ' HB Relation ('#1056#1077#1083#1072#1094#1080#1103' "'#1087#1088#1077#1076#1096#1077#1089#1090#1074#1072#1085#1077'/happened before") '
    TabOrder = 3
    object labelHB: TLabel
      Left = 65
      Top = 28
      Width = 353
      Height = 25
      Alignment = taCenter
      AutoSize = False
      Caption = 'UNORDERED EVENTS'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -20
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object labelLex: TLabel
      Left = 73
      Top = 59
      Width = 326
      Height = 21
      Alignment = taCenter
      AutoSize = False
      Caption = #1083#1077#1082#1089#1080#1082#1086#1075#1088#1072#1092#1080#1095#1077#1089#1082#1080': '
    end
  end
end
