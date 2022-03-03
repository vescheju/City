/**
 * \file TileTransporter.cpp
 *
 * \author Justin Vesche
 */


#include "pch.h"
#include "TileTransporter.h"
#include "TransporterCounter.h"
#include "City.h"

using namespace std;
using namespace Gdiplus;

/** Constructor
* \param city The city this is a member of
*/
CTileTransporter::CTileTransporter(CCity* city) : CTile(city)
{
}

/**
*  Destructor
*/
CTileTransporter::~CTileTransporter()
{
}


/**
  *  Create a of the transporter. Could have a minion on top 
  * if needed.
  *
  * \param graphics a Graphic we will use to draw.
  */
void CTileTransporter::Draw(Gdiplus::Graphics* graphics)
{
    
    
    CTransporterCounter visitor;
    GetCity()->Accept(&visitor);
    if (visitor.TransporterCount() == 1 || mShouldMinion)
    {
        SetImage(L"transporter.png");
        CTile::Draw(graphics);
        SetImage(L"transporter-minion.png");
        CTile::Draw(graphics);
        mShouldMinion = true;
    }
    else
    {
        SetImage(L"transporter.png");
        CTile::Draw(graphics);
    }

}