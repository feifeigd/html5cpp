#pragma once

#include "../resource/HTMLCanvas.h"

namespace engine{
	namespace renders{
		/// <code>Render</code> 是渲染管理类。它是一个单例
		class Render{
		public:
			//static _context:RenderContext;
			static engine::resource::HTMLCanvas* _mainCanvas;
			//static WebGL:any;
			//static clear:Function;
			/**
			* 清空纹理函数。
			*/
			//static clearAtlas:Function;
			/**
			* 完成函数。
			*/
			//static finish:Function;

			/**
			 * 初始化引擎。
			 * @param    width 游戏窗口宽度。
			 * @param    height    游戏窗口高度。
			 */
			Render(int width, int height);

			/** 目前使用的渲染器。*/
			//static context:RenderContext;
			/** 是否是 WebGl 模式。*/
			static bool isWebGl;
			/** 渲染使用的画布引用。 */
			//static canvas:any;
		};
	}
}
