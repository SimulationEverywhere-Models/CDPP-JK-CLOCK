/*******************************************************************
*
*  DESCRIPTION: Atomic Model for logic clock
*
*  AUTHOR: Khaldoon Al-Zoubi 
*
*  EMAIL: khaldoon_alzoubi@hotmail.com
*
*  DATE: 13/10/2003
*
*******************************************************************/

/** include files **/
#include "clock.h"     	  // class Clock
#include "message.h"   	  // class ExternalMessage, InternalMessage
#include "mainsimu.h"     // MainSimulator::Instance().getParameter( ... )

/*******************************************************************
* Function Name: Clock
* Description: 	It sets the input/output ports and the clock cycle
* 		
********************************************************************/
Clock::Clock( const string &name )
: Atomic( name )
, out_clk( addOutputPort( "out_clk" ) )
, cycleTime( 0, 0, 0, 50 )
{
	
string time( MainSimulator::Instance().getParameter( description(), "cycle" ) ) ;

if ( time != "" )
	cycleTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description:
* 
********************************************************************/
Model& Clock::initFunction()
{
	
clk = 0;  // start clock with low pulse
holdIn( active, Time::Zero );

return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model& Clock::externalFunction( const ExternalMessage &msg )
{

return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model& Clock::internalFunction( const InternalMessage & )
{

if (this->state() == active)
	{
	if (clk == 0)
		clk = 1;
	else
		clk = 0;

	holdIn( active, cycleTime );
	}

return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model& Clock::outputFunction( const InternalMessage &msg )
{

sendOutput( msg.time(), out_clk, (int) clk) ;

return *this ;
}
