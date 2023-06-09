/*******************************************************************
*
*  DESCRIPTION: Atomic Model NOR gate
*
*  AUTHOR: Khaldoon Al-Zoubi 
*
*  EMAIL: khaldoon_alzoubi@hotmail.com
*
*  DATE: 13/10/2003
*
*******************************************************************/

#ifndef __NORGATE_H
#define __NORGATE_H

#include "atomic.h"     // class Atomic

class norGate : public Atomic
{
public:
	norGate( const string &name = "norGate" );	//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &in_a;
	const Port &in_b;
	Port &out;
	Time delayTime;
	int in_a_val;   // last value received on port in_a
	int in_b_val;   // last value received on port in_b

};	// class norGate

// ** inline ** // 
inline
string norGate::className() const
{
	return "norGate" ;
}

#endif   //__NORGATE_H
