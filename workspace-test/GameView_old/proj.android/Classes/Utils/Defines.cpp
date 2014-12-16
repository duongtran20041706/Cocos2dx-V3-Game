//
//  Defines.cpp
//  DragonVideoPoker
//
//  Created by Ta Van Dung on 6/4/14.
//
//

#include "Defines.h"

Defines::Defines()
{
    //id.defineCommon();
}

Id Defines::id;

Id::Id() {
    defineCommon();
}

void Id::defineCommon() {
    jackpot_popup_background_container          = "jackpot_popup/background/container.png";
	jackpot_popup_chips                         = "jackpot_popup/sprites/chips.png";
	jackpot_popup_jackpot_text                  = "jackpot_popup/sprites/jackpot_text.png";
	jackpot_popup_reward_icon                   = "jackpot_popup/sprites/reward_icon.png";
	jackpot_popup_shine_circle                  = "jackpot_popup/sprites/shine_circle.png";
	jackpot_popup_star_shine                    = "jackpot_popup/sprites/star_shine.png";
    jackpot_popup_ok_ok_active                  = "common_ok_active.png";
    jackpot_popup_ok_ok_normal                  = "common_ok_normal.png";
    jackpot_popup_share_share_active            = "common_share_active.png";
    jackpot_popup_share_share_normal            = "common_share_normal.png";
    jackpot_popup_small_star                    = "common_pop_star_small.png";
    jackpot_popup_big_star                      = "common_pop_star_big.png";

	
	/**
	* VipUpgradePopupView image ids init
	* by apple
	*/
	vip_upgrade_popup_background_container		= "vip_upgrade_popup/background/container.png";
	vip_upgrade_popup_member_cards[0]           = "common_vip_card_sprite_0_big.png";
    vip_upgrade_popup_member_cards[1]           = "common_vip_card_sprite_1_big.png";
    vip_upgrade_popup_member_cards[2]           = "common_vip_card_sprite_2_big.png";
    vip_upgrade_popup_member_cards[3]           = "common_vip_card_sprite_3_big.png";
    vip_upgrade_popup_member_cards[4]           = "common_vip_card_sprite_4_big.png";
    vip_upgrade_popup_member_cards[5]           = "common_vip_card_sprite_5_big.png";
	vip_upgrade_popup_reward_icon               = "vip_upgrade_popup/sprites/reward_icon.png";
	vip_upgrade_popup_shine                     = "jackpot_popup/sprites/shine_circle.png";
	vip_upgrade_popup_star1                     = "common_pop_star_big.png";
	vip_upgrade_popup_star2                     = "common_pop_star_big.png";
	vip_upgrade_popup_vip_level_ribbon          = "vip_upgrade_popup/sprites/vip_level_ribbon.png";
	vip_upgrade_popup_ok_ok_active              = "common_ok_active.png";
	vip_upgrade_popup_ok_ok_normal              = "common_ok_normal.png";
	vip_upgrade_popup_share_share_active		= "common_share_active.png";
	vip_upgrade_popup_share_share_normal		= "common_share_normal.png";

	
	/**
	* LevelupPopupView image ids init
	* by apple
	*/
	levelup_popup_background_level		= "levelup_popup/background/level.png";
	levelup_popup_circle_container_1		= "levelup_popup/sprites/circle_container_1.png";
	levelup_popup_circle_container_2		= "levelup_popup/sprites/circle_container_2.png";
	levelup_popup_ribbon		= "levelup_popup/sprites/ribbon.png";
	levelup_popup_shine_circle		= "levelup_popup/sprites/shine_circle.png";
	levelup_popup_star1		= "levelup_popup/sprites/star1.png";
	levelup_popup_star2		= "levelup_popup/sprites/star2.png";
	levelup_popup_star3		= "levelup_popup/sprites/star3.png";
	levelup_popup_star_shine		= "levelup_popup/sprites/star_shine.png";
	levelup_popup_ok_ok_active		= "common_ok_active.png";
	levelup_popup_ok_ok_normal		= "common_ok_normal.png";
	levelup_popup_share_share_active		= "common_share_active.png";
	levelup_popup_share_share_normal		= "common_share_normal.png";

	//don't modify or delete this line
}
