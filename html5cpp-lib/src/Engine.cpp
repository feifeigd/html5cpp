#include <engine.core.h>

using engine::utils::Browser;

Engine::Engine()
	: is3DMode(false)
	, version("0.9.9")
{

}

Engine& Engine::instance(){
	static Engine e;
	return e;
}

void Engine::alertGlobalError(bool value){
	//if(value)
	__asm__(
		"var erralert=0;"		
		"window.onerror=function (msg,url,line,column,detail){"
			"if (erralert++< 5 && detail)"
				"alert(\"出错啦，请把此信息截图给研发商\\n\"+msg+\"\\n\"+detail.stack);"
		"}"
		);
	//else __asm__("window.onerror=null");
}

void Engine::init(short width, short height){
	Browser::__init__();
	//Font::__init__();
}

void Engine::initAsyn(){

}
