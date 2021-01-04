//---------------------------------------------------------------------------
//	Matrix Logical Clock as Vector of Vector Clocks
//
//	Copyright (c) 2009-2021 by Milen Loukantchevsky.
//---------------------------------------------------------------------------
//	SPECIFICATION: Spec.MatrixClock.VoV.docx
//---------------------------------------------------------------------------
#ifndef MClockH
#define MClockH
//---------------------------------------------------------------------------
#include "VClock.h"
//#include <algorithm>
using namespace std;
//---------------------------------------------------------------------------
template <class T_PID, int S>
class MClock
{
  protected:
	vector < VClock< int, S > > vvClock;
	T_PID PId;

  public:
	// MC1 - Èíèöèàëèçàöèÿ
	__fastcall MClock(void)
	{
		PId = 0;

		for(int i = 0; i < S; i++)
		{
			VClock< int, S > vc;
			vvClock.push_back(vc);
		}
	}

	__fastcall ~MClock(void)	{}

	VClock<int, S>& operator[](unsigned int inx)
	{
		return vvClock[inx];
	}

	const VClock<int, S>& operator[](unsigned int inx) const
	{
		return vvClock[inx];
	}

	unsigned int __fastcall Size(void) const	{return vvClock.size();}

	int __fastcall GetPId(void) const			{return PId;}
	void __fastcall SetPId(T_PID pid) 			{PId = pid;}

	void __fastcall Init(void)
	{
		for(unsigned int i = 0; i < vvClock.size(); i++)
		{
			for(unsigned int j = 0; j < vvClock[i].Size(); j++)
			{
				vvClock[i][j] = 0;
			}
		}
	}

	void __fastcall Update(unsigned int inx)
	{
		// MC2
		if(inx < Size())
			vvClock[inx].Update(inx);
	}

	void __fastcall Update(MClock<T_PID, S>& mc)
	{
		// MC3
		if(vvClock.size() == mc.Size())
		{
			for(unsigned int i=0; i < Size(); i++)
			{
				if(i != PId)
				vvClock[i].Update(mc[i]);
			}

			vvClock[PId].Update(mc[mc.GetPId()]);
			vvClock[PId].Update(PId);
		}
	}

	// ÎÏÅÐÀÒÎÐÈ ÇÀ ÑÐÀÂÍÅÍÈÅ

	bool operator==(const MClock<T_PID, S>& mc) const
	{
		if(vvClock.size() == mc.Size())
		{
			for(int i = 0; i < Size(); i++)
			{
				if(!(vvClock[i] == mc[i]))
					return false;
			}
			return true;
		}
		else
			return false;
	}

	bool operator<=(const MClock<T_PID, S>& mc) const
	{
		if(Size() == mc.Size())
		{
			for(unsigned int i = 0; i < Size(); i++)
			{
				if(!(vvClock[i] <= mc[i]))
					return false;
			}
			return true;
		}
		else
			return false;
	}

	bool operator<(const MClock<T_PID, S>& mc) const
	{
		return !(*this == mc) && *this <= mc;
	}
};
//---------------------------------------------------------------------------
#endif

