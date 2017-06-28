#pragma once

#include "engine/display/Stage.h"
#include "engine/utils/Timer.h"
#include "engine/net/LoaderManager.h"
#include "engine/renders/Render.h"

class Engine{
	Engine();
public:
	static Engine& instance();

	/**舞台信息*/
	engine::display::Stage stage;
	/**时间管理器*/
	engine::utils::Timer timer;
	/**加载管理器*/
	engine::net::LoaderManager loader;
	/**Render类*/
	engine::renders::Render* render;
	/**引擎版本*/
	std::string version;
	/**是否是3d模式*/
	bool is3DMode;

	/**
     * 初始化引擎
     * @param    width 游戏窗口宽度
     * @param    height    游戏窗口高度
     */
	void init(short width, short height);
	/**初始化异步函数调用*/
protected:
	void initAsyn();
public:
	/**是否捕获全局错误并弹出提示*/
	void alertGlobalError(bool value);
};

#define _G Engine::instance()
