#pragma once

#include "Falco/Layer.h"
#include "Falco/Events/ApplicationEvent.h"
#include "Falco/Events/KeyEvent.h"
#include "Falco/Events/MouseEvent.h"

namespace Falco {

	class FALCO_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	
	private:
		float m_Time = 0.0f;
	};

}