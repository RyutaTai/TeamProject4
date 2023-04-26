#include "all.h"

//�X�R�A�\��(�e�L�X�g��)
#include <sstream>
#include <iomanip>

//�X�R�A�\��(�摜�؂�o��)
#include<math.h>
#include<stdlib.h>


Sprite* HP[3];

const int HP_ANIME_MAX = 8;//hp�摜�̃R�}���̍ő�
const int HP_MAX = 3;
const int hp_width = 103;//�摜1�R�}���Ƃ̉���
int HpCount1;//HP�̉摜�̉��R�}�ڂ�
int HpCount2;
int HpCount3;
//int lostHP = 0;

//�X�R�A�p�ϐ�
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
	//HP�̐������`��
	//for (int count = hp; count >= 0; count--)//hp�̐��������[�v	
	//{
	//	if (damageFlag) {	//�_���[�W���󂯂Ă�����
	//		//�����Ă����n�[�g�̕`��
	//		for (int hpCopy = hp; tx < 800;) {
	//			if (timer % 60 == 0) {
	//				tx += 100;
	//				if (tx >= 800) { tx = 800; }
	//				sprite_render(HP[count - 1], posx, posy, 1, 1, tx, 0, 100, 100, 0, 0);
	//			}
	//		}
	//		//�����Ă��Ȃ��n�[�g�̕`��
	//		sprite_render(HP[count - 2], posx, posy, 1, 1, 0, 0, 100, 100, 0, 0);
	//		posx += 103;
	//	}
	//	
	//	else {//�_���[�W���󂯂Ă��Ȃ�
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
	//for (int count = 0 ; hp > count; count++)//hp�̐��������[�v(0->1->2�̏�)
	//{
	//	if (count > 2)break;
	//	sprite_render(HP[count], posx, posy, 1, 1, tx0, 0, 100, 100, 0, 0);
	//	posx += hp_width;
	//}


	if (damageFlag) {
		//�E�[
		if (HpCount1 < HP_ANIME_MAX) {
			HpCount1++; tx1 += 100; 
		}
		else if(HpCount1 == HP_ANIME_MAX) { 
			HpCount1 = HP_ANIME_MAX+1; tx1 = 800; setDamageFlag(false);
		}
		//����
		else if (HpCount2 < HP_ANIME_MAX && HpCount1 > HP_ANIME_MAX) {
			HpCount2++; tx2 += 100;
		}
		else if (HpCount2 == HP_ANIME_MAX) { 
			HpCount2 = HP_ANIME_MAX+1; tx2 = 800; setDamageFlag(false);
		}
		//���[
		else if (HpCount3 < HP_ANIME_MAX && HpCount2 > HP_ANIME_MAX) {
			HpCount3++; tx3 += 100;
		}
	    else if (HpCount3 == HP_ANIME_MAX) { 
			HpCount3 = HP_ANIME_MAX+1; tx3 = 800; setDamageFlag(false);
		}
	}
	
	sprite_render(HP[2], 2 * hp_width, posy, 1, 1, tx1, 0, 100, 100, 0, 0);//�E�[
	sprite_render(HP[1], 1 * hp_width, posy, 1, 1, tx2, 0, 100, 100, 0, 0);//����
	sprite_render(HP[0], 0 * hp_width, posy, 1, 1, tx3, 0, 100, 100, 0, 0);//���[
	


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

void UI::ScoreRender()//�ő�9999(�S��)�ɂ���
{
	//��̈�
	sprite_render(sprnum,
		numPosx - 116, numPosy,//�`��ʒu
		0.8f, 0.8f,				   //�X�P�[��
		(score/1000)*100, 0,			       //���`��ʒu
		100, 100, 				   //���摜�̕��A����
		1, 1					   //���摜�̊�_
	);

	//�S�̈�
	sprite_render(sprnum,
		numPosx - 78, numPosy,//�`��ʒu
		0.8f, 0.8f,				   //�X�P�[��
		(score%1000/100)*100, 0,			       //���`��ʒu
		100, 100, 				   //���摜�̕��A����
		1, 1					   //���摜�̊�_
	);

	//�\�̈�
	sprite_render(sprnum,
		numPosx - 40, numPosy,//�`��ʒu
		0.8f, 0.8f,				   //�X�P�[��
		(score%100/10)*100, 0,			       //���`��ʒu
		100, 100, 				   //���摜�̕��A����
		1, 1					   //���摜�̊�_
	);

	//��̈�
	sprite_render(sprnum,
		numPosx - 2, numPosy,//�`��ʒu
		0.8f, 0.8f,				   //�X�P�[��
		(score%10)*100, 0,			       //���`��ʒu
		100, 100, 				   //���摜�̕��A����
		1, 1					   //���摜�̊�_
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
	if (score > 9999)score = 9999;//�ő�9999(�S��)
}