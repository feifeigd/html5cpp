
#include <engine.core.h>

using engine::resource::Context;
using engine::resource::HTMLCanvas;

std::string HTMLCanvas::TYPE2D		= "2D";
std::string HTMLCanvas::TYPE3D		= "3D";
std::string HTMLCanvas::TYPEAUTO	= "AUTO";

std::function<Context*(std::string const& contextID)> HTMLCanvas::_createContext;

HTMLCanvas::HTMLCanvas(std::string const& type)
	: _is2D(false)
	, _ctx(nullptr)
{
	if(0){
	}else{
	}
	getContext = [](std::string const& contextID)->Context*{return nullptr;};
}

HTMLCanvas* HTMLCanvas::create(std::string const& type){
	return new HTMLCanvas(type);
}
