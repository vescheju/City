/**
 * \file MinionVisitor.h
 *
 * \author Justin Vesche
 *
 * Class that visits and sets minions.
 */


#pragma once
#include "TileVisitor.h"
class CTile;

class CTileTransporter;

/** Minion visitor to help change the minions*/
class CMinionVisitor :
    public CTileVisitor
{
public: 
    /**
    * Constructor for CMinionVisitor
    * 
    * \param toChange an int that will be set as the new minion location.
    */
    CMinionVisitor(int toChange) { mNewMinion = toChange; }

    void VisitPort(CTileTransporter* port);
    
private:
    /// new minion location
    int mNewMinion;
    /// current tile being looked at
    int mCurrentTile = 0;
};

