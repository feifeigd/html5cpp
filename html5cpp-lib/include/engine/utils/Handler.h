#pragma once

namespace engine{
	namespace utils{
		/**
		* <p><code>Handler</code> 是事件处理器类。</p>
		* <p>推荐使用 Handler.create() 方法从对象池创建，减少对象创建消耗。</p>
		* <p><b>注意：</b>由于鼠标事件也用本对象池，不正确的回收及调用，可能会影响鼠标事件的执行。</p>
		*/
		class Handler{
		private:
			static TArray<Handler*> _pool;
			static int _gid;
			/** 执行域(this)。*/
			client::Object* caller;
			/** 处理方法。*/
			Function method;
			/** 参数。*/
			Array args;

			/** 表示是否只执行一次。如果为true，回调后执行recover()进行回收，回收后会被再利用，默认为false 。*/
			bool once;
		protected:
			int _id;

			/**
			* 根据指定的属性值，创建一个 <code>Handler</code> 类的实例。
			* @param    caller 执行域。
			* @param    method 处理函数。
			* @param    args 函数参数。
			* @param    once 是否只执行一次。
			*/
			Handler(client::Object* caller, Function method, Array const& args, bool once = false);

			/**
			* 设置此对象的指定属性值。
			* @param    caller 执行域(this)。
			* @param    method 回调方法。
			* @param    args 携带的参数。
			* @param    once 是否只执行一次，如果为true，执行后执行recover()进行回收。
			* @return  返回 handler 本身。
			*/
			Handler* setTo(client::Object* caller, Function method, Array const& args, bool once);

			/**
			* 执行处理器。
			*/
			void run();

			/**
			* 执行处理器，携带额外数据。
			* @param    data 附加的回调数据，可以是单数据或者Array(作为多参)。
			*/
			void runWith(Object* data);

			/**
			* 清理对象引用。
			*/
			Handler* clear();

			/**
			* 清理并回收到 Handler 对象池内。
			*/
			void recover();

			/**
			* 从对象池内创建一个Handler，默认会执行一次回收，如果不需要自动回收，设置once参数为false。
			* @param    caller 执行域(this)。
			* @param    method 回调方法。
			* @param    args 携带的参数。
			* @param    once 是否只执行一次，如果为true，回调后执行recover()进行回收，默认为true。
			* @return  返回创建的handler实例。
			*/
			static Handler* create(client::Object* caller, Function method, Array const& args, bool once = true);
		};
	}
}
