//
//  EziFacebookUser.cpp
//  EziSocial
//
//  Created by Paras Mendiratta on 17/05/13.
//  Copyright @EziByte 2013 (http://www.ezibyte.com)
//
//  Version 1.2 (Dt: 30-May-2013)
//
/***
 
 This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.
 
 Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:
 
 1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
 
 2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
 
 3. This notice may not be removed or altered from any source distribution.
 
 */
#include "EziSocialDefinition.h"
#include "EziFacebookUser.h"
#include "cocos2d.h"

USING_NS_CC;

EziFacebookUser::EziFacebookUser()
{
    fullname        = "";
    username        = "";
    firstName       = "";
    lastName        = "";
    profileID       = "";
    hometown        = "";
    presentLocation = "";
    accessToken     = "";
    emailID         = "";
    gender          = "";
    userPhotoPath   = NULL;
    userFriends     = NULL;
}

EziFacebookUser:: ~EziFacebookUser()
{
    
}

EziFacebookUser* EziFacebookUser::create()
{
    EziFacebookUser* fbUser = new EziFacebookUser();
    if (fbUser)
    {
        fbUser->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(fbUser);
        return NULL;
    }
    
    return fbUser;
}

void EziFacebookUser::saveData(const char* key, std::string dataValue)
{
    if (strcmp(key, KEY_FB_USER_NAME) == 0)
    {
        this->username = dataValue;
    }
    else if (strcmp(key, KEY_FB_USER_ACCESS_TOKEN) == 0)
    {
        this->accessToken = dataValue;
    }
    else if (strcmp(key, KEY_FB_USER_EMAIL) == 0)
    {
        this->emailID = dataValue;
    }
    else if (strcmp(key, KEY_FB_USER_FIRST_NAME) == 0)
    {
        this->firstName = dataValue;
    }
    else if (strcmp(key, KEY_FB_USER_GENDER) == 0)
    {
        this->gender = dataValue;
    }
    else if (strcmp(key, KEY_FB_USER_HOMETOWN) == 0)
    {
        this->hometown = dataValue;
    }
    else if (strcmp(key, KEY_FB_USER_LAST_NAME) == 0)
    {
        this->lastName = dataValue;
    }
    else if (strcmp(key, KEY_FB_USER_PROFILE_ID) == 0)
    {
        this->profileID = dataValue;
    }
    else if (strcmp(key, KEY_FB_USER_PRESENT_LOCATION) == 0)
    {
        this->presentLocation = dataValue;
    }
    else
    {
        CCLOG("Unrecognized Key while saving the user data.");
    }
        
}

const char* EziFacebookUser::getUserName()
{
    return username.c_str();
}

const char* EziFacebookUser::getFirstName()
{
    return firstName.c_str();
}

const char* EziFacebookUser::getLastName()
{
    return lastName.c_str();
}

const char* EziFacebookUser::getProfileID()
{
    return profileID.c_str();
}

const char* EziFacebookUser::getHomeTown()
{
    return hometown.c_str();
}

const char* EziFacebookUser::getPresentLocation()
{
    return presentLocation.c_str();
}

const char* EziFacebookUser::getAccessToken()
{
    return accessToken.c_str();
}

const char* EziFacebookUser::getEmailID()
{
    return emailID.c_str();
}

const char* EziFacebookUser::getGender()
{
    return gender.c_str();
}

const char* EziFacebookUser::getFullName()
{
    if (fullname.compare("") == 0)
    {
        // Full name is not available. So join first name and last name and return it.
        fullname = firstName.append(" ").append(lastName);
    }
    
    return fullname.c_str();
}

const char* EziFacebookUser::getUserFriends()
{
    if (userFriends == NULL || userFriends->compare("") == 0)
    {
        // Friends are not available
        return NULL;
    }
    else {
        return userFriends->c_str();
    }
}

void EziFacebookUser::setUserPhotoPath(const char * photoPath)
{
    std::string str = std::string(photoPath);
    this->userPhotoPath = new std::string(photoPath);
}

void EziFacebookUser::saveUserFriends(const char *friends)
{
    this->userFriends = new std::string(friends);
}

const char* EziFacebookUser::getPhotoPath()
{
    if (userPhotoPath == NULL || userPhotoPath->compare("") == 0)
    {
        // Friends are not available
        return NULL;
    }
    else {
        return userPhotoPath->c_str();
    }
}

CCObject* EziFacebookUser::copyWithZone(CCZone *pZone)
{
        
    CCZone* pNewZone = NULL;
    EziFacebookUser* pCopy = NULL;
    if(pZone && pZone->m_pCopyObject)
    {
        //in case of being called at sub class
        pCopy = (EziFacebookUser*)(pZone->m_pCopyObject);
    }
    else
    {
        pCopy = new EziFacebookUser();
        pNewZone = new CCZone(pCopy);
    }
    
    pCopy->saveData(KEY_FB_USER_NAME, getUserName());
    pCopy->saveData(KEY_FB_USER_FIRST_NAME, getFirstName());
    pCopy->saveData(KEY_FB_USER_LAST_NAME, getLastName());
    pCopy->saveData(KEY_FB_USER_PROFILE_ID, getProfileID());
    pCopy->saveData(KEY_FB_USER_HOMETOWN, getHomeTown());
    pCopy->saveData(KEY_FB_USER_PRESENT_LOCATION, getPresentLocation());
    pCopy->saveData(KEY_FB_USER_ACCESS_TOKEN, getAccessToken());
    pCopy->saveData(KEY_FB_USER_EMAIL, getEmailID());
    pCopy->saveData(KEY_FB_USER_GENDER, getGender());
    pCopy->setUserPhotoPath(getPhotoPath());
    
    
    //pCopy->initWithAction((CCActionInterval *)(m_pInner->copy()->autorelease()));
    
    CC_SAFE_DELETE(pNewZone);
    return pCopy;
}