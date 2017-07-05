
#include <engine.core.h>

using engine::utils::Handler;

TArray<Handler*> Handler::_pool;
int Handler::_gid=1;

Handler::Handler(client::Object* caller, Function method, Array const& args, bool once)
	: once(false), _id(0)
{
	//this.caller=null;
	//this.method=null;
	//this.args=null;
	setTo(caller,method,args,once);
}

Handler* Handler::setTo(client::Object* caller, Function method, Array const& args, bool once){
	_id = Handler::_gid++;
	this->caller=caller;
	this->method=method;
	this->args=args;
	this->once=once;
	return this;
}

void Handler::run(){
	if (!method)return;
	int id = _id;
	//method.apply(caller, args);
	if(_id == id && once) recover();
}

void Handler::runWith(Object* data){
	if (!method)return;
	int id = _id;
	/*if (data==null)this.method.apply(this.caller,this.args);
	else if (!this.args && !data.unshift)this.method.call(this.caller,data);
	else if (this.args)this.method.apply(this.caller,this.args ? this.args.concat(data):data);
	else this.method.apply(this.caller,data);*/
	if(_id == id && once ) recover();
}

Handler* Handler::clear(){
	caller = nullptr;
	method = nullptr;
	//args = nullptr;
	return this;
}

void Handler::recover(){
	if (_id > 0){
		_id = 0;
		_pool.push(clear());
	}
}

Handler* Handler::create(client::Object* caller, Function method, Array const& args, bool once){	
	if (_pool.get_length())return Handler::_pool.pop()->setTo(caller,method,args,once);
	return new Handler(caller,method,args,once);
}
