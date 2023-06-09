/*******************************************************************
*
*  DESCRIPTION: Atomic Model for logic clock
*
*  AUTHOR: Khaldoon Al-Zoubi 
*
*  EMAIL: khaldoon_alzoubi@hotmail.com
*
*  DATE: 14/10/2003
*
*******************************************************************/

#ifndef __CLOCK_H
#define __CLOCK_H

#include "atomic.h"     // class Atomic

class Clock : public Atomic
{
public:
	Clock( const string &name = "Clock" );	//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	Port &out_clk;
	Time cycleTime;
	int clk;


};	// class Clock

// ** inline ** // 
inline
string Clock::className() const
{
	return "Clock" ;
}

#endif   //__CLOCK_H
