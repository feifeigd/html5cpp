#pragma once

#include <cheerp/clientlib.h>
using namespace client;

#include <functional>
#include <string>

#include "Engine.h"
#include "engine/utils/Color.h"
#include "engine/display/css/Font.h"
#include "engine/display/Sprite.h"
#include "engine/utils/Handler.h"
//#include "engine/events/EventDispatcher.h"
//#include "engine/resource/Resource.h"
//#include "engine/resource/Bitmap.h"
//#include "engine/resource/Context.h"
#include "engine/resource/HTMLCanvas.h"
#include "engine/utils/Browser.h"
#include "engine/utils/RunDriver.h"


/// 缩短名字
namespace engine{
	class Font : public display::css::Font{};
	class Sprite : public display::Sprite{};
}
