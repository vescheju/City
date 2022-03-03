/**
 * \file TransporterCounter.h
 *
 * \author Justin Vesche
 *
 * Building counter
 */

#pragma once
#include "TileVisitor.h"

class CTileTransporter;
 /** Tile transport visitor to count transporters*/
class CTransporterCounter :
    public CTileVisitor
{
public:
    /** 
    * default Constructor
    */
    CTransporterCounter() {};
    CTransporterCounter(CTileTransporter* port);
    void VisitPort(CTileTransporter* port);
    
    int TransporterCount();
    /** Visit a CTileTransporter object
    * \return mCurrentPort the ammount of transporters */
    int CurrentPortPosition() { return mCurrentPort; }

private:
    /// total num of transporters
    int mTransporterCounter = 0;
    /// are we finsing where the transporter is also
    bool mFindPort = false;
    /// what port are we at
    int mCurrentPort = 0;
    /// port if we are looking for it
    CTileTransporter* mPort = nullptr;
};

