#include <engine.core.h>

using engine::utils::Browser;
using engine::resource::HTMLCanvas;

HTMLCanvas* Browser::canvas = nullptr;

void Browser::__init__(){
	if(Browser::canvas)return;
	Browser::canvas = HTMLCanvas::create("2D");
}

client::Window& Browser::window(){
	return client::window;
}
