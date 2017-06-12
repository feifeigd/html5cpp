#pragma once

class Engine{

public:
	static Engine& instance();

	/**
     * 初始化引擎
     * @param    width 游戏窗口宽度
     * @param    height    游戏窗口高度
     */
	void init(short width, short height);

};

#define _G Engine::instance()
