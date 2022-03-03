/**
 * \file TransporterCounter.cpp
 *
 * \author Justin Vesche
 */


#include "pch.h"
#include "TransporterCounter.h"
#include "TileTransporter.h"
#include "TileTransporter.h"

 /**
   *  Constructor that we will use if we find where a port is.
   *
   * \param port a pointer used to find at what location it is in city.
   */
CTransporterCounter::CTransporterCounter(CTileTransporter* port)
{
	mFindPort = true;
	mPort = port;
}

/**
  *  visiter to count the number of transporters along with 
  * finiding a location of a transporter if needed.
  *
  * \param port a pointer of the current transporter
  */
void CTransporterCounter::VisitPort(CTileTransporter* port)
{
	mTransporterCounter++;
	if (mFindPort)
	{
		if (port == mPort)
		{
			mCurrentPort = mTransporterCounter;
		}
	}
}

/**
  *  Change the minion to the current given port.
  *
  * \return int count of the transporters.
  */
int CTransporterCounter::TransporterCount()
{
	return mTransporterCounter;
}



