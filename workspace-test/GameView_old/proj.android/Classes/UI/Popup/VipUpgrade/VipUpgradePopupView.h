/**
* This file is auto generated by Twin Dragons Tools
* VipUpgradePopupView.h
* DragonVideoPoker
*
* Created by apple on Fri Jun 06 12:50:39 GMT+07:00 2014
*
**/

#ifndef __DragonVideoPoker__VipUpgradePopupView__
#define __DragonVideoPoker__VipUpgradePopupView__

#include "cocos-ext.h"

#include "PopUpLayer.h"
#include "Defines.h"

using namespace std;
using namespace cocos2d;
using namespace cocos2d::extension;

class VipUpgradePopupView : public PopUpLayer {

public:
	static VipUpgradePopupView* create(const string &pChipsString,
                                       const string &pInappMultipleString,
                                       long pVipStatus,
                                       string pBackgroundImage = D::id.vip_upgrade_popup_background_container,
                                       string pExitNormalImage = "",
                                       string pExitSelectedImage = "");
    
    virtual bool init(const string &pChipsString,
                      const string &pInappMultipleString,
                      long pVipStatus,
                      string pBackgroundImage = D::id.vip_upgrade_popup_background_container,
                      string pExitNormalImage = "",
                      string pExitSelectedImage = "");	
 
 protected:
    virtual void addSprites();
    virtual void addLabels();
    virtual void addMenuItems();
    virtual void addProgressBars();
    virtual void addActions();
    virtual void onActionShowFinished();

private:
	enum MenuItemTag {
		
		okMenuItemTag	= 1000,
		shareMenuItemTag	= 1001,

	};
	
	void vipUpgradeMenuItemCallback(CCObject *pSender);
	
	//{extend_functions}

	
	CCSprite* mOkActiveSprite;
	
	CCSprite* mOkNormalSprite;

	CCMenuItem* mOkMenuItem;
	
	CCSprite* mShareActiveSprite;
	
	CCSprite* mShareNormalSprite;

	CCMenuItem* mShareMenuItem;

	CCSprite* mMemberCardSprite;
	
	CCSprite* mRewardIconSprite;
	
	CCSprite* mShineSprite;
	
	CCSprite* mStar1Sprite;
	
	CCSprite* mStar2Sprite;
	
	CCSprite* mVipLevelRibbonSprite;

	CCLabelTTF* mChipsLabel;
	
	CCLabelTTF* mInappLabel;

    string mChipsString;
    string mInappMultipleString;
    long mVipStatus;

};

#endif /* defined(__DragonVideoPoker__VipUpgradePopupView__) */
