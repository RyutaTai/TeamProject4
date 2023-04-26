#pragma once

class UI
{
public:
	void init();
	void render(int hp,obj2d* player);
	void update();
	void deinit();
	void setDamageFlag(bool damage);
	void CalcScore();//スコア加算
	void ScoreRender1_();//古い方
	void ScoreRender();//新しい方
	void HpRender(int hp, obj2d* player);//HP描画
private:
	int tx1;
	int tx2;
	int tx3;
	int posx, posy;
	bool damageFlag;
	int score;
};


