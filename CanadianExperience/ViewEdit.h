/**
 * \file ViewEdit.h
 *
 * \author Ben Haase
 *
 * View class the provides a window for editing our pixture
 */

#pragma once
#include "PictureObserver.h"
#include<memory>
class CMainFrame;
class CDrawable;
class CActor;

using namespace Gdiplus;
using namespace std;


/** View class the provides a window for editing our pixture */
class CViewEdit : public CScrollView, public CPictureObserver
{
	DECLARE_DYNCREATE(CViewEdit)

public:
	CViewEdit();           // protected constructor used by dynamic creation
	virtual ~CViewEdit();

	/**
	* Set the mainFrame pointer
	* \param mainFrame Pointer to the CMainFrame window
	*/
	void SetMainFrame(CMainFrame *mainFrame) { mMainFrame = mainFrame; }

	virtual void UpdateObserver() override;

protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct

	DECLARE_MESSAGE_MAP()

public:
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);

    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);

private:
	/// The main frame window that uses this view
	CMainFrame  *mMainFrame = nullptr;

	///pointer to a specific drawable
	std::shared_ptr<CDrawable> mDrawable;

	///pointer to specific actor 
	std::shared_ptr<CActor> mActor;

	/// The last mouse position
	Gdiplus::Point mLastMouse = Gdiplus::Point(0, 0);

	/// A scaling factor, converts mouse motion to rotation in radians
	const double RotationScaling = 0.02;
};


