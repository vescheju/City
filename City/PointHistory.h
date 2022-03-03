/**
* \file PointHistory.cpp
*
* \author Charles Owen
*
* Class that maintains a collection of Point objects in order.
*/

#pragma once
#include <memory>
#include <random>



/**
 * Class that maintains a collection of Point objects in order.
 */
class CPointHistory
{
public:
    /// The number of potato lists.
    const static int NumLists = 2;

    CPointHistory();
    virtual ~CPointHistory();

    void Add(Gdiplus::Point p);



protected:
    /// Data is stored in a linked list of data buckets,
    /// where each data bucket is a point and the next 
    /// to the next point in the array of points.

    /**
     * Bucket that stores a single point.
     */
    class PointBucket {
    public:
        /// a single point of the node
        Gdiplus::Point mPoint;
        /// next location of the node
        int mNext = -1;
    };

    /// Array containing all available points in buckets.
    std::vector<PointBucket> mPoints;

    /// Array of all available locations in mPoints. 
    std::vector<int> mAvailables;

    /// Index to the first item in the linked list 
    /// of point history. Initially none.
    int mPointFirst = -1;

    /// Index to the last item in the linked list of
    /// point history. Initially none.
    int mPointLast = -1;

    /// Random number generator to use for shuffling
    std::default_random_engine mRandInt;



public:
    /** Iterator that iterates over the city tiles */
    class Iter
    {
    public:
        /** Constructor
         * \param points collection of points
         * \param pos pointer to the current point bucket
         */
        Iter(CPointHistory* points, std::shared_ptr<PointBucket>pos) : mPointHistory(points), mPos(pos) {}

        /** Test for end of the iterator
         * 
         *\param other used to compare another iter
         * \returns True if we this position equals not equal to the other position */
        bool operator!=(const Iter& other) const
        {
            return mPos != other.mPos;
        }

        /** Get value at current position
         * \returns Value at mPos in the collection */
        Gdiplus::Point operator *() const { return mPos->mPoint; }

        /** Increment the iterator
         * \returns Reference to this iterator */
        const Iter& operator++()
        {
            
            if (mPointHistory->mPointFirst != -1 || mPos.get() != nullptr) {
                if (mPos->mNext == -1)
                {
                    mPos = nullptr;
                }
                else
                {
                    mPos = std::make_shared<PointBucket>(mPointHistory->mPoints[mPos->mNext]);
                }
            }
            return *this;
        }

    private:
        CPointHistory* mPointHistory;   ///< City we are iterating over
        std::shared_ptr<PointBucket> mPos;       ///< Position in the collection
        
    };

    /** Get an iterator for the beginning of the collection
    * \returns Iter object at last location in the array */
    Iter begin() 
    { 
        if (mPointFirst != -1)
            return Iter(this, std::make_shared<PointBucket>(mPoints[mPointFirst]));
        else 
            return Iter(this, nullptr);
    }

    /** Get an iterator for the end of the collection
    * \returns Iter object at position past the front */
    Iter end() { return Iter(this, nullptr); }
};


