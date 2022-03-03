/**
 * \file MinionSetter.h
 *
 * \author Justin Vesche
 *
 * Visit class to set the minion, uses the visitor minion to actually set.
 */


#pragma once
#include "TileVisitor.h"
class CCity;
class CTile;
/** Actually change all the minions visited*/
class CMinionSetter :
    public CTileVisitor
{
public:
    /** Constructor
    * \param city a city needed to use another visitor.
    */
    CMinionSetter(CCity* city) { mCity = city; }
    void VisitPort(CTileTransporter* port);

private:
    /// City to use for another visitor
    CCity *mCity;
    /// total number of transporters
    int mTransporters = 0;
    /// random number for the teleporter
    int mRand = 0;
};

