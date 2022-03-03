/**
 * \file MinionVisitor.cpp
 *
 * \author Justin Vesche
 */


#include "pch.h"
#include <memory>
#include "MinionVisitor.h"
#include "TileTransporter.h"

 /**
   *  Set the minion to true where we want it. 
   *  False elsewhere.
   *
   * \param port a pointer of the current transporter
   */
void CMinionVisitor::VisitPort(CTileTransporter* port)
{
	mCurrentTile++;
	if (mCurrentTile == mNewMinion)
	{
		port->SetMinion(true);
	}
	else
	{
		port->SetMinion(false);
	}
}
