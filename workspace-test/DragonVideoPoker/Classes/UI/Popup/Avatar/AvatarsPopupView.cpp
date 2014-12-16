/**
 * This file is auto generated by Twin Dragons Tools
 * AvatarsPopupView.cpp
 * DragonVideoPoker
 *
 * Created by apple on Fri May 30 14:23:18 GMT+07:00 2014
 *
 **/
#include "AvatarsPopupView.h"
#include "PopUpLayer.h"
#include "VisibleRect.h"
#include "GameParams.h"
#include "TableView.h"
#include "TdgServer.h"
#include "UserInfo.h"
#include "SoundManager.h"

#include "AvatarMenuItem.h"
#include "FBAvatarDownloader.h"
#include "ITableViewBuilder.h"
#include "ITableCellView.h"

class AvatarCellView : public ITableCellView {
public:
    static AvatarCellView* create(const vector<CCSprite*> &pAvatarsSprites,
                                       const int &idx);
    virtual bool init(const vector<CCSprite*> &pAvatarsSprites,
                      const int &idx = 0);
    virtual  void update(const int &idx);
protected:
    virtual void addSprites();
//    virtual void addLabels();
//    virtual void addMenuItems();
    
//    virtual void updateSprites(const int &idx);
//    virtual void updateLabels(const int &idx);
//    virtual void updateMenuItems(const int &idx);
private:
    CCSprite* mBgSprite;
    CCSprite *mFrameAvatarSprite;
    vector<CCSprite*> mAvatarsSprites;
};

AvatarCellView* AvatarCellView::create(const vector<CCSprite *> &pAvatarsSprites,
                                       const int &idx) {
    AvatarCellView* pRet = new AvatarCellView();
    pRet->init(pAvatarsSprites, idx);
    pRet->autorelease();
    
    return pRet;
}

bool AvatarCellView::init(const vector<CCSprite *> &pAvatarsSprites,
                          const int &idx) {
    mAvatarsSprites = pAvatarsSprites;
    return ITableCellView::init(idx);
}

void AvatarCellView::addSprites() {
    for(int i = 0 ; i < 3 ; i++) {
        this->addChild(this->mAvatarsSprites[mIndex*3 + i]);
    }
}

void AvatarCellView::update(const int &idx) {
    ITableCellView::update(idx);
}


AvatarsPopupView::~AvatarsPopupView() {
    SAFE_VECTOR_RELEASE(mAvatarsSprites);
}

AvatarsPopupView* AvatarsPopupView::create(string pBackgroundImage,
                                           string pExitNormalImage,
                                           string pExitSelectedImage) {
    AvatarsPopupView* pRet = new AvatarsPopupView();
    pRet->autorelease();
    pRet->init(pBackgroundImage, pExitNormalImage, pExitSelectedImage);
    
    return pRet;
}
bool AvatarsPopupView::init(string pBackgroundImage,
                            string pExitNormalImage,
                            string pExitSelectedImage) {
    PopUpLayer::init(pBackgroundImage,
                     pExitNormalImage,
                     pExitSelectedImage,
                     GPARAMS().POP_COMMON_EXIT_BUTTON_POSITION);
    setBackgroundPosition(VisibleRect::center());
    
    this->addContainerTable();
    
    return true;
}

void AvatarsPopupView::onExit()
{
    PopUpLayer::onExit();
    
    // update avatar
    SERVER().sendUpdateAvatarRequest(mSelectedAvatarIndex);
    
    if (USERINFO()->getUserAvatarType() != mSelectedAvatarIndex) {
        USERINFO()->setUserAvatarType(mSelectedAvatarIndex);
        CCNotificationCenter::sharedNotificationCenter()->postNotification(NOTIFICATION_GOT_UPDATE_AVATAR,
                                                                           NULL);
    }
}

void AvatarsPopupView::addMenuItems() {
    PopUpLayer::addMenuItems();
    
    //{add_menuitems}
}

void AvatarsPopupView::addSprites() {
	PopUpLayer::addSprites();
	
    this->addAvatarsSprites();
    
	mHeaderSprite = CCSprite::create("avatars_popup/sprites/header.png");
	mHeaderSprite->setPosition(GPARAMS().POP_COMMON_HEADER_POSITION);
	mBackgroundSprite->addChild(mHeaderSprite);
    

}
void AvatarsPopupView::addLabels() {
	PopUpLayer::addLabels();
    //{add_labels}
}
void AvatarsPopupView::addProgressBars() {
	PopUpLayer::addProgressBars();
	
	//{add_progressbars}
}

