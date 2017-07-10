
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

void func();	// 库的声明

void loadCallback(int a)
{
	func();	// 测试调用自定义库代码
	gameInstance = new Game;
	console.log("loadCallback!", a);
	//console.log("b=", b[0]);
}

class A{
public:
	String const& str;
	int b;
	A(String const& s, int b): str(s){this->b = b;}
};

void webMain(){	
	A c("fffffff", 888888888);
	console.log("Hello World Wide Web!");
	console.log(c.str, c.b);
	//char buf[256];
	//sprintf(buf, "%s=%d", "aaaaaaaa", 666);
	//puts(buf);
	document.addEventListener("DOMContentLoaded", cheerp::Callback(loadCallback));
	//std::cout << "webMain函数结束，代码仍然继续运行" << std::endl;
}
