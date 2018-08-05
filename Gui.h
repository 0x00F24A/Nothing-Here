#pragma once

#include<Windows.h>
#include<vector>

#define menuName ">>> WeebHook <<<"

const char* szTitle;

int x = 120.0;
int y = 12;

struct MenuFeatures_t {
	char szParent;
	int nIndex;
	float x1Min;
	float x1Max;
	float x1Step;
	bool isClassHeader;
};


std::string line_as_str(std::string text, bool *pState)
{
	while (text.size() < 18) text += " ";
	return text + (pState ? (*pState ? "~g~On" : "~r~Off") : "");
}

class WeebHookGui
{
public:
	void process_menu_start(void);
	
	void draw_aimbot_line(std::string caption, float lineWidth, float lineHeight, float lineTop, float lineLeft, float textLeft, bool active, bool title, bool rescaleText = true);
	
	void draw_triggerbot_line(std::string caption, float lineWidth, float lineHeight, float lineTop, float lineLeft, float textLeft, bool active, bool title, bool rescaleText = true);
	
	void draw_accuracy_line(std::string caption, float lineWidth, float lineHeight, float lineTop, float lineLeft, float textLeft, bool active, bool title, bool rescaleText = true);
	
	void draw_esp_line(std::string caption, float lineWidth, float lineHeight, float lineTop, float lineLeft, float textLeft, bool active, bool title, bool rescaleText = true);

	


	void draw_menu_line(void);

	int WeebHookDraw(int nIndex, char* szParent[40], float x1Min, float x1Max, float x1Step, bool isClassHeader);

	int WeebHookMenu(int x, int y, float menuSize, char* szMenuFeautures, bool menuTable);

private:
	bool menuTable;
	bool menuTableSize;
	MenuFeatures_t pGui[130];
};

extern WeebHookGui gWeebHookGui;