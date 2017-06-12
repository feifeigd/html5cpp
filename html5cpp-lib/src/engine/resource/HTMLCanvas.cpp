
#include <engine.core.h>

using engine::resource::HTMLCanvas;

std::string HTMLCanvas::TYPE2D = "2D";
std::string HTMLCanvas::TYPE3D = "3D";
std::string HTMLCanvas::TYPEAUTO = "AUTO";

HTMLCanvas::HTMLCanvas(std::string const& type)
	: _is2D(false)
{

}

HTMLCanvas* HTMLCanvas::create(std::string const& type){
	return new HTMLCanvas(type);
}
