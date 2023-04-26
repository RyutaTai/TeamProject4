#include "all.h"

//スコア表示(テキストで)
#include <sstream>
#include <iomanip>

//スコア表示(画像切り出し)
#include<math.h>
#include<stdlib.h>


Sprite* HP[3];

const int HP_ANIME_MAX = 8;//hp画像のコマ数の最大
const int HP_MAX = 3;
const int hp_width = 103;//画像1コマごとの横幅
int HpCount1;//HPの画像の何コマ目か
int HpCount2;
int HpCount3;
//int lostHP = 0;

//スコア用変数
Sprite* sprnum;
int numPosx = 1150;
int numPosy = 10;

void UI::init()
{
	for (int i = 0; i < HP_MAX; i++)
	{
		HP[i] = sprite_load(L"./Data/Images/hp.png");
	}
	sprnum = sprite_load(L"./Data/Images/number2.png");
	tx1 = 0;
	tx2 = 0;
	tx3 = 0;
	posx = 0;
	posy = 5;
	damageFlag = false;
	score = 0;

}

void UI::update()
{
	
}

void UI::render(int hp, obj2d* player)
{
	HpRender(hp, player);
	ScoreRender();
}

void UI::HpRender(int hp,obj2d* player)
{
	posx = 0;
	//HPの数だけ描画
	//for (int count = hp; count >= 0; count--)//hpの数だけループ	
	//{
	//	if (damageFlag) {	//ダメージを受けていたら
	//		//減っていくハートの描画
	//		for (int hpCopy = hp; tx < 800;) {
	//			if (timer % 60 == 0) {
	//				tx += 100;
	//				if (tx >= 800) { tx = 800; }
	//				sprite_render(HP[count - 1], posx, posy, 1, 1, tx, 0, 100, 100, 0, 0);
	//			}
	//		}
	//		//減っていないハートの描画
	//		sprite_render(HP[count - 2], posx, posy, 1, 1, 0, 0, 100, 100, 0, 0);
	//		posx += 103;
	//	}
	//	
	//	else {//ダメージを受けていない
	//		tx = 0;
	//		sprite_render(HP[count - 1], posx, posy, 1, 1, 0, 0, 100, 100, 0, 0);
	//		posx += 103;
	//	}
	//}

	
	/*if (damageFlag) {
		posx = 103;
		tx1 += 100;
		HpCount1++;
		sprite_render(HP[2], posx, posy, 1, 1, tx1, 0, 100, 100, 0, 0);
		if (HpCount1 == HP_ANIME_MAX){ HpCount1 == HP_ANIME_MAX; }
		posx += 103;
		setDamageFlag(false);
	}
	if (damageFlag) {
		tx2 += 100;
		HpCount2++;
		sprite_render(HP[1], posx, posy, 1, 1, tx2, 0, 100, 100, 0, 0);
		if (HpCount2 == HP_ANIME_MAX) { HpCount2 == HP_ANIME_MAX; }
		posx += 103;
		setDamageFlag(false);
	}
	if (damageFlag) {
		tx3 += 100;
		HpCount3++;
		sprite_render(HP[0], posx, posy, 1, 1, tx3, 0, 100, 100, 0, 0);
		if (HpCount3 == HP_ANIME_MAX) { HpCount3 == HP_ANIME_MAX; }
		posx += 103;
		setDamageFlag(false);
	}*/
	//for (int count = 0 ; hp > count; count++)//hpの数だけループ(0->1->2の順)
	//{
	//	if (count > 2)break;
	//	sprite_render(HP[count], posx, posy, 1, 1, tx0, 0, 100, 100, 0, 0);
	//	posx += hp_width;
	//}


	if (damageFlag) {
		//右端
		if (HpCount1 < HP_ANIME_MAX) {
			HpCount1++; tx1 += 100; 
		}
		else if(HpCount1 == HP_ANIME_MAX) { 
			HpCount1 = HP_ANIME_MAX+1; tx1 = 800; setDamageFlag(false);
		}
		//中央
		else if (HpCount2 < HP_ANIME_MAX && HpCount1 > HP_ANIME_MAX) {
			HpCount2++; tx2 += 100;
		}
		else if (HpCount2 == HP_ANIME_MAX) { 
			HpCount2 = HP_ANIME_MAX+1; tx2 = 800; setDamageFlag(false);
		}
		//左端
		else if (HpCount3 < HP_ANIME_MAX && HpCount2 > HP_ANIME_MAX) {
			HpCount3++; tx3 += 100;
		}
	    else if (HpCount3 == HP_ANIME_MAX) { 
			HpCount3 = HP_ANIME_MAX+1; tx3 = 800; setDamageFlag(false);
		}
	}
	
	sprite_render(HP[2], 2 * hp_width, posy, 1, 1, tx1, 0, 100, 100, 0, 0);//右端
	sprite_render(HP[1], 1 * hp_width, posy, 1, 1, tx2, 0, 100, 100, 0, 0);//中央
	sprite_render(HP[0], 0 * hp_width, posy, 1, 1, tx3, 0, 100, 100, 0, 0);//左端
	


}

void UI::ScoreRender1_()
{
	std::ostringstream ss;
	ss << "SCORE:" << std::setw(8) << std::setfill('0') << score;
	const VECTOR2 center{
	 window::getWidth() * 0.5f,
	 window::getHeight() * 0.5f,
	};
	font::textOut(4, ss.str(), { 1050,40 }, { 1.5,1.5 }, { 1,1,1,1 }, TEXT_ALIGN::MIDDLE);
}

void UI::ScoreRender()//最大9999(４桁)にする
{
	//千の位
	sprite_render(sprnum,
		numPosx - 116, numPosy,//描画位置
		0.8f, 0.8f,				   //スケール
		(score/1000)*100, 0,			       //元描画位置
		100, 100, 				   //元画像の幅、高さ
		1, 1					   //元画像の基準点
	);

	//百の位
	sprite_render(sprnum,
		numPosx - 78, numPosy,//描画位置
		0.8f, 0.8f,				   //スケール
		(score%1000/100)*100, 0,			       //元描画位置
		100, 100, 				   //元画像の幅、高さ
		1, 1					   //元画像の基準点
	);

	//十の位
	sprite_render(sprnum,
		numPosx - 40, numPosy,//描画位置
		0.8f, 0.8f,				   //スケール
		(score%100/10)*100, 0,			       //元描画位置
		100, 100, 				   //元画像の幅、高さ
		1, 1					   //元画像の基準点
	);

	//一の位
	sprite_render(sprnum,
		numPosx - 2, numPosy,//描画位置
		0.8f, 0.8f,				   //スケール
		(score%10)*100, 0,			       //元描画位置
		100, 100, 				   //元画像の幅、高さ
		1, 1					   //元画像の基準点
	);

}

void UI::deinit()
{
	for (int i = 0; i < HP_MAX; i++)
	{
		safe_delete(HP[i]);
	}
	safe_delete(sprnum);
}

void UI::setDamageFlag(bool damage)
{
	damageFlag = damage;
}

void UI::CalcScore()
{
	score += 100;
	if (score > 9999)score = 9999;//最大9999(４桁)
}