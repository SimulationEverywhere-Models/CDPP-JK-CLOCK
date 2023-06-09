/*******************************************************************
*
*  DESCRIPTION: Atomic Model AND gate with control (enable/disable) input
*
*  AUTHOR: Khaldoon Al-Zoubi 
*
*  EMAIL: khaldoon_alzoubi@hotmail.com
*
*  DATE: 13/10/2003
*
*******************************************************************/

#ifndef __ANDGATE_H
#define __ANDGATE_H

#include "atomic.h"     // class Atomic

class andGate : public Atomic
{
public:
	andGate( const string &name = "andGate" );	//Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &in_a;
	const Port &in_b;
	const Port &in_enable;
	Port &out;
	Time delayTime;
	int in_a_val;   // last value received on port in_a
	int in_b_val;   // last value received on port in_b

};	// class andGate

// ** inline ** // 
inline
string andGate::className() const
{
	return "andGate" ;
}

#endif   //__ANDGATE_H
