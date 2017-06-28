
#include <engine.core.h>

using engine::resource::Bitmap;

Bitmap::Bitmap()
	: _w(0), _h(0), _source(nullptr)
{

}

void Bitmap::copyTo(Bitmap& dec){
	dec._source = _source;
	dec._w = _w;
	dec._h = _h;
}

void Bitmap::dispose(){
	//this._resourceManager.removeResource(this);
	//Resource::dispose();
}
