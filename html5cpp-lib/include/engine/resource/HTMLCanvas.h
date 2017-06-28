#pragma once

#include "Bitmap.h"
#include "Context.h"

namespace engine{
	namespace resource{

		/**
		 * <code>HTMLCanvas</code> 是 Html Canvas 的代理类，封装了 Canvas 的属性和方法。
		 */
		class HTMLCanvas : Bitmap{
		public:
			/** 2D 模式。*/
			static std::string TYPE2D;
			/** 3D 模式。*/
			static std::string TYPE3D;
			/** 自动模式。*/
			static std::string TYPEAUTO;

			static std::function<Context*(std::string const& contextID)> _createContext;

			/**
			 * 根据指定的类型，创建一个 <code>HTMLCanvas</code> 实例。
			 * @param    type 类型。2D、3D。
			 */
			HTMLCanvas(std::string const& type);

		private:
			bool _is2D;
			Context* _ctx;

		public:
			static HTMLCanvas* create(std::string const& type);

			/**
			 * 获取 Canvas 渲染上下文。
			 * @param    contextID 上下文ID.
			 * @param    other
			 * @return  Canvas 渲染上下文 Context 对象。
			 */
			std::function<Context*(std::string const& contextID)> getContext;
		};
	}
}
