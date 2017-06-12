#include <engine.core.h>

using engine::utils::Browser;

Engine& Engine::instance(){
	static Engine e;
	return e;
}

void Engine::init(short width, short height){
	Browser::__init__();
}
