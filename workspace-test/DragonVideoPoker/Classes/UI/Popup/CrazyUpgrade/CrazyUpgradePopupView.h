/**
* This file is auto generated by Twin Dragons Tools
* CrazyUpgradePopupView.h
* DragonVideoPoker
*
* Created by apple on Fri Aug 15 20:12:11 GMT+07:00 2014
*
**/

#ifndef __DragonVideoPoker__CrazyUpgradePopupView__
#define __DragonVideoPoker__CrazyUpgradePopupView__

#include "cocos-ext.h"

#include "PopUpLayer.h"
#include "Defines.h"

using namespace std;
using namespace cocos2d;
using namespace cocos2d::extension;

class CrazyUpgradePopupView : public PopUpLayer {

public:
	static CrazyUpgradePopupView* create(
							string pBackgroundImage = D::id.crazy_upgrade_popup_background_cz_container,
                            string pExitNormalImage = "",
                            string pExitSelectedImage = "");
    
    virtual bool init(
    				string pBackgroundImage = D::id.crazy_upgrade_popup_background_cz_container,
                    string pExitNormalImage = "",
                    string pExitSelectedImage = "");	
 
 protected:
    virtual void addSprites();
    virtual void addLabels();
    virtual void addMenuItems();
    virtual void addProgressBars();
    virtual void addActions();
    virtual void addTables();
    
private:
	enum MenuItemTag {
		
	};
	
	void crazyUpgradeMenuItemCallback(CCObject *pSender);
	
	CCLabelTTF* mHelloMyLoveLabel;

	CCLabelTTF* mDungTaVanLabel;

	CCSprite* mHahaHahaSprite;

	CCSprite* mCzRewardIconSprite;
	CCSprite* mCzVipLevelRibbonSprite;

};

#endif /* defined(__DragonVideoPoker__CrazyUpgradePopupView__) */