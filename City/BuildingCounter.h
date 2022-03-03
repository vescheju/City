/**
 * \file BuildingCounter.h
 *
 * \author Justin Vesche
 *
 * Building counter
 */

 /** building visitor class */
#pragma once
#include "TileVisitor.h"
class CBuildingCounter :
    public CTileVisitor
{
public:
    /** Get the number of buildings
    * \returns Number of buildings */
    int GetNumBuildings() const { return mNumBuildings; }

    void VisitBuilding(CTileBuilding* building);

private:
    /// Buildings counter
    int mNumBuildings = 0;


};

