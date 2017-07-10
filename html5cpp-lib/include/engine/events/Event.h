#pragma once

namespace engine{

	namespace display{class Sprite;}

	namespace events{
		/**
		 * <code>Event</code> 是事件类型的集合。
		 */
		class Event {
		public:
			Event();

			/** 一个空的 Event 对象。用于事件派发中转使用。*/
			static Event* EMPTY;
			/** 定义 mousedown 事件对象的 type 属性值。*/
			static String MOUSE_DOWN;
			/** 定义 mouseup 事件对象的 type 属性值。*/
			static String MOUSE_UP;
			/** 定义 click 事件对象的 type 属性值。*/
			static String CLICK;
			/** 定义 rightmousedown 事件对象的 type 属性值。*/
			static String RIGHT_MOUSE_DOWN;
			/** 定义 rightmouseup 事件对象的 type 属性值。*/
			static String RIGHT_MOUSE_UP;
			/** 定义 rightclick 事件对象的 type 属性值。*/
			static String RIGHT_CLICK;
			/** 定义 mousemove 事件对象的 type 属性值。*/
			static String MOUSE_MOVE;
			/** 定义 mouseover 事件对象的 type 属性值。*/
			static String MOUSE_OVER;
			/** 定义 mouseout 事件对象的 type 属性值。*/
			static String MOUSE_OUT;
			/** 定义 mousewheel 事件对象的 type 属性值。*/
			static String MOUSE_WHEEL;
			/** 定义 mouseover 事件对象的 type 属性值。*/
			static String ROLL_OVER;
			/** 定义 mouseout 事件对象的 type 属性值。*/
			static String ROLL_OUT;
			/** 定义 doubleclick 事件对象的 type 属性值。*/
			static String DOUBLE_CLICK;
			/** 定义 change 事件对象的 type 属性值。*/
			static String CHANGE;
			/** 定义 changed 事件对象的 type 属性值。*/
			static String CHANGED;
			/** 定义 resize 事件对象的 type 属性值。*/
			static String RESIZE;
			/** 定义 added 事件对象的 type 属性值。*/
			static String ADDED;
			/** 定义 removed 事件对象的 type 属性值。*/
			static String REMOVED;
			/** 定义 display 事件对象的 type 属性值。*/
			static String DISPLAY;
			/** 定义 undisplay 事件对象的 type 属性值。*/
			static String UNDISPLAY;
			/** 定义 error 事件对象的 type 属性值。*/
			static String ERROR;
			/** 定义 complete 事件对象的 type 属性值。*/
			static String COMPLETE;
			/** 定义 loaded 事件对象的 type 属性值。*/
			static String LOADED;
			/** 定义 progress 事件对象的 type 属性值。*/
			static String PROGRESS;
			/** 定义 input 事件对象的 type 属性值。*/
			static String INPUT;
			/** 定义 render 事件对象的 type 属性值。*/
			static String RENDER;
			/** 定义 open 事件对象的 type 属性值。*/
			static String OPEN;
			/** 定义 message 事件对象的 type 属性值。*/
			static String MESSAGE;
			/** 定义 close 事件对象的 type 属性值。*/
			static String CLOSE;
			/** 定义 keydown 事件对象的 type 属性值。*/
			static String KEY_DOWN;
			/** 定义 keypress 事件对象的 type 属性值。*/
			static String KEY_PRESS;
			/** 定义 keyup 事件对象的 type 属性值。*/
			static String KEY_UP;
			/** 定义 enterframe 事件对象的 type 属性值。*/
			static String ENTER_FRAME;
			/** 定义 dragstart 事件对象的 type 属性值。*/
			static String DRAG_START;
			/** 定义 dragmove 事件对象的 type 属性值。*/
			static String DRAG_MOVE;
			/** 定义 dragend 事件对象的 type 属性值。*/
			static String DRAG_END;
			/** 定义 enter 事件对象的 type 属性值。*/
			static String ENTER;
			/** 定义 select 事件对象的 type 属性值。*/
			static String SELECT;
			/** 定义 blur 事件对象的 type 属性值。*/
			static String BLUR;
			/** 定义 focus 事件对象的 type 属性值。*/
			static String FOCUS;
			/** 定义 played 事件对象的 type 属性值。*/
			static String PLAYED;
			/** 定义 paused 事件对象的 type 属性值。*/
			static String PAUSED;
			/** 定义 stopped 事件对象的 type 属性值。*/
			static String STOPPED;
			/** 定义 start 事件对象的 type 属性值。*/
			static String START;
			/** 定义 end 事件对象的 type 属性值。*/
			static String END;
			/** 定义 enabledchanged 事件对象的 type 属性值。*/
			static String ENABLED_CHANGED;
			/** 定义 componentadded 事件对象的 type 属性值。*/
			static String COMPONENT_ADDED;
			/** 定义 componentremoved 事件对象的 type 属性值。*/
			static String COMPONENT_REMOVED;
			/** 定义 activechanged 事件对象的 type 属性值。*/
			static String ACTIVE_CHANGED;
			/** 定义 layerchanged 事件对象的 type 属性值。*/
			static String LAYER_CHANGED;
			/** 定义 hierarchyloaded 事件对象的 type 属性值。*/
			static String HIERARCHY_LOADED;
			/** 定义 memorychanged 事件对象的 type 属性值。*/
			static String MEMORY_CHANGED;
			/** 定义 recovering 事件对象的 type 属性值。*/
			static String RECOVERING;
			/** 定义 recovered 事件对象的 type 属性值。*/
			static String RECOVERED;
			/** 定义 released 事件对象的 type 属性值。*/
			static String RELEASED;
			/** 定义 link 事件对象的 type 属性值。*/
			static String LINK;
			/** 定义 label 事件对象的 type 属性值。*/
			static String LABEL;
			/** 事件类型。*/
			String type;
			/** 原生浏览器事件。*/
			client::Event* nativeEvent;
			/** 事件目标触发对象。*/
			engine::display::Sprite* target;
			/** 事件当前冒泡对象。*/
			engine::display::Sprite* currentTarget;
			bool _stoped;
			/** 分配给触摸点的唯一标识号（作为 int）。*/
			int touchId;

			/**
			 * 设置事件数据。
			 * @param    type 事件类型。
			 * @param    currentTarget 事件目标触发对象。
			 * @param    target 事件当前冒泡对象。
			 * @return 返回当前 Event 对象。
			 */
			Event& setTo(String const& type, engine::display::Sprite* currentTarget, engine::display::Sprite* target);

			/**
			 * 防止对事件流中当前节点的后续节点中的所有事件侦听器进行处理。
			 */
			void stopPropagation();

			/**
			 * 触摸点列表。
			 */
			// touches:Array<any>;
			Object* touches();

			/**
			 * 表示 Alt 键是处于活动状态 (true) 还是非活动状态 (false)。
			 */
			bool altKey()const;
			/**
			 * 表示 Ctrl 键是处于活动状态 (true) 还是非活动状态 (false)。
			 */
			bool ctrlKey()const;
			/**
			 * 表示 Shift 键是处于活动状态 (true) 还是非活动状态 (false)。
			 */
			bool shiftKey()const;
		};
	}
}
