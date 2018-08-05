#include"Gui.h"
#include<Windows.h>
#include"SDK.h"
#include"Menu.h"

WeebHookGui gWeebHookGui;

const char* szName;
const char* szValueType;


void WeebHookGui::draw_aimbot_line(std::string caption, float lineWidth, float lineHeight, float lineTop, float lineLeft, float textLeft, bool active, bool title, bool rescaleText = true)
{
	int text_col[4] = { 10, 210, 10, 250.0f },
		rect_col[4] = { 0, 0, 0, 180.f };
	float text_scale = 0.35;
	int font = 0;
	bool outline = false;
	bool dropShadow = false;

	int screen_w, screen_h;
	

	textLeft += lineLeft;

	float lineWidthScaled = lineWidth / (float)screen_w; // line width
	float lineTopScaled = lineTop / (float)screen_h; // line top offset
	float textLeftScaled = textLeft / (float)screen_w; // text left offset
	float lineHeightScaled = lineHeight / (float)screen_h; // line height

	float lineLeftScaled = lineLeft / (float)screen_w;
}



int WeebHookGui::WeebHookDraw(int nIndex, char* szParent[40], float x1Min, float x1Max, float x1Step, bool isClassHeader)
{
	int activeAimbotselection = 0;
	int activeTriggerbotSelection = 0;
	int activeAccuracySelection = 0;
	int acitveESPSelection = 0;

	const float lineWidth = 12;
	const int lineCount = 8;

	std::string caption = "[+] Aim bot";
	static struct {
		LPCSTR		text;
		bool		*pState;
		bool		*pUpdated;
	} lines[lineCount] = {
	{"Aimbot Key:", gEntVars.aimbot_key},
	{"Aimbot Mode:", gEntVars.aimbot_mode},
	{"Aimbot method:", gEntVars.aimbot_method},
	{"Aimbot FOV:", gEntVars.aimbot_fov},
	{"Aimbot Target", gEntVars.aimbot_target},
	{"Ignore Settings", gEntVars.aimbot_ignore_settings},
	{"extra features", gEntVars.aimbot_features},
	};

	DWORD waitTime = NULL;
	while (true)
	{


		DWORD maxTickCount = GetTickCount() + waitTime;
		do {
			//draw features
			draw_aimbot_line(caption, lineWidth, 7.0, 13.6, 4.0, 4.0, false, true);
			for (int i = 0; i < lineCount; i++)
			{
				if (i != activeAimbotselection)
					draw_aimbot_line(line_as_str(lines[i].text, lines[i].pState), lineWidth, 4.0, 60.0 + i * 24.0, 4.0, 9.0, false, false);
				draw_aimbot_line(line_as_str(lines[activeAimbotselection].text,
					lines[activeAimbotselection].pState), lineWidth + 1.0, 2.0, 60.0 + activeAimbotselection * 24.0, 4.0, 7.0, true, false);


			}
		} while (GetTickCount() < maxTickCount);
		waitTime = 0;
	}

	// draw trigger bot table

	const float lineWidth = 12;
	const int lineCount = 8;

	std::string caption = "[+] Trigger bot";
	static struct {
		LPCSTR		text;
		bool		*pState;
		bool		*pUpdated;
	} lines[lineCount] = {
		{},
		{},
		{},
		{},
		{},
	};
	DWORD maxTickCount = GetTickCount() + waitTime;
	do
	{
		// trigger bot menu item
		draw_triggerbot_line(caption, lineWidth, 7.0, 13.6, 4.0, 4.0, false, true);
		for (int i = 0; i < lineCount; i++)
		{
			if(i != activeTriggerbotSelection)
				draw_triggerbot_line(line_as_str(lines[i].text, lines[i].pState), lineWidth, 4.0, 60.0 + i * 24.0, 4.0, 9.0, false, false);
			draw_triggerbot_line(line_as_str(lines[activeTriggerbotSelection].text, lines[activeTriggerbotSelection].pState), lineWidth + 1.0, 2.0, 60.0 + activeTriggerbotSelection * 24.0, 4.0, 7.0, true, false);
		}
	} while (GetTickCount() < maxTickCount);
	waitTime = 0;
}


void process_menu_start(void)
{
	// draw the menu to screen
}