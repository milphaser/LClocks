//---------------------------------------------------------------------------
//	Vector Logical Clock
//
//	Copyright (c) 2009-2021 by Milen Loukantchevsky.
//---------------------------------------------------------------------------
//	SPECIFICATION: Spec.VectorClock.docx
//---------------------------------------------------------------------------
#ifndef VClockH
#define VClockH
//---------------------------------------------------------------------------
#include <algorithm>
#include <vector>
using namespace std;
//---------------------------------------------------------------------------
template <class T>
class VClock
{
  protected:
	vector< T > vectorVClock;

  public:
	__fastcall VClock(int n)
	{
		// VC1
		for(int i = 0; i < n; i++)
			vectorVClock.push_back(0);
	}

	__fastcall VClock(VClock& vc)
	{
		vectorVClock.clear();
		for(int i = 0; i < vc.Size(); i++)
			vectorVClock.push_back(vc.Get(i));
	}

	__fastcall ~VClock(void) 			{}

	void __fastcall Update(unsigned int inx)
	{
		// VC2
		if(inx < Size())
		{
			vectorVClock[inx]++;
			if(vectorVClock[inx] < 0)
				  vectorVClock[inx] = 0;
		}
	}

	void __fastcall Update(VClock& vc)
	{
		// VC4
		if(Size() == vc.Size())
			for(unsigned int i = 0; i < Size(); i++)
				vectorVClock[i] = std::max(vectorVClock[i], vc.Get(i));
	}

	unsigned int __fastcall Size(void) const	{ return vectorVClock.size();}

	const T& operator[](unsigned int inx) const
	{
		return vectorVClock[inx];
	}

	// ÎÏÅÐÀÒÎÐÈ ÇÀ ÑÐÀÂÍÅÍÈÅ
	//
	// In a C++ class definition, use the const modifier following a member function declaration:
	// The member function is prevented from modifying any data in the class.
	//
	bool operator==(const VClock& vc) const
	{
		if(Size() == vc.Size())
		{
			for(unsigned int i = 0; i < Size(); i++)
				if(!(vectorVClock[i] == vc[i]))
					return false;
			return true;
		}
		else
			return false;
	}
	bool operator<=(const VClock& vc) const
	{
		// ÑÐÀÂÍÅÍÈÅ "ÅËÅÌÅÍÒ ÏÎ ÅËÅÌÅÍÒ" != ËÅÊÑÈÊÎÃÐÀÔÈ×ÅÑÊÎ
		// íå ìîæå äà ñå èçïîëçâà âãðàäåíîòî ñðàâíåíèå íà êîíòåéíåða vector
		if(Size() == vc.Size())
		{
			for(unsigned int i = 0; i < Size(); i++)
				if(!(vectorVClock[i] <= vc[i]))
					return false;
			return true;
		}
		else
			return false;
	}
	bool operator<(const VClock& vc) const
	{
		// ÑÐÀÂÍÅÍÈÅ "ÅËÅÌÅÍÒ ÏÎ ÅËÅÌÅÍÒ" != ËÅÊÑÈÊÎÃÐÀÔÈ×ÅÑÊÎ
		// íå ìîæå äà ñå èçïîëçâà âãðàäåíîòî ñðàâíåíèå íà êîíòåéíåða vector
		return !(*this == vc) && *this <= vc;
	}
};
//---------------------------------------------------------------------------
#endif

