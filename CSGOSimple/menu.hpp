#pragma once

#include <string>
#include "singleton.hpp"
#include "imgui/imgui.h"

struct IDirect3DDevice9;

struct nk_context;

class Menu
    : public Singleton<Menu>
{
public:
    void Initialize();
    void Shutdown();

    void OnDeviceLost();
    void OnDeviceReset();

    void Render();

    void Show();
    void Hide();
    void Toggle();

	bool IsVisible() const { return _visible; };

	nk_context *ctx;

private:
    void CreateStyle();

    ImGuiStyle        _style;
    bool              _visible;
};