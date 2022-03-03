/**
 * \file MinionSetter.cpp
 *
 * \author Justin Vesche
 */


#include "pch.h"
#include "MinionSetter.h"
#include "TileTransporter.h"
#include "TransporterCounter.h"
#include "City.h"
#include "MinionVisitor.h"


 /**
  *  Change the minion to the current given port.
  * 
  * \param port a pointer of the current transporter
  */
void CMinionSetter::VisitPort(CTileTransporter* port)
{
	CTransporterCounter visitor(port);

	mCity->Accept(&visitor);
	/// The current port we are at
	auto currentPort = visitor.CurrentPortPosition();
	/// how many ports there are
	auto portCount = visitor.TransporterCount();
	// if we are at a minion that should have one
	if (port->ShouldMinion())
	{
		if (portCount > 1)
		{
			mRand = 1 + (rand() % portCount);
			while (mRand == currentPort)
				mRand = 1 + (rand() % portCount);

			CMinionVisitor visitor1(mRand);

			mCity->Accept(&visitor1);
		}
	}
	else
	{
		// a port without a minion so we must place a minion.
		CMinionVisitor visitor1(currentPort);

		mCity->Accept(&visitor1);
	}
}


