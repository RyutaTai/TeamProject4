#pragma once

class UI
{
public:
	void init();
	void render(int hp,obj2d* player);
	void update();
	void deinit();
	void setDamageFlag(bool damage);
	void CalcScore();//�X�R�A���Z
	void ScoreRender1_();//�Â���
	void ScoreRender();//�V������
	void HpRender(int hp, obj2d* player);//HP�`��
private:
	int tx1;
	int tx2;
	int tx3;
	int posx, posy;
	bool damageFlag;
	int score;
};


