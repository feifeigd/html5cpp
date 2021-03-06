﻿#pragma once

#include <map>

namespace engine{
	namespace events{
		/**
		 *<code>EventDispatcher</code> 类是可调度事件的所有类的基类。
		 */
		class EventDispatcher{
			static std::map<String, bool> MOUSE_EVENTS;

		protected:
			EventDispatcher();

			/// 初始化
			static void __init$();
			/**
			* 检查 EventDispatcher 对象是否为特定事件类型注册了任何侦听器。
			* @param    type 事件的类型。
			* @return 如果指定类型的侦听器已注册，则值为 true；否则，值为 false。
			*/
			bool hasListener(client::String const& type);

			/**
			* 派发事件。
			* @param    type 事件类型。
			* @param    data 回调数据。
			*                <b>注意：</b>如果是需要传递多个参数 p1,p2,p3,...可以使用数组结构如：[p1,p2,p3,...] ；如果需要回调单个参数 p 是一个数组，则需要使用结构如：[p]，其他的单个参数 p ，可以直接传入参数 p。
			* @return 此事件类型是否有侦听者，如果有侦听者则值为 true，否则值为 false。
			*/
			bool event(client::String const& type, Object* data = nullptr);

			/**
			* 使用 EventDispatcher 对象注册指定类型的事件侦听器对象，以使侦听器能够接收事件通知。
			* @param    type 事件的类型。
			* @param    caller 事件侦听函数的执行域。
			* @param    listener 事件侦听函数。
			* @param    args 事件侦听函数的回调参数。
			* @return 此 EventDispatcher 对象。
			*/
			EventDispatcher& on(client::String const& type, client::Object* caller, Function listener, Array const& args);

			/**
			* 使用 EventDispatcher 对象注册指定类型的事件侦听器对象，以使侦听器能够接收事件通知，此侦听事件响应一次后自动移除。
			* @param    type 事件的类型。
			* @param    caller 事件侦听函数的执行域。
			* @param    listener 事件侦听函数。
			* @param    args 事件侦听函数的回调参数。
			* @return 此 EventDispatcher 对象。
			*/
			EventDispatcher& once(client::String const& type, client::Object* caller, Function listener, Array const& args);

			/**
			* 从 EventDispatcher 对象中删除侦听器。
			* @param    type 事件的类型。
			* @param    caller 事件侦听函数的执行域。
			* @param    listener 事件侦听函数。
			* @param    onceOnly 如果值为 true ,则只移除通过 once 方法添加的侦听器。
			* @return 此 EventDispatcher 对象。
			*/
			EventDispatcher& off(client::String const& type, Object* caller, Function listener, bool onceOnly = false);

			/**
			* 从 EventDispatcher 对象中删除指定事件类型的所有侦听器。
			* @param    type 事件类型，如果值为 null，则移除本对象所有类型的侦听器。
			* @return 此 EventDispatcher 对象。
			*/
			EventDispatcher& offAll(String const& type);

			/**
			* 检测指定事件类型是否是鼠标事件。
			* @param    type 事件的类型。
			* @return    如果是鼠标事件，则值为 true;否则，值为 false。
			*/
			bool isMouseEvent(String const& type);

			/// 删除一个 Handler(s)
			void _recoverHandlers(Object* arr);

			EventDispatcher& _createListener(client::String const& type, client::Object* caller, Function listener, Array const& args, bool once);
		};
	}
}
