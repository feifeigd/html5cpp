#include <engine.core.h>

//using engine::events::Event;
namespace engine{namespace events{

Event::Event()
	: _stoped(false), touchId(0), nativeEvent(nullptr), target(nullptr), currentTarget(nullptr)
{
	//this.type=null;
}

Event& Event::setTo(String const& type, engine::display::Sprite* currentTarget, engine::display::Sprite* target){
	this->type = type;
	this->currentTarget = currentTarget;
	this->target = target;
	return *this;
}

void Event::stopPropagation(){
	_stoped=true;
}

bool Event::shiftKey()const{			
	//return nativeEvent->get_shiftKey();
	return false;
}

/**
*触摸点列表。
*/
Object* Event::touches(){
	/*var arr=this.nativeEvent.touches;
	if (arr){
	for (var i=0,n=arr.length;i < n;i++){
	var e=arr[i];
	var point=Point.TEMP;
	point.setTo(e.clientX,e.clientY);
	Laya.stage._canvasTransform.invertTransformPoint(point);
	e.stageX=point.x;
	e.stageY=point.y;
	}
	}
	return arr;*/
	return nullptr;
}

bool Event::altKey()const{
	//return nativeEvent->get_altKey();
	return false;
}

bool Event::ctrlKey()const{
	//return nativeEvent->get_ctrlKey();
	return false;
}

Event* Event::EMPTY=new Event();
String Event::MOUSE_DOWN("mousedown");
String Event::MOUSE_UP("mouseup");
String Event::CLICK("click");
String Event::RIGHT_MOUSE_DOWN("rightmousedown");
String Event::RIGHT_MOUSE_UP("rightmouseup");
String Event::RIGHT_CLICK("rightclick");
String Event::MOUSE_MOVE("mousemove");
String Event::MOUSE_OVER("mouseover");
String Event::MOUSE_OUT("mouseout");
String Event::MOUSE_WHEEL("mousewheel");
String Event::ROLL_OVER("mouseover");
String Event::ROLL_OUT("mouseout");
String Event::DOUBLE_CLICK("doubleclick");
String Event::CHANGE("change");
String Event::CHANGED("changed");
String Event::RESIZE("resize");
String Event::ADDED("added");
String Event::REMOVED("removed");
String Event::DISPLAY("display");
String Event::UNDISPLAY("undisplay");
String Event::ERROR("error");
String Event::COMPLETE("complete");
String Event::LOADED("loaded");
String Event::PROGRESS("progress");
String Event::INPUT("input");
String Event::RENDER("render");
String Event::OPEN("open");
String Event::MESSAGE("message");
String Event::CLOSE("close");
String Event::KEY_DOWN("keydown");
String Event::KEY_PRESS("keypress");
String Event::KEY_UP("keyup");
String Event::ENTER_FRAME("enterframe");
String Event::DRAG_START("dragstart");
String Event::DRAG_MOVE("dragmove");
String Event::DRAG_END("dragend");
String Event::ENTER("enter");
String Event::SELECT("select");
String Event::BLUR("blur");
String Event::FOCUS("focus");
String Event::PLAYED("played");
String Event::PAUSED("paused");
String Event::STOPPED("stopped");
String Event::START("start");
String Event::END("end");
String Event::ENABLED_CHANGED("enabledchanged");
String Event::COMPONENT_ADDED("componentadded");
String Event::COMPONENT_REMOVED("componentremoved");
String Event::ACTIVE_CHANGED("activechanged");
String Event::LAYER_CHANGED("layerchanged");
String Event::HIERARCHY_LOADED("hierarchyloaded");
String Event::MEMORY_CHANGED("memorychanged");
String Event::RECOVERING("recovering");
String Event::RECOVERED("recovered");
String Event::RELEASED("released");
String Event::LINK("link");
String Event::LABEL("label");

}}
