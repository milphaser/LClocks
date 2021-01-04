object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Matrix Clocks - comparison application'
  ClientHeight = 355
  ClientWidth = 668
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object gb2: TGroupBox
    Left = 443
    Top = 8
    Width = 215
    Height = 321
    Caption = 'Process 2'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    object labelM2: TLabel
      Left = 118
      Top = 81
      Width = 90
      Height = 13
      AutoSize = False
      Caption = 'Matrix Clock 2'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
    end
    object stxt2: TStaticText
      Left = 7
      Top = 51
      Width = 93
      Height = 17
      Alignment = taCenter
      Caption = 'Send message to :'
      TabOrder = 0
    end
    object btnP2toP0: TButton
      Left = 11
      Top = 69
      Width = 42
      Height = 25
      Caption = 'P0'
      TabOrder = 1
      OnClick = btnP2toP0Click
    end
    object btnP2toP1: TButton
      Left = 59
      Top = 69
      Width = 42
      Height = 25
      Caption = 'P1'
      TabOrder = 2
      OnClick = btnP2toP1Click
    end
    object btnEventP2: TButton
      Left = 12
      Top = 20
      Width = 88
      Height = 25
      Caption = 'Internal Event'
      TabOrder = 3
      OnClick = btnEventP0Click
    end
    object btnReset2: TButton
      Left = 114
      Top = 20
      Width = 90
      Height = 25
      Caption = 'Reset MC2'
      TabOrder = 4
      OnClick = btnReset2Click
    end
    object gb21: TGroupBox
      Left = 7
      Top = 186
      Width = 204
      Height = 127
      Caption = ' Compare MC2 with: '
      TabOrder = 5
      object Label3: TLabel
        Left = 67
        Top = 55
        Width = 54
        Height = 13
        AutoSize = False
        Caption = 'RESULT'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object result2: TLabel
        Left = 49
        Top = 79
        Width = 5
        Height = 19
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object resultTxt2: TLabel
        AlignWithMargins = True
        Left = 5
        Top = 106
        Width = 194
        Height = 16
        Align = alBottom
        Alignment = taCenter
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        ExplicitWidth = 4
      end
      object MC2andMC0: TButton
        Left = 4
        Top = 22
        Width = 89
        Height = 25
        Caption = 'MC0'
        TabOrder = 0
        OnClick = MC2andMC0Click
      end
      object MC2andMC1: TButton
        Left = 107
        Top = 22
        Width = 90
        Height = 25
        Caption = 'MC1'
        TabOrder = 1
        OnClick = MC2andMC1Click
      end
    end
  end
  object gb1: TGroupBox
    Left = 223
    Top = 8
    Width = 215
    Height = 321
    Caption = 'Process 1'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    object labelM1: TLabel
      Left = 117
      Top = 81
      Width = 90
      Height = 15
      AutoSize = False
      Caption = 'Matrix Clock 1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
    end
    object sTxt1: TStaticText
      Left = 7
      Top = 51
      Width = 93
      Height = 17
      Alignment = taCenter
      Caption = 'Send message to :'
      TabOrder = 0
    end
    object btnP1toP0: TButton
      Left = 10
      Top = 69
      Width = 42
      Height = 25
      Caption = 'P0'
      TabOrder = 1
      OnClick = btnP1toP0Click
    end
    object btnP1toP2: TButton
      Left = 58
      Top = 69
      Width = 42
      Height = 25
      Caption = 'P2'
      TabOrder = 2
      OnClick = btnP1toP2Click
    end
    object btnEventP1: TButton
      Left = 10
      Top = 20
      Width = 90
      Height = 25
      Caption = 'Internal Event'
      TabOrder = 3
      OnClick = btnEventP0Click
    end
    object btnReset1: TButton
      Left = 115
      Top = 20
      Width = 90
      Height = 25
      Caption = 'Reset MC1'
      TabOrder = 4
      OnClick = btnReset1Click
    end
    object gb11: TGroupBox
      Left = 7
      Top = 186
      Width = 202
      Height = 127
      Caption = ' Compare MC1 with: '
      TabOrder = 5
      object Label2: TLabel
        Left = 67
        Top = 55
        Width = 54
        Height = 13
        AutoSize = False
        Caption = 'RESULT'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object result1: TLabel
        Left = 49
        Top = 79
        Width = 5
        Height = 19
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object resultTxt1: TLabel
        AlignWithMargins = True
        Left = 5
        Top = 106
        Width = 192
        Height = 16
        Align = alBottom
        Alignment = taCenter
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        ExplicitWidth = 4
      end
      object MC1andMC0: TButton
        Left = 3
        Top = 22
        Width = 90
        Height = 25
        Caption = 'MC0'
        TabOrder = 0
        OnClick = MC1andMC0Click
      end
      object MC1andMC2: TButton
        Left = 108
        Top = 21
        Width = 90
        Height = 25
        Caption = 'MC2'
        TabOrder = 1
        OnClick = MC1andMC2Click
      end
    end
  end
  object gb0: TGroupBox
    Left = 2
    Top = 8
    Width = 215
    Height = 321
    Caption = 'Process 0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    object labelM0: TLabel
      Left = 117
      Top = 83
      Width = 90
      Height = 13
      AutoSize = False
      Caption = 'Matrix Clock 0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
    end
    object sTxt0: TStaticText
      Left = 9
      Top = 51
      Width = 90
      Height = 17
      Alignment = taCenter
      Caption = 'Send message to:'
      TabOrder = 0
    end
    object btnP0toP1: TButton
      Left = 9
      Top = 69
      Width = 42
      Height = 25
      Caption = 'P1'
      TabOrder = 1
      OnClick = btnP0toP1Click
    end
    object btnP0toP2: TButton
      Left = 55
      Top = 69
      Width = 42
      Height = 25
      Caption = 'P2'
      TabOrder = 2
      OnClick = btnP0toP2Click
    end
    object btnReset0: TButton
      Left = 110
      Top = 20
      Width = 92
      Height = 25
      Caption = 'Reset MC0'
      TabOrder = 3
      OnClick = btnReset0Click
    end
    object gb01: TGroupBox
      Left = 6
      Top = 186
      Width = 201
      Height = 127
      Caption = ' Compare MC0 with: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      object Label1: TLabel
        Left = 67
        Top = 55
        Width = 54
        Height = 13
        AutoSize = False
        Caption = 'RESULT'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object result0: TLabel
        Left = 49
        Top = 79
        Width = 5
        Height = 19
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object resultTxt0: TLabel
        AlignWithMargins = True
        Left = 5
        Top = 106
        Width = 191
        Height = 16
        Align = alBottom
        Alignment = taCenter
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        ExplicitWidth = 4
      end
    end
  end
  object btnEventP0: TButton
    Left = 11
    Top = 28
    Width = 87
    Height = 25
    Caption = 'Internal Event'
    TabOrder = 0
    OnClick = btnEventP0Click
  end
  object sgMatrix0: TStringGrid
    Left = 8
    Top = 108
    Width = 200
    Height = 80
    ColCount = 3
    FixedCols = 0
    RowCount = 3
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    GridLineWidth = 2
    ParentFont = False
    TabOrder = 1
  end
  object sgMatrix1: TStringGrid
    Left = 230
    Top = 108
    Width = 200
    Height = 80
    ColCount = 3
    FixedCols = 0
    RowCount = 3
    FixedRows = 0
    GridLineWidth = 2
    TabOrder = 2
    RowHeights = (
      24
      24
      24)
  end
  object sgMatrix2: TStringGrid
    Left = 451
    Top = 108
    Width = 200
    Height = 80
    ColCount = 3
    DoubleBuffered = False
    FixedCols = 0
    RowCount = 3
    FixedRows = 0
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = 15
    Font.Name = 'Tahoma'
    Font.Style = []
    GridLineWidth = 2
    ParentDoubleBuffered = False
    ParentFont = False
    TabOrder = 3
    RowHeights = (
      24
      24
      24)
  end
  object sbMsgReceived: TStatusBar
    Left = 0
    Top = 336
    Width = 668
    Height = 19
    Panels = <
      item
        Width = 175
      end
      item
        Width = 175
      end
      item
        Width = 175
      end
      item
        Width = 115
      end>
  end
  object MC0andMC1: TButton
    Left = 11
    Top = 218
    Width = 87
    Height = 25
    Caption = 'MC1'
    TabOrder = 8
    OnClick = MC0andMC1Click
  end
  object MC0andMC2: TButton
    Left = 112
    Top = 218
    Width = 93
    Height = 25
    Caption = 'MC2'
    TabOrder = 9
    OnClick = MC0andMC2Click
  end
end
