#pragma once
#include <cheerp/clientlib.h>
using namespace client;
//#include <engine.core.h>

class Role;

class Game{
public:
	Game();

	//定义英雄（主战斗机）
private:
	Role* hero;
	//子弹发射偏移位置表
	/*private bulletPos: Array<Array<number>> = [[0], [-15, 15], [-30, 0, 30], [-45, -15, 15, 45]];
	//关卡等级
	private level: number = 0;
	//积分成绩
	private score: number = 0;
	//升级等级所需的成绩数量
	private levelUpScore: number = 10;
	//子弹级别
	private bulletLevel: number = 0;
	//敌机被击半径表
	private radius: Array<number> = [18, 33, 80];
	//游戏角色容器
	private roleBox: Laya.Sprite;
	//游戏信息UI
	private gameInfo: GameInfo;*/
private:
	Object* showApe();

	void onLoaded();
};
