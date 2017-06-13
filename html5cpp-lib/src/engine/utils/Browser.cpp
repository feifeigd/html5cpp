#include <engine.core.h>

using engine::utils::Browser;
using engine::resource::Context;
using engine::resource::HTMLCanvas;

HTMLCanvas* Browser::canvas = nullptr;
Context* Browser::ctx = nullptr;
void* Browser::_pixelRatio = nullptr;

int Browser::height(){
	Browser::__init__();
	//_G.stage
	return 0;
}

void Browser::__init__(){
	if(Browser::canvas)return;
	Browser::canvas = HTMLCanvas::create("2D");
	Browser::ctx = Browser::canvas->getContext("2d");
}

client::Object* Browser::createElement(std::string const&type){
	return nullptr;
}

client::Window& Browser::window(){
	return client::window;
}
