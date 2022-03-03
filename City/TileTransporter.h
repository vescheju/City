/**
* \file TileTransporter.h
*
* \author Justin Vesche
*
*  Class that implements a Transporter tile
*/

#pragma once
#include "Tile.h"
#include "TileVisitor.h"

/**
*  A Transporter tile
*/
class CTileTransporter : public CTile
{
public:
    /** Accept a visitor
   * \param visitor The visitor we accept */
    virtual void Accept(CTileVisitor* visitor) override { visitor->VisitPort(this); }

    CTileTransporter(CCity* city);

    ///  Default constructor (disabled)
    CTileTransporter() = delete;

    ///  Copy constructor (disabled)
    CTileTransporter(const CTileTransporter&) = delete;

    ~CTileTransporter();

    /**  Draw this item
    * \param graphics The graphics context to draw on */
    virtual void Draw(Gdiplus::Graphics* graphics);

    /**
    * Getter for if there should be a minion
    * 
    * \returns mShouldMinion true if there should be a minion.
    */
    bool ShouldMinion() { return mShouldMinion; }

    /**
    * setter for mShouldMinion
    *
    * \param set uses a boolean to set minion
    */
    void SetMinion(bool set) { mShouldMinion = set; }

private:
    /// member of if there should be a minion.
    bool mShouldMinion = false; 


};

