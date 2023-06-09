/*******************************************************************
*
*  DESCRIPTION: Atomic Model NOR Gate
*
*  AUTHOR: Khaldoon Al-Zoubi 
*
*  EMAIL: khaldoon_alzoubi@hotmail.com
*
*  DATE: 13/10/2003
*
*******************************************************************/

/** include files **/
#include "andGate.h"      // class andGate
#include "message.h"   	  // class ExternalMessage, InternalMessage
#include "mainsimu.h"     // MainSimulator::Instance().getParameter( ... )

/*******************************************************************
* Function Name: andGate
* Description: 	It sets the input/output ports and the delay time of
* 		the gate
* 		
********************************************************************/
andGate::andGate( const string &name )
: Atomic( name )
, in_a( addInputPort( "in_a" ) )
, in_b( addInputPort( "in_b" ) )
, in_enable( addInputPort( "in_enable" ) )
, out( addOutputPort( "out" ) )
, delayTime( 0, 0, 0, 2 )
{
	
string time( MainSimulator::Instance().getParameter( description(), "delay" ) ) ;

if ( time != "" )
	delayTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description:
* 
********************************************************************/
Model& andGate::initFunction()
{
	
in_a_val = 0;
in_b_val = 1;

return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model& andGate::externalFunction( const ExternalMessage &msg )
{
if (this->state() == passive)
	{
	if (msg.port() == in_a)
		in_a_val = (int) msg.value();
	else if (msg.port() == in_b)
		in_b_val = (int) msg.value();
	else if (msg.port() == in_enable)
		{
		if ((int) msg.value() == 1)
			holdIn( active, delayTime );
		}
	} // if passive


return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model& andGate::internalFunction( const InternalMessage & )
{
passivate();
return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &andGate::outputFunction( const InternalMessage &msg )
{

sendOutput( msg.time(), out, ( in_a_val && in_b_val ) ) ;

return *this ;
}
