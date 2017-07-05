#pragma once

#include "../utils/Handler.h"

namespace engine{
	namespace events{

		class EventHandler : public utils::Handler{
			EventHandler(caller:any, method:Function, args:Array<any>, once:boolean):any;

			void recover();

			/**
			* 从对象池内创建一个Handler，默认会执行一次回收，如果不需要自动回收，设置once参数为false 。
			* @param    caller 执行域(this)
			* @param    method 回调方法
			* @param    args 携带的参数
			* @param    once 是否只执行一次，如果为true，回调后执行recover()进行回收，默认为true
			* @return  返回创建的handler实例
			*/
			static create(caller:any, method:Function, args?:Array<any>, once?:boolean):laya.utils.Handler;
		};
	}
}
