//
//  AvatarMenuItem.cpp
//  Dragon Poker
//
//  Created by Nguyen Tien Thanh on 9/11/13.
//
//

#include "AvatarMenuItem.h"
#include "GameParams.h"
#include "FBAvatarDownloader.h"

#include "UserInfo.h"
#include "BaseUserInfo.h"


AvatarMenuItem::~AvatarMenuItem()
{
}

AvatarMenuItem * AvatarMenuItem::create(const char* memeberID,
                                        long avatarType,
                                        CCSize avatarSize,
                                        CCPoint avatarPos)
{
    AvatarMenuItem *pRet = new AvatarMenuItem();
    pRet->initWithPos(memeberID,
                      avatarType,
                      avatarSize,
                      avatarPos);
    pRet->autorelease();
    
    return pRet;
}

bool AvatarMenuItem::initWithPos(const char* memeberID,
                                 long avatarType,
                                 CCSize avatarSize,
                                 CCPoint avatarPos)
{
    delegate = NULL;

    mMemberID = string(memeberID);
    mAvatarPos = avatarPos;
    mAvatarSize = avatarSize;
    
    mAvatarType = avatarType;
    if (mAvatarType >= TOTAL_AVATAR_NUMBER) {
        mAvatarType = 0;
    }
    
    // create default avatarName
    CCString *defaultAvatarName = CCString::createWithFormat("avatar_%ld.png",
                                                             mAvatarType);
    int size = (int)mAvatarSize.height;
    CCString *avatarFrameName = CCString::createWithFormat("avatar_inframe_%d.png", size);
    CCSprite *avatarFrame = CCSprite::create(avatarFrameName->getCString());

    // create avatar menu item
    CCSprite *normalSprite = CCSprite::create(defaultAvatarName->getCString());
    normalSprite->setScale((float)mAvatarSize.width / normalSprite->getContentSize().width);
    CCSprite *normalSprite2 = maskedSprites(normalSprite, avatarFrame);

    CCSprite *selectSprite = CCSprite::create(defaultAvatarName->getCString());
    selectSprite->setScale((float)mAvatarSize.width / selectSprite->getContentSize().width);
    CCSprite *selectSprite2 = maskedSprites(selectSprite, avatarFrame);

    this->initWithNormalSprite(normalSprite2,
                               selectSprite2,
                               NULL,
                               this,
                               menu_selector(AvatarMenuItem::menuSelectAvatarCallback));
    ((CCSprite *)this->getSelectedImage())->setColor(ccGRAY);
    this->setPosition(mAvatarPos);
    
    if (mAvatarType == 0) {
        this->scheduleOnce(schedule_selector(AvatarMenuItem::autoDownloadAvatar), 0.15f);
    }
    
    return true;
}

void AvatarMenuItem::autoDownloadAvatar(float dt)
{
    // auto download avatar if need
    FBAvatarDownloader::create(mMemberID.c_str(),
                               kFBAvatarAutoDownload,
                               this,
                               avatar_selector(AvatarMenuItem::internalAvatarLoadedCallback));
}

void AvatarMenuItem::updatePosition(CCPoint avatarPos)
{
    this->setPosition(avatarPos);
}

