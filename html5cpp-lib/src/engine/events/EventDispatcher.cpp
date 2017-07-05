
#include <engine.core.h>

using engine::events::EventDispatcher;	
using engine::utils::Handler;

std::map<String, bool> EventDispatcher::MOUSE_EVENTS;// = {"rightmousedown":true,"rightmouseup":true,"rightclick":true,"mousedown":true,"mouseup":true,"mousemove":true,"mouseover":true,"mouseout":true,"click":true,"doubleclick":true};

class EventHandler : public Handler{

	EventHandler(client::Object* caller, Function method, Array const& args, bool once = false) : engine::utils::Handler(caller,method,args,once){		

	}

	//static Handler* create(client::Object* caller, Function method, Array const& args, bool once = true){		
	//	if (_pool.get_length())return _pool.pop()->setTo(caller,method,args,once);
	//	return new EventHandler(caller,method,args,once);
	//}
};


EventDispatcher::EventDispatcher(){
	//this._events=null;
}

bool EventDispatcher::hasListener(client::String const& type){
	//var listener = _events && _events[type];
	//return !!listener;
	return false;
}

bool EventDispatcher::event(client::String const& type, client::Object* data){
	/*if (!this._events || !this._events[type])return false;
	var listeners=this._events[type];
	if (listeners.run){
		if (listeners.once)delete this._events[type];
		data !=null ? listeners.runWith(data):listeners.run();
	}else {
		for (var i=0,n=listeners.length;i < n;i++){
			var listener=listeners[i];
			if (listener){
				data !=null ? listener.runWith(data):listener.run();
			}
			if (!listener || listener.once){
				listeners.splice(i,1);
				i--;
				n--;
			}
		}
		if (listeners.length===0)delete this._events[type];
	}*/
	return true;
}

EventDispatcher& EventDispatcher::on(client::String const& type, client::Object* caller, Function listener, Array const& args){
	return _createListener(type,caller,listener,args,false);
}

EventDispatcher& EventDispatcher::once(client::String const& type, client::Object* caller, Function listener, Array const& args){
	return _createListener(type,caller,listener,args,true);
}

EventDispatcher& EventDispatcher::_createListener(client::String const& type, client::Object* caller, Function listener, Array const& args, bool once){
	off(type,caller,listener,once);
	/*Handler* handler=EventHandler::create(caller ? caller : this,listener,args,once);
	this._events || (this._events={});
	var events=this._events;
	if (!events[type])events[type]=handler;
	else {
		if (!events[type].run)events[type].push(handler);
		else events[type]=[events[type],handler];
	}*/
	return *this;
}

EventDispatcher& EventDispatcher::off(client::String const& type, Object* caller, Function listener, bool onceOnly){		
	/*if (!this._events || !this._events[type])return *this;
	var listeners=this._events[type];
	if (listener !=null){
		if (listeners.run){
			if ((!caller || listeners.caller===caller)&& listeners.method===listener && (!onceOnly || listeners.once)){
				delete this._events[type];
				listeners.recover();
			}
		}else {
			var count=0;
			for (var i=0,n=listeners.length;i < n;i++){
				var item=listeners[i];
				if (item && (!caller || item.caller===caller)&& item.method===listener && (!onceOnly || item.once)){
					count++;
					listeners[i]=null;
					item.recover();
				}
			}
			if (count===n)delete this._events[type];
		}
	}*/
	return *this;
}


EventDispatcher& EventDispatcher::offAll(client::String const& type){
	/*var events=this._events;
	if (!events)return this;
	if (type){
		this._recoverHandlers(events[type]);
		delete events[type];
	}else {
		for (var name in events){
			this._recoverHandlers(events[name]);
		}
		this._events=null;
	}*/
	return *this;
}

void EventDispatcher::_recoverHandlers(Object* arr){
	/*if (arr.run){
		arr.recover();
	}else {
		for (var i=arr.length-1;i >-1;i--){
			if (arr[i]){
				arr[i].recover();
				arr[i]=null;
			}
		}
	}*/
}

bool EventDispatcher::isMouseEvent(String const& type){
	//return MOUSE_EVENTS[type];
	return false;
}

void EventDispatcher::__init$(){

}
