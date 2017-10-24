/**
* \File Picture.h
*
* The picture we are drawing.
*
* There will be one picture object that contains all of
* our actors, which then contains the drawables.
* \author Ben Haase
*/



#pragma once
#include<vector>
#include <memory>


class CPictureObserver;
class CActor;



/**
* The picture we are drawing.
*/
class CPicture
{
public:
	/// Copy Constructor (Disabled)
	CPicture(const CPicture &) = delete;
	/// Assignment Operator (Disabled)
	CPicture &operator=(const CPicture &) = delete;


	CPicture();
	~CPicture();

	/** The picture size
	* \returns Size */
	Gdiplus::Size GetSize() { return mSize; }

	/** The picture size
	* \param size The new picture size */
	void SetSize(Gdiplus::Size size) { mSize = size; }

	void AddObserver(CPictureObserver *observer);
	void AddActor(std::shared_ptr<CActor> actor);
	void RemoveObserver(CPictureObserver *observer);
	void UpdateObservers();
	void Draw(Gdiplus::Graphics *graphics);

	/** Iterator that iterates over the city tiles */
	class Iter
	{
	public:
		/** Constructor
		* \param picture The city we are iterating over 
		* \param pos Position in list
		*/
		Iter(CPicture *picture, int pos) : mPicture(picture), mPos(pos) {}

		/** Test for end of the iterator
		* \returns True if we this position equals not equal to the other position */
		bool operator!=(const Iter &other) const
		{
			return mPos != other.mPos;
		}

		/** Get value at current position
		* \returns Value at mPos in the collection */
		std::shared_ptr<CActor> operator *() const { return mPicture->mActors[mPos]; }

		/** Increment the iterator
		* \returns Reference to this iterator */
		const Iter& operator++()
		{
			mPos++;
			return *this;
		}


	private:
		CPicture *mPicture;   ///< Picture we are iterating over
		int mPos;       ///< Position in the collection
	};

	/** Get an iterator for the beginning of the collection
	* \returns Iter object at position 0 */
	Iter begin() { return Iter(this, 0); }

	/** Get an iterator for the end of the collection
	* \returns Iter object at position past the end */
	Iter end() { return Iter(this, mActors.size()); }

private:
	/// The picture size
	Gdiplus::Size mSize = Gdiplus::Size(800, 600);

	/// The observers of this picture
	std::vector<CPictureObserver *> mObservers;

	/// list of actors in picture
	std::vector<std::shared_ptr<CActor>> mActors;
};