void AvatarMenuItem::updateAvatarWithUserInfo(UserInfo* userInfo)
{
    mMemberID = string(userInfo->getProfileID());
    mAvatarType = userInfo->getUserAvatarType();
    if (mAvatarType >= TOTAL_AVATAR_NUMBER) {
        mAvatarType = 0;
    }

    // create default avatarName
    CCString *defaultAvatarName = CCString::createWithFormat("avatar_%ld.png",
                                                             mAvatarType);
    int size = (int)mAvatarSize.height;
    CCString *avatarFrameName = CCString::createWithFormat("avatar_inframe_%d.png", size);
    CCSprite *avatarFrame = CCSprite::create(avatarFrameName->getCString());
    
    // create avatar menu item
    CCSprite *normalSprite = CCSprite::create(defaultAvatarName->getCString());
    normalSprite->setScale((float)mAvatarSize.width / normalSprite->getContentSize().width);
    CCSprite *normalSprite2 = maskedSprites(normalSprite, avatarFrame);
    
    CCSprite *selectSprite = CCSprite::create(defaultAvatarName->getCString());
    selectSprite->setScale((float)mAvatarSize.width / selectSprite->getContentSize().width);
    CCSprite *selectSprite2 = maskedSprites(selectSprite, avatarFrame);
    
    this->setNormalImage(normalSprite2);
    this->setSelectedImage(selectSprite2);
    
    if (mAvatarType == 0) {
        this->scheduleOnce(schedule_selector(AvatarMenuItem::autoDownloadAvatar), 0.15f);
    }
}

#pragma mark - (C) Callback functions

void AvatarMenuItem::internalAvatarLoadedCallback(CCSprite* avatarPhoto, CCObject* sender)
{
    // this item is no longer available
    if (this->retainCount() <= 0 || this->getParent() == NULL) {
        if (sender != NULL) {
            sender->release();
        }
        return;
    }
    
    CCSprite* selectedImage = CCSprite::createWithTexture(avatarPhoto->getTexture());
    selectedImage->setColor(ccGRAY);
    
    // scale this photo
    float scaleFactor = CCDirector::sharedDirector()->getContentScaleFactor();
    float imageSize = mAvatarSize.width * scaleFactor;
    avatarPhoto->setScale(imageSize/GPARAMS().CMM_ICON_FB_SIZE.width);
    selectedImage->setScale(imageSize/GPARAMS().CMM_ICON_FB_SIZE.width);
    
    int size = (int)mAvatarSize.height;
    CCString *avatarFrameName = CCString::createWithFormat("avatar_inframe_%d.png", size);
    CCSprite *avatarFrame = CCSprite::create(avatarFrameName->getCString());

    avatarPhoto = maskedSprites(avatarPhoto, avatarFrame);
    selectedImage = maskedSprites(selectedImage, avatarFrame);

    // Update to menu item
    this->setNormalImage(avatarPhoto);
    this->setSelectedImage(selectedImage);
    
    // delete sender if need
    if (sender != NULL) {
        sender->release();
    }
}

void AvatarMenuItem::menuSelectAvatarCallback(CCObject *pSender)
{
    if (delegate != NULL) {
        delegate->selectAvatarCallback(mMemberID.c_str());
    }
}

CCSprite* AvatarMenuItem::maskedSprites(CCSprite *textureSprite, CCSprite *maskSprite)
{
    // 1
    CCRenderTexture * rt = CCRenderTexture::create(maskSprite->getContentSize().width * 1,
                                                   maskSprite->getContentSize().height * 1);
    
    //    rt->setPosition(ccp(200, 200));
    // 2
    //    maskSprite->setPosition(ccp(200, 200));
    //    textureSprite->setPosition(ccp(200, 200));
    maskSprite->setPosition(ccp(maskSprite->getContentSize().width / 2,
                                maskSprite->getContentSize().height / 2));
    textureSprite->setPosition(ccp(maskSprite->getContentSize().width / 2,
                                   maskSprite->getContentSize().height / 2));
    
    // 3
    ccBlendFunc someBlends;
    someBlends.src = GL_ONE;
    someBlends.dst = GL_ZERO;
    maskSprite->setBlendFunc(someBlends);
    
//    maskSprite->setBlendFunc((ccBlendFunc){GL_ONE, GL_ZERO});
    textureSprite->setBlendFunc((ccBlendFunc){GL_DST_ALPHA, GL_ZERO});
    
    // 4
    rt->begin();
    maskSprite->visit();
    textureSprite->visit();
    rt->end();
    
    // 5
    CCSprite *retval = CCSprite::createWithTexture(rt->getSprite()->getTexture());
    retval->setFlipY(true);
    return retval;
}