void AvatarsPopupView::addAvatarsSprites() {
    mAvatarsSprites = vector<CCSprite*>(TOTAL_AVATAR_NUMBER);
    for(int i = 0 ; i < mAvatarsSprites.size() ; i++) {
        mCurrentBackgroundSprite = CCSprite::create("avatars_popup/tables/container/sprites/resources/sprites/current_background.png");
        mUseBackgroundSprite = CCSprite::create("avatars_popup/tables/container/sprites/resources/sprites/use_background.png");
        mUseBackgroundSprite->setPosition(CCPoint(mUseBackgroundSprite->getContentSize().width/2.0f,
                                                  mUseBackgroundSprite->getContentSize().height/2.0f));
        
        mSelectedSprite = CCSprite::create("avatars_popup/tables/container/sprites/resources/sprites/selected.png");
        mSelectedSprite->setPosition(GPARAMS().POP_AVATARS_USE_MENUITEM_POSITION);
        
        mUseMenuitemMenuItem = CCMenuItemSprite::create(CCSprite::create("avatars_popup/tables/container/sprites/resources/menus/use/menuitems/use/sprites/use_normal.png"),
                                                        CCSprite::create("avatars_popup/tables/container/sprites/resources/menus/use/menuitems/use/sprites/use_active.png"),
                                                        this,
                                                        menu_selector(AvatarsPopupView::avatarsMenuItemCallback));
        mUseMenuitemMenuItem->setPosition(GPARAMS().POP_AVATARS_USE_MENUITEM_POSITION);
        mUseMenuitemMenuItem->setTag(i);
        mUseMenu = CCMenu::createWithItem(mUseMenuitemMenuItem);
        mUseMenu->setTouchPriority(kCCMenuHandlerPriority - 102);
        mUseMenu->setAnchorPoint(CCPointZero);
        mUseMenu->setPosition(CCPointZero);
        
        mAvatarsSprites[i] = mCurrentBackgroundSprite;
        mAvatarsSprites[i]->retain();
        mAvatarsSprites[i]->setPosition(GPARAMS().POP_AVATARS_AVATARS_SPRITE_POSITIONS[i]);
        mAvatarsSprites[i]->addChild(mUseBackgroundSprite, 1, 1000);
        mAvatarsSprites[i]->addChild(mSelectedSprite, 2, 1001);
        mAvatarsSprites[i]->addChild(mUseMenu, 3, 1002);
        
        AvatarMenuItem* avatarLayer = AvatarMenuItem::create(USERINFO()->getProfileID(),
                                                             i,
                                                             GPARAMS().CMM_ICON_AVATAR_SIZE,
                                                             GPARAMS().POP_AVATARS_INFRAME_SPRITE_POSITION);
        mAvatarsSprites[i]->addChild(avatarLayer);
        
        // must download manually because it not a menuitem!
        if (i == 0) {
            FBAvatarDownloader::create(USERINFO()->getProfileID(),
                                       kFBAvatarAutoDownload,
                                       avatarLayer,
                                       avatar_selector(AvatarMenuItem::internalAvatarLoadedCallback));
        }
    }
    
    mSelectedAvatarIndex = USERINFO()->getUserAvatarType();
    mAvatarsSprites[mSelectedAvatarIndex]->getChildByTag(1000)->setVisible(false);
    mAvatarsSprites[mSelectedAvatarIndex]->getChildByTag(1002)->setVisible(false);
}

void AvatarsPopupView::addContainerTable() {
    mContainerTable = TableView::create(GPARAMS().POP_AVATARS_CONTAINER_TABLE_SIZE,
                                        3,
                                        3,
                                        GPARAMS().POP_AVATARS_CELL_POSITION,
                                        GPARAMS().POP_AVATARS_CONTAINER_TABLE_CELL_SIZE,
                                        this);
	mContainerTable->setAnchorPoint(CCPoint(0, 1));
    static_cast<TableView*>(mContainerTable)->addToParent(mBackgroundSprite,
                                 GPARAMS().POP_AVATARS_CONTAINER_TABLE_POSITION);
    mContainerTable->setTouchPriority(kCCMenuHandlerPriority - 101);
}

void AvatarsPopupView::avatarsMenuItemCallback(CCObject *pSender)
{
    SOUND().playSound(SOUND_BUTTON_CLICK);

    mAvatarsSprites[mSelectedAvatarIndex]->getChildByTag(1000)->setVisible(true);
    mAvatarsSprites[mSelectedAvatarIndex]->getChildByTag(1002)->setVisible(true);
    
    CCMenuItem* menuItem = static_cast<CCMenuItem*>(pSender);
    mSelectedAvatarIndex = menuItem->getTag();
    mAvatarsSprites[mSelectedAvatarIndex]->getChildByTag(1000)->setVisible(false);
    mAvatarsSprites[mSelectedAvatarIndex]->getChildByTag(1002)->setVisible(false);
}

ITableCellView* AvatarsPopupView::createTableViewCellAt(const int &idx) {
    ITableCellView *cell = AvatarCellView::create(mAvatarsSprites, idx);
    
    return cell;
}

