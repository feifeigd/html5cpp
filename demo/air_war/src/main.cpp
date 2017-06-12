
#include "Game.h"
#include <cheerp/client.h>
#include <cheerp/clientlib.h>
#include <cheerp/webgl.h>
#include <iostream>

// JS的函数直接声明在namespace client里面就行
namespace client{
	
}

using namespace client;

Game* gameInstance;

void func();

void loadCallback()
{
	func();
	gameInstance = new Game;
	console.log("loadCallback!");
}

void webMain(){
	console.log("Hello World Wide Web!");
	//char buf[256];
	//sprintf(buf, "%s=%d", "aaaaaaaa", 666);
	//puts(buf);
	document.addEventListener("DOMContentLoaded", cheerp::Callback(loadCallback));
	//std::cout << "webMain函数结束，代码仍然继续运行" << std::endl;
}
