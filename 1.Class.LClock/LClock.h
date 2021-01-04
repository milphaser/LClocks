//---------------------------------------------------------------------------
//	Lamport Logical (Scalar) Clock
//
//	Copyright (c) 2009-2021 by Milen Loukantchevsky.
//---------------------------------------------------------------------------
//	SPECIFICATION: Spec.LamportClock.docx
//---------------------------------------------------------------------------
#ifndef LClockH
#define LClockH
//---------------------------------------------------------------------------
#include <algorithm>
using namespace std;
//---------------------------------------------------------------------------
template <class T, class PID>
class LClock
{
  protected:
    T tLClock;
    PID pidMy;

  public:
    __fastcall LClock(const PID& pid)	{ tLClock = 0; pidMy = pid;}
    __fastcall LClock(const int lc, const PID& pid)	{ tLClock = lc; pidMy = pid;}
    __fastcall LClock(const LClock& lc)	{ tLClock = lc.tLClock; pidMy = lc.pidMy;}
    __fastcall ~LClock(void) 		{}

    T __fastcall Get(void)		{ return tLClock;}
    void __fastcall Update(const T& lc = 0)
    {
		tLClock = std::max(tLClock, lc) + 1;
		if(tLClock < 0)
			tLClock = 0;
	}

	// ОПЕРАТОРИ ЗА СРАВНЕНИЕ
	// Операторите за сравнение == и < се определят задължително
	// останалите оператори за сравнение се определят автоматично от тях
	//
	// In a C++ class definition, use the const modifier following a member function declaration:
	// The member function is prevented from modifying any data in the class.
	//
	bool operator==(const LClock& lcOther) const
	{
		return (tLClock == lcOther.tLClock && pidMy == lcOther.pidMy);
	}

	bool operator<(const LClock& lcOther) const
	{
		if(tLClock < lcOther.tLClock)
			return true;
		else if(tLClock == lcOther.tLClock)
		{
			if(pidMy.Length() < lcOther.pidMy.Length())
				return true;
			else if(pidMy.Length() == lcOther.pidMy.Length())
				if(pidMy < lcOther.pidMy)	// директно сравнение, само ако дължината съвпада
			return true;
		}

		return false;
	}
};
//---------------------------------------------------------------------------
#endif

