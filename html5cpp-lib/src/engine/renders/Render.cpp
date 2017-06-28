#include <engine.core.h>

using engine::renders::Render;
using engine::resource::HTMLCanvas;

HTMLCanvas* Render::_mainCanvas = nullptr;
bool Render::isWebGl = false;

Render::Render(int width, int height){
	_mainCanvas = HTMLCanvas::create("2D");
	/*var style = _mainCanvas.source.style;
	style.position='absolute';
	style.top=style.left="0px";
	style.background="#000000";
	Render._mainCanvas.source.id="layaCanvas";
	var isWebGl=laya.renders.Render.isWebGL;
	isWebGl && Render.WebGL.init(Render.canvas,width,height);
	Browser.document.body.appendChild(Render._mainCanvas.source);
	Render._context=new RenderContext(width,height,isWebGl ? null :Render._mainCanvas);
	Browser.window.requestAnimationFrame(loop);
	function loop (){
		Laya.stage._loop();
		Browser.window.requestAnimationFrame(loop);
	}*/
}
