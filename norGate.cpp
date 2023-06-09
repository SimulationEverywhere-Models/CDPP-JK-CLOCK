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
#include "norGate.h"      // class norGate
#include "message.h"   	  // class ExternalMessage, InternalMessage
#include "mainsimu.h"     // MainSimulator::Instance().getParameter( ... )

/*******************************************************************
* Function Name: norGate
* Description: 	It sets the input/output ports and the delay time of
* 		the gate
* 		
********************************************************************/
norGate::norGate( const string &name )
: Atomic( name )
, in_a( addInputPort( "in_a" ) )
, in_b( addInputPort( "in_b" ) )
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
Model& norGate::initFunction()
{
	
in_a_val = 1;
in_b_val = 0;

return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model& norGate::externalFunction( const ExternalMessage &msg )
{

if (msg.port() == in_a)
	in_a_val = (int) msg.value();
else
	in_b_val = (int) msg.value();

holdIn( active, delayTime );

return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model& norGate::internalFunction( const InternalMessage & )
{
passivate();
return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &norGate::outputFunction( const InternalMessage &msg )
{

sendOutput( msg.time(), out, !( in_a_val || in_b_val ) ) ;
return *this ;
}
