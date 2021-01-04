//---------------------------------------------------------------------------
//	Vector Logical Clock
//  modified for support of matrix clocks
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
template <class T, int N>
class VClock
{
  protected:
	vector< T > vClock;
	vector< T > vClockZero;

  public:
	__fastcall VClock(void)
	{
		// VC1
		for(int i = 0; i < N; i++)
			vClock.push_back(0);

		vClockZero.push_back(0);
	}

	__fastcall VClock(const VClock<T, N>& vc)
	{
		vClock.clear();
		for(int i = 0; i < vc.Size(); i++)
			vClock.push_back(vc[i]);

		vClockZero.push_back(0);
	}

	__fastcall ~VClock(void) 			{}

	void __fastcall Update(unsigned int inx)
	{
		// VC2
		if(inx < Size())
		{
			vClock[inx]++;
			if(vClock[inx] < 0)
				vClock[inx] = 0;
		}
	}

	void __fastcall Update(VClock& vc)
	{
		// VC2
		if(vClock.size() == vc.Size())
			for (unsigned int i=0; i < Size(); i++)
				vClock[i] = std::max(vClock[i],vc[i]);
	}

	unsigned int __fastcall Size(void) const	{return vClock.size();}

	T& operator[](unsigned int inx)
	{
		if(inx < Size())
			return vClock[inx];

		return vClockZero[0];
	}

	const T& operator[](unsigned int inx) const
	{
		if(inx < Size())
			return vClock[inx];

		return vClockZero[0];
	}

	// ОПЕРАТОРИ ЗА СРАВНЕНИЕ
	//
	// In a C++ class definition, use the const modifier following a member function declaration:
	// The member function is prevented from modifying any data in the class.
	//
	bool operator==(const VClock& vc) const
	{
		if(Size() == vc.Size())
		{
			for(unsigned int i = 0; i < Size(); i++)
				if(!(vClock[i] == vc[i]))
					return false;
			return true;
		}
		else
			return false;
	}

	bool operator<=(const VClock<T, N>& vc) const
	{
		// СРАВНЕНИЕ "ЕЛЕМЕНТ ПО ЕЛЕМЕНТ" != ЛЕКСИКОГРАФИЧЕСКО
		// не може да се използва вграденото сравнение на контейнерa vector
		if(Size() == vc.Size())
		{
			for(unsigned int i = 0; i < Size(); i++)
				if(!(vClock[i] <= vc[i]))
					return false;
			return true;
		}
		else
			return false;
	}

	bool operator<(const VClock<T, N>& vc) const
	{
		// СРАВНЕНИЕ "ЕЛЕМЕНТ ПО ЕЛЕМЕНТ" != ЛЕКСИКОГРАФИЧЕСКО
		// не може да се използва вграденото сравнение на контейнерa vector
		return !(*this == vc) && *this <= vc;
	}
};
//---------------------------------------------------------------------------
#endif

