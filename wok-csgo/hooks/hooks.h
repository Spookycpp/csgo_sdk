#pragma once
#include "../globals.h"
#include "../features/features.h"

namespace hooks {
	void init();

	void undo();

	namespace d3d_device {
		namespace reset {
			constexpr auto index = 16;
			typedef long(__stdcall* T)(IDirect3DDevice9*, D3DPRESENT_PARAMETERS*);
			long __stdcall fn(IDirect3DDevice9* device, D3DPRESENT_PARAMETERS* present_params);
		}

		namespace present {
			constexpr auto index = 17;
			typedef long(__stdcall* T)(IDirect3DDevice9*, RECT*, RECT*, HWND, RGNDATA*);
			long __stdcall fn(IDirect3DDevice9* device, RECT* src_rect, RECT* dest_rect, HWND dest_wnd_override, RGNDATA* dirty_region);
		}
	}

	namespace client_dll {
		namespace frame_stage_notify {
			constexpr auto index = 37;
			typedef void(__stdcall* T)(e_client_frame_stage);
			void __stdcall fn(e_client_frame_stage stage);
		}
	}

	namespace client_mode {
		namespace create_move {
			constexpr auto index = 24;
			typedef bool(__stdcall* T)(float, c_user_cmd*);
			bool __stdcall fn(float input_sample_time, c_user_cmd* cmd);
		}

		namespace override_view {
			constexpr auto index = 18;
			typedef void(__stdcall* T) (c_view_setup*);
			void __stdcall fn(c_view_setup* setup);
		}
	}

	namespace model_render {
		namespace draw_model_execute {
			constexpr auto index = 21;
			typedef void(__thiscall* T)(i_model_render*, void*, const draw_model_state_t&, const model_render_info_t&, matrix3x4_t*);
			void __fastcall fn(i_model_render* ecx, void* edx, void* context, const draw_model_state_t& state, const model_render_info_t& info, matrix3x4_t* bones);
		}
	}

	namespace panel {
		namespace paint_traverse {
			constexpr auto index = 41;
			typedef void(__thiscall* T)(void*, uint32_t, bool, bool);
			void __fastcall fn(void* ecx, void* edx, uint32_t id, bool force_repaint, bool allow_force);
		}
	}

	namespace surface {
		namespace lock_cursor {
			constexpr auto index = 67;
			typedef void(__thiscall* T)(i_surface*);
			void __fastcall fn(i_surface* ecx, void* edx);
		}
	}

	namespace player {
		namespace eye_angles {
			constexpr auto index = 169;
			typedef qangle_t*(__thiscall* T)(c_cs_player*);
			qangle_t* __fastcall fn(c_cs_player* ecx, void* edx);
		}
	}

	namespace renderable {
		namespace setup_bones {
			constexpr auto index = 13;
			typedef bool(__thiscall* T)(i_client_renderable*, matrix3x4_t*, int, int, float);
			bool __fastcall fn(i_client_renderable* ecx, void* edx, matrix3x4_t* bones, int max_bones, int mask, float time);
		}
	}

	extern std::unique_ptr<memory::hook_t> m_d3d_device;
	extern std::unique_ptr<memory::hook_t> m_client_dll;
	extern std::unique_ptr<memory::hook_t> m_client_mode;
	extern std::unique_ptr<memory::hook_t> m_model_render;
	extern std::unique_ptr<memory::hook_t> m_panel;
	extern std::unique_ptr<memory::hook_t> m_surface;
	extern std::unique_ptr<memory::hook_t> m_player;
	extern std::unique_ptr<memory::hook_t> m_renderable;
}
