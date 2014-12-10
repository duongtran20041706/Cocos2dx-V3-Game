/**
* This file is auto generated by Twin Dragons Tools
* CzaAvatarsPopupView.h
* DragonVideoPoker
*
* Created by apple on Mon Sep 22 23:42:59 GMT+07:00 2014
*
**/
#ifndef __DragonVideoPoker__CzaAvatarsPopupView__
#define __DragonVideoPoker__CzaAvatarsPopupView__
#include "cocos-ext.h"
#include "PopUpLayer.h"
#include "ITableViewBuilder.h"
#include "Defines.h"
using namespace std;
using namespace cocos2d;
using namespace cocos2d::extension;
class ITableCellView;
class TableView;
class CzaAvatarsPopupView : public PopUpLayer, public ITableViewBuilder {
public:
	static CzaAvatarsPopupView* create(//{parameters},
							string pBackgroundImage = D::id.cza_avatars_popup_background_cza_bg,
                            string pExitNormalImage = D::id.pop_common_close_normal,
                            string pExitSelectedImage = D::id.pop_common_close_active);
    
    virtual bool init(//{parameters},
    				string pBackgroundImage = D::id.cza_avatars_popup_background_cza_bg,
                    string pExitNormalImage = D::id.pop_common_close_normal,
                    string pExitSelectedImage = D::id.pop_common_close_active);
                    
   	virtual ITableCellView* createTableViewCellAt(const int &idx);
 
 protected:
    virtual void addSprites();
    virtual void addLabels();
    virtual void addMenus();
    virtual void addMenuItems();
    virtual void addProgressBars();
    virtual void addActions();
    virtual void addTables();
    
private:
	enum MenuItemTag {
		
	};
	
	void czaAvatarsMenuItemCallback(CCObject *pSender);
	
	CCSprite* mCzaComeBackTextSprite;
	CCSprite* mCzaHeaderSprite;
	CCSprite* mCzaLvProgressBgSprite;

	CCTableView* mContainerTable;

	CCProgressTimer* mCzaLvProgressOverProgressbar;

};
#endif /* defined(__DragonVideoPoker__CzaAvatarsPopupView__) */