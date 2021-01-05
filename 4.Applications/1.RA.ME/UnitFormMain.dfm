object formMain: TformMain
  Left = 0
  Top = 0
  Caption = 'R&A Algorithm'
  ClientHeight = 494
  ClientWidth = 735
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
  object gbProtocol: TGroupBox
    Left = 0
    Top = 247
    Width = 735
    Height = 227
    Align = alBottom
    Caption = ' Protocol '
    TabOrder = 0
    object memoProtocol: TMemo
      Left = 2
      Top = 18
      Width = 731
      Height = 207
      Align = alClient
      PopupMenu = popupProtocol
      TabOrder = 0
    end
  end
  object sbarStatus: TStatusBar
    Left = 0
    Top = 474
    Width = 735
    Height = 20
    Panels = <>
  end
  object panelControl: TPanel
    Left = 0
    Top = 0
    Width = 735
    Height = 247
    Align = alTop
    TabOrder = 2
    object gbOutChannels: TGroupBox
      Left = 503
      Top = 15
      Width = 208
      Height = 216
      Caption = 'Out Channels '
      TabOrder = 0
      object clbOutChannels: TCheckListBox
        Left = 2
        Top = 71
        Width = 204
        Height = 143
        Align = alBottom
        TabOrder = 0
      end
      object buttonOpen: TButton
        Left = 12
        Top = 28
        Width = 93
        Height = 31
        Caption = 'OPEN'
        TabOrder = 1
        OnClick = buttonOpenClick
      end
      object buttonClose: TButton
        Left = 104
        Top = 28
        Width = 93
        Height = 31
        Caption = 'CLOSE'
        TabOrder = 2
        OnClick = buttonCloseClick
      end
    end
    object leditLClock: TLabeledEdit
      Left = 69
      Top = 44
      Width = 90
      Height = 24
      EditLabel.Width = 73
      EditLabel.Height = 16
      EditLabel.Caption = 'Logical Clock'
      ReadOnly = True
      TabOrder = 1
      Text = '0'
    end
    object buttonRequest: TButton
      Left = 190
      Top = 41
      Width = 92
      Height = 30
      Caption = 'REQUEST'
      TabOrder = 2
      OnClick = buttonRequestClick
    end
    object buttonRelease: TButton
      Left = 281
      Top = 41
      Width = 92
      Height = 30
      Caption = 'RELEASE'
      TabOrder = 3
      OnClick = buttonReleaseClick
    end
    object gbState: TGroupBox
      Left = 191
      Top = 84
      Width = 182
      Height = 120
      Caption = ' State '
      TabOrder = 4
      object panelReleased: TPanel
        Left = 20
        Top = 23
        Width = 90
        Height = 27
        Caption = 'RELEASED'
        ParentBackground = False
        TabOrder = 0
      end
      object panelWanted: TPanel
        Left = 49
        Top = 53
        Width = 90
        Height = 27
        Caption = 'WANTED'
        ParentBackground = False
        TabOrder = 1
      end
      object panelHeld: TPanel
        Left = 75
        Top = 82
        Width = 90
        Height = 28
        Caption = 'HELD'
        ParentBackground = False
        TabOrder = 2
      end
    end
    object updownDelay: TUpDown
      Left = 161
      Top = 92
      Width = 20
      Height = 24
      Associate = leditDelay
      Max = 10000
      Increment = 500
      Position = 1000
      TabOrder = 5
      Thousands = False
    end
    object leditDelay: TLabeledEdit
      Left = 42
      Top = 92
      Width = 119
      Height = 24
      EditLabel.Width = 56
      EditLabel.Height = 16
      EditLabel.Caption = 'Delay, ms'
      TabOrder = 6
      Text = '1000'
      OnChange = leditDelayChange
    end
    object cbRandom: TCheckBox
      Left = 43
      Top = 128
      Width = 119
      Height = 21
      Caption = 'Random Delay'
      TabOrder = 7
    end
  end
  object savedialogProtocol: TSaveDialog
    Left = 62
    Top = 326
  end
  object popupProtocol: TPopupMenu
    Left = 64
    Top = 270
    object pmiClear: TMenuItem
      Caption = 'Clear'
      OnClick = pmiClearClick
    end
    object pmiSave: TMenuItem
      Caption = 'Save'
      OnClick = pmiSaveClick
    end
  end
end
